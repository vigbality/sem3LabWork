#include "impl.h"


struct word *getPair(char *word, char *meaning){
	struct word *r=(struct word *)malloc(sizeof(struct word));
	r->word=word; r->meaning = meaning;
	return r;
}

int main(){
	struct avl *t = (struct avl*) malloc(sizeof(struct avl)); t=NULL;
	t=insertNode(t,*getPair("bisk","soup"));
	t=insertNode(t,*getPair("cite","refer"));
	t=insertNode(t,*getPair("boom","sound"));
	t=insertNode(t,*getPair("able","oppurtunity"));
	t=insertNode(t,*getPair("aged","old"));
	t=insertNode(t,*getPair("crew","group of people"));
	inorder(t); printf("\n\n\n\n");
	printf("enter word to search for meaning: ");
	char word[20];
	scanf("%s",word);
	printf("Input: %s\n",word);
	printf("output: %s\n",find(t, word)->data.meaning);	
}
