/** @file node.h
 *  @version 1.1
 */

#ifndef _NODE_H_
#define _NODE_H_

#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>

typedef int Node_type;

/* Serie de constantes que servirao para definir tipos de nos (na arvore). 
 * Essa serie pode ser completada ou alterada a vontade.
 */
#define nodo_programa         302
#define nodo_declaracoes      303
#define nodo_declaracao       304
#define nodo_idf              305
#define nodo_listadeclaracao  306
//#define nodo_tipo           307
#define nodo_tipounico	      308
#define nodo_tipolista	      309
#define nodo_listadupla	      310
#define nodo_int              311
#define nodo_acoes            312
#define nodo_comando	      313
#define nodo_lvalue           314
#define nodo_parametro	      315
#define nodo_mais             316
#define nodo_menos            317
#define nodo_divisao          318
#define nodo_float            319
#define nodo_expr             320
#define nodo_proc             321
#define nodo_if               322
#define nodo_while            323
#define nodo_end              324
#define nodo_else             325
#define nodo_true             326
#define nodo_false            327
#define nodo_and              328
#define nodo_or               329
#define nodo_not              330
#define nodo_sup              331
#define nodo_inf              332
#define nodo_le               333
#define nodo_ge               334
#define nodo_eq               335
#define nodo_ne               336
#define nodo_multiplicacao    337
#define nodo_expressao        338
#define nodo_printf           339

#define nodo_coringa          500

#ifdef __GNUC__
    /* If using gcc, warn about missing NULLs */
    #define NULL_TERMINATED __attribute__((sentinel))
#else
    #define NULL_TERMINATED
#endif

typedef struct _node {
   int num_line;   /**< numero de linha. */
   char* lexeme;   /**< o lexema retornado pelo analizador lexical. */
   Node_type type; /**< Um dos valores definidos acima pelos # defines. */
   void* attribute;/**< Qualquer coisa por enquanto. */
   
   struct nodelist *children; /*lista de filhos*/
} Node;

extern Node * syntax_tree;


/**
 *  * Node constructor.
 *
 * @param nl: line number where this token was found in the source code.
 * @param t: node type (one of the values #define'd above). Must abort
 *             the program if the type is not correct.
 * @param lexeme: whatever string you want associated to this node.
 * @param attr: a semantical attribute.
 * @param child0: first of a list of pointers to children Node*'s. See the
 * extra file 'exemplo_func_var_arg.c' for an example.
 * To create a leaf, use NULL as last argument to create_node().
 * @return a pointer to a new Node.
 */
NULL_TERMINATED
Node* create_node(int nl, Node_type t,
        char* lexeme, Node* child0, ...);

Node* coringa(char* lexeme);

/** accessor to the number of children of a Node.
 *  Must abort the program if 'n' is NULL.
 */
int nb_of_children(Node* n);

/** Tests if a Node is a leaf.
 *  Must abort the program if 'n' is NULL.
 *  @return 1 if n is a leaf, 0 else.
 */
int is_leaf(Node* n);

/** accessor to the i'th child of a Node.
 * @param n : the node to be consulted. Must abort the program if 'n' is NULL.
 * @param i : the number of the child that one wants. Must be lower 
 *       than the degree of the node and larger than 0. 
 *       Must abort the program if i is not correct.
 * @return a pointer on a Node.
 */
Node* child(Node* n, int i) ;

/** Destructor of a Node. Desallocates (recursively) all the tree rooted at
 * 'n'.
 */
int deep_free_node(Node* n) ;

/** returns the height of the tree rooted by 'n'.
 *  The height of a leaf is 1. 
 */
int height(Node *n) ;

/** Prints into a file the lexemes contained in the node rooted by 'n'.
 *  The impression must follow a depth-first order.
 *  @param outfile : the file to which the lexemes are printed.
 *  @param n : the root node of the tree. Must abort the program if 'n' is NULL.
 *  FILE* outfile, 
 */
void uncompile(FILE* outfile, Node *n);


#endif
