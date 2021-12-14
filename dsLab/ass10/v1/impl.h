#include"adt.h"
#include"queueImpl.h"
#include"stackImpl.h"
#include<stdlib.h>
void create(struct cityAdt *g){
    // int adMat[20][20]={{0,1,0,0,0,0},{0,0,1,1,0,0},{1,0,0,0,0,1},{0,0,0,0,1,0},{0,0,0,0,0,1},{0,0,0,0,0,0}};
    int temp;
    printf("\nEnter no. of vertices: ");scanf("%d",&temp);
    g->size=temp;
    for(int i=0;i<g->size;i++){
        for(int j=0;j<g->size;j++){
            printf("\nE%d%d: ",i,j);scanf("%d",&temp);
            g->mat[i][j]=temp;
        }
    }
}

void initVis(int *ptr, int size){
    for(int i=0;i<size;i++){
        ptr[i]=0;
    }
}

int getUnvisited(int *vis,int size){
    for(int i=0;i<size;i++){
        if(vis[i]==0) return i;
    }
    return -1;
}

void visit(int *ptr, int v){ 
    ptr[v]=1;
    printf("-> %c ",(char)(65+v));
}

void BFS(struct cityAdt *g){
    printf("\n\n************BFS traversal************\n");
    struct qadt q;
    initQ(&q,20);
    int *visited =(int*) malloc(sizeof(int)*20);
    initVis(visited,g->size);
    int x,y,z;
    while(1==1){
        x=getUnvisited(visited,g->size);
        if(x==-1) break;
        visit(visited,x);
        enqueue(&q,x);
        while(!isEmptyQ(&q)){
            z=dequeue(&q);            
            for(int j=0;j<g->size;j++){
                if(g->mat[z][j]==1){
                    if(visited[j]==0){
                        visit(visited,j);
                        enqueue(&q,j);
                    }
                }
            }
        }
    }
}


void DFS(struct cityAdt *g){
    printf("\n\n************DFS traversal************\n");
    struct stack s;
    initS(20,&s);
    int *visited = (int*) malloc(sizeof(int)*20);
    initVis(visited,g->size);
    int x,y,t,temp;
    while(1==1){
        x=getUnvisited(visited,g->size);
        if(x==-1) break;
        visit(visited,x);
        push(&s,x);
        while(!isEmptyS(&s)){
            t=top(&s);
            temp=0;
            for(int j=0;j<g->size;j++){
                if(g->mat[t][j]==1){
                    if(visited[j]==0){
                        visit(visited,j);
                        push(&s,j);
                        temp=1;
                        break;
                    }
                }
            }
            if(temp==0) pop(&s);
        }
}
}
