#include "impl.h"


struct empData new(char c, int sal){
    static struct empData new;
    new.id=c; new.salary=sal;
    return new;
}

int main(){
	struct heap h;
    init(&h,10);
    del(&h);
    display(&h);
    insert(&h,new('A',15000));
    insert(&h,new('K',12000));
    insert(&h,new('R',4000));
    insert(&h,new('T',3500));
    insert(&h,new('L',4600));
    insert(&h,new('P',6000));
    insert(&h,new('Y',8600));
    display(&h);
    struct empData d=del(&h);
    printf("item deleted: (%c, %d)\n",d.id,d.salary);
    display(&h);
    return 0;
}
