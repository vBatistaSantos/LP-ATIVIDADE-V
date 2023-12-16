/*
Crie um software com 4 funcionalidades para um sistema de gestão de recursos humanos.
> SISTEMA DE RH <

1 - CADASTRAR FUNCIONARIO
2 - DEMISSÃO DE FUNCIONARIO
3 - BUSCAR MATRICULA FUNCIONARIO
4 - LISTAR FUNCIONARIOS
5 - SAIR
*/

#include <stdio.h>
#include <locale.h>
#include <ctype.h>
#include <string.h>

struct info_funcionario{

    char matricula[200];
    char nome[200];
    char cargo[200];
    char dataAdmissao[200];
    char status[200];
    float salario;

};

char confirmarOperacao(){
    
    char confirmar;

    fflush(stdin);
    printf("Deseja continuar?(s/n)");
    scanf("%c",&confirmar);
    confirmar = tolower(confirmar);
    //CONFIRMAR CADASTRAR
    while(confirmar!='n' && confirmar!='s'){
        printf("Por favor, escolha uma opção válida");
        scanf("%c",&confirmar);
        confirmar = tolower(confirmar);
        fflush(stdin);
    }

    return confirmar;
}

int menuPrincipal(){

    int opcao;

    printf("============ GESTÃO DE RH ============\n\n");
    printf("1 - CADASTRAR FUNCIONÁRIO\n");
    printf("2 - DEMISSÃO DE FUNCIONÁRIO\n");
    printf("3 - BUSCAR DO FUNCIONÁRIO\n");
    printf("4 - LISTA DE FUNCIONÁRIOS\n");
    printf("5 - SAIR\n");
    
    scanf("%i",&opcao);

    while(opcao<1 || opcao>5){
        printf("Por favor, escolha uma opção válida");
        scanf("%i",&opcao);
    }

    return opcao;

}

void listarFuncionario(struct info_funcionario funcionario[],int i){
    int j;
    for(j=0;j<i;j++){
        printf("MATRÍCULA: %s\n",funcionario[j].cargo);
        printf("NOME: %s\n",funcionario[j].nome);
        printf("CARGO: %s\n",funcionario[j].cargo);
        printf("DATA ADMISSÃO: %s\n",funcionario[j].dataAdmissao);
        printf("SALÁRIO: %.2f\n",funcionario[j].salario);
        printf("======================================\n\n");
    }

}

void buscarfuncionario (struct info_funcionario funcionario [],int j){

    int i;
    char buscarfuncionario [200];

    printf("INFORME O NÚMERO DE MATRÍCULA DO FUNCIONÁRIO: ");
    gets(buscarfuncionario);

    for(i=0;i<j;i++){
        if(strcmp(buscarfuncionario,funcionario[i].matricula)==0 && strcmp(funcionario[i].status,"DESLIGADO")!=0){
            printf("MATRICULA: %s\n",funcionario[i].matricula);
            printf("NOME: %s\n",funcionario[i].nome);
            printf("CARGO: %s\n",funcionario[i].cargo);
            printf("DATA DE ADMISSÃO:%s\n",funcionario[i].dataAdmissao);
            printf("SALÁRIO: R$%.2f\n",funcionario[i].salario);
        }
    }

    //continuarOperacao();
    
}

void cadastrarFuncionario(struct info_funcionario funcionario[],int i){

    printf("MATRICULA: ");
    gets(funcionario[i].matricula);
    printf("NOME: ");
    gets(funcionario[i].nome);
    printf("CARGO: ");
    gets(funcionario[i].cargo);
    printf("DATA DE ADMISSÃO: ");
    gets(funcionario[i].dataAdmissao);
    fflush(stdin);
    printf("SALÁRIO: ");
    scanf("%f",&funcionario[i].salario);
    strcmp(funcionario[i].status,"ATIVO");

}

void continuarOperacao(){
    int i;
    printf("Insira qualquer número para continuar");
    scanf("%i",&i);
}

void desligarFuncionario(struct info_funcionario funcionario[],int i){

    char buscarMatricula[200], continuar;
    int j;

    printf("Informe a matricula do funcionário: ");
    gets(buscarMatricula);

    for(j=0;j<i;j++){
        if(strcmp(buscarMatricula,funcionario[j].matricula)==0 && strcmp(funcionario[j].status,"DESLIGADO")!=0){
            
            printf("\nMATRICULA: %s\n",funcionario[j].matricula);
            printf("\nNOME: %s\n",funcionario[j].nome);
            printf("\nCARGO: %s\n",funcionario[j].cargo);
            printf("\nDATA DE ADMISSÃO: %s\n",funcionario[j].dataAdmissao);

            continuar = confirmarOperacao();

            if (continuar=='s'){
                strcpy(funcionario[j].status,"DESLIGADO");
                printf("\nFuncionário desligado com sucesso!\n");
            } else {
                printf("\nOperação cancelada.\n");
            }
            return;
        }
    }
    printf("\nFuncionário não encontrado.\n");

}

int main(){

    setlocale(LC_ALL,"portuguese");

    int opcao,i=0;
    char confirmar;
    
    struct info_funcionario funcionario[200];

    do{
        opcao = menuPrincipal();

        switch(opcao){
            case 1:
                printf("======= CADASTRAR FUNCIONÁRIOS =======\n\n");
                do{
                    fflush(stdin);
                    cadastrarFuncionario(funcionario,i);
                    i++;
                    //CADASTRAR MAIS FUNCIONARIOS
                    fflush(stdin);
                    printf("Deseja cadastrar mais funcionários?(s/n)");
                    scanf("%c",&confirmar);
                    confirmar = tolower(confirmar);
                    //CONFIRMAR CADASTRAR
                    while(confirmar!='n' && confirmar!='s'){
                        printf("Por favor, escolha uma opção válida");
                        scanf("%c",&confirmar);
                        confirmar = tolower(confirmar);
                        fflush(stdin);
                    }
                    printf("\n");
                }while(confirmar=='s');
                
                break;
            case 2:
                printf("======= DESLIGAR  FUNCIONÁRIOS =======\n\n");
                do{ 
                    fflush(stdin);
                    
                    desligarFuncionario(funcionario,i);

                    fflush(stdin);
                    printf("Deseja desligar mais funcionários?(s/n)");
                    scanf("%c",&confirmar);
                    confirmar = tolower(confirmar);
                    //CONFIRMAR CADASTRAR
                    while(confirmar!='n' && confirmar!='s'){
                        printf("Por favor, escolha uma opção válida");
                        scanf("%c",&confirmar);
                        confirmar = tolower(confirmar);
                        fflush(stdin);
                    }
                    printf("\n");
                }while(confirmar=='s');
                
                break;
            case 3:

                printf("======== BUSCAR  FUNCIONÁRIOS ========\n\n");
                fflush(stdin);
                buscarfuncionario(funcionario,i);
                //strcmp(confirmar,confirmarOperacao());
                continuarOperacao();
                break;

            case 4:
                printf("======= LISTA DE FUNCIONÁRIOS  =======\n\n");
                listarFuncionario(funcionario,i);
                continuarOperacao();
                break;
        }
        
        system("cls || clear");
    }while(opcao<5);

    printf("\nENCERRANDO PROGRAMA...\n");

    return 0;
}