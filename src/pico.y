%error-verbose
%{

  /* Aqui, pode-se inserir qualquer codigo C necessario ah compilacao
   * final do parser. Sera copiado tal como esta no inicio do y.tab.c
   * gerado por Yacc.
   */
  #include <stdio.h>
  #include <stdlib.h>
  #include "node.h"
  #include "symbol_table.h"
  #include "lista.h"

  #define UNDEFINED_SYMBOL_ERROR -21
  Node* syntax_tree = NULL;

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
code: declaracoes acoes{
		$$ = create_node(@1.first_line, nodo_programa, "code", $1, $2, NULL, NULL);
		syntax_tree = $$;
	}
    | acoes{ 
		$$ = $1; 
		syntax_tree = $$;
	}
    ;

declaracoes: declaracao ';'{
		$$ = create_node(@1.first_line, nodo_declaracoes, "declaracoes", $1, coringa(";"), NULL, NULL);	
	}
           | declaracoes declaracao ';'{
		$$ = create_node(@1.first_line, nodo_declaracoes, "declaracoes", $1, $2, coringa(";"), NULL, NULL);
	}
           ;

declaracao: tipo ':' listadeclaracao{
		$$ = create_node(@1.first_line, nodo_declaracao, "declaracao", $1, coringa(":"), $3, NULL, NULL);
	}
	   ; 

listadeclaracao: IDF {
		$$ = create_node(@1.first_line, nodo_idf, $1, NULL, NULL);
	}
               | IDF ',' listadeclaracao{
		$$ = create_node(@1.first_line, nodo_listadeclaracao, "listadeclaracao", create_node(@1.first_line, nodo_idf, $1, NULL, NULL), coringa(","), $3, NULL, NULL);
	}
               ;

tipo: tipounico{
		$$ = create_node(@1.first_line, nodo_tipo, "tipo", $1, NULL, NULL);	
	} 
    | tipolista{
		$$ = create_node(@1.first_line, nodo_tipo, "tipo", $1, NULL, NULL);	
	}
    ;

tipounico: 
    INT{
		$$ = create_node(@1.first_line, nodo_tipounico, "int", NULL, NULL);	
	} 
  | DOUBLE{
		$$ = create_node(@1.first_line, nodo_tipounico, "double", NULL, NULL);	
	} 
  | REAL{
		$$ = create_node(@1.first_line, nodo_tipounico, "real", NULL, NULL);	
	} 
  | CHAR{
		$$ = create_node(@1.first_line, nodo_tipounico, "char", NULL, NULL);	
	}
;

tipolista: INT '(' listadupla ')'{
		$$ = create_node(@1.first_line, nodo_tipolista, "int", coringa("("), $3, coringa(")"), NULL, NULL);	
	}
         | DOUBLE '(' listadupla ')'{
		$$ = create_node(@1.first_line, nodo_tipolista, "double", coringa("("), $3, coringa(")"), NULL, NULL);	
	}
         | REAL '(' listadupla ')'{
		$$ = create_node(@1.first_line, nodo_tipolista, "real", coringa("("), $3, coringa(")"), NULL, NULL);	
	}
         | CHAR '(' listadupla ')'{
		$$ = create_node(@1.first_line, nodo_tipolista, "char", coringa("("), $3, coringa(")"), NULL, NULL);	
	}
         ;

listadupla: INT_LIT ':' INT_LIT{
		$$ = create_node(@1.first_line, nodo_listadupla, "listadupla", create_node(@1.first_line, nodo_int, $1, NULL, NULL), coringa(":"), create_node(@1.first_line, nodo_int, $3, NULL, NULL), NULL, NULL);
	}
          | INT_LIT ':' INT_LIT ',' listadupla{
		$$ = create_node(@1.first_line, nodo_listadupla, "listadupla", create_node(@1.first_line, nodo_int, $1, NULL, NULL), coringa(":"), create_node(@1.first_line, nodo_int, $3, NULL, NULL), coringa(","), $5, NULL, NULL);
	}
          ;

acoes: comando ';'  { 
		$$ = create_node(@1.first_line, nodo_acoes, "acoes", $1, coringa(";"), NULL, NULL); 
	}
    | comando ';' acoes {
		$$ = create_node(@1.first_line, nodo_acoes, "acoes", $1, coringa(";"), $3, NULL, NULL);
	}
    ;

comando: lvalue '=' expr {
		$$ = create_node(@1.first_line, nodo_comando, "comando", $1, coringa("="), $3, NULL, NULL);
	}
       | enunciado { 
		$$ = create_node(@1.first_line, nodo_comando, "comando", $1, NULL, NULL);
	}
       ;

lvalue: IDF {
		$$ = create_node(@1.first_line, nodo_idf, $1, NULL, NULL);
	}
      | IDF '[' listaexpr ']' {
		$$ = create_node(@1.first_line, nodo_lvalue, "lvalue", create_node(@1.first_line, nodo_idf, $1, NULL, NULL), coringa("["), $3, coringa("]"), NULL, NULL);
	}
      ;

listaexpr: expr{
		$$ = create_node(@1.first_line, nodo_parametro, "listaexpr", $1, NULL, NULL);
	}
	   | expr ',' listaexpr {
		$$ = create_node(@1.first_line, nodo_parametro, "listaexpr", $1, coringa(","), $3, NULL, NULL);
	}
	   ;

expr: expr '+' expr {
	    // IMPLEMENTAR
		$$ = create_node(@1.first_line, nodo_mais, "+", $1, coringa("+"), $3, NULL, NULL);
	}
    | expr '-' expr{
    	// IMPLEMENTAR
		$$ = create_node(@1.first_line, nodo_menos, "-", $1, coringa("-"), $3, NULL, NULL);
	}
    | expr '*' expr{
    	// IMPLEMENTAR
		$$ = create_node(@1.first_line, nodo_multiplicacao, "*", $1, coringa("*"), $3, NULL, NULL);
	}
    | expr '/' expr{
    	// IMPLEMENTAR
		$$ = create_node(@1.first_line, nodo_divisao, "/", $1, coringa("/"), $3, NULL, NULL);
	}
    | '(' expr ')' {
    	// IMPLEMENTAR
		$$ = create_node(@1.first_line, nodo_expressao, "()", coringa("("), $2, coringa(")"), NULL, NULL);
	}
    | INT_LIT  {
    	// IMPLEMENTAR
		$$ = create_node(@1.first_line, nodo_int, $1, NULL, NULL);
	} 
    | F_LIT {
    	// IMPLEMENTAR
		$$ = create_node(@1.first_line, nodo_float, $1, NULL, NULL);
	}    
    | lvalue {
    	// IMPLEMENTAR
		$$ = create_node(@1.first_line, nodo_expr, "expr", $1, NULL, NULL);
	}
    | chamaproc {
		$$ = create_node(@1.first_line, nodo_expr, "expr", $1, NULL, NULL);
	}
    ;

chamaproc: IDF '(' listaexpr ')' {
		$$ = create_node(@1.first_line, nodo_proc, "chamaproc", create_node(@1.first_line, nodo_idf, $1, NULL, NULL), coringa("("), $3, coringa(")"), NULL, NULL);
	}
         ;

enunciado: expr { $$ = $1 ;}
         | IF '(' expbool ')' THEN acoes fiminstcontrole {
		$$ = create_node(@1.first_line, nodo_if, "if", coringa("("), $3, coringa(")"), coringa("then"), $6, $7, NULL, NULL);
	}
         | WHILE '(' expbool ')' '{' acoes '}' {
		$$ = create_node(@1.first_line, nodo_while, "while", coringa("("), $3, coringa(")"), coringa("{"), $6, coringa("}"), NULL, NULL);
	}
         ;

fiminstcontrole: END {
		$$ = create_node(@1.first_line, nodo_end, "end", NULL, NULL);
	}
               | ELSE acoes END {
		$$ = create_node(@1.first_line, nodo_else, "else", $2, create_node(@1.first_line, nodo_end, "end", NULL, NULL), NULL, NULL);
	}
               ;

expbool: TRUE {
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

enunciado: PRINTF '(' expr ')' {
		$$ = create_node(@1.first_line, nodo_printf, "print", $3, NULL, NULL);
	}
		;

%%
 /* A partir daqui, insere-se qlqer codigo C necessario.
  */

