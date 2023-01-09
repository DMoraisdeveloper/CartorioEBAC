#include <stdio.h> //biblioteca de comunicação com o usuário
#include <stdlib.h> //biblioteca de alocação de espaço para memória
#include <locale.h> //biblioteca de alocação de texto por região
#include <string.h> //biblioteca responsável por cuidar das strings

int registro() // Função responsável por cadastrar os usuários no sistema
{
	// inicio criação de variáveis/strings
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	
	printf("Digite o CPF a ser cadastrado: "); //coletando infirmação de usuário
	scanf("%s", cpf); //salvando o valor digitado na variário %s refere-se a string
	
	strcpy(arquivo, cpf); //Responsável por copiar os valores das strings
	
	FILE *file; // criar o arquivo
	file = fopen(arquivo, "w"); // criar o arquivo - W siginifica escrever
	fprintf(file,cpf); //salva o vaor da variável
	fclose(file); // fecha o arquivo
	
	file = fopen(arquivo, "a");
	fprintf(file,",");
	fclose(file);
	
	printf("Digite um nome a ser cadastrado: ");
	scanf("%s",nome);
	
	file = fopen(arquivo, "a");
	fprintf(file,nome);
	fclose(file);

	file = fopen(arquivo, "a");
	fprintf(file,",");
	fclose(file);
	
	printf("Digite o sobrenome a ser cadastrado: ");
	scanf("%s", sobrenome);
	file = fopen(arquivo, "a");
	fprintf(file,sobrenome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file,",");
	fclose(file);
	
	
	printf("Digite o cargo a ser armazenado: ");
	scanf("%s", cargo);
	file = fopen(arquivo, "a");
	fprintf(file,cargo);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file,",");
	fclose(file);
	
	
}
int consulta()
{
	setlocale(LC_ALL, "Portuguese");
	
	char cpf[40];
	char conteudo[200];
	
	printf("Digite o CPF a ser consultado: ");
	scanf("%s", cpf);
	
	FILE *file;
	file = fopen(cpf, "r"); //
	
	if(file == NULL)
	{
		printf("Não foi possível localizar. CPF não cadastrado! \n");
	}
	
	while(fgets(conteudo, 200, file) != NULL)
	{
		printf("\n Essas são as informações do usuário: \n");
		printf("%s", conteudo);
		printf("\n\n");
	}
	
	system("pause");
	
	
	
}
int deletar()
{
	char cpf[40];
	
	printf("Qual CPF a ser deletado: ");
	scanf("%s",cpf);
	
	remove(cpf);
	
	FILE *file;
	file = fopen(cpf,"r");
	if(file == NULL)
	{
		printf("O usuário não se encontra no sistema! \n");
		system("pause");
		
	}
	
	
}

int main()
{
	int opcao=0;
	int laco=1;
	
	for(laco=1;laco=1;)
	{
		system("cls"); //responsável por deletar a tela
		setlocale(LC_ALL, "Portuguese"); //definição de linguagem
	
		printf("### Cartório da EBAC ###\n\n");//inicio menu
	
		printf("Escolha a opção desejada no menu: \n\n");
		printf("\t1 - Registrar nomes\n"); // "\t" dará espaço _ parágrafos
		printf("\t2 - Consultar nomes\n");
		printf("\t3 - Deletar nomes\n\n\n"); 
		printf("Opção desejada: ");
		scanf( "%d", &opcao);//amrmazeamento da escolha do usuário
	
		system("cls"); // responsável por deletar a tela - limpar
	
		switch(opcao) //seleção de opções
		{
			case 1:
			registro(); //chamada de funções
			break;
			
			case 2:	
			consulta();
			break;
			
			case 3:
			deletar();
			break;
			
			default:
			printf("valor invalido!\n");
			system("pause");
			break;
		} //fim de seleção
	
}
}
