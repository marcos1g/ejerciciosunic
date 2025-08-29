#include <iostream>
#include <fstream>

using namespace std;
void masvendido(int mat[][8],int dim, int& masindus,int& mascable ){
    int col=5;
    masindus=0;
    mascable=0;
   
for (int i=0;i<dim;i++){
for(int j=0;j<col;j++){
    if(mat[i][j]>mat[masindus][mascable]){
       masindus=i;
       mascable=j;
    }
}
}
}
void ordenamiento(int v[], int dim)
{
	int i, pos, imin, temp;

	for (pos = 0; pos < dim ; pos++) {
		imin = pos;
		for (i = pos; i < dim; i++)
			if (v[i] < v[imin])
				imin = i;
		temp = v[pos];
		v[pos] = v[imin];
		v[imin] = temp;
	}
}
int destacado(int sum[],int dim){
int max=3;
for(int i=1; i<dim-1;i++){
if(sum[i]>sum[i-1]&&sum[i]>sum[i+1]){
max=i;
break;
}}
return max;

}
int main()
{
    ifstream archilec;
    archilec.open("archivo.txt");
    int indus=5;
    int cable=8;
    int metros[indus]{};
    int rollos[indus][cable]{};
    int induin[5]{};
    int sum=0;
    int entregas[cable]{};
    int sumatoria[indus];
    int promedio[cable];
   
    int IDindus, IDcable, metro, rollos2;
    int indven=0;
    int cableven=0;
    //punto1
while(archilec >>IDcable>>IDindus>>metro>>rollos2){
metros[IDindus]+=metro;
rollos[IDindus][IDcable]+=rollos2;

}
for(int i=0; i<indus;i++){
sumatoria[i]+=metros[i];
}
int dest=destacado(sumatoria,indus);
//punto 2
   while(archilec >>IDcable>>IDindus>>metro>>rollos2){
if(IDindus==dest){
    entregas[IDcable]++;
}
}
for(int b=0;b<cable;b++){
promedio[b]=rollos[dest][b]/entregas[b];
}
ordenamiento(promedio,cable);

//punto 3   
masvendido(rollos,indus,indven,cableven);

    return 0;
}