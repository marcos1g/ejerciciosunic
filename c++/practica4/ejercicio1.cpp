#include <iostream>
#include <fstream>

using namespace std;
int maximo(int vec[],int pos){
   
for (int i = 0; i < pos; ++i){
    int maximo;
        if(i=0){
            maximo=vec[i];
        }
        if(vec[i]>maximo){
            pos=i;
        }
    }

return pos;


}
int main()
{
    int pos=10;
    int vec[pos]{4,65,32,76,9,54,87,23,27,10};

int maximo1=maximo(vec,pos);
int nummax=vec[maximo1];


    return 0;
}