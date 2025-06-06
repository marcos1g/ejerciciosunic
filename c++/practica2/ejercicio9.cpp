#include <iostream>
#include <iomanip>
using namespace std;

int calculo(int num){
    if(num<2)
    return num;
    else
    return calculo(num-1)+calculo(num-2);
    
}
int main(){
    int num;
    cout << "Ingrese datos" << endl;
    cin>>num;
    int dato=calculo(num);
      cout << dato << endl;

    
}
