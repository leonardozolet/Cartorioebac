#include <stdio.h> //biblioteca de comunicação com o usuário
#include <stdlib.h> //biblioteca de alocação de espaço em memória
#include <locale.h> //biblioteca de alocação de texto por região
#include <string.h> //biblioteca responsável por cuidar das string
		
int registro()//função responsável por cadastrar os usuários no sistema
{
	//início criação de variáveis / string
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//fim da criação de variáveis
	
	printf("Digite o CPF a ser cadastrado: ");//coletando informação do usuário
	scanf("%s", cpf);////%s refere-se ao armazenamento das strings
	
	strcpy(arquivo, cpf); //Responsável por copiar os valores das string
	
	FILE *file; // cria o arquivo
	file = fopen(arquivo, "w"); // cria o arquivo e o "w" escreve
	fprintf(file,cpf); // salvo o valor da variável
	fclose(file); // fecha o arquivo
	
	file = fopen(arquivo, "a");//cria o arquivo e o "a" atualiza o mesmo
	fprintf(file,",");//salvo o valor da variável
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

int consulta()//função de consulta de usuários
{
	setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem
	
	//início das variáveis
	char cpf[40];//cpf do usuário cadastrado
	char conteudo[200];//conteúdo do cadastro
	//encerramento das variáveis
	
	printf("Digite o cpf a ser consultado: ");//mensagem de consulta ao cliente
	scanf("%s",cpf);
	
	FILE *file;//cria um arquivo
	file = fopen(cpf,"r");//lê o aquivo do cpf com o "r"
	
	if(file == NULL)//caso o arquivo não seja encontrado
	{
		printf("Não foi possível abrir o arquivo, não localizado!.\n");//informa ao cliente
	}
	
	while(fgets(conteudo, 200, file) != NULL)//caso o usuário seja encontrado
	{
		printf("\nEssas são as informações do usuário: ");//menssagens ao cliente
		printf("%s", conteudo);//mostra as informações do arquivo selecionado
		printf("\n\n");
	}
	
	system("pause");//mantém a tela
	
}

int deletar()//função deletar usuários
{
	char cpf[40];//variavél única, cpf do usuário
	
	printf("Digite o CPF do usuário a ser deletado: ");//pedindo as informações de usuário ao cliente
	scanf("%s",cpf);
	
	remove(cpf);//remoção do usuário
	
	FILE *file;//buscando o aruivo de usuário
	file = fopen(cpf,"r");//abrindo o arquivo
	
	if(file == NULL)//se os dados digitados não forem encontrados
	{
		printf("Ususário não encontrado!\n\n");//informando o usuário
		system("pause");
	}
	
	else//caso o usuário seja encontrado
	{
		remove(cpf);//remoção do usuário do banco de dados
		printf("\nUsuário deletado com sucesso!\n\n");//informando o cliente
		system("pause");
	
	}
}


	
int main()
	{
	int opcao=0; //Definindo variáveis
	int laco=1;
	
	for(laco=1;laco=1;)
	{

		system("cls");//responsável por limpar a tela

		setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem
			
		printf("### Cartório de seleção ###\n\n"); //inicio do menu
		printf("Escolha a opção desejada do menu\n\n");
		printf("\t1 - Registrar nomes\n");
		printf("\t2 - Consultar nomes\n");
		printf("\t3 - Deletar nomes\n"); 
		printf("\t4 - Sair do sistema.\n\n");
		printf("Opção: ");//fim do menu
				
		scanf("%d", &opcao); //armazenando a escolha do usuário
		
		system("cls");//responsável por limpar a tela
	
		switch(opcao) //inicio da seleção do menu
		{
			case 1:
			registro();//chamada de funções
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
			printf("Essa opção não está disponivel!\n");
			system("pause");
			break;
		} //fim da seleção
			
	}	
}
