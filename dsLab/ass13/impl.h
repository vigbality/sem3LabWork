#include"adt.h"
#include<stdlib.h>
void create(struct city *c){
    int temp;
    printf("Enter no. of cities: ");scanf("%d",&temp);
    c->n=temp;
    for(int i=0; i<temp;i++){
        for(int j=0; j<temp; j++){
            scanf("%d",&(c->dist[i][j]));
        }
    }
    for(int i=0; i<temp;i++){
        for(int j=0; j<temp; j++){
            c->pred[i][j]=0;
        }
    }
}
void display(struct city *c){
    for(int i=0; i<c->n;i++){
        for(int j=0; j<c->n; j++){
            printf("%d ",c->pred[i][j]);
        }
        printf("\t\t\t\t");
        for(int j=0; j<c->n; j++){
            printf("%d ",c->dist[i][j]);
        }
        printf("\n");
    }
}
void floyd(struct city *c){
    for(int k=0;k<c->n;k++){
        for(int i=0;i<c->n;i++){
            for(int j=0;j<c->n;j++){
                if(c->dist[i][j] > (c->dist[i][k]+c->dist[k][j])){
                    c->dist[i][j] = (c->dist[i][k]+c->dist[k][j]);
                    c->pred[i][j] = k+1;
                }
            }
        }
        printf("\nK=%d\n\n",k);
        display(c);
    }

}


void displayPath(struct city *c, int s, int d){
    // printf("%d ",s);
    if(c->pred[s][d]==0) printf("%d ",d);
    else{
        displayPath(c, s, c->pred[s][d]);
        displayPath(c, c->pred[s][d], d);
    }

}