#include<iostream>
using namespace std;
class graph{
    int vertices;
    int cost[20][20];
    int edges;
    public:
    void acceptg();
    void displayg();
    void prims(int startv);

};
void  graph::acceptg(){
    cout<<"Enter no. of vertices : ";
    cin>>vertices;
    cout<<"Enter no. of edges : ";
    cin>>edges;
    for(int i=0;i<vertices;i++){
        for(int j=0;j<vertices;j++){
            cost[i][j]=INT_MAX;
        }
    }
    for(int i=0;i<edges;i++){
        cout<<"Enter souce vertex,destination vertex  and cost of edge "<<endl;
        int sv,dv,coste;
        cin>>sv>>dv>>coste;
        cost[sv][dv]=coste;
        cost[dv][sv]=coste;
    }
    
}
void  graph::displayg(){
    cout<<endl<<" Cost matrix :"<<endl;
    for(int i=0;i<vertices;i++){
        for(int j=0;j<vertices;j++){
            cout<<cost[i][j]<<" ";
        }
        cout<<endl;
    }

}
void  graph::prims(int startv){
    int mincost=0;
    // int nearest[vertices];
    // int t[vertices-1][3];
    int nearest[20];
    int t[20][3];
    nearest[startv]=-1;
    for(int i=0;i<vertices;i++){
        if(i!=startv){
            nearest[i]=startv;
        }
    }
    int r=0;
    for(int i=1;i<vertices;i++){
        int mini=INT_MAX;
        int j=0;
        for(int k=0;k<vertices;k++){
            if(nearest[k]!=-1&&cost[k][nearest[k]]<mini){
                j=k;
                mini=cost[k][nearest[k]];
            }
        }
        t[r][0]=nearest[j];
        t[r][1]=j;
        t[r][2]=mini;
        r++;
        mincost=mincost+cost[j][nearest[j]];
        nearest[j]=-1;

        for(int k=0;k<vertices;k++){
            if(nearest[k]!=-1&&cost[k][nearest[k]]>cost[k][j]){
                nearest[k]=j;
            }
        }
    }
    cout<<"Minimum cost is : "<<mincost<<endl;

}


int main(){
    graph g;
    g.acceptg();
    g.displayg();
    cout<<"Enter source vertex : ";
    int sv;
    cin>>sv;
    g.prims(sv);
}