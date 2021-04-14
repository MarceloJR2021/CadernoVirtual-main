
char menuEstoque(void);
void adicionarEstoque(void);
void removerEstoque(void);
void verEstoque(void);

struct estoque {
	char item[20];
	char quantidade[50];
	char preco[20];
    char medida[12];
	
};

typedef struct estoque Estoque;