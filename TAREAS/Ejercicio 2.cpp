#include <iostream>
#include <string>      
using namespace std;    

int main() {
    
    int numero;
    cout << "Ingrese un número positivo:";
    cin >> numero;

    int arr[numero];

    for (int i = 0; i < numero; i++){
        arr[i] = numero - i;
    }
    cout << "Arreglo generado: [";
    for (int i = 0; i < numero; i++){
        cout << arr[i] << (i == numero - 1 ? "" : ", ");
    }
    cout << "]" << endl;
    return 0;
}

