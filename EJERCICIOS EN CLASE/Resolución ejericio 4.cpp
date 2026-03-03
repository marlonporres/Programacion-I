#include <iostream>
#include <string>

using namespace std; 

int main(){
    string cadena;
    int pos1, pos2;
    
    cout << "Ingrese cadena: ";
    cin >> cadena;

    cout << "Ingrese posición 1: ";
    cin >> pos1;

    cout << "Ingrese posición 2: ";
    cin >> pos2;

    if(cadena.empty())
    {
        cout << "Error: Cadena vacía! \n";
        return 0;
    }

    if(pos1 < 0) pos1 = 0;
    if(pos2 >= (int)cadena.size()) pos2 = (int)cadena.size() - 1;

    if(pos1 > pos2)
    {
        int aux = pos1; pos1= pos2; pos2 = aux;
    }
    
    while(pos1 < pos2)
    {
        char aux = cadena[pos1];
        cadena[pos1] = cadena[pos2];
        pos1++;
        pos2--;
    }

    cout << "Resultado: " << cadena;

    return 0;
}