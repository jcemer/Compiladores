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
    #define ARRAY_DIM_ERROR -22
    #define NOT_ARRAY_ERROR - 23
    #define GET_ERROR 1

    #define SP "SP"
    #define RX "Rx"

    const char * itoa(int);
    void address(char **, int, char *);

    void insert_nodes(Node *, Node *);
    int operation(attr_expr **, char *, attr_expr *, attr_expr *);
    int rx_temp(int type);

    int errorValue;
    int error(int);
    int error_undeclared(char *);
    int error_array(int, char *);
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

%left '+' '-'
%left '*' '/'
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
        at->type_size = INT_SIZE;
        at->size = at_inner->size * INT_SIZE;
        at->inner = at_inner;

        $$ = create_node(@1.first_line, nodo_tipolista, "int", coringa("("), $3, coringa(")"), NULL, NULL);
        $$->attribute = at;
    }
  | DOUBLE '(' listadupla ')' {
        attr_tipolista * at = malloc(sizeof(attr_tipolista));
        attr_listadupla * at_inner = ((attr_listadupla *) $3->attribute);

        at->type = DOUBLE_TYPE;
        at->type_size = DOUBLE_SIZE;
        at->size = at_inner->size * DOUBLE_SIZE;
        at->inner = at_inner;

        $$ = create_node(@1.first_line, nodo_tipolista, "double", coringa("("), $3, coringa(")"), NULL, NULL);
        $$->attribute = at;
    }
  | REAL '(' listadupla ')' {
        attr_tipolista * at = malloc(sizeof(attr_tipolista));
        attr_listadupla * at_inner = ((attr_listadupla *) $3->attribute);

        at->type = REAL_TYPE;
        at->type_size = REAL_SIZE;
        at->size = at_inner->size * REAL_SIZE;
        at->inner = at_inner;

        $$ = create_node(@1.first_line, nodo_tipolista, "real", coringa("("), $3, coringa(")"), NULL, NULL);
        $$->attribute = at;    
    }
  | CHAR '(' listadupla ')' {
        attr_tipolista * at = malloc(sizeof(attr_tipolista));
        attr_listadupla * at_inner = ((attr_listadupla *) $3->attribute);

        at->type = CHAR_TYPE;
        at->type_size = CHAR_SIZE;
        at->size = at_inner->size * CHAR_SIZE;
        at->inner = at_inner;

        $$ = create_node(@1.first_line, nodo_tipolista, "char", coringa("("), $3, coringa(")"), NULL, NULL);
        $$->attribute = at;
    }
;

