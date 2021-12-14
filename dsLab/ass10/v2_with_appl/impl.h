#include"adt.h"
#include"queueImpl.h"
#include"stackImpl.h"
#include<stdlib.h>
void create(struct cityAdt *g){
    // int adMat[20][20]={{0,1,0,0,0,0},{0,0,1,1,0,0},{1,0,0,0,0,1},{0,0,0,0,1,0},{0,0,0,0,0,1},{0,0,0,0,0,0}};
    int adMat[20][20]={{0,1,0,0,0},{1,0,1,0,0},{0,1,0,0,0},{0,0,0,0,1},{0,0,0,1,0}};
    // int temp;
    // printf("\nEnter no. of vertices: ");scanf("%d",&temp);
    // g->size=temp;
    g->size=5;
    for(int i=0;i<g->size;i++){
        for(int j=0;j<g->size;j++){
            // printf("\nE%d%d: ",i,j);scanf("%d",&temp);
            // g->mat[i][j]=temp;
            g->mat[i][j]=adMat[i][j];
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
    // printf("-> %c ",(char)(65+v));
    // printf(" /%d/ ",v);
}

// void BFS(struct cityAdt *g, int start){
//     printf("\n\n************BFS traversal************\n");
//     struct qadt q;
//     initQ(&q,20);
//     int *visited =(int*) malloc(sizeof(int)*20);
//     initVis(visited,g->size);
//     int x,y,z;
//     int first=1;
//     while(1==1){
//         x=getUnvisited(visited,g->size);
//         if(x==-1) break;
//         if(first!=1){
//             visit(visited,x);
//             enqueue(&q,x);
//         }
//         if(first==1 && start!=0){
//             visit(visited,start);
//             enqueue(&q,start);
//         }
//         first=0;
//         while(!isEmptyQ(&q)){
//             z=dequeue(&q);            
//             for(int j=0;j<g->size;j++){
//                 if(g->mat[z][j]==1){
//                     if(visited[j]==0){
//                         visit(visited,j);
//                         enqueue(&q,j);
//                     }
//                 }
//             }
//         }
//     }
// }


// void DFS(struct cityAdt *g, int start){
//     printf("\n\n************DFS traversal************\n");
//     struct stack s;
//     initS(20,&s);
//     int *visited = (int*) malloc(sizeof(int)*20);
//     initVis(visited,g->size);
//     int x,y,t,temp;
//     int first=1;
//     while(1==1){
//         x=getUnvisited(visited,g->size);
//         if(x==-1) break;
//         if(first!=1){
//             visit(visited,x);
//             push(&s,x);
//         }
//         if(first==1 && start!=0){
//             visit(visited,start);
//             push(&s,start);
//         }
//         first=0;
//         while(!isEmptyS(&s)){
//             t=top(&s);
//             temp=0;
//             for(int j=0;j<g->size;j++){
//                 if(g->mat[t][j]==1){
//                     if(visited[j]==0){
//                         visit(visited,j);
//                         push(&s,j);
//                         temp=1;
//                         break;
//                     }
//                 }
//             }
//             if(temp==0) pop(&s);
//         }
// }
// }


int *DFSreturnsVisited(struct cityAdt *g, int start){
    struct stack s;
    initS(20,&s);
    int *visited = (int*) malloc(sizeof(int)*20);
    initVis(visited,g->size);
    int x,y,t,temp;
    visit(visited,start);
    push(&s,start);
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
    return visited;
}
