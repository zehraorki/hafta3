#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node *next;
}node;

void addOrdered(node** head, int value) {
    node*yeni=(node*)malloc(sizeof(node));
    yeni->data=value;
    yeni->next=NULL;

    if (*head==NULL || value<(*head)->data) {     //listenin bos olmasi veya yeni elemanin ilk elemandan kucuk olmasi durumunda calisir
        yeni->next=*head;
        *head=yeni;
    }else {
        node*iter=*head;
        while (iter->next!=NULL && iter->next->data<value) {     //elemanlarin sirali olmasi icin data lar kontrol edilip dogru yer aranir
            iter=iter->next;
        }
        yeni->next=iter->next;    //Yeni düğümün nexti, kendisinden büyük olan bir sonraki düğümün adresi yapilir
        iter->next=yeni;          //while bitmeden onceki son datanin nextine yeni eleman eklenir, bu yeni elemanin nexti ise kendisinden buyuk ilk elemandir
    }
}
void removeNode(node** head, int value) {
    if (*head==NULL) {
        return;
    }
    if ((*head)->data==value) {     //ilk eleman silinmek istenirse
        node*temp=*head;
        *head=(*head)->next;
        free(temp);
        return;
    }
    node* iter = *head;
    while (iter->next != NULL && iter->next->data != value) {
        iter = iter->next;
    }
    if (iter->next!=NULL) {
        node*temp=iter->next;
        iter->next=iter->next->next;
        free(temp);
    }
}

int count(node *head) {
    int total=0;            //listede gezinme işlemi yardimiyla eleman sayisini döngü kullanarak hesaplar
    node*iter =head;
    while (iter!=NULL) {
        total++;
        iter=iter->next;
    }
    return total;
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
    int sayilar[] = {23, 11, 5, 9, 6, 4, 12, 24};
    int n = sizeof(sayilar) / sizeof(sayilar[0]);

    for (int i = 0; i < n; i++) {
        addOrdered(&root, sayilar[i]);
    }
    printf("Listedeki dugum sayisi: %d\n",count(root));
    printf("Listedeki elemanlar:\n");
    printList(root);

    printf("Listedeki eleman silindi: \n");
    removeNode(&root,11);
    printf("Yeni dugum sayisi: %d\n",count(root));
    printf("Listedeki elemanlar:\n");
    printList(root);

    printf("Liste temizlendi \n");
    clear(&root);
    printf("Son dugum sayisi: %d\n",count(root));
    return 0;
}



