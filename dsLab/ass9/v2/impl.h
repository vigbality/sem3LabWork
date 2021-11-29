#include"adt.h"
void init(struct heap *h, int size){
    h->size=size;
    h->curr=0;
}

void display(struct heap *h){
    if(h->curr==0) printf("\nHeap is EMPTY, nothing to display!\n");
    else{
        printf("\n------------------\n");
        for(int i=1;i<=h->curr;i++) printf("(%c, %d) ",h->arr[i].id, h->arr[i].salary);
        printf("\n------------------\n\n");
    }  
}

void  insert(struct heap *h, struct empData data){
    if(h->curr==h->size) printf("\nHeap is FULL, cant insert!\n");
    else{
        h->curr++; h->arr[h->curr]=data;
        for(int i=h->curr;h->arr[i/2].salary>data.salary;i/=2){
            h->arr[i]=h->arr[i/2];
            h->arr[i/2]=data;
        }
    }
}

struct empData del(struct heap *h){
    if(h->curr==0){
        printf("\nHeap is EMPTY, cant delete!\n");
        struct empData dummy; return dummy;
    }
    else{
        struct empData min=h->arr[1], temp;
        int child;
        h->arr[1]=h->arr[h->curr--];
        for(int i=1; 2*i<=h->curr; i=child){
            if(h->arr[i].salary < h->arr[2*i].salary && h->arr[i].salary < h->arr[2*i+1].salary) break;
            else{
                child = (h->arr[2*i].salary < h->arr[2*i+1].salary) ? 2*i : 2*i+1;
                temp=h->arr[i];
                h->arr[i]=h->arr[child];
                h->arr[child]=temp;
            }
        }
        return min;
    }
}