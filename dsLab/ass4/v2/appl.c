#include "impl.h"

int userChoice(){
	int x; printf("Stack 1 or 2: ");
	scanf("%d",&x);
	printf("\n");
	return x;
}
int twoStacks(struct stack *a, struct stack *b, int max){
	int temp=0, res=0;
	while(temp<=max){
		if(isEmpty(a) && isEmpty(b)) break;
		switch(userChoice()){
			case 1:{
				if(!isEmpty(a)){temp+=top(a);pop(a);res++;}
				else printf("Stack empty choose another\n");			
			};break;
			case 2:{
				if(!isEmpty(b)){temp+=top(b);pop(b);res++;}
				else printf("Stack empty choose another\n");			
			};break;
		}
	}
	return --res;
}
void takeStackInput(struct stack *s){
	int n; printf("Enter length	: ");
	scanf("%d",&n);
	printf("\n");
	int ele;
	for(int i=1;i<=n;i++){
		printf("Enter element %d: ",i);
		scanf("%d",&ele);
		printf("\n");
		push(s,ele);
	}
}

void main(){
	struct stack s1,s2;
	init(20,&s1); init(20, &s2);
	takeStackInput(&s1); display(&s1);
	 takeStackInput(&s2); display(&s2);
	int maxSum; printf("Enter maxSum value: ");
	scanf("%d",&maxSum); printf("\n");
	printf("\n\nFinal Score: %d \n\n",twoStacks(&s1,&s2,maxSum));
}
