%error-verbose
%{
    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>
    #include <stdarg.h>

    #include "node.h"
    #include "symbol_table.c"
    #include "lista.c"
    #include "attr.h"

    Node* syntax_tree = NULL;
    symbol_t s_table;
    int desloc = 0;

    #define UNDEFINED_SYMBOL_ERROR -21
    #define TYPE_MISMATCH_ERROR -20
    #define GET_ERROR 1
    int errorValue;
    int error(int type);

    #define SP "SP"
    #define RX "Rx"

    void insert_nodes(Node *, Node *);
    void address(char **, int, char *);
    int operation(attr_expr **, char *, attr_expr *, attr_expr *);

    int rx_tempCount = 0;
    int rx_temp(int type);
%}

%union {
  struct _node * no;
  char* string;
}


%token<string> IDF
%token<no> INT
%token<no> DOUBLE
%token<no> REAL
%token<no> CHAR
%token<no> QUOTE
%token<no> LE
%token<no> GE
%token<no> EQ
%token<no> NE
%token<no> AND
%token<no> OR
%token<no> NOT
%token<no> IF
%token<no> THEN
%token<no> ELSE
%token<no> WHILE
%token<string> INT_LIT
%token<string> F_LIT
%token<no> END
%token<no> TRUE
%token<no> FALSE
%token<no> STRING
%token<string> CONST
%token<string> STR_LIT
%token<no> PRINTF

%left "+" "-"
%left "*" "/"
%left OR
%left AND
%left NOT


%type<no> code 
%type<no> declaracoes
%type<no> declaracao
%type<no> listadeclaracao
%type<no> tipo
%type<no> tipounico
%type<no> tipolista
%type<no> listadupla
%type<no> acoes
%type<no> comando
%type<no> lvalue
%type<no> listaexpr
%type<no> expr
%type<no> chamaproc
%type<no> enunciado
%type<no> fiminstcontrole
%type<no> expbool


%start code

 /* A completar com seus tokens - compilar com 'yacc -d' */

%%
code: 
    declaracoes acoes{
        syntax_tree = $$ = create_node(@1.first_line, nodo_programa, "code", $1, $2, NULL, NULL);
        $$->attribute = $2->attribute;
        print_tac(stdout, ((attr *) $$->attribute)->code);
    }
  | acoes{ 
        syntax_tree = $$ = $1;
    }
;

declaracoes: 
    declaracao ';' {
        $$ = create_node(@1.first_line, nodo_declaracoes, "declaracoes", $1, coringa(";"), NULL, NULL); 
    }
  | declaracoes declaracao ';' {
        $$ = create_node(@1.first_line, nodo_declaracoes, "declaracoes", $1, $2, coringa(";"), NULL, NULL);
    }
;

declaracao: 
    tipo ':' listadeclaracao{
        insert_nodes((Node *)$1, (Node *)$3);
        $$ = create_node(@1.first_line, nodo_declaracao, "declaracao", $1, coringa(":"), $3, NULL, NULL);
    }
; 

listadeclaracao: 
    IDF {
        $$ = create_node(@1.first_line, nodo_idf, $1, NULL, NULL);
    }
  | IDF ',' listadeclaracao{
        $$ = create_node(@1.first_line, nodo_listadeclaracao, "listadeclaracao", create_node(@1.first_line, nodo_idf, $1, NULL, NULL), coringa(","), $3, NULL, NULL);
    }
;

tipo: 
    tipounico {
        //$$ = create_node(@1.first_line, nodo_tipo, "tipo", $1, NULL, NULL);
        //$$->attribute = $1->attribute;
        $$ = $1;
    } 
  | tipolista {
        //$$ = create_node(@1.first_line, nodo_tipo, "tipo", $1, NULL, NULL);
        //$$->attribute = $1->attribute;
        $$ = $1;   
    }
;

