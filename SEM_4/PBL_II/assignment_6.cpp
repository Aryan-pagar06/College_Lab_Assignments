#include<iostream>
using namespace std;
class Knapsack{
int n;
int c;
int w[20];
int p[20];
public:
void accept();
void display();
void ks();
};

void Knapsack::accept(){
    cout<<"Enter capacity of knapsack"<<endl;
    cin>>c;
    cout<<"Enter no. of items "<<endl;
    cin>>n;
    cout<<"Enter weight and profit"<<endl;
    for(int i=0;i<n;i++){
        cin>>w[i]>>p[i];
    }
}
void Knapsack::display(){

    cout<<"Weights and Profits of items :"<<endl;
    for(int i=0;i<n;i++){
        cout<<"Item "<<i<<": "<<w[i]<<" "<<p[i]<<endl;
    }
}

void Knapsack::ks(){
    int b[21][21]={0};

    for(int i=1;i<=n;i++) {
        for(int j=0;j<=c;j++){
            if(w[i-1]<=j){
                b[i][j]=max(b[i-1][j-w[i-1]]+p[i-1],b[i-1][j]);
            }
            else{
                b[i][j]=b[i-1][j];
            }
        }
    }
    int i=n,k=c;
    while(i>0&&k>0){
        if(b[i][k]!=b[i-1][k]){
            cout<<i<<" ";
            i--;
            k=k-w[i];
        }
        else{
            i--;
        }
    }
    cout<<endl;

    cout<<"Maximum profit is : "<<b[n][c];
}
int main(){
    Knapsack k;
    k.accept();
    k.display();
    k.ks();
    
}