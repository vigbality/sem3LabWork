#include"impl.h"

void pathExists(struct cityAdt *g,int s, int d){
    int *arr=DFSreturnsVisited(g,s);
    if(arr[d]==1) printf("Path exists");
    else printf("Path not exists");
}
void findConnected(struct cityAdt *g){
    int *vertices = (int*) malloc(sizeof(int)*g->size);
    for(int i=0;i<g->size;i++) vertices[i]=0;
    int done=0;
    int *temp;
    while(done!=1){
        for(int j=0;j<g->size;j++){
            if(vertices[j]==0){
                temp=DFSreturnsVisited(g,j);
                printf("\n");
                for(int k=0;k<g->size;k++){
                    if(temp[k]==1) printf(" -%d- ",k);
                    vertices[k]+=temp[k];
                }
                done=1;
                for(int x=0;x<g->size;x++){
                    if(vertices[x]==0){
                        done=0; break;
                    }
                }
            }
        }
    }
}
int main(){
    struct cityAdt g;
    create(&g);
    // BFS(&g,0);
    // int *arr;
    // arr=DFSreturnsVisited(&g,0);
    // printf("\n\n");
    // for(int i=0;i<g.size;i++) printf(" /%d/ ",arr[i]);
    pathExists(&g,3,2);
    pathExists(&g,2,1);
    findConnected(&g);

}