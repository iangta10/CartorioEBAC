#include <stdio.h> //biblioteca de comunica��o com o �suario
#include <stdlib.h> //biblioteca de aloca��o de espa�o em memoria
#include <locale.h> //biblioteca de aloca��es de texto por regi�o
#include <string.h> //biblioteca respons�vel por cuidar das strings

int registra(){  //fun�ao para registrar novos usuarios
	
	//declara��o de variaveis
	char arquivo[40];
	char cpf[12];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	
	setlocale(LC_ALL,"Portuguese");  //definir linguagem
	
	printf("Digite o CPF a ser cadastrado: ");  //Coletando informa��o do usuario
	scanf("%s", cpf);
	
	strcpy(arquivo, cpf); //Respons�vel por copiar os valores das strings
	
	FILE *file;  //cria o arquivo
	file= fopen(arquivo, "w");  //cria o arquivo e escreve usando a fun��o "w"
	fprintf(file, cpf);  //salvo o valor da variavel
	fprintf(file,"\n");  //pula uma linha no arquivo salvo
	fclose(file);  //fecha o arquivo
	
	printf("Digite o nome a ser cadastrado: ");
	scanf("%s", nome);
	nome[0] = toupper(nome[0]);
	
	file = fopen(arquivo, "a");
	fprintf(file,nome);  //adiciona o nome cadastrado ao arquivo salvo
	fprintf(file," ");  //adiciona " " ao arquivo salvo
	fclose(file);
	
	printf("Digite o sobrenome a ser cadastrado(apenas 1 sobrenome): ");
	scanf("%s", sobrenome);
	sobrenome[0] = toupper(sobrenome[0]);
	
	file = fopen(arquivo, "a");
	fprintf(file,sobrenome);  //adiciona o sobrenome cadastrado ao arquivo salvo
	fprintf(file,"\n");  //pula uma linha no arquivo salvo
	fclose(file);
	
	printf("Digite o cargo a ser cadastrado: ");
	scanf("%s", cargo);
	
	file = fopen(arquivo, "a");
	fprintf(file,cargo);  //adiciona o cargo cadastrado ao arquivo salvo
	fclose(file);
		
}

int consulta(){  //fun��o para consultar usuario registrados
	
	char cpf[12];
	char conteudo[200];
	int x = 0;
	
	setlocale(LC_ALL,"Portuguese");  //definir linguagem
	
	printf("Digite o CPF a ser consultado: ");  //pede ao usuario um CPF para consultar no banco de dados
	scanf("%s", cpf);  
	
	FILE *file;
	file = fopen(cpf, "r");  //le o banco de dados em busca do cpf solicitado
	
	if(file == NULL){
		printf("CPF nao localizado!\n");  //informa o usuario que o CPF nao existe no sistema
	}
	
	while(fgets(conteudo, 200, file) != NULL){
		
		
		switch(x){
			case 0:
				printf("\nEssas s�o as informa��es do usuario consultado: ");
				printf("\n\n");
				printf("CPF do usuario consultado: %s",conteudo);  //mostra ao usuario o CPF consultado
				break;
			
			case 1:
				printf("Nome do usuario consultado: %s",conteudo);  //mostra ao usuario o Nome consultado
				break;	
			
			case 2:
				printf("Cargo do usuario consultado: %s",conteudo);  //mostra ao usuario o Cargo consultado
				printf("\n\n");
				break;	
				
			default:
				break;	
		}
		
		
		
		x += 1;   
	}
	
	system("pause");
}

int deleta(){  //fun��o para deletar usuarios registrados
	
	char cpf[12];
	
	printf("Digite o CPF a ser deletado: ");  // solicita o CPF a ser deletado ao usuario
	scanf("%s", cpf);  // salva o CPF na variavel cpf
	
	
	FILE *file;
	file = fopen(cpf, "r");
	
	if(file == NULL){
		printf("CPF n�o encontrado no sistema.\n");  //avisa o usuario caso o CPF n�o esteja cadastrado
		system("pause");
	}
	
	remove(cpf);  //deleta o arquivo relacionado ao CPF digitado pelo usuario
	
	printf("\nUsu�rio deletado com sucesso!\n\n");  //avisa ao usuario que o CPF solicitado foi deletado
	system("pause");
}

int main(){
	
	//declara��es de variaveis
	int opcao=0;
	int n=1;
	
	
	for(n=1;n=1;){
	
		system("cls"); //limpar tela para usuario
		
		setlocale(LC_ALL,"Portuguese");  //definir linguagem
		
		//inicio do programa
		printf("    Cart�rio da EBAC \n\n");
		
		printf("Escolha a op��o desejada: \n\n");//inicio do menu
		printf("\t1 - Registrar usu�rio \n");
		printf("\t2 - Consultar usu�rio \n");
		printf("\t3 - Deletar usu�rio \n"); 
		printf("\t4 - Sair do programa \n"); 
		printf("\nOp��o: "); //fim do menu
		
		
		scanf("%d",  &opcao);  //armazenando escolha do usuario
		
		system("cls"); //limpar tela para usuario
		
		
		switch(opcao){    //resposta da op�ao selecionada pelo usuario
			case 1:
				registra();  //chama a fun��o "registra"
				break;
			
			case 2:
				consulta();  //chama a fun��o "consulta"
				break;
				
			case 3:
				deleta();  //chama a fun��o "deleta"
				break;
				
			case 4:
				printf("Voce escolheu Sair do programa\n\n");
				exit (0) ;  //encerra o programa
				break;	
				
			default:
				printf("Op��o invalida, escolha uma das op��es disponiveis\n\n");
				system("pause");
				break;			
		}
		
		
	
	}
	
}
