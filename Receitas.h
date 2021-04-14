
void verReceitas(void);
void deletarReceitas(void);
void atualizarReceitas(void);
void encontrarReceitas(void);
void CadastrarReceitas(void);
char menuReceitas(void);
int valQuantidade(int);

struct ingredientes {
	int codReceita;
	char ingredientes[50];
	char medida[12];
	char quantidade[50];
};

struct receitas {
	int codReceita;
	char nome[50];
	char origem[20];
	char obtencao[30];
	char tempo[6];
	char dificuldade[2];
	char status;

};

struct preparo {
	int codReceita;
	char preparo[200];

};

typedef struct receitas Receita;
typedef struct ingredientes Ingredientes;
typedef struct preparo Preparo;

void gravarReceita(Receita*);
void exibirReceita(Receita*);
Receita* buscarReceita(char*); 