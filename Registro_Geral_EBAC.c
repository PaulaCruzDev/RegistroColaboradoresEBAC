#include <stdio.h> //biblioteca de comunicação com o usuário
#include <stdlib.h> //biblioteca de alocação de espaço em memória // Permite criar e manipular arquivos no computador
#include <locale.h> //biblioteca de alocações de texto por região
#include <string.h> //biblioteca responsável por cuidar das strings

int cadastro() // Função responsável por cadastrar os colaboradores no sistema
{
	//Início da criação das variáveis/strings
	char arquivo[40]; 
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40]; 
	//Fim da criação das variáveis

	printf("\n\nVocê escolheu Cadastro de Colaborador(a). Vamos lá!\n\n"); //Mensagem de confirmação da opção escolhida no menu
	printf("Digite o CPF: "); //Pede para o usuário digitar o CPF do colaborador
	scanf("%s", cpf); // Armazena a string referente ao cpf (OBS: "%s" refere-se à string)
	
	strcpy(arquivo, cpf); //Copia o valor da string cpf na string arquivo
	
	FILE *file; //Cria/procura um arquivo no banco de dados
	file = fopen (arquivo, "w"); //Cria e abre o arquivo (OBS: "w" significa escrever (write))
	fprintf(file, "\tCPF: ");
	fprintf(file, cpf); //Salva o valor da variável cpf no arquivo
	fprintf(file, "\n"); 
	fclose(file); //Fecha o arquivo
	
	printf("Digite o nome: "); //Pede para o usuário digitar o nome do colaborador 
	scanf("%s", nome); //Armazena a string referente ao nome
	
	file = fopen(arquivo, "a"); //Abre e atualiza o arquivo (OBS: "a" signifca atualizar)
	fprintf(file, "\tNOME: ");
	fprintf(file, nome); //Salva o valor da variável nome no arquivo
	fprintf(file, "\n");
	fclose(file); //Fecha o arquivo
	
	printf("Digite o sobrenome: "); //Pede pro usuário digitar o sobrenome do colaborador
	scanf("%s", sobrenome); //Armazena a string referente ao sobrenome

	file = fopen(arquivo, "a"); //Abre e atualiza o arquivo 
	fprintf(file, "\tSOBRENOME: ");
	fprintf(file, sobrenome); //Salva o valor da variável sobrenome no arquivo
	fprintf(file, "\n");
	fclose(file); //Fecha o arquivo

	printf("Digite o cargo: "); //Pede pro usuário digitar o cargo do colaborador
	scanf("%s", cargo); //Armazena a string referente ao cargo
	
	file = fopen(arquivo, "a"); //Abre e atualiza o arquivo 
	fprintf(file, "\tCARGO: ");
	fprintf(file, cargo); //Salva o valor da variável cargo no arquivo
	fprintf(file, "\n");
	
	fclose(file); //Fecha o arquivo
	
	system("pause");	
}

int consulta() // Função responsável por consultar colaboradores no sistema a partir do CPF
{
	//Início da criação das variáveis/strings
	char cpf[40];
	char conteudo[200];
	//Fim da criação das variáveis/strings
	
	printf("\n\nVocê escolheu Consulta de Colaborador(a). Vamos lá!\n\n"); //Mensagem de confirmação da opção escolhida no menu
	printf("Digite o CPF a ser consultado: "); //Pede para o usuário digitar o CPF do colaborador a ser consultado
	scanf("%s", cpf); // Armazena a string referente ao cpf

	system("cls"); //Limpa a tela
	
	FILE *file; //Procura um arquivo na biblioteca
	file = fopen(cpf,"r"); //Abre e lê o arquivo (OBS: "r" refere-se a ler (read))
		
	if(file == NULL) //Função responsável por definir a mensagem de retorno à busca do usuário
	{
		printf("\n\nHmm... Esse registro não foi localizado. Por favor, confira o CPF.\n\n"); //Mensagem de retorno quando o CPF não consta no sistema
	}
	else
	{
		printf("\n\nOba! Registro encontrado. Aqui estão as informações:\n\n\n"); //Mensagem de retorno quando o CPF está cadastrado no sistema
	}
			
	while (fgets(conteudo, 200, file) != NULL) //Função responsável por acessar as informações do colaborador pesquisado 
	{
		printf("%s", conteudo); //Mostra as informações do colaborador pesquisado ao usuário
		printf("\n\n"); 
	}

	fclose(file); //Fecha o arquivo
	
	system("pause");
}

int exclusao() // Função responsável por excluir cadastro de colaborador no sistema
{
	//Início da criação de variável/string
	char cpf[40];
	// Fim da criação de variável
	
	printf("\n\nVocê escolheu Exclusão de Colaborador(a). Vamos lá!\n\n"); //Mensagem de confirmação da opção escolhida no menu
	printf("Digite o CPF do registro a ser excluído: "); //Pede para o usuário digitar CPF do colaborador a ser excluído 
	scanf("%s",cpf); //Armazena a string referente ao CPF
	
	if (remove(cpf) == 0) //Função responsável por excluir cadastro do colaborador
	{
		printf("\n\nRegistro excluído com sucesso!\n\n"); //Mensagem de confirmação da exclusão do colaborador
		system("pause");
	}
	else 
	{
		printf("\n\nRegistro não encontrado. Por favor, confira o CPF.\n\n"); //Mensagem de retorno quando o CPF não consta no sistema
		system("pause");
	}
	return 0; //Fim da função responsável por excluir colaborador cadastrado
}		
		
int main () //Função principal
{
	//Início da definição de variáveis
	int opcao=0; 
	int laco=1;
	//Fim da definição de variáveis
	
	for(laco=1;laco=1;) //Responsável por fazer o sistema retornar ao início do menu quantas vezes o usuário desejar 
	{
		system("cls"); //Limpa a tela
		
		setlocale(LC_ALL, "Portuguese"); //Define o idioma
	
		//Início do menu
		printf("### Registro de Colaboradores da EBAC ###\n\n"); 
		printf("O que você deseja fazer? \n\n");
		printf("\t1-Cadastrar um(a) colaborador(a)\n");
		printf("\t2-Consultar um(a) colaborador(a)\n");
		printf("\t3-Excluir um(a) colaborador(a)\n");
		printf("\t4-Sair do sistema\n\n");  
		printf("Opção desejada: "); 
		//Fim do menu
		
		scanf("%d", &opcao); //Armazena a escolha do usuário (OBS: "%d" refere-se à variável do tipo inteiro e o & especifica em qual variável armazenar)
		
		system("cls"); //Responsável por limpar a tela
		
		switch(opcao) //Função responsável por chamar a função relativa à opção do menu selecionada pelo usuário
		{
			case 1: 
			cadastro(); //Chamada da função "registro"
			break;
			
			case 2:
			consulta(); //Chamada da função "consulta"
			break;
			
			case 3:
			exclusao(); //Chamada da função "exclusão"
			break;
			
			case 4:
			printf("\n\nVocê saiu do sistema. Até a próxima!\n\n");
			return 0;
			break;
			
			default:
			printf("\n\nPoxa, esta opção está indisponível. Por favor, tente novamente.\n\n"); //Mensagem ao usuário quando a opção digitada não consta no sistema
			system("pause");
			break;
		} //Fim da seleção
	}	
}

