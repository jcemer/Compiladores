#define INT_TYPE 1
#define CHAR_TYPE 2
#define REAL_TYPE 3
#define DOUBLE_TYPE 4

#define INT_SIZE 4
#define CHAR_SIZE 1
#define REAL_SIZE 4
#define DOUBLE_SIZE 8

typedef struct attr {
    struct node_tac *code;
} attr;

typedef struct {
    int type;
    int size;
} attr_tipounico;

typedef struct {
    int dim;
    int * dim_init; /* limite inferior da dimensão i */
    int * dim_size; /* tamanho da dimensão i */
    int size;
} attr_listadupla;

typedef struct {
    int type;
    int size; /*tamanho total ocupado (número de elementos * w)*/
    //int w; /*tamanho de cada elemento*/
    attr_listadupla * inner;
} attr_tipolista;

typedef struct {
    int type;
    char *value; /*temporário a armazenar o cálculo*/
    struct node_tac *code; /*código para calcular*/
} attr_expr;

typedef struct {
    attr_expr **expr; /*array de expressões*/
    int lenght; /*número de expressões*/
} attr_listaexpr;

/*informações sobre o array a serem armazenadas no campo extra da tabela de
 * símbolos
typedef struct array_attr_t{
    int c; /*constante pré-calculada
    int nd; /*número de dimensões
    int *size; /*tamanho das dimensões
  //  int *inicio; /*início das dimensões
    int w;  /*tamanho de cada elemento
} array_attr_t; */

typedef struct {
    char *oper_int; /*nome a ser utilizado quando operando inteiros*/
    char *oper_float; 
} attr_opera;

typedef struct {
    struct node_tac *code; /*código para calcular*/
    //char* t; char* f;
} attr_expbool;

