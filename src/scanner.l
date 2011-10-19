 /* Secao das declaracoes */
%option yylineno
%option noyywrap
  /* Sera copiado no .c final */

%{
	#define YY_USER_ACTION yylloc.first_line = yylineno;

	#include <stdlib.h>
	#include <string.h>

	/* este include eh importante... */
	#include "tokens.h"

	int VAL_INT;
	double VAL_DOUBLE;
%}
 
  /* Definicoes regulares (A COMPLETAR conforme a especificacao) */
digit	   [0-9]
letterLow  [a-z] 
letterUp   [A-Z]

%%

 /* Secao das Regras de traducao */
 
 /* TOKENS SIMPLES (Todos os Tokens definidos em tokens.h 
	mais os Tokens simples que retornam a própria entrada) */

int    		{return(INT);}
double 		{return(DOUBLE);}
real   		{return(REAL); }
char 		{return(CHAR);}
string 		{return(STRING);}
"*"    		{return('*');}
"+"    		{return('+');}
"-"    		{return('-');}
"/"    		{return('/');}
","    		{return(',');}
";"    		{return(';');}
":"    		{return(':');}
"'"    		{return(QUOTE);}
"("    		{return('(');}
")"    		{return(')');}
"["    		{return('[');}
"]"    		{return(']');}
"{"    		{return('{');}
"}"    		{return('}');}
"<"    		{return('<');}
">"    		{return('>');}
"="    		{return('=');}
"<="   		{return(LE);}
">="   		{return(GE) ;}
"=="   		{return(EQ);}
"<>"   		{return(NE);}
"&"   		{return(AND);}
"|"   		{return(OR);}
"!"   		{return(NOT);}
if     		{return(IF);}
then   		{return(THEN);}
else   		{return(ELSE);}
while  		{return(WHILE);}
end    		{return(END);}
true   		{return(TRUE);}
false  		{return(FALSE);}
"print"   {return(PRINTF);}

 /* OUTROS TOKENS (IDF, CONST, STR_LIT, INT_LIT,
	F_LIT e tratamento de espaços em branco) */

 /* Brancos - Dúvida: Imprimo o 'SPACE' ou deveria ser em branco printf(" "); */
[ \n\t]+ {

}

 /* IDF - Acho que também poderia ser com [a-z_][a-zA-Z0-9_]* */
("_"|{letterLow})({letterLow}|{letterUp}|{digit}|"_")*  {
		yylval.string = (char*) malloc(strlen(yytext) + 1); 
		strcpy(yylval.string, yytext); 
		return IDF; 
	}

 /* CONST - Ou [A-Z][A-Z0-9_]* */
{letterUp}({letterUp}|{digit}|"_")* {
		yylval.string = (char*) malloc(strlen(yytext) + 1); 
		strcpy(yylval.string, yytext); 
		return CONST;
	}

 /* STR_LIT - Qualquer literal entre aspas */
["]({letterUp}|{letterLow}|{digit}|" ")*["] {
		yylval.string = (char*) malloc(strlen(yytext) + 1); 
		strcpy(yylval.string, yytext); 
		return STR_LIT;
	}
 /* INT_LIT - Simples, qualquer sequência de dígitos */
{digit}+ {
		VAL_INT = atoi(yytext);
		yylval.string = (char*) malloc(strlen(yytext) + 1);
		strcpy(yylval.string, yytext);
		return(INT_LIT);
	}
 /* F_LIT - Um pouco mais complexo, Números com ponto flutuante*/
({digit}*)"."({digit}+)([eE][+-]?({digit}+))? {
		VAL_DOUBLE = atof(yytext);
		yylval.string = (char*) malloc(strlen(yytext) + 1);
		strcpy(yylval.string, yytext);
		return(F_LIT);
	}
	
  /* Tratamento dos erros lexicais: a regra seguinte pega tudo o que nao
   * fechou com uma Regexp anterior.
   */
. { printf("Erro lexical - caractere nao reconhecido: %c.\n", yytext[0]);
    exit(-1); }
%%
 /* Secao dos  Procedimentos auxiliares  */

 /* Para redefinir a entrada padrao do LEX. 
  * Redefinir a variavel 'yyin' para ler de um arquivo. Por exemplo:
     yyin = fopen("Meu_programa.c", "r");
  * ira mandar ler o programa a ser compilado pelo analisador lexical
  * em 'Meu_programa.c'.
  * O default eh ler da entrada standard (o teclado).
  */

extern FILE *yyin;
int main_old(int argc, char* argv[]) {
   int token;
   if (argc != 2) {
     printf("uso: %s <input_file>. Try again!\n", argv[0]);
     exit(-1);
   }
   yyin = fopen(argv[1], "r");
   if (!yyin) {
     printf("Uso: %s <input_file>. Could not find %s. Try again!\n", 
         argv[0], argv[1]);
     exit(-1);
   }
  /* agora a entrada padrao eh o arquivo especificado como 1o argumento ao
   * executavel (argv[1]).
   * Soh chama o analisador lexical default fornecido pelo output do Flex:
   */
  while (token=yylex()) { 
     /* neste laco, obtem-se "palavra por palavra" os tokens reconhecidos
      * pelo scanner fornecido pelo Lex. Poderia ser feita a analise
      * sintatica... Sera feito depois!
      */
     printf("Meu analisador lexical reconheceu o token %d\n", token);
  }
  return(0);
}
