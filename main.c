#include <stdio.h>
#include <stdlib.h>

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
    if(n < 1) return NULL;
    //getchar(); // to override of the newline character returned after the above statement
    printf("Enter string: ");
    for(i = 0; i < n; i++){
        new = (struct string *)malloc(sizeof(struct string));
        //new->data = getchar(); //alternative way
        scanf(" %c",&new->data); //other solution to the use of getchar() for buffer clear is a space before %c in scanf
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

int main(){

    struct string *s1 = create();// *s2 = create(), *s3;
    // if(s1 == NULL) {
    //     printf("Structure not implemented\n");
    // }
    bool t = isEmpty(s1);
    printf("%d ",t);
    display(s1);
    
    // bool t = isEmpty(s1);
    // printf("%d ",t);
    display(s1);
    printf("%d",count(s1));
    // display(s2);
    // s3 = join(s1,s2);
    // display(s3);
    return 0 ;
}