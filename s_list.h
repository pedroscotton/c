#ifndef S_LIST_H   
#define S_LIST_H
#include "s_list.c"

list* create_list();
void ask_node_head(list *lista);
void ask_node_tail(list *lista);
void add_head(list *lista, int ivalor, char cchave[201]);
void add_tail(list *lista, int ivalor, char cchave[201]);
void print_list(list *lista);


#endif
