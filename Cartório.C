#include <stdio.h> //biblioteca de comunica��o com o usu�rio
#include <stdlib.h> //biblioteca de aloca��o de espea�o de mem�ria
#include <locale.h> //biblioteca de aloca��es de texto por regi�o
#include <string.h> //biblioteac responsavel por cuidar das strings


int registro()//Fun��o respons�vel por cadastrar os usu�rios no sistema.
{
	setlocale(LC_ALL, "Portuguese");//definindo a linguagem
	
	//Inicio da cria��o de Vari�veis/String.
	char arquivo[40];
	char cpf[40];
	char nome [40];
	char sobrenome[40];
	char cargo[40];
	char opcao[40];
	//Final da cria��o de Vari�veis/String
	
	printf("Digite o CPF a ser cadastrado: "); //Coletando informa��o do usu�rio.
	scanf("%s",cpf);//"%s" refere-se a string
	
	strcpy(arquivo, cpf); //Responsavel por copiar os valores das strings
		
	FILE * file;//cria o arquivo 	
	file = fopen(arquivo, "w");//cria o arquivo e o "w" significa escrever.
	fprintf(file,cpf);//salvo o valor da variavel
	fclose(file);//fecha o arquivo
	
	file = fopen(arquivo, "a");
	fprintf(file, ",");
	fclose(file);
	
	printf("Digite o Nome a ser cadastrado: ");
	scanf("%s",nome);
	
	file = fopen(arquivo, "a");
	fprintf(file,nome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file, ",");
	fclose(file);
	
	printf("Digite o Sobrenome a ser cadastrado: ");
	scanf("%s",sobrenome);
	
	file = fopen(arquivo, "a");
	fprintf(file, sobrenome);
	fclose(file);
		
	file = fopen(arquivo, "a");
	fprintf(file, ",");
	fclose(file);
	
	printf("Digite o Cargo a ser cadastrado:");
	scanf("%s",cargo);
	
	file = fopen(arquivo, "a");
	fprintf(file,cargo);
	fclose(file);
	
	printf("\n");
	
	system("pause");
	
	printf("\nDeseja cadastrar outro usu�rio?:\n\n[sim]\t[nao]:");
    scanf("%s", opcao);

    if (strcmp(opcao, "nao") == 0)
    {
        return 0; // Retorna ao menu
    }
	if(strcmp(opcao, "sim") == 0)	
	{
		system("cls");
		registro();
	}
	
}

int consulta()
{
	setlocale(LC_ALL, "Portuguese");//definindo a linguagem
	
	//Inicio da cria��o de Vari�veis/String.
	char cpf[40];
	char conteudo[200];
	char opcao[40];
	//Final da cria��o de Vari�veis/String
	
	printf("Digite o CPF a ser consultado: ");//Coletando informa��o do usu�rio.
	scanf("%s",cpf);
	
	FILE *file;
	file = fopen(cpf,"r");
	
	if(file == NULL)
	{
		printf("\nN�o foi poss�vel abrir o arquivo, este CPF n�o foi localizado.\n\n");
	}
	
	while(fgets(conteudo, 200, file) != NULL)
	{
		printf("\nEssas s�o as informa��es do usu�rio: ");
		printf("%s", conteudo);
		printf("\n\n");
	}
	system("pause");
	fclose(file);
	
	printf("\nDeseja consultar outro usu�rio?:\n\n[sim]\t[nao]:");
    scanf("%s", opcao);
	
	if (strcmp(opcao, "nao") == 0)
    {
        return 0; // Retorna ao menu
    }
	if(strcmp(opcao, "sim") == 0)	
	{
		system("cls");
		consulta();
	}
}

int deletar()
{
	setlocale(LC_ALL, "Portuguese");//definindo a linguagem
	
	//Inicio da cria��o de Vari�veis/String
	char cpf[40];
	char opcao[40];
	//Final da cria��o de Vari�veis/String
	
	printf("Digite o CPF a ser deletado: ");//Coletando informa��o do usu�rio.
	scanf("%s",cpf);
	printf("\n");
	
	FILE *file;
	file = fopen(cpf,"r");
	
	if(file == NULL)
	{
		printf("CPF do usu�rio n�o encontrado no sistema!\n\n");
		system("pause");
	}
	else
	{
		fclose(file);//Fechando o arquivo, pois ele existe
		remove(cpf);//Deletando o arquivo do CPF
		printf("\nO CPF solicitado foi deletado!\n");
		system("pause");
	}
	
	printf("\nDeseja deletar outro usu�rio?:\n\n[sim]\t[nao]:");
    scanf("%s", opcao);

    if (strcmp(opcao, "nao") == 0)
    {
        return 0; // Retorna ao menu
    }
	if(strcmp(opcao, "sim") == 0)	
	{
		system("cls");//limpeza da tela
		deletar();//volta ao inicio da fun��o
	}
}

int main()
{

	int opcao=0;//definindo as variaveis
	int laco=1;
	char senhadigitada[20]="a";
	
	printf("### Cart�rio da EBAC ###\n\n");
	printf("Login de Administrador\n\nDigite a sua senha ou digite encerrar para fechar o sistema:");
	scanf("%s", senhadigitada);
	
	if(strcmp(senhadigitada,"encerrar") == 0)
	{
		printf("Obrigado por utilizar o sistema!");
		return 0;
	}
		
	if(strcmp(senhadigitada, "adminzk") == 0)
	{

		for(laco=1;laco=1;)//Definindo la�o de repeti��o
		{
		
			system("cls");//Respons�vel por limpar a tela
	
			setlocale(LC_ALL, "Portuguese");//definindo a linguagem
	
			printf("### Cart�rio da EBAC ###\n\n");//Inicio do menu
			printf("Escolha a op��o desejada do menu:\n\n");
			printf("\t1 - Registrar Nomes\n");
			printf("\t2 - Consultar Nomes\n");
			printf("\t3 - Deletar Nomes\n");
			printf("\t4 - Sair do Sistema\n\n");
			printf("Op��o: ");//Final do Menu

			scanf("%d", &opcao);//armazenando a escolha do usuario
	
			system("cls");
		
		
			switch(opcao)//inicio da sele��o do menu
			{
				case 1:
					registro(); //Chamada de fun��es
				break;
			
				case 2:
					consulta(); //Chamada de fun��es
				break;
			
				case 3:
					deletar(); //Chamada de fun��es
				break;
			
				case 4://Encerramento do programa 
					printf("Obrigado por utilizar o sistema!");
					return 0;
					break;
			
				default:
				printf("Esta op��o n�o est� dispon�vel! Digite uma op��o v�lida!\n\n");
				system("pause");
				break;
			
			}//final da sele��o
	
		}
	}	
	else
		printf("\nSenha Incorreta\n");
		system("pause");
		system("cls");
		main();
		
}
