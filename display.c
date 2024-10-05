#include "create.c"



void display(struct string * head){
    if(head == NULL) return;
    struct string* current = head;
    printf("[");
    do{
        printf("%c,",head->data);
        head = head->next;
    }while(current != head);
    puts("\b]");
}

void displayN(struct string * head, int N){
    if(head == NULL || N < 1) return;
    int i = 1;
    struct string* current = head;
    do{
        printf("%c ",head->data);
        head = head->next;
        i++;
    }while(current != head && i <= N);
    puts("");//puts comes with inbuilt \n character and need atleast one argument.
}

int count(struct string * str){
    if(str == NULL) return 0;
    int count = 0;
    struct string *current = str;
    do{
        count++;
        str = str->next;
    }while(current != str);
    return count;
}