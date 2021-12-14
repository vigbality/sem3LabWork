#include<stdio.h>
#include"adt.h"
#include<string.h>
void init(struct arradt *ptr){
	ptr->n=-1;
}
void insertFront(struct arradt *ptr, struct student ele){
	if(ptr->n==-1){
		ptr->n++;
		ptr->data[0]=ele;
	}
	else{
		ptr->n++;
		for(int i=ptr->n;i>0;i--){
			ptr->data[i]=ptr->data[i-1];
		}
		ptr->data[0]=ele;
	}
}


void insertEnd(struct arradt *ptr, struct student ele){
	ptr->n++;
	ptr->data[ptr->n]=ele;
}


void insertRegNo(struct arradt *ptr, struct student ele, int regno){
	int mid;
	for(int i=0;i<=ptr->n;i++){
		if(ptr->data[i].regno==regno){
			mid=i; break;
		}
	}
	ptr->n++;
	for(int i=ptr->n;i>mid+1;i--){
		ptr->data[i]=ptr->data[i-1];
	}
	ptr->data[mid+1]=ele;
}


void searchName(struct arradt *ptr, char *name){
	int found;
	for(int i=0;i<=ptr->n;i++){
		if(strcmp(ptr->data[i].name,name)==0){
			found=i; break;
		}
	}
	struct student temp=ptr->data[found];
	printf("\nRegno: %ld",temp.regno);
	printf("\nname: %s",temp.name);
	printf("\nm1: %d",temp.m1);
	printf("\nm2: %d",temp.m2);
	printf("\nm3: %d",temp.m3);
	printf("\ntot: %d",temp.tot);
	printf("\nresult: %c",temp.result);
	printf("\n\n");

}


void del(struct arradt *ptr, int regno){
	int mid;
	for(int i=0;i<=ptr->n;i++){
		if(ptr->data[i].regno==regno){
			mid=i; break;
		}
	}
	ptr->n--;
	for(int j=mid;j<=ptr->n;j++){
		ptr->data[j]=ptr->data[j+1];
	}
}

void computeResult(struct arradt *ptr){
	struct student temp;
	for(int i=0;i<=ptr->n;i++){
		temp=ptr->data[i];
		if(temp.m1>40 && temp.m2>40 && temp.m3>40) ptr->data[i].result='P';
		else ptr->data[i].result='F';
	}
}



void display(struct arradt *ptr){
	for(int i=0;i<=ptr->n;i++){
		printf("\n**************************\n");
		printf("\nRegno: %ld",ptr->data[i].regno);
		printf("\nname: %s",ptr->data[i].name);
		printf("\nm1: %d",ptr->data[i].m1);
		printf("\nm2: %d",ptr->data[i].m2);
		printf("\nm3: %d",ptr->data[i].m3);
		printf("\ntot: %d",ptr->data[i].tot);
		printf("\nresult: %c",ptr->data[i].result);
		printf("\n**************************\n");
		printf("\n\n");
	}
}
