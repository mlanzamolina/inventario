#include <iostream>
#include "iomanip"
#include <string.h>
using namespace std;
class inventario
{
private:
    string nombre;
    string tipo;
    double precio;
    int cantidad;
    int vendidos;

public:
    string getNombre() {
	return this->nombre;
    }
        void setNombre(string nombre) {
	    this->nombre = nombre;
    }  
    string getTipo() {
    	return this->tipo;
    }
    void setTipo(string tipo) {
    	this->tipo = tipo;
    }
    double getPrecio() {
    	return this->precio;
    }
    void setPrecio(double precio) {
    	this->precio = precio;
    }
    int getCantidad() {
	    return this->cantidad;
    }
    void setCantidad(int cantidad) {
	    this->cantidad = cantidad;
    }
    int getVendidos() {
	return this->vendidos;
    }
    void setVendidos(int vendidos) {
	this->vendidos = vendidos;
    }


    inventario();
};
