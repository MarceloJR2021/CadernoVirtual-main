
char menuFinancas(void);
void adicionarFinancas(void);
void removerFinancas(void);
int abrirArquivofin(void);

struct financas {
	float financa;
	char ultEntrada[10];
	char ultSaida[10];
	
};
typedef struct financas Financas;

Financas* telaAdicionarFinancas(void);
void gravarFinanca(Financas*);
Financas* somaFinancas(Financas*);
Financas* deletarFinancas(Financas*);