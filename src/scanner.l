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