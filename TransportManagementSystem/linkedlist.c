#include "stop.c"
#include <string.h>
#include <stdlib.h>

#ifndef LINKEDLIST
#define LINKEDLIST

struct Career{
    char name[20];
    struct stop* head;
    struct stop* tail;
};

void add_node_to_head(struct Career* list, struct stop *source) {
    if (list->head == NULL) {
        list->head = source;
        list->tail = source;
    }
    else {
        source->next = list->head;
        list->head = source;
    }
    list->tail->next=NULL;
}

void add_node_to_tail(struct Career* list, struct stop *source) {

    if (list->tail == NULL) {
        list->head = source;
        list->tail = source;
    }
    else {
        list->tail->next = source;
        list->tail = list->tail->next;
    }
    list->tail->next=NULL;
}

void print_list(struct Career* list) {
    int count = 0;
    float sum = 0;
    float duration = 0;
    struct stop* prev_node = NULL;
    struct stop* current_node = list->head;
    if(list->head != NULL)
        printf("%s ", current_node->name);
    while (current_node != NULL) {
        count++;
        duration = duration + current_node->duration;
        sum = sum + current_node->cost;
        prev_node = current_node;
        current_node = current_node->next;
    }
    if(prev_node != NULL)
        printf("%s ", prev_node->name);
    printf("%d ", count);
    printf("%.2f ", sum);
    printf("%.2f ", duration);
    printf("\n");
}

void print_stops_name(struct Career* list){
    struct stop* current_node = list->head;
    while (current_node!= NULL) {
        printf("%s ", current_node->name);
        current_node = current_node->next;
    }
    printf("\n");
}

void print_stops_name_inverse_helper(struct stop* head){
    if(head == NULL)
        return;
    print_stops_name_inverse_helper(head->next);
    printf("%s ", head->name);
}

void print_stops_name_inverse(struct Career* list){
    print_stops_name_inverse_helper(list->head);
    printf("\n");
}

void add(struct Career* list, struct stop* source, struct stop* last, float cost, float duration){

    if( list->head == NULL )
    {
        add_node_to_head(list, source);
        list->tail = last;
        list->head->next = list->tail;
        source->cost = 0;
        source->duration = 0;
        last->cost = cost;
        last->duration = duration;
        source->number_of_careers++;
        last->number_of_careers++;
        return;
    }

    if ( !strcmp(list->head->name, last->name) ) {
        source->cost = cost;
        source->duration = duration;
        last->cost = 0;
        last->duration = 0;
        add_node_to_head(list, source);
        source->number_of_careers++;
    }
    else if( !strcmp(list->tail->name, source->name) ) {
        last->cost = cost;
        last->duration = duration;
        add_node_to_tail(list, last);
        last->number_of_careers++;
    }

    else
        printf("link cannot be associated with bus line\n");

    list->tail->next=NULL;
}

#endif
