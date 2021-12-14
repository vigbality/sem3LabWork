#include"impl.h"

int main(){
    int arr[50]={4,7,3,2,1,9,8,7,3,4};
    struct nadt n;
    init(&n, 10);
    insertElements(&n,arr);

    display(&n);
    printf("Using linear search: \n");
    printf("Element %d found at %d\n",9,lSearch(&n,9));
    printf("Element %d found at %d\n",16,lSearch(&n,16));
    printf("Element %d found at %d\n",7,lSearch(&n,7));

    printf("\n\nUsing binary search: (index with respect to sorted array)\n");
    printf("Element %d found at %d\n",9,bSearch(&n,9));
    printf("Element %d found at %d\n",16,bSearch(&n,16));
    printf("Element %d found at %d\n",7,bSearch(&n,7));
}