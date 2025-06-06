#include <iostream>
using namespace std;
int  doble(int num){
num*=2;
return num;

}
int main() {
    int total;
    cout << "Ingrese un numero y se calcula el doble" << endl;
    cin>>total;

   cout << doble(total) << endl;

    return 0;
}
