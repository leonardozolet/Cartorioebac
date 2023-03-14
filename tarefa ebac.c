#include <stdio.h> //biblioteca de comunica��o com o usu�rio
#include <stdlib.h> //biblioteca de aloca��o de espa�o em mem�ria
#include <locale.h> //biblioteca de aloca��o de texto por regi�o
#include <string.h> //biblioteca respons�vel por cuidar das string
		
int registro()//fun��o respons�vel por cadastrar os usu�rios no sistema
{
	//in�cio cria��o de vari�veis / string
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//fim da cria��o de vari�veis
	
	printf("Digite o CPF a ser cadastrado: ");//coletando informa��o do usu�rio
	scanf("%s", cpf);////%s refere-se ao armazenamento das strings
	
	strcpy(arquivo, cpf); //Respons�vel por copiar os valores das string
	
	FILE *file; // cria o arquivo
	file = fopen(arquivo, "w"); // cria o arquivo e o "w" escreve
	fprintf(file,cpf); // salvo o valor da vari�vel
	fclose(file); // fecha o arquivo
	
	file = fopen(arquivo, "a");//cria o arquivo e o "a" atualiza o mesmo
	fprintf(file,",");//salvo o valor da vari�vel
	fclose(file);//fecha o arquivo
	
	printf("Digite o nome a ser cadastrado: ");
	scanf("%s",nome);
	
	file = fopen(arquivo, "a");
	fprintf(file,nome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file,",");
	fclose(file);
	
	printf("Digite o sobrenome a ser cadastrado: ");
	scanf("%s",sobrenome);
	
	file = fopen(arquivo, "a");
	fprintf(file,sobrenome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file,",");
	fclose(file);
	
	printf("Digite o cargo a ser cadastrado: ");
	scanf("%s",cargo);
	
	file = fopen(arquivo, "a");
	fprintf(file,cargo);
	fclose(file);	
	
    system("pause");

}

int consulta()//fun��o de consulta de usu�rios
{
	setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem
	
	//in�cio das vari�veis
	char cpf[40];//cpf do usu�rio cadastrado
	char conteudo[200];//conte�do do cadastro
	//encerramento das vari�veis
	
	printf("Digite o cpf a ser consultado: ");//mensagem de consulta ao cliente
	scanf("%s",cpf);
	
	FILE *file;//cria um arquivo
	file = fopen(cpf,"r");//l� o aquivo do cpf com o "r"
	
	if(file == NULL)//caso o arquivo n�o seja encontrado
	{
		printf("N�o foi poss�vel abrir o arquivo, n�o localizado!.\n");//informa ao cliente
	}
	
	while(fgets(conteudo, 200, file) != NULL)//caso o usu�rio seja encontrado
	{
		printf("\nEssas s�o as informa��es do usu�rio: ");//menssagens ao cliente
		printf("%s", conteudo);//mostra as informa��es do arquivo selecionado
		printf("\n\n");
	}
	
	system("pause");//mant�m a tela
	
}

int deletar()//fun��o deletar usu�rios
{
	char cpf[40];//variav�l �nica, cpf do usu�rio
	
	printf("Digite o CPF do usu�rio a ser deletado: ");//pedindo as informa��es de usu�rio ao cliente
	scanf("%s",cpf);
	
	remove(cpf);//remo��o do usu�rio
	
	FILE *file;//buscando o aruivo de usu�rio
	file = fopen(cpf,"r");//abrindo o arquivo
	
	if(file == NULL)//se os dados digitados n�o forem encontrados
	{
		printf("Usus�rio n�o encontrado!\n\n");//informando o usu�rio
		system("pause");
	}
	
	else//caso o usu�rio seja encontrado
	{
		remove(cpf);//remo��o do usu�rio do banco de dados
		printf("\nUsu�rio deletado com sucesso!\n\n");//informando o cliente
		system("pause");
	
	}
}


	
int main()
	{
	int opcao=0; //Definindo vari�veis
	int laco=1;
	
	for(laco=1;laco=1;)
	{

		system("cls");//respons�vel por limpar a tela

		setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem
			
		printf("### Cart�rio de sele��o ###\n\n"); //inicio do menu
		printf("Escolha a op��o desejada do menu\n\n");
		printf("\t1 - Registrar nomes\n");
		printf("\t2 - Consultar nomes\n");
		printf("\t3 - Deletar nomes\n"); 
		printf("\t4 - Sair do sistema.\n\n");
		printf("Op��o: ");//fim do menu
				
		scanf("%d", &opcao); //armazenando a escolha do usu�rio
		
		system("cls");//respons�vel por limpar a tela
	
		switch(opcao) //inicio da sele��o do menu
		{
			case 1:
			registro();//chamada de fun��es
			break;
			
			case 2:
			consulta();
			break;
		
			case 3:
			deletar();
			break;
			
			case 4:
			printf("Obrigado por utilizar o sistema\n");
			return 0;
			break;
		
			default:
			printf("Essa op��o n�o est� disponivel!\n");
			system("pause");
			break;
		} //fim da sele��o
			
	}	
}
