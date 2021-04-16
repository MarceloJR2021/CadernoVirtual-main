
char menuFinancas(void);
void adicionarFinancas(void);
void removerFinancas(void);
void verFinancas(void);

struct financas {
	float financa;
	char ultEntrada[10];
	char ultSaida[10];
	
};
typedef struct financas Financas;

Financas* telaAdicionarFinancas(void);
void gravarFinanca(Financas*);
void exibirFinancas(void);