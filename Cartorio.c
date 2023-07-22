#include <stdio.h> // biblioteca de comunica��o com o usu�rio
#include <stdlib.h>  // biblioteca de aloca��o de espa�o
#include <locale.h> // biblioteca de aloca��o de texto por regi�o
#include <string.h> // biblioteca respons�vel por cuidar das strings

int registro()  // Fun��o responsavel por cadastrar os usu�rios no sistema
{
    // Inicio cria��o de vari�veis/string
	char arquivo[40];
	char cpf[40];
    char nome[40];
    char sobrenome[40];
    char cargo[40];
    // Final cria��o de vari�veis/string
   
    printf("Digite o CPF a ser cadastrado: "); // Coleta informa��es do usu�rio
    scanf("%s", cpf);  //%s refere-se o string
    
    strcpy(arquivo, cpf);  //copia o conteudo da string cpf
    
    FILE *file; // cria o arquivo 
    file = fopen(arquivo, "w"); //cria o arquivo e o "w" significa escrever 
    fprintf(file,cpf); // salva o valor da variavel
    fclose(file); //fecha o arquivo
    
    file = fopen(arquivo, "a"); //abre o arquivo
    fprintf(file,",");
    fclose(file);
    
    printf("Digite o nome a ser cadastrado: ");  //coleta o nome do usu�rio
    scanf("%s", nome);
    
    file = fopen(arquivo, "a");
    fprintf(file,nome);
    fclose(file);
    
    file = fopen(arquivo, "a"); //abre o arquivo
    fprintf(file,",");
    fclose(file);

    printf("Digite o sobrenome a ser cadastrado: ");  //coleta o sobrenome do usu�rio
    scanf("%s", sobrenome);
    
    file = fopen(arquivo, "a");
    fprintf(file,sobrenome);
    fclose(file);

    file = fopen(arquivo, "a"); //abre o arquivo em modo adicionar (append)
    fprintf(file,",");
    fclose(file);  //fecha o aquivo
    
    printf("Digite o cargo a ser cadastrado: ");  //coleta o cargo do usu�rio
    scanf("%s", cargo);
    
    file = fopen(arquivo, "a");
    fprintf(file,cargo);
    fclose(file);
    
    system("pause");

	
}

int consulta()
{
    // Inicio cria��o de vari�veis/string
	char cpf[40];
	char conteudo[200];
    // Final cria��o de vari�veis/string
   	
	setlocale(LC_ALL, "Portuguese");
	
	printf("Digite o CPF a ser perguntado: "); // Coleta informa��es do usu�rio
	scanf("%s", cpf); //%s refere-se o string
	
	FILE *file;
	file = fopen(cpf,"r");  //abre o arquivo como leitura "r"
	
	if(file == NULL)  // verifica se o arquivo existe
	{
		printf("N�o foi poss�vel abrir o arquivo, n�o localizado!\n");
	}
	
	while(fgets(conteudo, 200, file) != NULL)  //mostra as informa��es caso exista
	{
		printf("\nEssas s�o as informa��es do usu�rio: ");
		printf("%s", conteudo);
		printf("\n\n");
	}
	
	system("pause");

}

int deletar()
{
	
    // Inicio cria��o de vari�veis/string
   	char cpf[40];
    // Final cria��o de vari�veis/string
   	
	setlocale(LC_ALL, "Portuguese");
	
	printf("Digite o CPF do usu�rio a ser deletado: "); // Coleta informa��es do usu�rio
	scanf("%s", cpf); //%s refere-se o string
	
    remove(cpf);  //remove o arquivo com os dados do usu�rio informado
    
    FILE *file;
    file = fopen(cpf, "r"); //abre o arquivo como leitura "r"
    
    if (file == NULL)  // verifica se o arquivo existe
    {
    	printf("\nO usu�rio n�o se encotra no sistema!!");
    	printf("\n\n");
	}
	system("pause");

		   	    
}


int main()
{
    int opcao = 0;  //Definindo as vari�veis
    int laco = 1;
		
    for (laco=1; laco=1;)
    {

		setlocale(LC_ALL, "Portuguese"); // Definindo a linguagem
		
		system("cls");
	
		printf("### Cart�rio da EBAC ###\n\n");
		printf("Escolha a op��o desejada do menu:\n\n");
		printf("\t1 - Registrar nomes\n");
	    printf("\t2 - Consultar nomes\n");
	    printf("\t3 - Deletar nomes\n\n");

	    
	 
	    printf("Informe a op��o: ");  // armazena a escolha do usu�rio
	    scanf("%d", &opcao);
	    
	    system("cls");  //Limpa a tela antes de apresentar a op��o selecionada
	    
		switch(opcao)  //inicio da sele��o do menu
		{
			case 1:
		   	    registro(); // chamada de fun��es
			    break;
			  
			case 2:		
			    consulta();
		   	    break;
		   	  
		   	case 3:
		   		deletar();
		   	    break;
		   	  
		   	default:
		  	    printf("Essa op��o n�o est� dispon�vel!\n");	
		   	    system("pause");
   			    break;	   		
		   		
		}
		
   }
}

