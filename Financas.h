
char menuFinancas(void);
void adicionarFinancas(void);
void removerFinancas(void);
void verFinancas(void);

struct financas {
	char financa[10];
	char ultEntrada[10];
	char ultSaida[10];
	
};
typedef struct financas Financas;