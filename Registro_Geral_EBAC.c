#include <stdio.h> //biblioteca de comunica��o com o usu�rio
#include <stdlib.h> //biblioteca de aloca��o de espa�o em mem�ria // Permite criar e manipular arquivos no computador
#include <locale.h> //biblioteca de aloca��es de texto por regi�o
#include <string.h> //biblioteca respons�vel por cuidar das strings

int cadastro() // Fun��o respons�vel por cadastrar os colaboradores no sistema
{
	//In�cio da cria��o das vari�veis/strings
	char arquivo[40]; 
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40]; 
	//Fim da cria��o das vari�veis

	printf("\n\nVoc� escolheu Cadastro de Colaborador(a). Vamos l�!\n\n"); //Mensagem de confirma��o da op��o escolhida no menu
	printf("Digite o CPF: "); //Pede para o usu�rio digitar o CPF do colaborador
	scanf("%s", cpf); // Armazena a string referente ao cpf (OBS: "%s" refere-se � string)
	
	strcpy(arquivo, cpf); //Copia o valor da string cpf na string arquivo
	
	FILE *file; //Cria/procura um arquivo no banco de dados
	file = fopen (arquivo, "w"); //Cria e abre o arquivo (OBS: "w" significa escrever (write))
	fprintf(file, "\tCPF: ");
	fprintf(file, cpf); //Salva o valor da vari�vel cpf no arquivo
	fprintf(file, "\n"); 
	fclose(file); //Fecha o arquivo
	
	printf("Digite o nome: "); //Pede para o usu�rio digitar o nome do colaborador 
	scanf("%s", nome); //Armazena a string referente ao nome
	
	file = fopen(arquivo, "a"); //Abre e atualiza o arquivo (OBS: "a" signifca atualizar)
	fprintf(file, "\tNOME: ");
	fprintf(file, nome); //Salva o valor da vari�vel nome no arquivo
	fprintf(file, "\n");
	fclose(file); //Fecha o arquivo
	
	printf("Digite o sobrenome: "); //Pede pro usu�rio digitar o sobrenome do colaborador
	scanf("%s", sobrenome); //Armazena a string referente ao sobrenome

	file = fopen(arquivo, "a"); //Abre e atualiza o arquivo 
	fprintf(file, "\tSOBRENOME: ");
	fprintf(file, sobrenome); //Salva o valor da vari�vel sobrenome no arquivo
	fprintf(file, "\n");
	fclose(file); //Fecha o arquivo

	printf("Digite o cargo: "); //Pede pro usu�rio digitar o cargo do colaborador
	scanf("%s", cargo); //Armazena a string referente ao cargo
	
	file = fopen(arquivo, "a"); //Abre e atualiza o arquivo 
	fprintf(file, "\tCARGO: ");
	fprintf(file, cargo); //Salva o valor da vari�vel cargo no arquivo
	fprintf(file, "\n");
	
	fclose(file); //Fecha o arquivo
	
	system("pause");	
}

int consulta() // Fun��o respons�vel por consultar colaboradores no sistema a partir do CPF
{
	//In�cio da cria��o das vari�veis/strings
	char cpf[40];
	char conteudo[200];
	//Fim da cria��o das vari�veis/strings
	
	printf("\n\nVoc� escolheu Consulta de Colaborador(a). Vamos l�!\n\n"); //Mensagem de confirma��o da op��o escolhida no menu
	printf("Digite o CPF a ser consultado: "); //Pede para o usu�rio digitar o CPF do colaborador a ser consultado
	scanf("%s", cpf); // Armazena a string referente ao cpf

	system("cls"); //Limpa a tela
	
	FILE *file; //Procura um arquivo na biblioteca
	file = fopen(cpf,"r"); //Abre e l� o arquivo (OBS: "r" refere-se a ler (read))
		
	if(file == NULL) //Fun��o respons�vel por definir a mensagem de retorno � busca do usu�rio
	{
		printf("\n\nHmm... Esse registro n�o foi localizado. Por favor, confira o CPF.\n\n"); //Mensagem de retorno quando o CPF n�o consta no sistema
	}
	else
	{
		printf("\n\nOba! Registro encontrado. Aqui est�o as informa��es:\n\n\n"); //Mensagem de retorno quando o CPF est� cadastrado no sistema
	}
			
	while (fgets(conteudo, 200, file) != NULL) //Fun��o respons�vel por acessar as informa��es do colaborador pesquisado 
	{
		printf("%s", conteudo); //Mostra as informa��es do colaborador pesquisado ao usu�rio
		printf("\n\n"); 
	}

	fclose(file); //Fecha o arquivo
	
	system("pause");
}

