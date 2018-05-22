/*
 ============================================================================
 Name        : main.c
 Author      : Pedro Ernesto Scotton
 Version     :
 Copyright   : 
 Description : Main for usage headers
 Compile     : gcc main.c -o main
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "s_list.h"

void print_entry(char *entry) {
	printf("You entered: %s\n", entry);
}

int main(int argc, char *argv[]) {
	char input[201];
	list *lista;
	lista = create_list();

	while(1) {
		printf("prompt> ");
		if (fgets(input, 200, stdin) == NULL) {
			printf("An error ocurred.\n");
			break;
		}

		if (strncmp(input, "exit\n", 5) == 0) {
			printf("Leaving. Good bye.\n");
			break;
		}
		if (strncmp(input, "size\n", 5) == 0) {
			printf("Size = %x\n",lista->size);
			printf("Size = %d\n",lista->size);
			
		}
		if (strncmp(input, "print\n", 5) == 0) {
			print_list(lista);	
		}
		if (strncmp(input, "addh\n", 5) == 0) {
			ask_node_head(lista);
			
		}
		if (strncmp(input, "addt\n", 5) == 0) {
			ask_node_tail(lista);
			
		}
		
		//print_entry(input);
		
		
	}

	return EXIT_SUCCESS;
}

