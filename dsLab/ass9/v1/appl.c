#include "impl.h"


int main(){
	struct heap h;
    init(&h,20);
    del(&h);
    display(&h);
    insert(&h,14);
    insert(&h,16);
    insert(&h,22);
    insert(&h,11);
    insert(&h,9);
    insert(&h,18);
    insert(&h,10);
    insert(&h,7);
    insert(&h,4);
    insert(&h,1);
    display(&h);
    printf("item deleted: %d",del(&h));
    display(&h);
    return 0;
}
