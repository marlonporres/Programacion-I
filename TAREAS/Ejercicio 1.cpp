#include <iostream>
#include <string>
#include <cmath>
using namespace std; 
int main(){
    
    string número;
    int suma_total = 0;
    int multiplicador = 1;
    
    cout << "Ingrese el número binario: " << endl;
    cin >> número;

    for (int i = número.length() - 1; i >= 0; i--){
        if (número[i] == '1'){
            suma_total += multiplicador;
        } else if (número[i] != '0'){
            cout << "Error: Ingresaste un caracter que no es 0 ni 1." << endl;
            return 1; 
        }
        multiplicador *= 2;
    }

    cout << "El número decimal es: " << suma_total << endl;
    return 0;
}