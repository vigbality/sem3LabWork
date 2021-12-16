#include"impl.h"
int main(){
    struct city c;
    create(&c);
    display(&c);
    floyd(&c);
    displayPath(&c,0,2);
}