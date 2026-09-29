#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node *next;
}node;
void insertAt(node** head,int value,int position) {
    node* yeni = (node*)malloc(sizeof(node));
    yeni->data = value;
    yeni->next = NULL;

    if (*head == NULL || position <= 0) {  //position 0 veya daha küçükse elemani basa ekler
        yeni->next = *head;
        *head = yeni;
        return;
    }
    node* iter = *head;
    for (int i = 0; iter->next != NULL && i < position - 1; i++) { //eklenecek yerin önceki dugumunu bulur
        iter = iter->next;
    }
    yeni->next = iter->next;
    iter->next = yeni;

}
void deleteAt(node** head,int position) {
    if (*head == NULL || position < 0) {
        return;
    }
    if (position==0) {
        node*temp=*head;
        *head=(*head)->next;
        free(temp);
        return;
    }
    node* iter = *head;
    for (int i = 0; iter != NULL && i < position - 1; i++) {    //silinecek elemandan öncekinde durur
        iter = iter->next;
    }
    if (iter == NULL || iter->next == NULL) {
        return;
    }
    node* temp = iter->next;
    iter->next = iter->next->next;
    free(temp);

}

void printList(node *head) {
    node* iter=head;             //listede gezinme islemi yardimiyla liste elemanlarini yazdirir
    while (iter!=NULL) {
        printf("%d -> ",iter->data);
        iter=iter->next;
    }
    printf("NULL\n");
}

void clear(node** head) {
    node* iter=*head;            //listedeki tum dugumleri tek fonksiyonla serbest birakir
    while (iter!=NULL) {
        node *temp=iter;
        iter=iter->next;
        free(temp);
    }
    *head=NULL;
}

int main(void) {
    node * root= NULL;

    insertAt(&root,10,0);
    insertAt(&root,5,1);
    insertAt(&root,20,3);
    insertAt(&root,15,-1);


    printf("Listedeki elemanlar:\n");
    printList(root);

    printf("Listedeki eleman silindi: \n");
    deleteAt(&root,1);
    printf("Listedeki elemanlar:\n");
    printList(root);

    clear(&root);
    printf("Liste temizlendi \n");
    printList(root);

    return 0;
}
