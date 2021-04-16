
void verReceitas(void);
void deletarReceitas(void);
void atualizarReceitas(void);
void encontrarReceitas(void);
void CadastrarReceitas(void);
char menuReceitas(void);
int valQuantidade(int);

struct ingredientes {
	char codReceita[4];
	char ingredientes[4];
	char medida[3];
	char quantidade[4];
};

struct receitas {
	char codReceita[4];
	char nome[50];
	char origem[20];
	char obtencao[30];
	char tempo[6];
	char dificuldade[2];
	char status;

};

struct preparo {
	char codReceita[4];
	char preparo[100];

};

typedef struct receitas Receita;
typedef struct ingredientes Ingredientes;
typedef struct preparo Preparo;

Ingredientes* telaPreencherIngredientes(void);
Receita* telaPreencherReceita(void);
void gravarReceita(Receita*);
void gravarIngredientes(Ingredientes*);
void gravarPreparo(Preparo*);
void regravarReceita(Receita*);
void exibirReceita(Receita*);
Receita* buscarReceita(char*); 
Preparo* buscaPreparo(char*);
Ingredientes* buscaIngredientes(char*);