#include "Financas.h"

char menuEstoque(void);
void adicionarEstoque(void);
void removerEstoque(void);
void exibirEstoque(void);

struct estoque {
	char status;
	char item[30];
	char quantidade[5];
	char preco[10];
    char medida[9];
	struct estoque* prox;
};


typedef struct estoque Estoque;

Estoque* telaAdicionarEstoque(void);
void gravarEstoque(Estoque*);
Estoque* procurarEstoque(char*);
void regravarEstoque(Estoque*);
Estoque* aberturaFinancas(Estoque*);
Financas* deletarFinancasest(Estoque*);
void gravarFinancaest(Financas*);