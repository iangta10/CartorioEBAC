#include <stdio.h> //biblioteca de comunicação com o úsuario
#include <stdlib.h> //biblioteca de alocação de espaço em memoria
#include <locale.h> //biblioteca de alocações de texto por região
#include <string.h> //biblioteca responsável por cuidar das strings
#include <ctype.h>  //biblioteca usada para capitalizar algumas letras, deixando um melhor visual no sistema

int registraColaborador(){  //funçao para registrar novos colaboradores
	
	//declaração de variaveis
	char arquivo[40];
	char cpf[12];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	int y = 1;
	
	setlocale(LC_ALL,"Portuguese");  //definir linguagem
	
	while(y==1){
	
		system("cls");
		
		printf("Digite o CPF a ser cadastrado: ");  //Coletando informação do usuario
		scanf("%s", cpf);
		
		strcpy(arquivo, cpf); //Responsável por copiar os valores das strings
		
		FILE *file;  //cria o arquivo
		file= fopen(arquivo, "w");  //cria o arquivo e escreve usando a função "w"
		fprintf(file, cpf);  //salvo o valor da variavel
		fprintf(file,"\n");  //pula uma linha no arquivo salvo
		fclose(file);  //fecha o arquivo
		
		printf("Digite o nome a ser cadastrado: ");
		fflush (stdin);
    	fgets(nome, 40, stdin);
    	nome[strcspn(nome, "\n")] = '\0'; 
		nome[0] = toupper(nome[0]);
		
		file = fopen(arquivo, "a");
		fprintf(file,nome);  //adiciona o nome cadastrado ao arquivo salvo
		fprintf(file," ");  //adiciona " " ao arquivo salvo
		fclose(file);
		
		printf("Digite o sobrenome a ser cadastrado: ");
		fflush (stdin);
    	fgets(sobrenome, 40, stdin);
    	sobrenome[strcspn(sobrenome, "\n")] = '\0'; // Remover o caractere '\n' do final da string
		sobrenome[0] = toupper(sobrenome[0]);
		
		file = fopen(arquivo, "a");
		fprintf(file,sobrenome);  //adiciona o sobrenome cadastrado ao arquivo salvo
		fprintf(file,"\n");  //pula uma linha no arquivo salvo
		fclose(file);
		
		printf("Digite o cargo a ser cadastrado: ");
		fflush (stdin);
    	fgets(cargo, 40, stdin);
    	cargo[strcspn(cargo, "\n")] = '\0'; // Remover o caractere '\n' do final da string
		cargo[0] = toupper(cargo[0]);
		
		file = fopen(arquivo, "a");
		fprintf(file,cargo);  //adiciona o cargo cadastrado ao arquivo salvo
		fclose(file);
		
		system("cls");
		printf("Usuário cadastrado com sucesso\n");
		system("pause");
		y = 3;
		while(y != 1 && y != 2 ){  //looping para verificar se o usuario deseja cadastrar mais colaboradores
			system("cls");
			
			printf("Deseja cadastrar outro usuário?\n");
			printf("\t1 - Sim \n");
			printf("\t2 - Não \n");
			scanf("%d",&y);
			
			if(y != 1 && y != 2){
				printf("Opção invalida, escolha entre as opções disponiveis\n");
				system("pause");
			}
		}	
	}
		
}

int consultaColaborador(){  //função para consultar colaboradores registrados
	
	// Declaração de variaveis
	char cpf[12];
	char conteudo[200];
	int x = 0;
	int y = 1;
	
	setlocale(LC_ALL,"Portuguese");  //definir linguagem
	
	while(y==1){
		system("cls");
		
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
					printf("\nEssas são as informações do usuario consultado: ");
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
			
			
			
			x += 1;   //acrescenta valor a variavel x para exibir as informações de forma mais organizada ao usuario
		}
		system("pause");
		x = 0;  //volta a variavel 'x' ao estado inicial, caso o usuario queira fazer uma nova consulta
		y = 3;  //altera o valor da variavel 'y' para melhor funcionamento dos loopings de confirmação com o usuario
		while(y != 1 && y != 2 ){
			system("cls");
			
			printf("Deseja consultar outro usuário?\n");
			printf("\t1 - Sim \n");
			printf("\t2 - Não \n");
			scanf("%d",&y);  
			
			if(y != 1 && y != 2){  //confere se a resposta do usuario é valida
				printf("Opção invalida, escolha entre as opções disponiveis\n");
				system("pause");
			}
		}
	}
}

int deletaColaborador(){  //função para deletar colaboradores registrados
	
	char cpf[12];
	int x = 1;
	
	
	while(x == 1){
	
		system("cls");
		
		printf("Digite o CPF a ser deletado: ");  // solicita o CPF a ser deletado ao usuario
		scanf("%s", cpf);  // salva o CPF na variavel cpf
		
		FILE *file;
		file = fopen(cpf, "r");  //le o arquivo em busca do CPF solicitado
		
		if(file == NULL){
			
			printf("CPF não encontrado no sistema.\n");  //avisa o usuario caso o CPF não esteja cadastrado
			system("pause");
			
		} else{
			fclose(file);
			remove(cpf);  //deleta o arquivo relacionado ao CPF digitado pelo usuario
			
			printf("\nUsuário deletado com sucesso!\n\n");  //avisa ao usuario que o CPF solicitado foi deletado
			system("pause");
		}
		
		x = 3;  //altera o valor da variavel 'x' para melhor funcionamento dos loopings de confirmação com o usuario
		
		while(x != 1 && x != 2 ){
			system("cls");
			
			printf("Deseja deletar outro usuário?\n");
			printf("\t1 - Sim \n");
			printf("\t2 - Não \n");
			scanf("%d",&x);  //Coleta a resposta do usuario
			
			if(x != 1 && x != 2){  //confere se a resposta do usuario é valida
				printf("Opção invalida, escolha entre as opções disponiveis\n");
				system("pause");
			}
		}
	}
}