listadupla: 
    INT_LIT ':' INT_LIT {
        attr_listadupla * at = malloc(sizeof(attr_listadupla));

        at->lenght = 1;
        at->dim_init = malloc(sizeof(int));
        at->dim_size = malloc(sizeof(int));

        at->dim_init[0] = atoi($1);
        at->dim_size[0] = atoi($3) - at->dim_init[0] + 1;
        at->size = at->dim_size[0];

        $$ = create_node(@1.first_line, nodo_listadupla, "listadupla", create_node(@1.first_line, nodo_int, $1, NULL, NULL), coringa(":"), create_node(@1.first_line, nodo_int, $3, NULL, NULL), NULL, NULL);
        $$->attribute = at;
    }
  | INT_LIT ':' INT_LIT ',' listadupla {
        attr_listadupla * at = malloc(sizeof(attr_listadupla));
        attr_listadupla * at_last = ((attr_listadupla *) $5->attribute);

        at->lenght = at_last->lenght + 1;
        at->dim_init = malloc(sizeof(int) * at->lenght);
        at->dim_size = malloc(sizeof(int) * at->lenght);

        at->dim_init[0] = atoi($1);
        at->dim_size[0] = atoi($3) - at->dim_init[0] + 1;
        int i;
        for (i = 0; i < at_last->lenght; i++) {
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
        attr * at = (attr *) malloc(sizeof(attr));
        at->code = NULL;
        cat_tac(&(at->code), &((attr *) $1->attribute)->code);
        cat_tac(&(at->code), &((attr *) $3->attribute)->code);

        $$ = create_node(@1.first_line, nodo_acoes, "acoes", $1, coringa(";"), $3, NULL, NULL);
        $$->attribute = at;
    }
;

comando: 
    lvalue '=' expr {
        attr * at = (attr *) malloc(sizeof(attr));
        attr_expr * left = ((attr_expr *) $1->attribute);
        attr_expr * right = ((attr_expr *) $3->attribute);

        if (left->type != right->type)
            return error(TYPE_MISMATCH_ERROR);

        at->code = left->code;
        cat_tac(&(at->code), &(right->code));
        append_inst_tac(&(at->code), create_inst_tac(left->value, right->value, ":=", ""));

        $$ = create_node(@1.first_line, nodo_comando, "comando", $1, coringa("="), $3, NULL, NULL);
        $$->attribute = at;
    }
  | enunciado { 
        $$ = create_node(@1.first_line, nodo_comando, "comando", $1, NULL, NULL);
        $$->attribute = $1->attribute;
    }
;

lvalue: 
    IDF {
        attr_expr *at = malloc(sizeof(attr_expr));
        entry_t * e = lookup(s_table, $1);
        if (!e)
            return error_undeclared($1);
        address(&(at->value), e->desloc, SP);
        at->type = e->type;
        at->code = NULL;

        $$ = create_node(@1.first_line, nodo_idf, $1, NULL, NULL);
        $$->attribute = at;
    }
  | IDF '[' listaexpr ']' {
        attr_expr *at = malloc(sizeof(attr_expr));
        attr_listaexpr * at_lista = ((attr_listaexpr *) $3->attribute);

        entry_t * e = lookup(s_table, $1);
        if (!e)
            return error_undeclared($1);
        at->type = e->type;
        at->code = NULL;

        // EXTRA
        entry_textra * e_extra = ((entry_textra *) e->extra);
        if (!e_extra)
            return error_array(NOT_ARRAY_ERROR, $1);
        if (at_lista->lenght > e_extra->lenght)
            return error_array(ARRAY_DIM_ERROR, $1);

        // CHECK LISTAEXPR: type and cat codes
        int i;
        for (i = 0; i < at_lista->lenght; i++) {
            if (at_lista->expr[i]->type != INT_TYPE)
                return error(TYPE_MISMATCH_ERROR);
            cat_tac(&(at->code), &(at_lista->expr[i]->code));
        }

        char * res;
        address(&res, rx_temp(INT_TYPE), RX);
        // e
        if (at_lista->lenght == 1)
            append_inst_tac(&(at->code), create_inst_tac(res, at_lista->expr[0]->value, ":=", ""));

        for (i = 1; i < at_lista->lenght; i++) {
            append_inst_tac(&(at->code), create_inst_tac(res, i == 1 ? at_lista->expr[0]->value : res, "MUL", itoa(e_extra->dim_size[i])));
            append_inst_tac(&(at->code), create_inst_tac(res, res, "ADD", at_lista->expr[i]->value));
        }
        // e * k
        append_inst_tac(&(at->code), create_inst_tac(res, res, "MUL", itoa(e_extra->type_size)));
        // e * k + c
        append_inst_tac(&(at->code), 
            create_inst_tac(res, res, e_extra->c > 0 ? "ADD" : "SUB", itoa(abs(e_extra->c)))
        );
        
        at->value = malloc(sizeof(char) * 17);
        strcpy(at->value, res);
        strcat(at->value, " (000(SP))");

        $$ = create_node(@1.first_line, nodo_lvalue, "lvalue", create_node(@1.first_line, nodo_idf, $1, NULL, NULL), coringa("["), $3, coringa("]"), NULL, NULL);
        $$->attribute = at;
    }
;

listaexpr: 
    expr {
        attr_listaexpr *at = malloc(sizeof(attr_listaexpr));
        at->lenght = 1;
        at->expr = malloc(sizeof(attr_expr *));
        at->expr[0] = (attr_expr *) $1->attribute;

        $$ = create_node(@1.first_line, nodo_parametro, "listaexpr", $1, NULL, NULL);
        $$->attribute = at;
    }
  | expr ',' listaexpr {
        attr_listaexpr * at = malloc(sizeof(attr_listaexpr));
        attr_listaexpr * at_last = ((attr_listaexpr *) $3->attribute);

        at->lenght = at_last->lenght + 1;
        at->expr = malloc(sizeof(attr_expr *) * at->lenght);
        
        at->expr[0] = (attr_expr *) $1->attribute;
        int i;
        for (i = 0; i < at_last->lenght; i++) 
            at->expr[i+1] = at_last->expr[i];

        $$ = create_node(@1.first_line, nodo_parametro, "listaexpr", $1, coringa(","), $3, NULL, NULL);
        $$->attribute = at;
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
        attr_expr * at = malloc(sizeof(attr_expr));
        
        at->type = ((attr_expr *) $1->attribute)->type;
        at->code = ((attr_expr *) $1->attribute)->code;
        
        char * res;
        address(&res, rx_temp(INT_TYPE), RX);
        append_inst_tac(&(at->code), create_inst_tac(res, ((attr_expr *) $1->attribute)->value, ":=", ""));
        
        at->value = res;

        // 

        /*char * right = malloc(sizeof(char) * 17);
        strcpy(right, res);
        strcat(right, " (000(SP))");

        append_inst_tac(&(at->code), create_inst_tac(ret, right, ":=", ""));
        at->value = ret;*/
      
        $$ = create_node(@1.first_line, nodo_expr, "expr", $1, NULL, NULL);
        $$->attribute = at;
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
const char * itoa(int value) {
    static char buffer [33];
    sprintf(buffer, "%d", value);
    return buffer;
}
void address(char ** out, int num, char *ap) {
    * out = malloc(sizeof(char) * 8);
    sprintf(* out, "%03d(%s)", num, ap);
}

void insert_nodes(Node * ntype, Node * nvar) {
    int i;
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

            attr_tipolista * at = (attr_tipolista *) ntype->attribute;
            attr_listadupla * at_lista = at->inner;
            // extra
            entry_textra * e_extra = malloc(sizeof(entry_textra));
            e_extra->lenght = at_lista->lenght;
            e_extra->type_size = at->type_size;
            // extra / c
            e_extra->c = at_lista->dim_init[0];
            for(i = 1; i < at_lista->lenght; i++)
                e_extra->c = (e_extra->c * at_lista->dim_size[i]) + at_lista->dim_init[i];
            e_extra->c *= -at->type_size;
            e_extra->c += desloc;
            // extra / dim_size
            e_extra->dim_size = malloc(sizeof(int) * e_extra->lenght);
            for(i = 0; i < e_extra->lenght; i++)
                e_extra->dim_size[i] = at_lista->dim_size[i];

            e->extra = e_extra;
        }
        e->desloc = desloc;
        desloc += e->size;
        insert(&s_table, e);

    /* NODO LISTA DECLARACAO */
    } else if (nvar->type == nodo_listadeclaracao) {
        for(i = 0; i < nb_of_children(nvar); i++)
            insert_nodes(ntype, child(nvar, i));
    }
}

// OPERATION: add sub mul div
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

// RX TEMP
int rx_temp(int type) {
    static int tmp = 0;
    int ret = tmp;
    switch (type) {
        case CHAR_TYPE:     tmp += CHAR_SIZE; break;
        case INT_TYPE:      tmp += INT_SIZE; break;
        case REAL_TYPE:     tmp += REAL_SIZE; break;
        case DOUBLE_TYPE:   tmp += DOUBLE_SIZE; break;
    }
    return ret;
}

// ERROR
int error(int value) {
    if (value == GET_ERROR) {
        printf("Error %i", value);
        return errorValue;
    }
    return errorValue = value;
}
int error_undeclared(char * var) {
    printf("UNDEFINED SYMBOL. A Variavel %s nao foi declarada\n", var);
    return error(UNDEFINED_SYMBOL_ERROR);
}
int error_array(int type, char * var) {
    switch (type) {
        case NOT_ARRAY_ERROR:
            printf("ERRO! Variavel %s nao eh um array!\n", var); break;
        case ARRAY_DIM_ERROR:
            printf("ERRO! Array %s indexado em mais dimensoes do que possui!\n", var); break;
    }
    return error(type);
}

