#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct contacto{
    char name[30];
    int number;
    int index;
    struct contacto *next;
    struct contacto *prev;
};

void push(struct contacto * head, char name[30], int number) {
    struct contacto * current = head;
    int index_aux = 0;
    while (current->next != NULL) {
        current = current->next;
        index_aux+=1;
    }

    current->next = (struct contacto *) malloc(sizeof(struct contacto));
    strcpy(current->next->name, name);
    current->next->number = number;
    current->next->index=index_aux;
    current->next->next = NULL;
    current->next->prev=current;
}

void print_list(struct contacto * head) {
    struct contacto * current = head;

    while (current!= NULL) {
        printf("INDEX: %d \n NAME: %s\n NUMBER: %d \n\n\n", current->index, current->name, current->number);
        current = current->next;
    }
}

void free_memory(struct contacto * head) {
    struct contacto * current = head;

    while (current != NULL) {
        current = current->next;
        free(current);
    }
}

// Inputs
int main(){
    struct contacto * head = NULL;
    head = (struct contacto *) malloc(sizeof(struct contacto));

    push(head, "Crisel", 555511);
    push(head, "Kevin", 555511);

    print_list(head);




   free_memory(head);
    return 0;
}