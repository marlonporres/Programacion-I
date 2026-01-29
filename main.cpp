#include <iostream>

using namespace std;

int main()
{
    double peso_libras, altura_metros, peso_kilos, resultado_bmi;

    cout << "----Calculadora Beast Mode---" << endl;
    
    cout << "Ingresa tu peso en libras: ";
    cin >> peso_libras;

    cout << "Ingrese su altura en metros: ";
    cin >> altura_metros;

    peso_kilos : peso_libras * 0.453592;

    resultado_bmi : peso_kilos / (altura_metros*altura_metros);

    cout << "Tu indice de masa corporal es: " << resultado_bmi << endl;

    return 0;

}