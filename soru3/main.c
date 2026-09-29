#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node *next;
}node;

node* findMiddle(node* head) {
    if (head == NULL) {
        return NULL;
    }
    node* slow = head;  //1
    node* fast = head;  //2

    while (fast != NULL && fast->next != NULL) {  //fast once sona vardıgından
        slow = slow->next;
        fast = fast->next->next;
    }

    return slow;
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
    node* s1 = (node*)malloc(sizeof(node));
    node* s2 = (node*)malloc(sizeof(node));
    node* s3 = (node*)malloc(sizeof(node));
    node* s4 = (node*)malloc(sizeof(node));
    node* s5 = (node*)malloc(sizeof(node));

    s1->data = 30; s1->next = s2;
    s2->data = 40; s2->next = s3;
    s3->data = 20; s3->next = s4;
    s4->data = 50; s4->next = s5;
    s5->data = 70; s5->next = NULL;

    node* root=s1;
    printf("Listedeki elemanlar:\n");
    printList(root);

    node* orta = findMiddle(root);
    if (orta != NULL) {
        printf("Ortadaki dugumun degeri: %d\n\n", orta->data);
    }

    clear(&root);
    printf("Liste temizlendi \n");
    printList(root);

    return 0;
}
