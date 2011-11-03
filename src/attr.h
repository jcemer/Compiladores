#define INT_TYPE 1
#define CHAR_TYPE 2
#define REAL_TYPE 3
#define DOUBLE_TYPE 4

#define INT_SIZE 4
#define CHAR_SIZE 1
#define REAL_SIZE 4
#define DOUBLE_SIZE 8

/* DECLARACOES */

typedef struct {
    int type;
    int size;
} attr_tipounico;

typedef struct {
    int lenght;
    int * dim_init; /* limite inferior da dimensão i */
    int * dim_size; /* tamanho da dimensão i */
    int size;
} attr_listadupla;

typedef struct {
    int type;
    int type_size;
    int size;
    attr_listadupla * inner;
} attr_tipolista;

typedef struct {
    int lenght;
    int type_size;
    int * dim_size;
    int c;
} entry_textra;

/* ACOES */

typedef struct attr {
    struct node_tac *code;
} attr;

typedef struct {
    int type;
    char *value;
    struct node_tac *code;
} attr_expr;

typedef struct {
    attr_expr ** expr;
    int lenght;
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


