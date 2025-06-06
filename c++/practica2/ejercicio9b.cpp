#include <iostream>
#include <iomanip>
using namespace std;
static int fo=0;
static int f1=1;
int calculo(int num){
    int total=0;
    int f0=0;
    int f1=1;
    if (num<2)
     return num;
     else
for(int i=2;i<=num;i++){
total=f0+f1;
f0=f1;
f1=total;
    
}
return total;
    
}
int main(){
    int num;
    cout << "Ingrese datos" << endl;
    cin>>num;
    int dato=calculo(num);
      cout << dato << endl;

    
}