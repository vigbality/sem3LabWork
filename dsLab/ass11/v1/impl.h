#include"adt.h"
#include<stdlib.h>
void init(struct nadt *n, int size){
    n->size=size;
}

void insertElements(struct nadt *n, int x[]){
    for(int i=0;i<n->size;i++) n->arr[i]=x[i];
}
int lSearch(struct nadt *n, int key){
    int res=-1;
    for(int i=0;i<n->size;i++){
        if(n->arr[i]==key){
            res=i;
            break;
        }
    }
    return res;
}


int binS(int *arr, int l, int r, int x){
    if(r >= l){
        int mid=l+(r-l)/2;
        if(arr[mid]==x) return mid;
        else if(arr[mid] > x) return binS(arr, l, mid - 1, x);
        else return binS(arr, mid + 1, r, x);
    }
    return -1;
}

int *returnSorted(int arr[], int size){
    int *res=(int*)malloc(sizeof(int)*size);
    for(int x=0;x<size;x++) res[x]=arr[x];
    int min,temp;
    for(int i=0;i<size;i++){
        min=i;
        for(int j=i+1;j<size;j++){
            if(res[j]<res[min]) min=j;
        }
        temp=res[i];
        res[i]=res[min];
        res[min]=temp;
    }
    return res;
}



int bSearch(struct nadt *n, int key){
    return binS(returnSorted(n->arr,n->size), 0, n->size-1, key);
}

void display(struct nadt *n){
    printf("\n");
    for(int i=0; i<n->size; i++) printf("%d ",n->arr[i]);
    printf("\n");
}
