#include<iostream>
using namespace std;
//se inicializa el template para despues poder darle los valores requeridos, asi evitando sobreesritura de codigo
template< typename T >
 void suma(T a,T b){
cout << a << " + " << b << " = " << a + b << endl;
}
template <typename T>
void mostrardatos(T precio,int (*criterio)(T a)){
int costo=criterio(precio);
if (costo==1){
cout<<"El auto es caro";
}else{
    cout<<"El auto no es caro";
}
}
template<typename T>int Costo(T precio){
if(precio>=500){
    return 1;
}
else{
        return 0;
}

}
int main(){
int a=5,b=6;
suma(a,b);
suma(3.4,5.4);
suma<double>(3.5,7);//se pasan los parametros como double;
suma<int>(3.6,6);//se pasan los parametros como int;
suma<string>("holas","godines");//"holas" no se considera string sino como char[] que no tiene definidas las funciones + por
// lo tanto hay que aclaralse que se trata de strings con <string>
mostrardatos(500.00,Costo);

}