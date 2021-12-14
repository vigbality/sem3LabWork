#include"impl.h"

int main(){
    int arr[50]={4,7,3,2,1,9,8,7,3,4};
    struct nadt n;
    init(&n, 10);
    insertElements(&n,arr);

    display(&n);
    printf("Using selection sort: \n");
    selSort(&n);
    display(&n);

    insertElements(&n,arr);
    display(&n);
    printf("Using shell sort: \n");
    shellSort(&n);
    display(&n);
}