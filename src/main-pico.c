#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#include "node.h"
#include "symbol_table.h"
#include "lista.h"
#include "attr.h"

/* Programa principal do pico. */
char* progname;
int lineno;
extern FILE* yyin;
extern int desloc;
FILE *fp;

extern symbol_t s_table;

int main(int argc, char* argv[]) {
   int opt, p_table = 0;
   char * ftac = NULL;
   while ((opt = getopt(argc, argv, "po:")) != -1) {
      if (opt == 'p') {
         p_table = 1;
      } else {
         ftac = (char *) malloc(sizeof(char) * (strlen(optarg) + 1));
         strcpy(ftac, optarg);
      } 
   }

   if (optind >= argc) {
     printf("Usage: %s [-p] [-o <tac_output>] <input_file>. Try again!\n", argv[0]);
     exit(-1);
   }

   if (!(yyin = fopen(argv[optind], "r"))) {
     printf("Usage: %s [-p] [-o <tac_output>] <input_file>. Could not find %s. Try again!\n", argv[0], argv[optind]);
     exit(-1);
   }

   progname = argv[0];
   if (!yyparse()) {
      printf("OKAY.\n");
      if (ftac && (fp = fopen(ftac, "w+"))) {
         fprintf(fp, "%d\n%d\n", desloc, rx_temp(0));
         print_tac(fp, ((attr *) syntax_tree->attribute)->code);
      }
   } else { 
      printf("ERROR.\n");
   }

   /*
   
   uncompile(fp, syntax_tree);
   fclose(fp);
   */

   if (p_table)
      print_table(s_table);

   return(0);
}

yyerror(char* s) {
  fprintf(stderr, "%s: %s", progname, s);
  fprintf(stderr, "line %d\n", lineno);
}
