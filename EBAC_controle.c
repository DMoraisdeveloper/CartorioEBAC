#include <stdio.h> //biblioteca de comunica��o com o usu�rio
#include <stdlib.h> //biblioteca de aloca��o de espa�o para mem�ria
#include <locale.h> //biblioteca de aloca��o de texto por regi�o
#include <string.h> //biblioteca respons�vel por cuidar das strings

int registro() // Fun��o respons�vel por cadastrar os usu�rios no sistema
{
	// inicio cria��o de vari�veis/strings
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	
	printf("Digite o CPF a ser cadastrado: "); //coletando infirma��o de usu�rio
	scanf("%s", cpf); //salvando o valor digitado na vari�rio %s refere-se a string
	
	strcpy(arquivo, cpf); //Respons�vel por copiar os valores das strings
	
	FILE *file; // criar o arquivo
	file = fopen(arquivo, "w"); // criar o arquivo - W siginifica escrever
	fprintf(file,cpf); //salva o vaor da vari�vel
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
		printf("N�o foi poss�vel localizar. CPF n�o cadastrado! \n");
	}
	
	while(fgets(conteudo, 200, file) != NULL)
	{
		printf("\n Essas s�o as informa��es do usu�rio: \n");
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
		printf("O usu�rio n�o se encontra no sistema! \n");
		system("pause");
		
	}
	
	
}

int main()
{
	int opcao=0;
	int laco=1;
	
	for(laco=1;laco=1;)
	{
		system("cls"); //respons�vel por deletar a tela
		setlocale(LC_ALL, "Portuguese"); //defini��o de linguagem
	
		printf("### Cart�rio da EBAC ###\n\n");//inicio menu
	
		printf("Escolha a op��o desejada no menu: \n\n");
		printf("\t1 - Registrar nomes\n"); // "\t" dar� espa�o _ par�grafos
		printf("\t2 - Consultar nomes\n");
		printf("\t3 - Deletar nomes\n\n\n"); 
		printf("Op��o desejada: ");
		scanf( "%d", &opcao);//amrmazeamento da escolha do usu�rio
	
		system("cls"); // respons�vel por deletar a tela - limpar
	
		switch(opcao) //sele��o de op��es
		{
			case 1:
			registro(); //chamada de fun��es
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
		} //fim de sele��o
	
}
}
