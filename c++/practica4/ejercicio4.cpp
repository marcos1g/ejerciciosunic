
#include <iostream>
#include <fstream>
#include <vector>
using namespace std;
int maximo(int vector[],int dimen){
int maximo=vector[0];
int indi=0;
for (int i=1;i<dimen; i++){
if(vector[i]>maximo){
    maximo=vector[i];
    indi=i;
}

}
return indi;
}
int main(){
int dimen=10;
int vector[dimen]{23,32,54,21,87,65,13,43,12,98};
int indmax=maximo(vector,dimen);
int maximo=vector[indmax];

cout<<"El valor maximo es"<< maximo<<" y se encuentra en la pocision"<< indmax<<endl;
    return 0;
}