
void verReceitas(void);
void deletarReceitas(void);
void atualizarReceitas(void);
void encontrarReceitas(void);
void CadastrarReceitas(void);
char menuReceitas(void);
int valQuantidade(int);
int buscaCompleta(char*);
int buscaporIngredientes(char*);
int abrirArquivo(void);


struct ingredientes {
	char codReceita[4];
	char ingredientes[30];
	char medida[9];
	char quantidade[4];
	char status;
};

struct receitas {
	char codReceita[4];
	char nome[50];
	char origem[20];
	char obtencao[20];
	char tempo[4];
	char dificuldade[2];
	char status;
	struct receitas *prox;
};

struct preparo {
	char codReceita[4];
	char preparo[200];
	char status;

};

typedef struct receitas Receita;
typedef struct ingredientes Ingredientes;
typedef struct preparo Preparo;
Ingredientes* ingr;


Ingredientes* telaPreencherIngredientes(void);
Receita* telaPreencherReceita(void);
Preparo* telaPreencherPreparo(void);
void gravarReceita(Receita*);
void gravarIngredientes(Ingredientes*);
void gravarPreparo(Preparo*);
void regravarReceita(Receita*);
void regravarPreparo(Preparo*);
void regravarIngredientes(Ingredientes*);
void exibirReceita(Receita*);
void exibirIngredientes(char*);
void exibirPreparo(Preparo*);
char telaescolha(void);
char telaescolhaPesquisa(void);
Receita* buscarReceita(char*); 
Preparo* buscaPreparo(char*);
Ingredientes* buscaIngredientes(char*);
int vernoEstoque(Ingredientes* ing);
int acharExistente(char*);