int exclusao() // Fun��o respons�vel por excluir cadastro de colaborador no sistema
{
	//In�cio da cria��o de vari�vel/string
	char cpf[40];
	// Fim da cria��o de vari�vel
	
	printf("\n\nVoc� escolheu Exclus�o de Colaborador(a). Vamos l�!\n\n"); //Mensagem de confirma��o da op��o escolhida no menu
	printf("Digite o CPF do registro a ser exclu�do: "); //Pede para o usu�rio digitar CPF do colaborador a ser exclu�do 
	scanf("%s",cpf); //Armazena a string referente ao CPF
	
	if (remove(cpf) == 0) //Fun��o respons�vel por excluir cadastro do colaborador
	{
		printf("\n\nRegistro exclu�do com sucesso!\n\n"); //Mensagem de confirma��o da exclus�o do colaborador
		system("pause");
	}
	else 
	{
		printf("\n\nRegistro n�o encontrado. Por favor, confira o CPF.\n\n"); //Mensagem de retorno quando o CPF n�o consta no sistema
		system("pause");
	}
	return 0; //Fim da fun��o respons�vel por excluir colaborador cadastrado
}		
		
int main () //Fun��o principal
{
	//In�cio da defini��o de vari�veis
	int opcao=0; 
	int laco=1;
	//Fim da defini��o de vari�veis
	
	for(laco=1;laco=1;) //Respons�vel por fazer o sistema retornar ao in�cio do menu quantas vezes o usu�rio desejar 
	{
		system("cls"); //Limpa a tela
		
		setlocale(LC_ALL, "Portuguese"); //Define o idioma
	
		//In�cio do menu
		printf("### Registro de Colaboradores da EBAC ###\n\n"); 
		printf("O que voc� deseja fazer? \n\n");
		printf("\t1-Cadastrar um(a) colaborador(a)\n");
		printf("\t2-Consultar um(a) colaborador(a)\n");
		printf("\t3-Excluir um(a) colaborador(a)\n");
		printf("\t4-Sair do sistema\n\n");  
		printf("Op��o desejada: "); 
		//Fim do menu
		
		scanf("%d", &opcao); //Armazena a escolha do usu�rio (OBS: "%d" refere-se � vari�vel do tipo inteiro e o & especifica em qual vari�vel armazenar)
		
		system("cls"); //Respons�vel por limpar a tela
		
		switch(opcao) //Fun��o respons�vel por chamar a fun��o relativa � op��o do menu selecionada pelo usu�rio
		{
			case 1: 
			cadastro(); //Chamada da fun��o "registro"
			break;
			
			case 2:
			consulta(); //Chamada da fun��o "consulta"
			break;
			
			case 3:
			exclusao(); //Chamada da fun��o "exclus�o"
			break;
			
			case 4:
			printf("\n\nVoc� saiu do sistema. At� a pr�xima!\n\n");
			return 0;
			break;
			
			default:
			printf("\n\nPoxa, esta op��o est� indispon�vel. Por favor, tente novamente.\n\n"); //Mensagem ao usu�rio quando a op��o digitada n�o consta no sistema
			system("pause");
			break;
		} //Fim da sele��o
	}	
}

