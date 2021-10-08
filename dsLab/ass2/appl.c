#include<stdio.h>
#include"impl.h"

int main(){
	int done=0, user;
	struct polyADT *p1=NULL, *p2=NULL;
	while(done==0){
		printf("\n\n---------------------\nEnter\n1 to ADD\n2 to MULTIPLY\n3 to SIMPLIFY\n4 to FIND DEGREE\n5 to EVALUATE\n6 to Quit\n------------------------\ninput: ");
		scanf("%d",&user);
		switch(user){
			case 1:{
				p1=NULL, p2=NULL;
				p1=createPoly(p1); p2=createPoly(p2);
				display(polyAdd(p1,p2));	
			};break;
			case 2:{
				p1=NULL, p2=NULL;
				p1=createPoly(p1); p2=createPoly(p2);
				display(polyMul(p1,p2));
			};break;
			case 3:{
				p1=NULL;
				p1=createPoly(p1);
				p1=polySimplify(p1);
				display(p1);
			};break;
			case 4:{
				p1=NULL;
				p1=createPoly(p1);
				polyDegree(p1);
			};break;
			case 5:{
				p1=NULL;
				p1=createPoly(p1);
				printf("\nValue: %d\n",polyEvaluate(p1));
			};break;
			case 6:{
				done = 1;
			};break;	
		};
	}
	return 0;
}
