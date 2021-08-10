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

struct Node {
    inventario data;
    Node* next;
};
void insert(Node** root, inventario item)
{
    Node* temp = new Node;
    Node* ptr;
    temp->data = item;
    temp->next = NULL;
 
    if (*root == NULL)
        *root = temp;
    else {
        ptr = *root;
        while (ptr->next != NULL)
            ptr = ptr->next;
        ptr->next = temp;
    }
}
void display(Node* root)
{
    cout<<"\nHISTORIAL DE VENTAS\n";
    Node * actual = root;
    while (actual != NULL) {
        if (actual->data.getPrecio()!=0)
        {
           cout<<"\nNombre: "<<actual->data.getNombre()
         <<"\nPrecio: "<<actual->data.getPrecio()<<endl;
        }
        actual = actual->next;
    }
}
Node *arrayToList(inventario arr[], int n)
{
    Node *root = NULL;
    for (int i = 0; i < n; i++)
        insert(&root, arr[i]);
   return root;
}
 void setear(string nombre,double precio,string tipo,int cantidad)
{
    arreglo[posicion].setNombre(nombre);
    arreglo[posicion].setPrecio(precio);
    arreglo[posicion].setTipo(tipo);
    arreglo[posicion].setCantidad(cantidad);
    arreglo[posicion].setVendidos(0);
    posicion++;
}
double fRand(double fMin, double fMax)
{
    double f = (double)rand() / RAND_MAX;
    return fMin + f * (fMax - fMin);
}
void llenar()
{
    //llenar pan
    string pan="pan";
    string pan1="molde";
    string pan2="Pan blanco";
    string pan3="hotdog";
    string pan4="Bunuelo";
    setear(pan1,fRand(10,100),pan,5);
    setear(pan2,fRand(10,100),pan,3);
    setear(pan3,fRand(10,100),pan,2);
    setear(pan4,fRand(10,100),pan,5);

    //llenar reposteria
    string reposteria="reposteria";
    string reposteria1="quequitos";
    string reposteria2="semitas";
    string reposteria3="relampagos";
    string reposteria4="braouini";
    setear(reposteria1,fRand(10,100),reposteria,(rand() % 5) + 1);
    setear(reposteria2,fRand(10,100),reposteria,(rand() % 5) + 1);
    setear(reposteria3,fRand(10,100),reposteria,(rand() % 5) + 1);
    setear(reposteria4,fRand(10,100),reposteria,(rand() % 5) + 1);

    //llenar postres
    string postres="postres";
    string postres1="flan";
    string postres2="paletas";
    string postres3="gelatina";
    string postres4="jugos";
    setear(postres1,fRand(10,100),postres,(rand() % 5) + 1);
    setear(postres2,fRand(10,100),postres,(rand() % 5) + 1);
    setear(postres3,fRand(10,100),postres,(rand() % 5) + 1);
    setear(postres4,fRand(10,100),postres,(rand() % 5) + 1);

      //llenar comida
    string comida="comida";
    string comida1="sandwich";
    string comida2="croissant";
    string comida3="pizza";
    string comida4="baleada";
    setear(comida1,fRand(10,100),comida,(rand() % 5) + 1);
    setear(comida2,fRand(10,100),comida,(rand() % 5) + 1);
    setear(comida3,fRand(10,100),comida,(rand() % 5) + 1);
    setear(comida4,fRand(10,100),comida,(rand() % 5) + 1);

      //llenar refrescos
    string refrescos="refrescos";
    string refrescos1="naranja";
    string refrescos2="coca cola";
    string refrescos3="uva";
    string refrescos4="malteada";
    setear(refrescos1,fRand(10,100),refrescos,(rand() % 5) + 1);
    setear(refrescos2,fRand(10,100),refrescos,(rand() % 5) + 1);
    setear(refrescos3,fRand(10,100),refrescos,(rand() % 5) + 1);
    setear(refrescos4,fRand(10,100),refrescos,(rand() % 5) + 1);
    
     //llenar chucherias
    string chucherias="chucherias";
    string chucherias1="churos";
    string chucherias2="galletas saladas";
    string chucherias3="galletas dulces";
    string chucherias4="chocolates";
    setear(chucherias1,fRand(10,100),chucherias,(rand() % 5) + 1);
    setear(chucherias2,fRand(10,100),chucherias,(rand() % 5) + 1);
    setear(chucherias3,fRand(10,100),chucherias,(rand() % 5) + 1);
    setear(chucherias4,fRand(10,100),chucherias,(rand() % 5) + 1);

     //llenar otros
    string otros="otros";
    string otros1="tijeras";
    string otros2="pegamento";
    string otros3="papel bon";
    string otros4="globos";
    setear(otros1,fRand(10,100),otros,(rand() % 5) + 1);
    setear(otros2,fRand(10,100),otros,(rand() % 5) + 1);
    setear(otros3,fRand(10,100),otros,(rand() % 5) + 1);
    setear(otros4,fRand(10,100),otros,(rand() % 5) + 1);

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
void verInventarioCompleto()
{
    cout<<"\n************************************\n";
    cout<<"\nIMPRIMIENDO INVENTARIO COMPLETO PARA COMPRA\n";
    for (int i = 0; i < posicion; i++)
    {
         cout<<"\nNombre: "<<arreglo[i].getNombre()
         <<"\nPrecio: "<<arreglo[i].getPrecio()
         <<"\nCantidad: "<<arreglo[i].getCantidad()<<endl;
    }
}
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
         <<"\nPrecio: "<<arreglo[i].getPrecio()
         <<"\nCantidad: "<<arreglo[i].getCantidad()<<endl;
        }
        
         
    }
    return true;
    
}
void vender()
{
    cout<<"\n************************************\n";
    cout<<"\nVENDER\n ";
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
        
        for (int i = 0; i < posicion; i++)
        {
           if(op.compare(arreglo[i].getNombre())==0)
           {
               if (arreglo[i].getCantidad()>0)
               {
                venta[posicionVenta]=arreglo[i];
                posicionVenta++;
                total+=arreglo[i].getPrecio();
                arreglo[i].setVendidos(arreglo[i].getVendidos()+1);
                arreglo[i].setCantidad(arreglo[i].getCantidad()-1);

               }else
               {
                   cout<<"\nExistencias agotadas\n";
               }
           }
        }
        
           
           
        
        cout<<"\n1.Imprimir recibo\n2.Hacer otra compra?: ";
        cin>>otro;
        if (otro==1)
        {
             cout<<"\nSUBTOTAL: "<<total;
             cout<<"\nProporcionenos su edad: ";cin>>edad;
             if (edad>=60)
             {
             total=total*0.5;
             }
             cout<<"\nTotal: "<<total<<endl;
            vTerminada=true;
        }else if(otro>2 || otro<1 || cin.fail()){
              cout<<"\nOpcion no valida.\n Ingrese una opcion del 1-2!!\n";
				cin.clear();   
				cin.ignore(); 
               continue;
        }
    }
    
}

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
int menu(int op)
{
    /*
    1. Ver Inventario ya
    2. Vender
    3. preciosya
    4. Ventas por producto
    5. Total ventas
    0. Salir ya"*/

    inventario * ventaMain;
    int salir=0;
    switch (op)
    {
    case 0:
        cout<<"\n\t*INGRESAR NOMBRE DE INTEGRANTES DE GRUPO LINEA 337 del main.cpp*\n";
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
          int n = sizeof(venta) / sizeof(venta[0]);
          Node* root = arrayToList(venta, n);
          display(root);
         //totalVentas(ventaMain);
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

int main()
{
    llenar();
    int op=0,salir =0;
    while (salir!=-1)
    {
        cout<<"\n************************************\n";
        cout<<"\nMenu Principal\n";
        cout<<"\n1. Ver Inventario\n2. Vender\n3. precios\n4. Ventas por producto\n5. Total ventas\n6. cls\n0. Salir"<<"\nIngrese una opcion: ";
        cin>>op;
          if(op>6 || op<0 || cin.fail())
            {
                //este if comprueba si el cin falla
           //ej. un string o char retorna true porque fallo   
           //o si el rango del int es mayor de 6 o menor a 0
               cout<<"\nOpcion no valida.\n Ingrese una opcion del 0-6!!\n";
				 //limpia el cin buffer
				cin.clear();   
                //ignora el cin utilizado
				cin.ignore(); 
                //salta a la otra iteracion del ciclo ignorando el codigo faltante en la iteracion
                continue;
            } 
        salir = menu(op);

    }

}