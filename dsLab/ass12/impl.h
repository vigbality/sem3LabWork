#include"adt.h"
#include<stdlib.h>
void init(struct nadt *n, int size){
    n->size=size;
}

void insertElements(struct nadt *n, int x[]){
    for(int i=0;i<n->size;i++) n->arr[i]=x[i];
}


void selSort(struct nadt *n){
    int min,temp;
    for(int i=0;i<n->size;i++){
        min=i;
        for(int j=i+1;j<n->size;j++){
            if(n->arr[j]<n->arr[min]) min=j;
        }
        temp=n->arr[i];
        n->arr[i]=n->arr[min];
        n->arr[min]=temp;
    }
}

void shellSort(struct nadt *n){
    int curr,j,gap = n->size/2;
    while(gap>0){
        for(int i=gap; i<n->size; i++){
            curr=n->arr[i];
            j=i-gap;
            while(j>=0 && n->arr[j]>curr){
                n->arr[j+gap] = n->arr[j];
                j-=gap;
            }
            n->arr[j+gap]=curr;
        }
        gap=gap/2;
    }
}



void display(struct nadt *n){
    printf("\n");
    for(int i=0; i<n->size; i++) printf("%d ",n->arr[i]);
    printf("\n");
}
