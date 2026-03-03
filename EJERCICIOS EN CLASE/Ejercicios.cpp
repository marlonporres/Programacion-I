#include <iostream>

using namespace std;

double calcularPrecioFinal(double precio, double porcentajeImpuesto){
    return precio * (1 + porcentajeImpuesto);
}

bool esPiezaCara(double precio){
    if (precio >= 500){
        return true;
    } else{
        return false;
    }
}

int main(){
    double precio, porcentaje;

    cout << "Precio de repuesto: ";
    cin >> precio;

    if (esPiezaCara(precio)){
        porcentaje = 0.15;
    } else{
        porcentaje = 0.12;
    }

    cout << "El resultado final es igual a: " << calcularPrecioFinal(precio,porcentaje) << endl;

    return 0;
}