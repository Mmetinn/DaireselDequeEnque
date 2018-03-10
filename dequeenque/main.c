
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node{
    int data;
    struct node *next;
}liste;
liste *first=NULL,*end=NULL,*temp,*temp2;

void dequeue();
void enqueue(liste *);
void listele();
int main(){
    int deger;
    liste *giden;
    char secim;
    puts("eklemek icin e\ncikarmak icin c\nlistelemek icin l\n");
    while(1==1){
        secim=getchar();
        switch(secim){
            case 'e':
                puts("eklemek istediginiz degeri giriniz::");
                scanf("%d",&deger);
                giden=(liste *)malloc(sizeof(liste));
                giden->data=deger;
                enqueue(giden);
                puts("ekleme islemi tamamlanmistir..");
                break;
            case 'c':
                dequeue();
                if(first!=NULL)
                    puts("cikarma islemi tamamlanmistir..");
                break;
            case 'l':
                puts("LISTE");
                listele();
                break;
        }
    }
    return 0;
}
void enqueue(liste *gelen){
    if(first==NULL){
        first=gelen;
        first->next=first;
        end=first;
    }
    else{
        temp=first;
        while(temp->next!=first){
            temp=temp->next;
        }
        temp->next=gelen;
        gelen->next=first;
        end=gelen;
    }
}
void dequeue(){
    if(first==NULL){
        puts("KUYRUK BOS CIKARMA ISLEMI YAPILAMAZ");
    }
    else if(first==end){
        first=NULL;
        end=NULL;
    }
    else{
        temp=first;
        first=first->next;
        end->next=first;
        free(temp);
    }
}
void listele(){
    temp=first;
    if(first==NULL && end==NULL){
        puts("KUYRUK BOS");
    }
    else{
        printf("---------%d\n",temp->data);
        temp=temp->next;
        while(temp!=first){
                printf("---------%d\n",temp->data);
                temp=temp->next;
        }
    }


}
