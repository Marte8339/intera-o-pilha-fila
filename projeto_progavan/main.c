//Nome:Caique Jose Domingos RA:0040962313031
//Nome:Natan Noveli de Melo RA:0040962313047
//Nome:Leonardo Dantas Rodrigues RA:0040962313045

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct pilha{
    int id;
    char nome[50];

    struct pilha *next, *back;
}pilha;

struct pilha *topo=NULL, *auxiliarP=NULL;

typedef struct fila{
    int id;
    char nome[50];

    struct fila *next;
}fila;

struct fila *inicio=NULL, *fim=NULL, *auxiliarF=NULL;

int contador_Pilha=0, contador_Fila=0;

void limparBuffer(){
    int c;
    while((c = getchar()) != '\n' && c != EOF);
}

int main()
{
    int opcao;

    do{
        system("cls");

        printf("\tProjeto Pilha && Fila");

        printf("\n\n|1|Inserir na Pilha.");
        printf("\n|2|Ver topo da Pilha.");
        printf("\n|3|Retirar da Pilha e mandar para a fila.");

        printf("\n\n|4|Inserir na fila.");
        printf("\n|5|Ver Fila.");
        printf("\n|6|Retirar da Fila e mandar para a Pilha.");

        printf("\n\n|7|Sair.");

        printf("\nDigite sua opcao aqui: ");
        scanf("%i", &opcao);

        switch(opcao){
        case 1:
            system("cls");
            push();
        break;
        case 2:
            system("cls");
            top();
        break;
        case 3:
            system("cls");
            topo_para_fim();
        break;
        case 4:
            system("cls");
            enqueue();
        break;
        case 5:
            system("cls");
            sequeue();
        break;
        case 6:
            system("cls");
            inicio_para_topo();
        break;
        case 7:
            system("cls");
            printf("\n\tSaindo...\n");
            exit(0);
        break;
        default:
            system("cls");
            printf("\n\tOpcao nao encontrada!!\n\tTente novamente...\n\n");
            system("pause");
            main();
        }

    }while(opcao < 8);
}

//Inicio codigo da pilha
void push(){
    if(contador_Pilha >=5){
        printf("\nA pilha esta cheia.\n\n");
        system("pause");
        main();
    }else if(topo == NULL){
        topo = (pilha*)malloc(sizeof(pilha));
        if(topo == NULL){
            printf("\nErro ao gerar Pilha\n");
            system("pause");
        }
        topo->next = NULL;
        topo->back = NULL;
        auxiliarP = topo;

    }else{
        topo = (pilha*)malloc(sizeof(pilha));
        if(topo == NULL){
            printf("\nErro ao gerar Topo\n");
            system("pause");
        }
        auxiliarP->next = topo;
        topo->back = auxiliarP;
        auxiliarP = topo;
        topo->next = NULL;
    }

    printf("\nInsira o ID: ");
    scanf("%d", &topo->id);

    limparBuffer();

    printf("\nInsira o Nome: ");
    scanf("%s", &topo->nome);

    contador_Pilha++;
}

void top(){
    if(topo == NULL){
        printf("\nPilha vazia\n");
        system("pause");
    }else{
        printf("\nID: %d | Nome: %s\n\n", topo->id, topo->nome);
        system("pause");
    }
}

void topo_para_fim(){
    if(contador_Fila >= 3){
        printf("\n\tLista cheia.\n");
        system("pause");
        main();
    }else if(inicio == NULL){
        fim = (fila*)malloc(sizeof(fila));
        if(fim == NULL){
            printf("\nErro ao gerar fila\n");
            system("pause");
        }
        fim->next = NULL;
        auxiliarF = fim;
        inicio = fim;
    }else{
        fim = (fila*)malloc(sizeof(fila));
        if(fim == NULL){
            printf("\nErro ao gerar item para Fila\n");
            system("pause");
        }
        auxiliarF->next = fim;
        auxiliarF = fim;
        fim->next = NULL;
    }

    fim->id = topo->id;
    strcpy(fim->nome,topo->nome);

    contador_Fila=contador_Fila+1;

    if(topo == NULL){
        printf("\nA Pilha ja esta vazia.\n");
        system("pause");
    }else if(topo->next == NULL && topo->back == NULL){
        free(topo);
        topo=NULL;

        contador_Pilha = 0;

        printf("\nItem removido com sucesso.");
        printf("\nPilha vazia\n");
        system("pause");
        main();
    }else{
        auxiliarP = topo;
        topo = topo->back;
        free(auxiliarP);
        topo->next=NULL;
        contador_Pilha=contador_Pilha-1;

        printf("\nItem removido com sucesso.\n");
        system("pause");
    }
}
//Fim codigo da pilha
////////////////////////////////////////////////////////////////////////////
//Inicio codigo da Fila
void enqueue(){
    system("cls");

    if(contador_Fila >= 3){
        printf("\n\tLista cheia.\n");
        system("pause");
        main();
    }else if(inicio == NULL){
        fim = (fila*)malloc(sizeof(fila));
        if(fim == NULL){
            printf("\nErro ao gerar fila\n");
            system("pause");
        }
        fim->next = NULL;
        auxiliarF = fim;
        inicio = fim;
    }else{
        auxiliarF = fim;
        fim = (fila*)malloc(sizeof(fila));
        if(fim == NULL){
            printf("\nErro ao gerar item para Fila\n");
            system("pause");
        }
        auxiliarF->next = fim;
        auxiliarF = fim;
        fim->next = NULL;
    }

    printf("\nInsira o ID: ");
    scanf("%d", &fim->id);

    limparBuffer();

    printf("\nInsira o Nome: ");
    scanf("%s", &fim->nome);

    contador_Fila++;
}

void sequeue(){
    system("cls");

    if(inicio==NULL){
        printf("\nFila vazia.\n");
        system("pause");
    }else{
        auxiliarF = inicio;

        printf("\n\tFila");
        for(int i=0;i<contador_Fila;i++){
            printf("\n%i | ID: %i | Nome: %s", i, auxiliarF->id, auxiliarF->nome);
            auxiliarF=auxiliarF->next;
        }
        printf("\n");
        system("pause");
    }
}

void inicio_para_topo(){
    if(contador_Pilha >=5){
        printf("\nA pilha esta cheia.\n\n");
        system("pause");
        main();
    }else if(topo == NULL){
        topo = (pilha*)malloc(sizeof(pilha));
        if(topo == NULL){
            printf("\nErro ao gerar Pilha\n");
            system("pause");
        }
        topo->next = NULL;
        topo->back = NULL;
        auxiliarP = topo;

    }else{
        topo = (pilha*)malloc(sizeof(pilha));
        if(topo == NULL){
            printf("\nErro ao gerar topo\n");
            system("pause");
        }
        auxiliarP->next = topo;
        topo->back = auxiliarP;
        auxiliarP = topo;
        topo->next = NULL;
    }

    topo->id=inicio->id;
    strcpy(topo->nome,inicio->nome);

    contador_Pilha=contador_Pilha+1;

    if(inicio==NULL){
        printf("\nFila vazia.\n");
        system("pause");
    }else if(inicio == fim){
        free(inicio);
        inicio=NULL;
        auxiliarF=NULL;
        fim=NULL;
        contador_Fila = 0;

        printf("\nLista esvaziada.\n");
        system("pause");
    }else{
        auxiliarF = inicio;
        inicio = inicio->next;
        free(auxiliarF);
        auxiliarF = inicio;
        contador_Fila=contador_Fila-1;

        printf("\nUm processo foi retirado da lista.\n");
        system("pause");
    }
}
//Fim codigo da Fila
