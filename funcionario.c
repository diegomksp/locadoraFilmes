
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funcionario.h"



FUNCIONARIO cadastra_funcionario(){			//Função testada e funcionando!
		open_AW();
		
		printf("Entre com o primeiro nome: ");
		scanf("%s",&a.nome);
		fflush(stdin);
		printf("Entre com o sobrenome: ");
		scanf("%s",&a.sobrenome);
		fflush(stdin);
		printf("Entre com o cargo do funcionario: ");
		scanf("%s",&a.cargo);
		fflush(stdin);
		printf("Entre com o ID do funcionario: ");
		scanf("%d",&a.id);
		int c;
    	while ((c = getchar()) != '\n' && c != EOF) { }
		
		grava_txt();		


}

void menu_funcionario(){
	printf("\n\n_*_*_*_*_*_*_*_*_*_*_*Menu Funcionario*_*_*_*_*_*_*_*_*_*_*_*_\n\n");
	printf("[1] Cadastro de funcionario \n[2] Alterar funcionario \n[3] Excluir funcionario \n[4] Lista de funcionarios \n[5] Retornar menu principal \n");
	printf("Resposta: ");
	scanf("%d",&menu);
	printf("\n");
	
	fflush(stdin);
	
}

void grava_txt(){		//Função testada
	fprintf(arquivo, "%s %s %s %d\n", a.nome, a.sobrenome, a.cargo, a.id);
	fclose(arquivo);
	printf("Arquivo gravado com sucesso.\n");
	}

void imprime_lista(){		//TESTADO
	arquivo = fopen("funcionario.txt","r");
		if(arquivo==NULL){
			printf("Erro ao abrir arquivo.\n");
		}else{
			while(fgets(linha,sizeof(linha),arquivo)!=NULL){
				printf("%s",linha);
			}
		}
		fclose(arquivo);
}

void alterarCargo() {			//TESTADO
    FUNCIONARIO funcionarios[MAX];
    int totalFuncionarios = 0;
    int idProcurado=0, i;
    char novoCargo[MAX];
    
    // Abrir o arquivo para leitura
    open_R();

    // Ler os dados do arquivo
    while (fscanf(arquivo, "%s %s %s %d", funcionarios[totalFuncionarios].nome, 
           funcionarios[totalFuncionarios].sobrenome, 
           funcionarios[totalFuncionarios].cargo, 
           &funcionarios[totalFuncionarios].id) != EOF) {
        totalFuncionarios++;
    }
    fclose(arquivo);
    
    // Solicitar o ID do funcionário a ser alterado
    printf("Digite o ID do funcionario para alterar o cargo: ");
    scanf("%d", &idProcurado);

    // Verificar se o ID existe e solicitar o novo cargo
    for (i = 0; i < totalFuncionarios; i++) {
        if (funcionarios[i].id == idProcurado) {
            printf("Funcionario encontrado: %s %s - Cargo atual: %s\n", 
                   funcionarios[i].nome, funcionarios[i].sobrenome, funcionarios[i].cargo);
            printf("Digite o novo cargo: ");
            scanf(" %[^\n]", novoCargo);
            strcpy(funcionarios[i].cargo, novoCargo);
            printf("Cargo alterado com sucesso!\n");
            break;
        }
    }

    if (i == totalFuncionarios) {
        printf("Funcionario com ID %d nao encontrado.\n", idProcurado);
        return;
    }

    // Abrir o arquivo para reescrever os dados alterados
    arquivo = fopen("funcionario.txt", "w");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo para escrita.\n");
        return;
    }

    // Regravar todos os dados no arquivo
    for (i = 0; i < totalFuncionarios; i++) {
        fprintf(arquivo, "%s %s %s %d\n", funcionarios[i].nome, funcionarios[i].sobrenome, 
                funcionarios[i].cargo, funcionarios[i].id);
    }

    fclose(arquivo);
    printf("Arquivo atualizado com sucesso.\n");
}

void exclui_funcionario(){
	 FUNCIONARIO funcionarios[MAX];
    int totalFuncionarios = 0;
    int idProcurado=0, i,k=MAX+1;
    char novoCargo[MAX];
    
    // Abrir o arquivo para leitura
    open_R();

    // Ler os dados do arquivo
    while (fscanf(arquivo, "%s %s %s %d", funcionarios[totalFuncionarios].nome, 
           funcionarios[totalFuncionarios].sobrenome, 
           funcionarios[totalFuncionarios].cargo, 
           &funcionarios[totalFuncionarios].id) != EOF) {
        totalFuncionarios++;
    }
    fclose(arquivo);
    
    // Solicitar o ID do funcionário a ser alterado
    printf("Digite o ID do funcionario para Excluir: ");
    scanf("%d", &idProcurado);

    // Verificar se o ID existe e solicitar o novo cargo
    for (i = 0; i < totalFuncionarios; i++) {
        if (funcionarios[i].id == idProcurado) {
            printf("Funcionario encontrado: %s %s - Cargo atual: %s\n", 
                   funcionarios[i].nome, funcionarios[i].sobrenome, funcionarios[i].cargo);
            
            strcpy(funcionarios[i].nome,"Excluido");
            strcpy(funcionarios[i].sobrenome,"Excluido");
			strcpy(funcionarios[i].cargo, "Excluido");
			funcionarios[i].id=0;
            k=i;
            printf("Cargo excluido com sucesso!\n");
            break;
        }
    }

    if (i == totalFuncionarios) {
        printf("Funcionario com ID %d nao encontrado.\n", idProcurado);
        return;
    }

    // Abrir o arquivo para reescrever os dados alterados
    open_W();

    // Regravar todos os dados no arquivo
    for (i = 0; i < totalFuncionarios; i++) {
    	if(funcionarios[i].id!=funcionarios[k].id){
        fprintf(arquivo, "%s %s %s %d\n", funcionarios[i].nome, funcionarios[i].sobrenome, 
                funcionarios[i].cargo, funcionarios[i].id);
            }
    }

    fclose(arquivo);
    printf("Arquivo atualizado com sucesso.\n");
}

void opcoes_funcionario(){	
int sair =0;
	do{
		menu_funcionario();
		
	switch(menu) {
		case 1:
			cadastra_funcionario();
			getchar();
			break;		
	
		case 2:
			alterarCargo();
			getchar();
			break;
			
		case 3:
			exclui_funcionario();
			getchar();
			break;
			
		case 4:
			imprime_lista();
			getchar();
			break;
				
		default:
			sair=1;
			break;
	}
		
	}while(sair!=1);
}

void open_R(){
	arquivo = fopen("funcionario.txt", "r");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return;
    }
}

void open_W(){
	    arquivo = fopen("funcionario.txt", "w");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo para escrita.\n");
        return;
    }
}

void open_AW(){
	arquivo = fopen("funcionario.txt","a+");
		if(arquivo==NULL){
			fopen("funcionario.txt","w");
		}
}