int verificarCredenciais(char *login, char *senha) {  //função para verificar as credenciais de login do usuario
    char linha[100];
    char usuario[50], senhaArmazenada[50];

    FILE *arquivo = fopen("usuarios.txt", "r"); // Abre o arquivo no modo de leitura

    if (arquivo != NULL) {
        while (fgets(linha, sizeof(linha), arquivo) != NULL) {
            sscanf(linha, "%s %s", usuario, senhaArmazenada);  //busca o usuario e senha no arquivo

            if (strcmp(login, usuario) == 0 && strcmp(senha, senhaArmazenada) == 0) {  //confere se o usuario e senha estao corretos
                fclose(arquivo);
                return 1; // Credenciais válidas encontradas
            }
        }

        fclose(arquivo);
    }

    return 0; // Credenciais inválidas ou erro ao ler o arquivo
}

void registrarUsuario() {  // função para registrar um novo usuario do sistema
    char login[50];
    char senha[50];
    
	system("cls");
    printf("	Registro de novo usuário\n\n");
    printf("Digite o nome de usuário: ");
    scanf("%s", login);
    printf("Digite a senha: ");
    scanf("%s", senha);

    FILE *arquivo = fopen("usuarios.txt", "a"); // Abre o arquivo no modo de adição

    if (arquivo != NULL) {
        fprintf(arquivo, "%s %s\n", login, senha);  //adiciona um novo usuario e a sua senha no arquivo
        fclose(arquivo);
        printf("Usuário registrado com sucesso.\n");
        system("pause");
    } else {
        printf("Não foi possível abrir o arquivo.\n");
        system("pause");
    }
}

int main(){
	
	//declarações de variaveis
	int opcaoLogin=0;
	int opcaoMenu=0;
	int n=1;
	char login[50], senha[50];
	int y = 0;
	
	setlocale(LC_ALL,"Portuguese");  //definir linguagem
	
	while(y == 0){
		system("cls");
		printf("    Cartório da EBAC \n\n");  //inicio do programa
			
			printf("Escolha a opção desejada: \n\n");//inicio do menu de login
			printf("\t1 - Fazer login \n");
			printf("\t2 - Criar novo usuário \n");
			printf("\t3 - Sair do programa \n"); 
			printf("\nOpção: "); //fim do menu
			scanf("%d", &opcaoLogin);
			
			switch(opcaoLogin){    //resposta da opçao selecionada pelo usuario
				case 1:
					system("cls");
					printf("    Cartório da EBAC \n\n");  //tela de login
					printf("Usuario: ");
    				scanf("%s", login);
    				printf("Senha: ");
    				scanf("%s", senha);

   					 if (verificarCredenciais(login, senha) || strcmp(login, "admin") == 0 && strcmp(senha, "admin") == 0 ){
   					     printf("\nCredenciais válidas. Acesso permitido.\n");
   					     system("pause");
   					     y = 1;
   					 } 
						else {
    					    printf("\nCredenciais inválidas. Acesso negado.\n");
    					    system("pause");
   					 }
					break;
				
				case 2:
					registrarUsuario();  //chama a função para registrar um novo usuario
					break;
					
				case 3:
					system("cls");
					printf("Voce escolheu Sair do programa\n\n");
					exit (0) ;  //encerra o programa
					break;	
					
				default:
					printf("Opção invalida, escolha uma das opções disponiveis\n\n");
					system("pause");
					break;			
			}
	}
	
	for(n=1;n=1;){
	
		system("cls"); //limpar tela para usuario

		printf("    Cartório da EBAC \n\n");
		
		printf("Escolha a opção desejada: \n\n");//inicio do menu
		printf("\t1 - Registrar usuário \n");
		printf("\t2 - Consultar usuário \n");
		printf("\t3 - Deletar usuário \n"); 
		printf("\t4 - Sair do programa \n"); 
		printf("\nOpção: "); //fim do menu
		
		
		scanf("%d",  &opcaoMenu);  //armazenando escolha do usuario
		
		system("cls"); //limpar tela para usuario
		
		
		switch(opcaoMenu){    //resposta da opçao selecionada pelo usuario
			case 1:
				registraColaborador();  //chama a função que registra um novo colaborador
				break;
			
			case 2:
				consultaColaborador();  //chama a função que consulta um colaborador cadastrado
				break;
				
			case 3:
				deletaColaborador();  //chama a função que deleta um colaborador cadastrado
				break;
				
			case 4:
				printf("Voce escolheu Sair do programa\n\n");
				exit (0) ;  //encerra o programa
				break;	
				
			default:
				printf("Opção invalida, escolha uma das opções disponiveis\n\n");
				system("pause");
				break;			
		}
		
		
	
	}

}
