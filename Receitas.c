
char menuReceitas(void) {
	char op;
    system("cls");
	printf("\n");
	printf("***************************************************************************\n");
	printf("**                                                                       **\n");
	printf("**           -----------------------------------------------             **\n");
	printf("**           ---------------  Menu Receitas  ---------------             **\n");
	printf("**           -----------------------------------------------             **\n");
	printf("**                                                                       **\n");
	printf("**           1. Cadastrar Receitas                                       **\n");
	printf("**           2. Encontrar Receitas                                       **\n");
	printf("**           3. Atualizar Receitas                                       **\n");
    printf("**           4. Deletar receitas                                         **\n");
	printf("**           5. Ver Receitas                                             **\n");
	printf("**           0. Voltar                                                   **\n");
	printf("**                                                                       **\n");
	printf("             Escolha a opcao desejada:  ");
	scanf("%c", &op);
	getchar();
	printf("**                                                                       **\n");
	printf("***************************************************************************\n");
	printf("\n");
    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
	getchar();
	return op;
}

void CadastrarReceitas(void) {
	char nome[50];
	char preparo[200];
	char origem[20];
	char obtencao[50];
	char ingredientes[200];
	int quantidade[50];
	int quant;
	int cont;

    system("cls");
	printf("\n");
	printf("***************************************************************************\n");
	printf("**                                                                       **\n");
	printf("**           -----------------------------------------------             **\n");
	printf("**           ------------  Cadastrar Receitas  -------------             **\n");
	printf("**           -----------------------------------------------             **\n");
	printf("**                                                                       **\n");
	printf("           Nome da Receita: ");
	scanf("%[A-ZÁÉÍÓÚÂÊÔÇÀÃÕ a-záéíóúâêôçàãõ,.;0-9]", nome);
	getchar();
	system("cls");
	printf("\n");
	printf("***************************************************************************\n");
	printf("           Ingredientes: \n");
	printf("           Digite a Quantidade de Ingredientes diferentes na Receita: ");
	scanf("%d",&quant);
	getchar();
	for ( cont = 1; cont <= quant; cont++)
	{
		printf("           Ingrediente e tipo(kg,litro,g,unidade): \n");
		printf("           (Exemplo:carne de sol,kg):");
		scanf("%[A-ZÁÉÍÓÚÂÊÔÇÀÃÕ a-záéíóúâêôçàãõ.,;0-9]",&ingredientes[cont]);
		getchar();
		printf("           Quantidade(So Numero): ");
		scanf("%d", &quantidade[cont]);
		getchar();
	}
	system("cls");
	printf("\n");
	printf("***************************************************************************\n");
    printf("           Modo de Preparo: ");
	scanf("%[A-ZÁÉÍÓÚÂÊÔÇÀÃÕ a-záéíóúâêôçàãõ.,;]", preparo);
	getchar();
	system("cls");
	printf("\n");
	printf("***************************************************************************\n");
	printf("           Origem da Receita(Pais ou Regiao): ");
	scanf("%[A-ZÁÉÍÓÚÂÊÔÇÀÃÕ a-záéíóúâêôçàãõ.;,0-9]",origem);
	getchar();
	system("cls");
	printf("\n");
	printf("***************************************************************************\n");
	printf("           Local de Obtencao da Receita(Site,Livro,Revista): ");
	scanf("%[A-ZÁÉÍÓÚÂÊÔÇÀÃÕ a-záéíóúâêôçàãõ.;,0-9]",obtencao);
	getchar();
	printf("\n");
	printf("***************************************************************************\n");
    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
	getchar();
	system("cls");
	printf("\n");
	printf("Nome da Receita : %s",&nome);
	printf("\n");
	printf("Modo de Preparo :\n%s",&preparo);
	printf("\n");
	printf("Origem : %s",&origem);
	printf("\n");
	printf("Local de Obtencao : %s",&obtencao);
	printf("\n");
}


void encontrarReceitas(void) {
    system("cls");
	printf("\n");
	printf("***************************************************************************\n");
	printf("**                                                                       **\n");
	printf("**           -----------------------------------------------             **\n");
	printf("**           ------------ Encontrar Receita por ------------             **\n");
	printf("**           -----------------------------------------------             **\n");
	printf("**                                                                       **\n");
	printf("**           1. Nome:                                                    **\n");
	printf("**           2. Ingrediente:                                             **\n");
    printf("**           3. Origem:                                                  **\n");
	printf("**           0. Voltar                                                   **\n");
	printf("**                                                                       **\n");
	printf("**                                                                       **\n");
	printf("***************************************************************************\n");
	printf("\n");
    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
	getchar();
}

void atualizarReceitas(void) {
    system("cls");
	printf("\n");
	printf("***************************************************************************\n");
	printf("**                                                                       **\n");
	printf("**           -----------------------------------------------             **\n");
	printf("**           -------------- Atualizar Receita --------------             **\n");
	printf("**           -----------------------------------------------             **\n");
	printf("**                                                                       **\n");
	printf("**           Nome da Receita para Atualizar:                             **\n");
	printf("**                                                                       **\n");
	printf("**                                                                       **\n");
	printf("**                                                                       **\n");
	printf("***************************************************************************\n");
	printf("\n");
    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
	getchar();
}

void deletarReceitas(void) {
    system("cls");
	printf("\n");
	printf("***************************************************************************\n");
	printf("**                                                                       **\n");
	printf("**           -----------------------------------------------             **\n");
	printf("**           -------------- Deletar Receita ----------------             **\n");
	printf("**           -----------------------------------------------             **\n");
	printf("**                                                                       **\n");
	printf("**           Nome da Receita para Deletar:                               **\n");
	printf("**                                                                       **\n");
	printf("***************************************************************************\n");
	printf("\n");
    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
	getchar();
}

void verReceitas(void) {
    system("cls");
	printf("\n");
	printf("***************************************************************************\n");
	printf("**                                                                       **\n");
	printf("**           -----------------------------------------------             **\n");
	printf("**           --------------   Ver Receitas  ----------------             **\n");
	printf("**           -----------------------------------------------             **\n");
	printf("**                                                                       **\n");
	printf("**           |Nome da Receita|                                           **\n");
	printf("**                                                                       **\n");
	printf("**                                                                       **\n");
	printf("***************************************************************************\n");
	printf("\n");
    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
	getchar();
}
