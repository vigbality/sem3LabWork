#include "impl.h"
#include <math.h>

int isSame(struct bst *t1, struct bst *t2){
	int len1,len2,arr1[50],arr2[50],same=1;
	inorderArr(t1, (int *)arr1, &len1); inorderArr(t2, (int *)arr2, &len2);
	for(int i=0; i<=len1;i++){
		if(arr1[i]!=arr2[i]){
			same=1; break;
		}
	}
	return same;
}

int isComplete(struct bst *t){
	int h=getHeight(t), count=0;
	getLevelCount(t,h-1,&count);
	if(count==pow(2,h-1)) return 1;
	else return 0;
}

int nodeCountRange(struct bst *t, int s, int e){
	int count=0;
	for(int i=s; i<=e; i++){
		struct bst *temp=find(t,i);
		if(temp!=NULL){
			count++;
			printf("%d ",temp->data);
		}
	}
	return count;		
}


int main(){
	struct bst *t1 = (struct bst*) malloc(sizeof(struct bst)); t1=NULL;
	t1=insertNode(t1,10);
	t1=insertNode(t1,5);
	t1=insertNode(t1,50);
	t1=insertNode(t1,1);
	t1=insertNode(t1,40);
	t1=insertNode(t1,100);

	struct bst *t2 = (struct bst*) malloc(sizeof(struct bst)); t2=NULL;
	t2=insertNode(t2,10);
	t2=insertNode(t2,5);
	t2=insertNode(t2,50);
	t2=insertNode(t2,1);
	t2=insertNode(t2,40);
	t2=insertNode(t2,100);


	if(isSame(t1,t1)) printf("Tree1 and Tree2 are identical with a set of elements\n\n");
	else printf("Tree1 and Tree2 are NOT identical with a set of elements\n\n");

	if(isComplete(t1)) printf("Tree1 is complete\n\n");
	else printf("Tree1 is NOT complete\n\n");

	printf("\nNo. of nodes in [5,45]: %d\n\n", nodeCountRange(t1,5,45));
	printf("\nNo. of nodes in [1,45]: %d\n\n", nodeCountRange(t1,1,45));
	return 0;		
}
