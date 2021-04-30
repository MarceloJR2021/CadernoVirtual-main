
char menuEstoque(void);
void adicionarEstoque(void);
void removerEstoque(void);
void exibirEstoque(void);
void exibirtudo(void);
void telaexibirEstoque(void);

struct estoque {
	char status;
	char item[30];
	char quantidade[50];
	char preco[20];
    char medida[12];
	
};
struct financas {
	float financa;
	char ultEntrada[10];
	char ultSaida[10];
	
};

typedef struct financas Financas;

typedef struct estoque Estoque;

Estoque* telaAdicionarEstoque(void);
void gravarEstoque(Estoque*);
Estoque* procurarEstoque(char*);
void regravarEstoque(Estoque*);
Estoque* aberturaFinancas(Estoque*);
Financas* deletarFinancasest(Estoque*);
void gravarFinancaest(Financas*);