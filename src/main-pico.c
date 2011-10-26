#include <stdio.h>
#include <stdlib.h>


#include <string.h>
#include "node.h"
#include "symbol_table.h"
#include "symbol_table.c"
#include "lista.h"

/* Programa principal do pico. */
char* progname;
int lineno;
extern FILE* yyin;
FILE *fp;
symbol_t s_table;
int desloc = 0;

int main(int argc, char* argv[]) {
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

   progname = argv[0];
   init_table(&s_table);

   if (!yyparse()) {
      


      printf("OKAY.\n");
   } else { 
      printf("ERROR.\n");
   }

   fp=fopen("saida.pico", "w+");
   uncompile(fp, syntax_tree);
   fclose(fp);

   yyin = fopen("saida.pico", "r");
   if (!yyparse()) 
      printf("OKAY.\n");
   else 
      printf("ERROR.\n");

   /*fp=fopen("saida2.pico", "w+");
   uncompile(fp, syntax_tree);
   fclose(fp);*/


   return(0);
}

yyerror(char* s) {
  fprintf(stderr, "%s: %s", progname, s);
  fprintf(stderr, "line %d\n", lineno);
}
