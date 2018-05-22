#ifndef S_LIST_C   
#define S_LIST_C

#include "s_list.h"
#include <string.h>

struct Node{
	int valor;
	char chave[201];
	struct Node *prev;
	struct Node *next;
}; 
typedef struct Node node;

struct List{
	int size;
	node *head;
	node *tail;
};
typedef struct List list;

list*   create_list(){
	list *lista;
	lista =(list*) malloc(sizeof (list*));
	lista->size =0;
	lista->head = NULL;
	lista->tail = NULL;
	printf("Lista criada, size = %d\n",lista->size);
	return lista;	
} 

void add_head(list *lista, int ivalor, char cchave[201]){
	node *no;
	node *old_head;

	old_head = lista->head;	
	no = (node*) malloc(sizeof(node));
	no->valor = ivalor;
	strcpy(no->chave, cchave);

	if(lista->size == 0){
		lista->tail = no;
		lista->head = no;
		old_head = no;
	}

	no->next = old_head;
	no->prev  = no;

	lista->head = no;
	old_head->prev = no;
	lista->size = lista->size + 1;
	printf("No adicionado: valor= %d, chave = %s , size = %d\n", lista->head->valor, lista->head->chave, lista->size);
}

void add_tail(list *lista, int ivalor, char cchave[201]){
	node *no;
	node *old_tail;
	old_tail = lista->tail;	
	no = (node*) malloc(sizeof(node));
	no->valor = ivalor;
	strcpy(no->chave, cchave);

	
	if(lista->size == 0){
		lista->head = no;
		lista->tail = no;
		old_tail = no;
	}

	no->prev = old_tail;
	no->next = no;
	lista->tail = no;
	old_tail->next = no;
	lista->size = lista->size + 1;
	printf("No adicionado: valor= %d, chave = %s , size = %d\n", lista->tail->valor, lista->tail->chave, lista->size);
}

void ask_node_head(list *lista){
	int valor;
	char chave[201];
	printf("Insira o valor\n");
	scanf("%d",&valor);
	printf("Insira a chave\n");	
	scanf("%s",chave);
	add_head(lista,valor,chave);
}
void ask_node_tail(list *lista){
	int valor;
	char chave[201];
	printf("Insira o valor\n");
	scanf("%d",&valor);
	printf("Insira a chave\n");	
	scanf("%s",chave);
	add_tail(lista,valor,chave);
}

void print_list(list *lista){
	int size = lista->size;
	int i;
	node *aux;
	if(lista->size >=1)
	{
		aux= lista->head;
		for (i=1;i<size + 1; i++){
			printf("valor: %d, chave:'%s', posição %d, size %d\nhead-valor: %d, head-chave: '%s'\ntail-valor: %d, tail-chave: '%s'\n\n", aux->valor, aux->chave, i, size, lista->head->valor,lista->head->chave,lista->tail->valor, lista->tail->chave);
			aux = aux->next;		
		}
	}
}

#endif
