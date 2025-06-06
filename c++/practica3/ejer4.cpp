#include <iostream>
#include <fstream>
using namespace std;
int main()
{
string texto;
ifstream archilec;
fstream archilec2;
 //input file stream: para lectura
archilec.open("texto.txt");
archilec2.open("texto2.txt");
archilec2.seekp(0, ios::end);
while(archilec>>texto){
 archilec2<< " "<<texto ;
}
archilec.close();
archilec2.close();
return 0;
}