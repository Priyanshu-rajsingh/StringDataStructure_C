#include <stdio.h>

struct string{
    struct string * prev;
    char data;
    struct string * next;
};

typedef enum{
    false = 0, true = 1
}bool;

struct string *create(){
    struct string *head = NULL, *tail = NULL, *new;
    int n, i;
    printf("Enter Size: ");
    scanf("%d",&n);
    printf("Enter string: ");
    for(i = 0; i < n; i++){
        new = (struct string *)malloc(sizeof(struct string));
        scanf(" %c",&new->data);
        new->next = NULL; new->prev = NULL;
        if(head == NULL){
            head = new; tail = new; tail->next = head; head->prev = tail;
        }
        else{
            new->next = tail->next;
            new->prev = tail;
            tail->next = new;
            head->prev = new;
            tail = new;
        }
    }
    return head;
}

struct string *createD(char ch[]){
    struct string *head = NULL, *tail = NULL, *new;
    int n = sizeof(ch)/sizeof(ch[0]), i;
    for(i = 0; i < n; i++){
        new = (struct string *)malloc(sizeof(struct string));
        new->data = ch[i];
        new->next = NULL; new->prev = NULL;
        if(head == NULL){
            head = new; tail = new; tail->next = head; head->prev = tail;
        }
        else{
            new->next = tail->next;
            new->prev = tail;
            tail->next = new;
            head->prev = new;
            tail = new;
        }
    }
    return head;
}

struct string *createN(int N){
    struct string *head = NULL, *tail = NULL, *new;
    int i;
    printf("Enter string: ");
    for(i = 0; i < N; i++){
        new = (struct string *)malloc(sizeof(struct string));
        scanf(" %c",&new->data);
        new->next = NULL; new->prev = NULL;
        if(head == NULL){
            head = new; tail = new; tail->next = head; head->prev = tail;
        }
        else{
            new->next = tail->next;
            new->prev = tail;
            tail->next = new;
            head->prev = new;
            tail = new;
        }
    }
    return head;
}

bool isEmpty(struct string *head){
    if(head == NULL) return false;
    else return true;
}

struct string *join(struct string * A, struct string * B){
    if(A == B && A == NULL) return A;
    else{
        struct string *temp1 = A->prev, *temp2 = B->prev;
        temp1->next = B;
        B->prev = temp1;
        temp2->next = A;
        A->prev = temp2;
        return A;
    }
}

struct string * copy(struct string * C){
    
}