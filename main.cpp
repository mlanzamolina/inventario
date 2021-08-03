#include "inventario.h"
using namespace std;

const int clases = 5;
int posicion=0;
inventario arreglo[clases];



void llenar()
{
   string a="bimbo";
   string b="pan";
   string aa="los andes";
   string aaa="hawit";
    arreglo[posicion].setNombre(a);
    arreglo[posicion].setPrecio(42.24);
    arreglo[posicion].setTipo(b);
    arreglo[posicion].setCantidad(5);
    arreglo[posicion].setVendidos(0);
    posicion++;
    arreglo[posicion].setNombre(aa);
    arreglo[posicion].setPrecio(15);
    arreglo[posicion].setTipo(b);
    arreglo[posicion].setCantidad(2);
    arreglo[posicion].setVendidos(0);
    posicion++;
    arreglo[posicion].setNombre(aaa);
    arreglo[posicion].setPrecio(22);
    arreglo[posicion].setTipo(b);
    arreglo[posicion].setCantidad(3);
    arreglo[posicion].setVendidos(0);
    posicion++; 
}
void verPrecios()
{
    cout<<"\n************************************\n";
    cout<<"\nImprimiendo Precios\n";
    for (int i = 0; i < posicion; i++)
    {
         cout<<"\nNombre: "<<arreglo[i].getNombre()
         <<"\nPrecio: "<<arreglo[i].getPrecio()
         <<"\nTipo: "<<arreglo[i].getTipo()<<endl;
    }
}
void verInventario()
{
    cout<<"\n************************************\n";
    cout<<"\nImprimiendo Inventario\n";
    for (int i = 0; i < posicion; i++)
    {
         cout<<"\nNombre: "<<arreglo[i].getNombre()
         <<"\nPrecio: "<<arreglo[i].getPrecio()
         <<"\nCantidad: "<<arreglo[i].getCantidad()<<endl;
    }
    
}

int menu(int op)
{
    /*
    1. Ver Inventario ya
    2. Vender
    3. preciosya
    4. Ventas por producto
    5. Total ventas
    0. Salir ya"*/
    int salir=0;
    switch (op)
    {
    case 0:
        cout<<"\nGracias saludos\n";
        return salir=-1;
        exit(0);
        break;

    case 1:
         verInventario();
    break;

    case 2:
    break;

    case 3:
         verPrecios();
    break;

    case 4:
    break;

    case 5:
    break;

    default:
    break;

    }
   
   return salir;


}

int main()
{
    llenar();
    int op=0,salir =0;
    while (salir!=-1)
    {
        cout<<"\n1. Ver Inventario\n2. Vender\n3. precios\n4. Ventas por producto\n5. Total ventas\n0. Salir"<<"\nIngrese una opcion: ";
        cin>>op;
        salir = menu(op);

    }

}