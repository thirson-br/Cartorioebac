#include <stdio.h> // biblioteca de comunicação com o usuário
#include <stdlib.h>  // biblioteca de alocação de espaço
#include <locale.h> // biblioteca de alocação de texto por região
#include <string.h> // biblioteca responsável por cuidar das strings

int registro()  // Função responsavel por cadastrar os usuários no sistema
{
    // Inicio criação de variáveis/string
	char arquivo[40];
	char cpf[40];
    char nome[40];
    char sobrenome[40];
    char cargo[40];
    // Final criação de variáveis/string
   
    printf("Digite o CPF a ser cadastrado: "); // Coleta informações do usuário
    scanf("%s", cpf);  //%s refere-se o string
    
    strcpy(arquivo, cpf);  //copia o conteudo da string cpf
    
    FILE *file; // cria o arquivo 
    file = fopen(arquivo, "w"); //cria o arquivo e o "w" significa escrever 
    fprintf(file,cpf); // salva o valor da variavel
    fclose(file); //fecha o arquivo
    
    file = fopen(arquivo, "a"); //abre o arquivo
    fprintf(file,",");
    fclose(file);
    
    printf("Digite o nome a ser cadastrado: ");  //coleta o nome do usuário
    scanf("%s", nome);
    
    file = fopen(arquivo, "a");
    fprintf(file,nome);
    fclose(file);
    
    file = fopen(arquivo, "a"); //abre o arquivo
    fprintf(file,",");
    fclose(file);

    printf("Digite o sobrenome a ser cadastrado: ");  //coleta o sobrenome do usuário
    scanf("%s", sobrenome);
    
    file = fopen(arquivo, "a");
    fprintf(file,sobrenome);
    fclose(file);

    file = fopen(arquivo, "a"); //abre o arquivo em modo adicionar (append)
    fprintf(file,",");
    fclose(file);  //fecha o aquivo
    
    printf("Digite o cargo a ser cadastrado: ");  //coleta o cargo do usuário
    scanf("%s", cargo);
    
    file = fopen(arquivo, "a");
    fprintf(file,cargo);
    fclose(file);
    
    system("pause");

	
}

int consulta()
{
    // Inicio criação de variáveis/string
	char cpf[40];
	char conteudo[200];
    // Final criação de variáveis/string
   	
	setlocale(LC_ALL, "Portuguese");
	
	printf("Digite o CPF a ser perguntado: "); // Coleta informações do usuário
	scanf("%s", cpf); //%s refere-se o string
	
	FILE *file;
	file = fopen(cpf,"r");  //abre o arquivo como leitura "r"
	
	if(file == NULL)  // verifica se o arquivo existe
	{
		printf("Não foi possível abrir o arquivo, não localizado!\n");
	}
	
	while(fgets(conteudo, 200, file) != NULL)  //mostra as informações caso exista
	{
		printf("\nEssas são as informações do usuário: ");
		printf("%s", conteudo);
		printf("\n\n");
	}
	
	system("pause");

}

int deletar()
{
	
    // Inicio criação de variáveis/string
   	char cpf[40];
    // Final criação de variáveis/string
   	
	setlocale(LC_ALL, "Portuguese");
	
	printf("Digite o CPF do usuário a ser deletado: "); // Coleta informações do usuário
	scanf("%s", cpf); //%s refere-se o string
	
    remove(cpf);  //remove o arquivo com os dados do usuário informado
    
    FILE *file;
    file = fopen(cpf, "r"); //abre o arquivo como leitura "r"
    
    if (file == NULL)  // verifica se o arquivo existe
    {
    	printf("\nO usuário não se encotra no sistema!!");
    	printf("\n\n");
	}
	system("pause");

		   	    
}


int main()
{
    int opcao = 0;  //Definindo as variáveis
    int laco = 1;
		
    for (laco=1; laco=1;)
    {

		setlocale(LC_ALL, "Portuguese"); // Definindo a linguagem
		
		system("cls");
	
		printf("### Cartório da EBAC ###\n\n");
		printf("Escolha a opção desejada do menu:\n\n");
		printf("\t1 - Registrar nomes\n");
	    printf("\t2 - Consultar nomes\n");
	    printf("\t3 - Deletar nomes\n\n");

	    
	 
	    printf("Informe a opção: ");  // armazena a escolha do usuário
	    scanf("%d", &opcao);
	    
	    system("cls");  //Limpa a tela antes de apresentar a opção selecionada
	    
		switch(opcao)  //inicio da seleção do menu
		{
			case 1:
		   	    registro(); // chamada de funções
			    break;
			  
			case 2:		
			    consulta();
		   	    break;
		   	  
		   	case 3:
		   		deletar();
		   	    break;
		   	  
		   	default:
		  	    printf("Essa opção não está disponível!\n");	
		   	    system("pause");
   			    break;	   		
		   		
		}
		
   }
}

