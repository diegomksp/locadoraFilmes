#ifndef _FUNCIONARIO_H_
#define _FUNCIONAIRO_H_
#define MAX 100

typedef struct {
    char nome[MAX];
    char sobrenome[MAX];
    char cargo[MAX];
    int id;
} FUNCIONARIO;

FILE *cont_func;
FILE *arquivo;

FUNCIONARIO a, temp[100];

int menu,busca;
char linha[100];

FUNCIONARIO cadastra_funcionario(); 
void grava_txt();
void menu_funcionario();
void alterarCargo();
void exclui_funcionario();
void opcoes_funcionario();
void imprime_lista();
void open_R();
void open_W();
void open_AW();


#endif 
