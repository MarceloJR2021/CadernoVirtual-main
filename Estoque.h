
char menuEstoque(void);
void adicionarEstoque(void);
void removerEstoque(void);
void exibirEstoque(void);

struct estoque {
	char status;
	char item[20];
	char quantidade[50];
	char preco[20];
    char medida[12];
	
};

typedef struct estoque Estoque;

Estoque* telaAdicionarEstoque(void);
void gravarEstoque(Estoque*);
Estoque* procurarEstoque(char*);
void regravarEstoque(Estoque*);