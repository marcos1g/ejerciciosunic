#include <iostream>
#include <iomanip>
using namespace std;

int factorial(int num){
    int total=1;
   for(int i=1;i<=num;i++){
total=total*i;
}
return total;
    }
int main(){
    int num;
    cout << "Ingrese datos" << endl;
    cin>>num;
    int dato=factorial(num);
      cout << dato << endl;

    
}