tipounico: 
    INT{
        attr_tipounico * at = malloc(sizeof(attr_tipounico));
        at->type = INT_TYPE;
        at->size = INT_SIZE;
        $$ = create_node(@1.first_line, nodo_tipounico, "int", NULL, NULL);
        $$->attribute = at;
    } 
  | DOUBLE{
        attr_tipounico * at = malloc(sizeof(attr_tipounico));
        at->type = DOUBLE_TYPE;
        at->size = DOUBLE_SIZE;
        $$ = create_node(@1.first_line, nodo_tipounico, "double", NULL, NULL);
        $$->attribute = at;
    } 
  | REAL{
        attr_tipounico * at = malloc(sizeof(attr_tipounico));
        at->type = REAL_TYPE;
        at->size = REAL_SIZE;
        $$ = create_node(@1.first_line, nodo_tipounico, "real", NULL, NULL);
        $$->attribute = at;
    } 
  | CHAR{
        attr_tipounico * at = malloc(sizeof(attr_tipounico));
        at->type = CHAR_TYPE;
        at->size = CHAR_SIZE;
        $$ = create_node(@1.first_line, nodo_tipounico, "char", NULL, NULL);
        $$->attribute = at;
    }
;

tipolista: 
    INT '(' listadupla ')' {
        attr_tipolista * at = malloc(sizeof(attr_tipolista));
        attr_listadupla * at_inner = ((attr_listadupla *) $3->attribute);

        at->type = INT_TYPE;
        at->size = at_inner->size * INT_SIZE;
        at->inner = at_inner;

        $$ = create_node(@1.first_line, nodo_tipolista, "int", coringa("("), $3, coringa(")"), NULL, NULL);
        $$->attribute = at;
    }
  | DOUBLE '(' listadupla ')' {
        attr_tipolista * at = malloc(sizeof(attr_tipolista));
        attr_listadupla * at_inner = ((attr_listadupla *) $3->attribute);

        at->type = DOUBLE_TYPE;
        at->size = at_inner->size * DOUBLE_SIZE;
        at->inner = at_inner;

        $$ = create_node(@1.first_line, nodo_tipolista, "double", coringa("("), $3, coringa(")"), NULL, NULL);
        $$->attribute = at;
    }
  | REAL '(' listadupla ')' {
        attr_tipolista * at = malloc(sizeof(attr_tipolista));
        attr_listadupla * at_inner = ((attr_listadupla *) $3->attribute);

        at->type = REAL_TYPE;
        at->size = at_inner->size * REAL_SIZE;
        at->inner = at_inner;

        $$ = create_node(@1.first_line, nodo_tipolista, "real", coringa("("), $3, coringa(")"), NULL, NULL);
        $$->attribute = at;    
    }
  | CHAR '(' listadupla ')' {
        attr_tipolista * at = malloc(sizeof(attr_tipolista));
        attr_listadupla * at_inner = ((attr_listadupla *) $3->attribute);

        at->type = CHAR_TYPE;
        at->size = at_inner->size * CHAR_SIZE;
        at->inner = at_inner;

        $$ = create_node(@1.first_line, nodo_tipolista, "char", coringa("("), $3, coringa(")"), NULL, NULL);
        $$->attribute = at;
    }
;

listadupla: 
    INT_LIT ':' INT_LIT {
        attr_listadupla * at = malloc(sizeof(attr_listadupla));

        at->dim = 1;
        at->dim_init = malloc(sizeof(int));
        at->dim_size = malloc(sizeof(int));

        at->dim_init[0] = atoi($1);
        at->dim_size[0] = atoi($3) - at->dim_init[0] + 1;
        at->size = at->dim_size[0];

        $$ = create_node(@1.first_line, nodo_listadupla, "listadupla", create_node(@1.first_line, nodo_int, $1, NULL, NULL), coringa(":"), create_node(@1.first_line, nodo_int, $3, NULL, NULL), NULL, NULL);
        $$->attribute = at;
    }
  | INT_LIT ':' INT_LIT ',' listadupla {
        int i;
        attr_listadupla * at = malloc(sizeof(attr_listadupla));
        attr_listadupla * at_last = ((attr_listadupla *) $5->attribute);

        at->dim = at_last->dim + 1;
        at->dim_init = malloc(sizeof(int) * at->dim);
        at->dim_size = malloc(sizeof(int) * at->dim);

        at->dim_init[0] = atoi($1);
        at->dim_size[0] = atoi($3) - at->dim_init[0] + 1;
        for (i = 0; i < at->dim - 1; i++) {
            at->dim_init[i+1] = at_last->dim_init[i];
            at->dim_size[i+1] = at_last->dim_size[i];
        }
        at->size = at->dim_size[0] * at_last->size;

        $$ = create_node(@1.first_line, nodo_listadupla, "listadupla", create_node(@1.first_line, nodo_int, $1, NULL, NULL), coringa(":"), create_node(@1.first_line, nodo_int, $3, NULL, NULL), coringa(","), $5, NULL, NULL);
        $$->attribute = at;    
    }
