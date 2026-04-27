// NQueens

#include<iostream>
using namespace std;

int x[20];

int abs_val(int a){
    if(a>0) return -a;
    return a;

}
int place(int k,int col){
    for(int j=1;j<=k-1;j++){
        if((x[j]==col)|| (abs_val(x[j]-col))==abs_val(j-k))
        return 0;
    }
    return 1;
}

void nqueen(int k,int n){
    for(int colm=1;colm<=n;colm++){
        if(place(k,colm)){
            x[k]=colm;
            if(k==n){
                for(int i=1;i<=n;i++){
                    cout<<x[i]<<" ";
                }
                cout<<endl;
            }
            else{
                nqueen(k+1,n);
            }
        }
    }
}
int main(){
    int n;
    cout<<"enter no of queens: ";
    cin>>n;
    nqueen(1,n);
    return 0;
}