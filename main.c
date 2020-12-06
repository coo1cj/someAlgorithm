#include <stdio.h>
#include <stdlib.h>


typedef struct node{
    struct node* next;
    int data;
}Node;

typedef Node* Liste;

Liste creatNode(int x){
    Liste tmp = (Liste)malloc(sizeof(Node));
    tmp->next = NULL;
    tmp->data = x;
    return tmp;
}

void appendNode(Liste* l, int x){
    Liste p = *l;
    if(p == NULL){
        *l = creatNode(x);
        return;
    }
    while(p){
        if(p->next == NULL){
            p->next = creatNode(x);
            return;
        }
        p = p->next;
    }
}

void print(Liste* l){
    Liste p = *l;
    while(p){
        printf("%d ", p->data);
        p = p->next;
    }
    printf("\n");
}

void deleteNode(Liste *l){
    Liste p = *l;
    *l = (*l)->next;
    free(p);
}


void Begyate(Liste *l){
    if(*l){
        
        while(*l && (*l)->data <= 0){
            //printf("test: %d", l->data);
            deleteNode(l);
        }
        //printf("%d\n", l->data);
        if((*l)->data > 0){

            Liste tmp = creatNode((*l)->data);
            tmp->next = (*l)->next;
            (*l)->next = tmp;
            while(tmp->next != NULL && tmp->next->data <= 0){
                tmp->next = tmp->next->next;
            }
            Begyate(&tmp->next);
        }
    }
}



int main(){
    Liste head = creatNode(-2);
    //head = deleteNode(head, -2);
    appendNode(&head, -9);
    appendNode(&head, 5);
    appendNode(&head, 7);
    appendNode(&head, -7);
    appendNode(&head, -9);
    appendNode(&head, 9);
    appendNode(&head, 9);
    print(&head);
    Begyate(&head);
    print(&head);
}