;

acoes: 
    comando ';' {
        $$ = create_node(@1.first_line, nodo_acoes, "acoes", $1, coringa(";"), NULL, NULL);
        $$->attribute = $1->attribute;
    }
  | comando ';' acoes {
        fprintf(stderr, "oi");
        attr * at = (attr *) malloc(sizeof(attr));
        at->code = NULL;
        cat_tac(&(at->code), &((attr *) $1->attribute)->code);
        fprintf(stderr, "z\n");
        cat_tac(&(at->code), &((attr *) $3->attribute)->code);
        fprintf(stderr, "z\n");

        $$ = create_node(@1.first_line, nodo_acoes, "acoes", $1, coringa(";"), $3, NULL, NULL);
        $$->attribute = at;
    }
;

comando: 
    lvalue '=' expr {
        // IMPLEMENTAR
        $$ = create_node(@1.first_line, nodo_comando, "comando", $1, coringa("="), $3, NULL, NULL);
    }
  | enunciado { 
        $$ = create_node(@1.first_line, nodo_comando, "comando", $1, NULL, NULL);
        $$->attribute = $1->attribute;
    }
;

lvalue: 
    IDF {
        // IMPLEMENTAR
        $$ = create_node(@1.first_line, nodo_idf, $1, NULL, NULL);
    }
  | IDF '[' listaexpr ']' {
        // IMPLEMENTAR
        $$ = create_node(@1.first_line, nodo_lvalue, "lvalue", create_node(@1.first_line, nodo_idf, $1, NULL, NULL), coringa("["), $3, coringa("]"), NULL, NULL);
    }
;

listaexpr: 
    expr {
        // IMPLEMENTAR
        $$ = create_node(@1.first_line, nodo_parametro, "listaexpr", $1, NULL, NULL);
    }
  | expr ',' listaexpr {
        // IMPLEMENTAR
        $$ = create_node(@1.first_line, nodo_parametro, "listaexpr", $1, coringa(","), $3, NULL, NULL);
    }
;

expr: 
    expr '+' expr {
        $$ = create_node(@1.first_line, nodo_mais, "+", $1, coringa("+"), $3, NULL, NULL);
        if (operation((attr_expr **) &($$->attribute), "ADD", $1->attribute, $3->attribute))
            return error(GET_ERROR);
    }
  | expr '-' expr{
        $$ = create_node(@1.first_line, nodo_menos, "-", $1, coringa("-"), $3, NULL, NULL);
        if (operation((attr_expr **) &($$->attribute), "SUB", $1->attribute, $3->attribute))
            return error(GET_ERROR);
    }
  | expr '*' expr{
        $$ = create_node(@1.first_line, nodo_multiplicacao, "*", $1, coringa("*"), $3, NULL, NULL);
        if (operation((attr_expr **) &($$->attribute), "MUL", $1->attribute, $3->attribute))
            return error(GET_ERROR);
    }
  | expr '/' expr{
        $$ = create_node(@1.first_line, nodo_divisao, "/", $1, coringa("/"), $3, NULL, NULL);
        if (operation((attr_expr **) &($$->attribute), "DIV", $1->attribute, $3->attribute))
            return error(GET_ERROR);
    }
  | '(' expr ')' {
        $$ = create_node(@1.first_line, nodo_expressao, "()", coringa("("), $2, coringa(")"), NULL, NULL);
        $$->attribute = $2->attribute;
    }
  | INT_LIT  {
        $$ = create_node(@1.first_line, nodo_int, $1, NULL, NULL);
        attr_expr * at = malloc(sizeof(attr_expr));
        at->value = $1;
        at->type = INT_TYPE;
        at->code = NULL;
        $$->attribute = at;
    } 
  | F_LIT {
        $$ = create_node(@1.first_line, nodo_float, $1, NULL, NULL);
        attr_expr * at = malloc(sizeof(attr_expr));
        at->value = $1;
        at->type = REAL_TYPE;
        at->code = NULL;
        $$->attribute = at;
    }    
  | lvalue {
        $$ = create_node(@1.first_line, nodo_expr, "expr", $1, NULL, NULL);
        $$->attribute = $1->attribute;
    }
  | chamaproc {
        $$ = create_node(@1.first_line, nodo_expr, "expr", $1, NULL, NULL);
    }
