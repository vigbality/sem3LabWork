#include"impl.h"
int main(){
    struct city c;
    create(&c);
    display(&c);
    floyd(&c);
    printf("\n\n\ngh\n");
    displayPath(&c,3,1);
}