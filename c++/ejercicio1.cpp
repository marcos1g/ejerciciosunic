#include <iostream>
using namespace std;
bool biciesto(int num){
bool a;
num%4==0&&(num%100!=0||num%400==0)?a=true:a=false;
return a; 

}
int main() {
    int total;
    cout << "Ingrese un año" << endl;
    cin>>total;

   cout << (biciesto(total)==true?"es biciesto":"no es biciesto") << endl;//no olvidar el parentesis en el ternario

    return 0;
}
