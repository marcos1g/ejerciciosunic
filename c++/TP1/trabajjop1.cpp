using namespace std;
#include <iostream>
#include <fstream>

struct Productos
{
    string SKU;
    string descripcion;
    float costofijo;

};
int scnSKU = 10;
int scnDes = 20;

struct Reparaciones
{
    string cliente;
    int tipoproducto;
    string SKU;
    float Costodirecto;
    float Presupuestado;

};
 int srcncliente = 15;
 string readstring(fstream &fs, int largo)
{
    // char buffer[largo + 1];
    char *buffer = new char[largo + 1];
    buffer[largo] = '\0';
    fs.read(buffer, largo);
    string str(buffer);
    delete[] buffer;
    return str;
}
fstream &operator>>(fstream &fs, Productos &product)
{

    product.SKU = readstring(fs, scnSKU);
    product.descripcion = readstring(fs, scnDes);
    fs.read(reinterpret_cast<char *>(&product.costofijo), sizeof(product.costofijo));
    return fs;
}
fstream &operator>>(fstream &fs, Reparaciones  &reparacion)
{

    reparacion.cliente = readstring(fs, srcncliente);
    fs.read(reinterpret_cast<char *>(&reparacion.tipoproducto), sizeof(reparacion.tipoproducto));
    reparacion.SKU = readstring(fs, scnSKU);
    fs.read(reinterpret_cast<char *>(&reparacion.Costodirecto), sizeof(reparacion.Costodirecto));
    fs.read(reinterpret_cast<char *>(&reparacion.Presupuestado), sizeof(reparacion.Presupuestado));
    return fs;
}

Reparaciones *busquedalineal(string nombre, int dim, Reparaciones *vec, int &encontrados)
{
 encontrados = 0;
    int i;
    for (i = 0; i < dim; i++)
    {

        if (vec[i].cliente == nombre)
        {
            encontrados++;
        }
    }
    if (encontrados == 0)
    {

        return nullptr;
    }
    Reparaciones *usuarios = new Reparaciones[encontrados];
    int j = 0;
    for (i= 0; i< dim; i++)
    {

        if (vec[i].cliente == nombre)
        {
            usuarios[j] = vec[i];
            j++;
        }
    }
    return usuarios;
}
void mostrar(Reparaciones *resul, int dim, Productos *produc, int dim2, string vec[] ,int dim3)
{
    int ganancias = 0;
    for (int i = 0; i < dim; i++)
    {
        cout<<resul[i].cliente<<endl;
        
        cout << vec[resul[i].tipoproducto]<<endl;
        cout << resul[i].SKU<<endl;
        for (int j = 0; j < dim2; j++)
        {
            if (produc[j].SKU == resul[i].SKU)
            {
                ganancias += resul[i].Presupuestado - (resul[i].Costodirecto + produc[j].costofijo);
                cout << produc[j].descripcion<<endl;
                cout << produc[j].costofijo<<endl;
                break;
            }
        }
        cout << resul[i].Costodirecto<<endl;
        cout << resul[i].Presupuestado<<endl;
    }
    
    cout << ganancias;
}
 void ordenar(Reparaciones *reparar, int dim, int (*criterio)(Reparaciones,Reparaciones))
{
    Reparaciones temporal;
    int pos;
    for (int i = 0; i < dim; i++)
    {
       
        pos = i;
        for (int j = i; j < dim; j++)
        {
            if(criterio(reparar[j],reparar[pos])>0){
                pos=j;
            }
        }
 temporal=reparar[i];
 reparar[i]=reparar[pos];
 reparar[pos]=temporal;

    }
}
template<typename T> int criteriogeneral(T a,T b){

    if (a.cliente == b.cliente){

        if (a.tipoproducto == b.tipoproducto)
             return a.SKU.compare(b.SKU);
         else
            return a.tipoproducto - b.tipoproducto;
		
    }else
		return a.cliente > b.cliente ? 1 : -1;
		
}

void temporal(Productos* produc,int dim){
    for(int i=0;i<dim;i++){

cout<<produc[i].SKU<<endl;
cout<<produc[i].descripcion<<endl;
cout<<produc[i].costofijo<<endl;

    }
}
    void temporal2(Reparaciones* reparacion,int dim){
    for(int i=0;i<dim;i++){

cout<<reparacion[i].cliente<<endl;
cout<<reparacion[i].tipoproducto<<endl;
cout<<reparacion[i].SKU<<endl;
cout<<reparacion[i].Presupuestado<<endl;
cout<<reparacion[i].Costodirecto<<endl;

    }


}
int main()
{
    int dim = 3;
    string tipo[dim] = {"Electronico", "Mecanico", "Mecatronico"};
    fstream archivo;
    fstream archivo2;
    archivo.open("archivos/productos.bin", ios::binary | ios::in);
    archivo2.open("archivos/reparaciones.bin", ios::binary | ios::in);
    archivo.seekg(0, ios::end);
    archivo2.seekg(0, ios::end);
    int tamArchivo = archivo.tellg();
    int cantstruc = tamArchivo / sizeof(Productos);
    int tamArchivo2 = archivo2.tellg();
    int cantrepa = tamArchivo2 / sizeof(Reparaciones);
    Productos *vec = new Productos[cantstruc];
    Reparaciones *vec2 = new Reparaciones[cantrepa];
    archivo.seekg(0, ios::beg);
    archivo2.seekg(0, ios::beg);
    if (!archivo)
    {

        cout << "error";
    }
    for (int i = 0; i < cantstruc && archivo; i++)
    {
        archivo >> vec[i];
    }
    temporal(vec,cantstruc);
   
    if (!tamArchivo2)
    {

        cout << "error";
    }
    for (int a = 0; a < cantrepa && archivo2; a++)
    {
        archivo2 >> vec2[a];
    }
     temporal2(vec2,cantrepa);
    cout << "Escribir el nombre de usuario a buscar" << endl;
    string nombre;
    while (getline(cin, nombre) && nombre != "Terminar")
    {
        int encontrados;
        Reparaciones *resultado = busquedalineal(nombre, cantrepa, vec2, encontrados);

        if (resultado != nullptr)
        {
            ordenar(resultado, encontrados, criteriogeneral<Reparaciones>);
            mostrar(resultado, encontrados, vec, cantstruc, tipo,dim);
        }
        else
        {

            cout << "No se encontraron usuarios";
        }
        cout << "Escribir el nombre de usuario a buscar" << endl;
    }
}