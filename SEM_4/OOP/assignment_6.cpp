#include<iostream>
#include<fstream>
using namespace std;
class Student{
    int id;
    string name;
    int age;
    public:
    Student(){
        id=0;
        name="XYZ";
        age=20;
    }
    void readfile(ifstream &fin){
        fin>>id>>name>>age;
    }

    void writefile(ofstream &fout){
    
        fout<<id<<" "<<name<<" "<<age;

    }
    void display(){
        cout<<id<<" "<<name<<" "<<age;
    }
};
int main(){

 
        ifstream fin("input.txt");
        if(!fin.is_open()){
            cout<<"File is not open ";
        }
        ofstream fout("output.txt");
        if(!fout.is_open()){
           cout<<"File is not open ";
        }
    Student s[3];
        int i=0;
        while((!fin.eof()) && i < 3){
            cout <<"Executing loop for " << i << " time";
            s[i].readfile(fin);
       s[i].writefile(fout);
        s[i].display();
        fout<<endl;
         i++;

        }
   
        fin.close();
        fout.close();
        

}