;

chamaproc: 
    IDF '(' listaexpr ')' {
        $$ = create_node(@1.first_line, nodo_proc, "chamaproc", create_node(@1.first_line, nodo_idf, $1, NULL, NULL), coringa("("), $3, coringa(")"), NULL, NULL);
    }
;

enunciado: 
    expr {
        attr * at = (attr *) malloc(sizeof(attr));
        at->code = ((attr_expr *) $1->attribute)->code;

        $$ = create_node(@1.first_line, nodo_expr, "expr", $1, NULL, NULL);
        $$->attribute = at;
    }
  | PRINTF '(' expr ')' {
        attr * at = (attr *) malloc(sizeof(attr));
        at->code = ((attr_expr *) $3->attribute)->code;
        append_inst_tac(&(at->code), create_inst_tac("", "", "PRINT", ((attr_expr *) $3->attribute)->value));

        $$ = create_node(@1.first_line, nodo_printf, "print", $3, NULL, NULL);
        $$->attribute = at;
    }
  | IF '(' expbool ')' THEN acoes fiminstcontrole {
        $$ = create_node(@1.first_line, nodo_if, "if", coringa("("), $3, coringa(")"), coringa("then"), $6, $7, NULL, NULL);
    }
  | WHILE '(' expbool ')' '{' acoes '}' {
        $$ = create_node(@1.first_line, nodo_while, "while", coringa("("), $3, coringa(")"), coringa("{"), $6, coringa("}"), NULL, NULL);
    }
;

fiminstcontrole: 
    END {
        $$ = create_node(@1.first_line, nodo_end, "end", NULL, NULL);
    }
  | ELSE acoes END {
        $$ = create_node(@1.first_line, nodo_else, "else", $2, create_node(@1.first_line, nodo_end, "end", NULL, NULL), NULL, NULL);
    }
;

expbool: 
    TRUE {
        $$ = create_node(@1.first_line, nodo_true, "true", NULL, NULL);
    }
  | FALSE {
        $$ = create_node(@1.first_line, nodo_false, "false", NULL, NULL);
    }
  | '(' expbool ')' {
        $$ = create_node(@1.first_line, nodo_expressao, "()", coringa("("), $2, coringa(")"), NULL, NULL);
    }
  | expbool AND expbool {
        $$ = create_node(@1.first_line, nodo_and, "and", $1, coringa("&"), $3, NULL, NULL);
    }
  | expbool OR expbool {
        $$ = create_node(@1.first_line, nodo_or, "or", $1, coringa("|"), $3, NULL, NULL);
    }
  | NOT expbool {
        $$ = create_node(@1.first_line, nodo_not, "not", coringa("!"), $2, NULL, NULL);
    }
  | expr '>' expr {
        $$ = create_node(@1.first_line, nodo_sup, "sup", $1, coringa(">"), $3, NULL, NULL);
    }
  | expr '<' expr {
        $$ = create_node(@1.first_line, nodo_inf, "inf", $1, coringa("<"),$3, NULL, NULL);
    }
  | expr LE expr {
        $$ = create_node(@1.first_line, nodo_le, "le", $1, coringa("<="), $3, NULL, NULL);
    }
  | expr GE expr {
        $$ = create_node(@1.first_line, nodo_ge, "ge", $1, coringa(">="), $3, NULL, NULL);
    }
   | expr EQ expr {
        $$ = create_node(@1.first_line, nodo_eq, "eq", $1, coringa("=="), $3, NULL, NULL);
    }
  | expr NE expr {
        $$ = create_node(@1.first_line, nodo_ne, "ne", $1, coringa("<>"), $3, NULL, NULL);
    }
