#include<stdio.h>
#include<stdlib.h>
#include"adt.h"
void display(struct polyADT *p){
	struct polyADT *ptr = p;
	printf("\n------------\n");
	while(ptr!=NULL){
		printf("%dx^%d ",ptr->c,ptr->e);
		if(ptr->next!=NULL && ptr->next->c>0) printf("+ ");
		ptr=ptr->next;	
	}
	printf("\n------------\n");
}

struct polyADT* insertEnd(struct polyADT *p, int c, int e){
	struct polyADT *temp=(struct polyADT*) malloc(sizeof(struct polyADT));
	temp->next=NULL; temp->c=c; temp->e=e;
	if(p==NULL) p=temp;
	else{
		struct polyADT *ptr=p;
		while(ptr->next!=NULL) ptr=ptr->next;
		ptr->next=temp;
	}
	return p;
}

struct polyADT* polyAdd(struct polyADT *p1, struct polyADT *p2){
	static struct polyADT *p3 = NULL;
	struct polyADT *ptr1=p1, *ptr2=p2;
	while(ptr1!=NULL && ptr2!=NULL){
		if(ptr1->e > ptr2->e){
			p3=insertEnd(p3, ptr1->c, ptr1->e); ptr1 = ptr1->next;
		}
		else if(ptr2->e > ptr1->e){
			p3=insertEnd(p3, ptr2->c, ptr2->e); ptr2 = ptr2->next;
		}
		else{
			p3=insertEnd(p3, ptr1->c + ptr2->c, ptr1->e);
			ptr1 = ptr1->next; ptr2 = ptr2->next;
		}
	}
	while(ptr1!=NULL){
		p3=insertEnd(p3, ptr1->c, ptr1->e); ptr1 = ptr1->next;
	}
	while(ptr2!=NULL){
		p3=insertEnd(p3, ptr2->c, ptr2->e); ptr2 = ptr2->next;
	}
	return p3;
}


struct polyADT* polySimplify(struct polyADT *p){
	struct polyADT *res=(struct polyADT*)malloc(sizeof(struct polyADT)),*temp;
	res->next=NULL;
	while(p!=NULL){
		temp=res;
		while(temp->next!=NULL){
			if(temp->next->e==p->e){
				temp->next->c+=p->c;break;
			}
			else if(temp->next->e<p->e){
				struct polyADT *new=(struct polyADT*)malloc(sizeof(struct polyADT));
				new->c=p->c; new->e=p->e;
				new->next=temp->next;
				temp->next=new; break;
			}
			else{
				temp=temp->next;
			}
		}
		if(temp->next==NULL){
			struct polyADT *new=(struct polyADT*)malloc(sizeof(struct polyADT));
			new->c=p->c; new->e=p->e; new->next=NULL;
			temp->next=new;
		}
		p=p->next;	
	}
	return res->next;
}

struct polyADT* polyMul(struct polyADT *p1, struct polyADT *p2){
	struct polyADT *p3 = NULL;
	struct polyADT *ptr1=p1, *ptr2=p2;
	while(ptr1!=NULL){
		ptr2=p2;
		while(ptr2!=NULL){
			p3=insertEnd(p3, ptr1->c * ptr2->c, ptr1->e + ptr2->e); ptr2 = ptr2->next;
		}
		ptr1 = ptr1->next;
	}
	display(p3);
	printf("After simplifying: \n");
	return polySimplify(p3);
}

struct polyADT* createPoly(struct polyADT *res){
	printf("\n\nEnter the number of terms: ");
	int x; scanf("%d",&x);
	int c,e;
	for(int i=0; i<x; i++){
		printf("\nEnter coeff and exp sep by space: ");
		scanf("%d %d",&c,&e);
		res=insertEnd(res,c,e);
	}
	return res;
}

void polyDegree(struct polyADT *p){
	int deg;
	while(p!=NULL){
		if(p->e>deg) deg=p->e;
		p=p->next;
	}
	printf("\n----------\nDegree: %d\n-----------\n",deg);
}

int polyEvaluate(struct polyADT *p){
	int x; printf("\nEnter x value: ");
	scanf("%d",&x);
	int res;
	while(p!=NULL){
		int pow=1, i=p->e;
		while(i!=0){
			pow*=x;i--;
		}
		res+=p->c*pow;
		p=p->next;
	}
	return res;
}