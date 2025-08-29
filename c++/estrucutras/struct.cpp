#include <iostream>
using namespace std;
#include <string>
struct Frestyler {
string nombre;//"Atributos de la estructura"
int batallas;
int Bganadas;
};
ostream& operator << (ostream &os, const Frestyler& raper)
{
	os << raper.nombre << "\t" << raper.batallas << "\t\t"<< raper.Bganadas;
	return os;
}
template<typename T>void mostrar(T vec[], int dim){
for(int i=0;i<dim;i++){

cout << i << ": " << vec[i] << endl;
}
}
template<typename T> void ordenar(T vec[],int dim,int (*criterio)(T a,T b)){
int i,j;
T temp;

for(i=1;i<dim;i++){
temp=vec[i];
j=i-1;
while(j>=0&& criterio(vec[j],temp)>0){
vec[j+1]=vec[j];
j--;
}
vec[j+1]=temp;

}
}

int batallasganadas(Frestyler a, Frestyler b){
    if(a.Bganadas==b.Bganadas){
    return a.batallas-b.batallas;
}else {

    return a.Bganadas>b.Bganadas? 1: 0;


}
}

int main(){
    int dim=6;
Frestyler vec[dim]={"Kodigo",1000,689,"Larrix",789,508,"Exe",378,245,"Papo",1392,897,"Dtocke",1298,915,"Mecha",657,451};
ordenar(vec,dim,batallasganadas);
mostrar(vec,dim);

return 0;
}