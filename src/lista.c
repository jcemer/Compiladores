#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

int main(int argc, char* argv[]) {
   printf("oi");
}

struct tac* create_inst_tac(const char* res, const char* arg1, const char* op, const char* arg2) {
   struct tac* i = (struct tac*) malloc(sizeof(struct tac));
   i->res = res;
   i->arg1 = arg1;
   i->op = op;
   i->arg2 = arg2;
   return i;
}

/** \brief Funcao que imprime o conteudo de uma instrucao TAC 
 *
 * @param out um ponteiro sobre um arquivo (aberto) aonde ira ser escrita a instrucao.
 * @param i a instrucao a ser impressa.
 */
void print_inst_tac(FILE* out, struct tac i);

/** \brief Imprime no arquivo apontado por 'out' o conteudo da lista apontada
 * por 'code'.
 *
 * @param out um ponteiro sobre um arquivo (aberto) aonde ira ser escrita a lista (uma linha por elemento).
 * @param code o ponteiro para a lista a ser impressa.
 *
 * Obs.: cada linha impressa no arquivo deve comecar por um numero inteiro
 * (3 digitos) seguido de ':'. O numero deve ser o numero da linha.
 * Exemplo:
 *   001:  instrucao_qualquer
 *   002:  outra_instrucao
 *    .....
 *   999:  ultima_instrucao
 *   000:  agora_tem_instrucao_demais
 */
void print_tac(FILE* out, struct node_tac * code);

void append_inst_tac(struct node_tac ** code, struct tac * inst) {
    struct node_tac *new = (struct node_tac *) malloc(sizeof(struct node_tac));
    new->number = 1;
    new->inst = inst;
    cat_tac(code, &new);
}

void cat_tac(struct node_tac ** code_a, struct node_tac ** code_b) {
    int i = 1;
    struct node_tac *temp = *code_a;

    if (code_b) {
        if (code_a) {
            while (temp->next) {
               temp = temp->next;
               i++;
            }
            temp->next = *code_b;
            (*code_b)->prev = temp;
            temp = *code_b;
            do {
                temp->number = i++;
            } while (temp->next);
        } else {
           *code_a = *code_b;
        }
    }
}

