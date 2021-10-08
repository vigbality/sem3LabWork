#include<stdio.h>
struct polyADT{
	int c;
	int e;
	struct polyADT *next;
};
void display(struct polyADT *p);
struct polyADT* insertEnd(struct polyADT *p, int c, int e);
struct polyADT* polyAdd(struct polyADT *p1, struct polyADT *p2);
struct polyADT* polyMUL(struct polyADT *p1, struct polyADT *p2);
struct polyADT* polySimplify(struct polyADT *p);
struct polyADT* createPoly(struct polyADT *res);
void polyDegree(struct polyADT *p);
int polyEvaluate(struct polyADT *p);