#include "inventario.h"
#include <string>
#include <ctime>
#include <cstdlib>
using namespace std;

const int productos = 30;
int posicion=0;
int posicionVenta=0;
inventario arreglo[productos];
inventario venta[productos];
// set los valores del inventario a esa posicion y sube 1 pos
 void setear(string nombre,double precio,string tipo,int cantidad)
{
    string * codigo=&nombre;
    
    arreglo[posicion].setNombre(nombre);
    arreglo[posicion].setPrecio(precio);
    arreglo[posicion].setTipo(tipo);
    arreglo[posicion].setCantidad(cantidad);
    arreglo[posicion].setVendidos(0);
    arreglo[posicion].setCodigo(codigo);
    posicion++;
}
// random de un double fmin=limite inferior fmax=limite superior
double fRand(double fMin, double fMax)
{
    double f = (double)rand() / RAND_MAX;
    return fMin + f * (fMax - fMin);
}
//llenar el arreglo con datos
void llenar()
{
    //llenar pan
    string pan="pan";
    string pan1="molde";
    string pan2="Pan_blanco";
    string pan3="hotdog";
    string pan4="Bunuelo";
    setear(pan1,fRand(10,100),pan,(rand() % 50) + 10);
    setear(pan2,fRand(10,100),pan,(rand() % 5) + 10);
    setear(pan3,fRand(10,100),pan,(rand() % 5) + 10);
    setear(pan4,fRand(10,100),pan,(rand() % 5) + 10);

    //llenar reposteria
    string reposteria="reposteria";
    string reposteria1="quequitos";
    string reposteria2="semitas";
    string reposteria3="relampagos";
    string reposteria4="braouini";
    setear(reposteria1,fRand(10,100),reposteria,(rand() % 50) + 10);
    setear(reposteria2,fRand(10,100),reposteria,(rand() % 50) + 10);
    setear(reposteria3,fRand(10,100),reposteria,(rand() % 50) + 10);
    setear(reposteria4,fRand(10,100),reposteria,(rand() % 50) + 10);

    //llenar postres
    string postres="postres";
    string postres1="flan";
    string postres2="paletas";
    string postres3="gelatina";
    string postres4="jugos";
    setear(postres1,fRand(10,100),postres,(rand() % 50) + 10);
    setear(postres2,fRand(10,100),postres,(rand() % 50) + 10);
    setear(postres3,fRand(10,100),postres,(rand() % 50) + 10);
    setear(postres4,fRand(10,100),postres,(rand() % 50) + 10);

      //llenar comida
    string comida="comida";
    string comida1="sandwich";
    string comida2="croissant";
    string comida3="pizza";
    string comida4="baleada";
    setear(comida1,fRand(10,100),comida,(rand() % 50) + 10);
    setear(comida2,fRand(10,100),comida,(rand() % 50) + 10);
    setear(comida3,fRand(10,100),comida,(rand() % 50) + 10);
    setear(comida4,fRand(10,100),comida,(rand() % 50) + 10);

      //llenar refrescos
    string refrescos="refrescos";
    string refrescos1="naranja";
    string refrescos2="coca_cola";
    string refrescos3="uva";
    string refrescos4="malteada";
    setear(refrescos1,fRand(10,100),refrescos,(rand() % 50) + 10);
    setear(refrescos2,fRand(10,100),refrescos,(rand() % 50) + 10);
    setear(refrescos3,fRand(10,100),refrescos,(rand() % 50) + 10);
    setear(refrescos4,fRand(10,100),refrescos,(rand() % 50) + 10);
    
     //llenar chucherias
    string chucherias="chucherias";
    string chucherias1="churos";
    string chucherias2="galletas_saladas";
    string chucherias3="galletas_dulces";
    string chucherias4="chocolates";
    setear(chucherias1,fRand(10,100),chucherias,(rand() % 50) + 10);
    setear(chucherias2,fRand(10,100),chucherias,(rand() % 50) + 10);
    setear(chucherias3,fRand(10,100),chucherias,(rand() % 50) + 10);
    setear(chucherias4,fRand(10,100),chucherias,(rand() % 50) + 10);

     //llenar otros
    string otros="otros";
    string otros1="tijeras";
    string otros2="pegamento";
    string otros3="papel_bon";
    string otros4="globos";
    setear(otros1,fRand(10,100),otros,(rand() % 50) + 10);
    setear(otros2,fRand(10,100),otros,(rand() % 50) + 10);
    setear(otros3,fRand(10,100),otros,(rand() % 50) + 10);
    setear(otros4,fRand(10,100),otros,(rand() % 50) + 10);

}
//imprime todos los productos con sus precios
void verPrecios()
{
    cout<<"\n************************************\n";
    cout<<"\nImprimiendo Precios\n";
    for (int i = 0; i < posicion; i++)
    {
         cout<<"\nNombre: "<<arreglo[i].getNombre()
         <<"\nCodigo: "<<arreglo[i].getCodigo()
         <<"\nPrecio: "<<arreglo[i].getPrecio()
         <<"\nTipo: "<<arreglo[i].getTipo()<<endl;
    }
}
//imprime todo el inventario sin filtros por tipo
void verInventarioCompleto()
{
    cout<<"\n************************************\n";
    cout<<"\nIMPRIMIENDO INVENTARIO COMPLETO PARA COMPRA\n";
    for (int i = 0; i < posicion; i++)
    {
         cout<<"\nNombre: "<<arreglo[i].getNombre()
         <<"\nCodigo: "<<arreglo[i].getCodigo()
         <<"\nPrecio: "<<arreglo[i].getPrecio()
         <<"\nCantidad: "<<arreglo[i].getCantidad()<<endl;
    }
}
//imprime el inventario filtrando por tipo
bool verInventario()
{
       cout<<"\n************************************\n";
       int opTipo=0;
       string strTipo=" ";
       cout<<"\n1.pan\n2.reposteria\n3.postres\n4.comida\n5.refrescos\n6.chucherias\n7.otros\n0.Salir\nIngrese que tipo quiere: ";
       cin>>opTipo;
       switch (opTipo)
       {
       case 0:
           return false;
           break;
        case 1:
        strTipo="pan";
        break;
        case 2:
           strTipo="reposteria";
        break;
         case 3:
           strTipo="postres";
        break;
        case 4:
           strTipo="comida";
        break;
        case 5:
          strTipo="refrescos";
        break;
        case 6:
           strTipo="chucherias";
        break;
        case 7:
          strTipo="otros";
         break;
       
       default:
           break;
       }
       
    cout<<"\n************************************\n";
    cout<<"\nImprimiendo Inventario\n";
    for (int i = 0; i < posicion; i++)
    {
        if (strTipo.compare(arreglo[i].getTipo())==0)
        {
            /* code */
            cout<<"\nNombre: "<<arreglo[i].getNombre()
            <<"\nCodigo: "<<arreglo[i].getCodigo()
         <<"\nPrecio: "<<arreglo[i].getPrecio()
         <<"\nCantidad: "<<arreglo[i].getCantidad()<<endl;
        }
        
         
    }
    return true;
    
}
//funcion para vender 
void vender()
{
    cout<<"\n************************************\n";
    cout<<"\nVENDER\n ";
    int mayoreo=0;
    string op=" ";
    bool vTerminada=false;
    int otro;
    double total=0;
    int edad=0;
    string strTipo=" ";
       
    while (!vTerminada)
    {
        if(!verInventario())
            break;

        cout<<"\nIngrese el nombre del producto que desea: \n";
        cin>>op;
        cout<<"\nIngrese la cantidad que desea: \n";
        cin>>mayoreo;

        
        for (int i = 0; i < posicion; i++)
        {
           if(op.compare(arreglo[i].getNombre())==0)
           {
                
                
               if (arreglo[i].getCantidad()<mayoreo)
               {
                   cout<<"\nProductos insuficientes\n";
                   continue;
               }
               
               for (int j = 0; j < mayoreo; j++)
               {
                if (arreglo[i].getCantidad()>0)
               {
                venta[posicionVenta]=arreglo[i];
                posicionVenta++;
                total+=arreglo[i].getPrecio();
                arreglo[i].setVendidos(arreglo[i].getVendidos()+1);
                arreglo[i].setCantidad(arreglo[i].getCantidad()-1);
                  if (mayoreo>=10)
                {
                 int subtotal=total;
                 subtotal = total * 0.05;
                 total-=subtotal;
                }
              
               }else
               {
                   cout<<"\nExistencias agotadas\n";
               }
               }
           }
            if (mayoreo>=10)
                {
                 cout<<"\nMayoreo aplicado, 5%\n";
                }
        }
        
           system("cls");
       
        cout<<"\n1.Imprimir recibo\n2.Hacer otra compra?: ";
        cin>>otro;
        if (otro==1)
        {
            
             cout<<"\nSUBTOTAL: "<<total;

             cout<<"\nProporcionenos su edad: ";cin>>edad;
              if (mayoreo>=10)
                {
                 int subtotal=total;
                 subtotal = total * 0.05;
                 total-=subtotal;
                 cout<<"\nMayoreo aplicado, 5%\n";
                }
            
             if (edad>=60)
             {
                 cout<<"\nTercera edad aplicado, 50%\n";
                 total=total*0.5;
             }
             cout<<"\nTotal: "<<total<<endl;
            vTerminada=true;
        }
    }
    
}
//funcion que busca producto por nombre y imprime el producto con sus atributos y total vendido del mismo precio*cantidad vendidos
void getear(string op)
{
    for (int i = 0; i < posicion; i++)
    {
        if (op.compare(arreglo[i].getNombre())==0)
        {
            /* code */
        cout<<"\nNombre: "<<arreglo[i].getNombre()
         <<"\nPrecio: "<<arreglo[i].getPrecio()
         <<"\nCantidad: "<<arreglo[i].getCantidad() 
         <<"\nVendidos: "<<arreglo[i].getVendidos()
         <<"\n\tTotal vendido del producto: "<<arreglo[i].getPrecio()*arreglo[i].getVendidos()
         <<endl;
        }
        
    }
    
    

}
//funcion para llamar al get de todos los atributos
void ventasXproducto()
{
     cout<<"\n************************************\n";
    cout<<"\nVENTAS POR PRODUCTO\n";
    string op="";
   
        verInventarioCompleto();

        cout<<"\nIngrese el nombre del producto que desea: \n";
        cin>>op;
        getear(op);
        

}
//historial de todos los productos vendidos
void totalVentas()
    {
   
   cout<<"\n************************************\n";
    cout<<"\nVENTAS TOTALES\n";
    for (int i = 0; i < posicionVenta; i++)
    {
         cout<<"\nNombre: "<<venta[i].getNombre()
         <<"\nCodigo: "<<arreglo[i].getCodigo()
         <<"\nPrecio: "<<venta[i].getPrecio()
         <<"\nCantidad: "<<venta[i].getCantidad()<<endl;
    }


}
//MENU PRINCIPAL LLAMA TODAS LAS FUNCIONES
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
        cout<<"\n\tJuan Carlos Calix Arriaga 2016-2030-180\n\tDiana Alejandra Palacios Carvajal 2019-2000-516\n\tPauleth Nerea Hernandez Turcios 2017-2000-484\n\tDudley Fitzgerald Sampson Gómez 2015-2006-502\n";
        return salir=-1;
        exit(0);
        break;

    case 1:
         verInventario();
    break;

    case 2:
        vender();
    break;

    case 3:
         verPrecios();
    break;

    case 4:
         ventasXproducto();
    break;

    case 5:{
         totalVentas();
    }
    break;
    case 6:
    system("cls");
    break;


    default:
    cout<<"\nOpcion no valida.\n Ingrese una opcion del 0-6!!\n";
    break;

    }
   
   return salir;


}
//CODIGO MAIN 
int main()
{
    system("Color 0A");
    llenar();
    int op=0,salir =0;
    while (salir!=-1)
    {
        cout<<"\n************************************\n";
        cout<<"\nMenu Principal\n";
        cout<<"\n1. Ver Inventario\n2. Vender\n3. precios\n4. Ventas por producto\n5. Total ventas\n6. cls\n0. Salir"<<"\nIngrese una opcion: ";
        cin>>op;
          
        salir = menu(op);

    }

}