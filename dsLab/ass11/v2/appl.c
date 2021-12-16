#include"impl.h"
int binS2occ(int *arr, int l, int r, int x, int k){
    if(r >= l){
        int mid=l+(r-l)/2;
        if(arr[mid]==x){
            if(arr[mid-1]==x) return binS2occ(arr, l, mid - 1, x,k);
            if(arr[mid+k-1]==x) return mid+k-1;
            else return -1;
        }
        else if(arr[mid] > x) return binS2occ(arr, l, mid - 1, x,k);
        else return binS2occ(arr, mid + 1, r, x,k);
    }
    return -1;
}

int bSearch2occ(struct nadt *n, int key,int k){
    return binS2occ(returnSorted(n->arr,n->size), 0, n->size-1, key,k);
}

void findFreq(struct nadt *n, int key){
    int count;
    for(int i=0; i<n->size; i++){
        if(n->arr[i]==key) count++;
    }
    printf("Frequency: %d\n",count);
}

void isSame(struct nadt *n1, struct nadt *n2){
    int same=1;
    for(int i=0; i<n1->size; i++){
        if(lSearch(n2, n1->arr[i])==-1){
            same=0; break;
        }
    }
    if(same) printf("same\n");
    else printf("not same\n");
}


void pairDiff(struct nadt *n, int d){
    int a,b1,b2;
    for(int i=0; i<n->size; i++){
        a=n->arr[i];
        b1=lSearch(n, a+d);
        b2=lSearch(n, a-d);
        if(b1!=-1) printf("%d %d\n",a,n->arr[b1]);
        if(b2!=-1) printf("%d %d\n",a,n->arr[b2]);
    }
}




int main(){
    // int arr[50]={4,7,3,2,1,9,8,7,3,4};
    int arr[50]={1,3,5,7,9,9,9,9,9,9,9,10,10,13};
    struct nadt n;
    init(&n, 14);
    insertElements(&n,arr);
    display(&n);
    printf("found at %d \n",bSearch2occ(&n,13,2));
    // pairDiff(&n,3);
    
}