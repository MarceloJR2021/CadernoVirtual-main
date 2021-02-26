

char menuEstoque(void) {
	char op;
    system("cls");
	printf("\n");
	printf("***************************************************************************\n");
	printf("**                                                                       **\n");
	printf("**           -----------------------------------------------             **\n");
	printf("**           ---------------  Menu Estoque   ---------------             **\n");
	printf("**           -----------------------------------------------             **\n");
	printf("**                                                                       **\n");
	printf("**           1. Adicionar Estoque                                        **\n");
	printf("**           2. Remover Estoque                                          **\n");
	printf("**           3. Ver Estoque                                              **\n");
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

void adicionarEstoque(void) {
	char item[20];
	int quant;
	float valor;

    system("cls");
	printf("\n");
	printf("***************************************************************************\n");
	printf("**                                                                       **\n");
	printf("**           -----------------------------------------------             **\n");
	printf("**           ------------- Adicionar Estoque ---------------             **\n");
	printf("**           -----------------------------------------------             **\n");
	printf("**                                                                       **\n");
	printf("             Item:  ");
	scanf("%[A-ZÁÉÍÓÚÂÊÔÇÀÃÕ a-záéíóúâêôçàãõ,.;0-9]", item);
	getchar();
	printf("             Quantidade:   ");
	scanf("%d",&quant);
	getchar();
	printf("             Valor Gasto R$(00.00):    ");
	scanf("%f",&valor);
	getchar();
	printf("**                                                                       **\n");	
	printf("***************************************************************************\n");
	printf("\n");
    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
	getchar();
}

void removerEstoque(void) {
    system("cls");
	printf("\n");
	printf("***************************************************************************\n");
	printf("**                                                                       **\n");
	printf("**           -----------------------------------------------             **\n");
	printf("**           -------------- Remover Estoque ----------------             **\n");
	printf("**           -----------------------------------------------             **\n");
	printf("**                                                                       **\n");
	printf("**           Item:                                                       **\n");
	printf("**           Quantidade:                                                 **\n");
	printf("**                                                                       **\n");
	printf("***************************************************************************\n");
	printf("\n");
    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
	getchar();
}

void verEstoque(void) {
    system("cls");
	printf("\n");
	printf("***************************************************************************\n");
	printf("**                                                                       **\n");
	printf("**           -----------------------------------------------             **\n");
	printf("**           ---------------   Ver Estoque  ----------------             **\n");
	printf("**           -----------------------------------------------             **\n");
	printf("**                                                                       **\n");
	printf("**             Nome              |            Quantidade                 **\n");
	printf("**                               |                                       **\n");
	printf("**                               |                                       **\n");
	printf("**                               |                                       **\n");
	printf("**                               |                                       **\n");
	printf("**                               |                                       **\n");
	printf("**                               |                                       **\n");
	printf("**                               |                                       **\n");
	printf("**                               |                                       **\n");
	printf("**                               |                                       **\n");
	printf("**                                                                       **\n");			
	printf("***************************************************************************\n");
	printf("\n");
    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
	getchar();
}
