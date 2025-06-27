#include <iostream>
#include <fstream>
#include <vector>

using namespace std;
void carga(int vector[],int dim){
    int con=0;
    int num;
    int acen=vector[0];
    cout<<"Ingrese 8 numeros de forma acendente"<<endl;
    while(con<8){
        bool valor=true;
        while(valor){
        cin>>num;
        if(num>acen){
            vector[con]=num;
            acen=num; 
            con++;
            valor=false;
        }else{
            cout<<"El valor ingresado no es menor al anterior ingrese el dato nuevamente"<<endl;
            valor=false;
 }
    }
}
}
void diferencia(int vec[],int dim){
    int difmax= vec[1]-vec[0];
    int el1=1;
    int el2=2;
for(int i=2;i<dim;i++){
int dif=vec[i]-vec[i-1];
if(dif>difmax){
difmax=dif;
el1=i;
el2=i-1;
}
}
cout<<"La diferencia maxima entre elementos susecivos es de"<< difmax<<" y se encuentra entre los elementos"<<el1<<"y"<<el2<<endl;

}
int main()
{
int dim=8;
int vec[dim]{0};
carga(vec,dim);
for(auto nose:vec){
 cout<<nose<<" ";

}
diferencia(vec,dim);
}