#include <iostream>
#include <iomanip>
using namespace std;

int factorial(int num){
    if(num<=2)
    return num;
    else
    return num*factorial(num-1);
    
}
int main(){
    int num;
    cout << "Ingrese datos" << endl;
    cin>>num;
    int dato=factorial(num);
      cout << dato << endl;

    
}