;


%%
 /* A partir daqui, insere-se qlqer codigo C necessario.
  */

int NaN(int type) {
    return type == CHAR_TYPE; // not a number
}
void address(char ** out, int num, char *ap) {
    * out = malloc(sizeof(char) * 8);
    sprintf(* out, "%03d(%s)", num, ap);
}

void insert_nodes(Node * ntype, Node * nvar) {
    /* NODO IDF */
    if (nvar->type == nodo_idf) {
        entry_t *e = malloc(sizeof(entry_t));
        e->name = malloc(sizeof(char)* (strlen(nvar->lexeme) + 1));
        strcpy(e->name, nvar->lexeme);

        // TIPO UNICO
        if (ntype->type == nodo_tipounico) {
            e->type = ((attr_tipounico *) ntype->attribute)->type;
            e->size = ((attr_tipounico *) ntype->attribute)->size;
            e->extra = NULL;
        // TIPO LISTA
        } else if(ntype->type == nodo_tipolista) {
            e->type = ((attr_tipolista *) ntype->attribute)->type;
            e->size = ((attr_tipolista *) ntype->attribute)->size;

            /*constante 'c' pré-calculada para acessar algo no array 
            int c;
            attr_listadupla *aux = ((attr_tipolista *) ntype->attribute)->inner;




            //int i;
            //array_attr_t * at = malloc(sizeof(array_attr_t));

            /*calcula a constante 
            c = aux->inicio[0];
            for(i=1; i< aux->tam_arrays; i++)
            {
                c = c * aux->size[i] + aux->inicio[i];
            }
            c = c * ((tipolista_attr_t *)tipo->attribute)->w;
            c = desloc - c;
           
            at->c = c;
            at->nd = aux->tam_arrays;
            at->size = malloc(sizeof(int)* at->nd);
            for(i=0; i< at->nd; i++)
            {
                at->size[i] = aux->size[i];
            }
            at->w = ((tipolista_attr_t *)tipo->attribute)->w;

            entrada->extra= at;*/
        }
        e->desloc = desloc;
        desloc += e->size;
        insert(&s_table, e);

    /* NODO LISTA DECLARACAO */
    } else if (nvar->type == nodo_listadeclaracao) {
        int i;
        for(i = 0; i < nb_of_children(nvar); i++)
            insert_nodes(ntype, child(nvar, i));
    }
}

int operation(attr_expr ** ret, char * type, attr_expr * left, attr_expr * right) {
    attr_expr * at = (attr_expr *) malloc(sizeof(attr_expr));
    * ret = at;
    at->code = left->code;
    cat_tac(&(at->code), &(right->code));

    if(NaN(left->type) || NaN(right->type))
        return error(TYPE_MISMATCH_ERROR);
    
    if(left->type == INT_TYPE && right->type == INT_TYPE) {
        at->type = INT_TYPE;
        address(&(at->value), rx_temp(INT_TYPE), RX);
        append_inst_tac(&(at->code), create_inst_tac(at->value, left->value, type, right->value));
    }
    // TODO: FLOAT
    return 0;
}
int error(int value) {
    if (value == GET_ERROR)
        return errorValue;
    return errorValue = value;
}

int rx_temp(int type) {
    int ret = rx_tempCount;
    switch (type) {
        case CHAR_TYPE:     rx_tempCount += CHAR_SIZE; break;
        case INT_TYPE:      rx_tempCount += INT_SIZE; break;
        case REAL_TYPE:     rx_tempCount += REAL_SIZE; break;
        case DOUBLE_TYPE:   rx_tempCount += DOUBLE_SIZE; break;
    }
    return ret;
}
