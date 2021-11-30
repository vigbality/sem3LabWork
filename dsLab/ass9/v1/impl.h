#include"adt.h"
void init(struct heap *h, int size){
    h->size=size;
    h->curr=0;
}

void display(struct heap *h){
    if(h->curr==0) printf("\nHeap is EMPTY, nothing to display!\n");
    else{
        printf("\n------------------\n");
        for(int i=1;i<=h->curr;i++) printf("%d ",h->arr[i]);
        printf("\n------------------\n\n");
    }
    
}

void  insert(struct heap *h, int data){
    if(h->curr==h->size) printf("\nHeap is FULL, cant insert!\n");
    else{
        h->curr++; h->arr[h->curr]=data;
        for(int i=h->curr;h->arr[i/2]>data;i/=2){
            h->arr[i]=h->arr[i/2];
            h->arr[i/2]=data;
        }
    }
}

int del(struct heap *h){
    if(h->curr==0){
        printf("\nHeap is EMPTY, cant delete!\n");
        return -1;
    }
    else{
        int min=h->arr[1], child, temp;
        h->arr[1]=h->arr[h->curr--];
        for(int i=1; 2*i<=h->curr; i=child){
            if(h->arr[i] < h->arr[2*i] && h->arr[i] < h->arr[2*i+1]) break;
            else{
                child = (h->arr[2*i] < h->arr[2*i+1]) ? 2*i : 2*i+1;
                temp=h->arr[i];
                h->arr[i]=h->arr[child];
                h->arr[child]=temp;
            }
        }
        return min;
    }
}