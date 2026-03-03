#include <iostream>

using namespace std;

int suma(int n1, int n2){
    return n1 + n2;
}

int multiplicar (int n1, int n2){
    return n1*n2;
}

int resta (int n1, int n2){
    return n1 - n2;
}

float division(float n1, float n2){
    return n1 / n2;
}

int main()
{
    int opcion, numero1, numero2;

    cout << "1. Suma\n ";
    cout << "2. Resta\n ";
    cout << "3. Multiplicación\n ";
    cout << "4. División\n ";
    cout << "5. Despedirse\n ";
    cout << "6. Salir\n ";
    cout << "Cuál será su selección? ";
    cin >> opcion;

    switch (opcion){
        case 1:
            cout << "Ingrese un número: ";
            cin >> numero1;
            cout << "Ingrese un número: ";
            cin >> numero2;
            cout << "Resultado: " << suma(numero1, numero2)<< endl;
            break;
        case 2:
            cout << "Ingrese un número: ";
            cin >> numero1;
            cout << "Ingrese un número: ";
            cin >> numero2;
            cout << "Resultado: " << resta(numero1, numero2);
            break;
        case 3:
            cout << "Ingrese un número: " << endl;
            cin >> numero1;
            cout << "Ingrese un número: " << endl;
            cin >> numero2;
            cout << "Resultado: " << multiplicar(numero1, numero2);
        case 4:
            cout << "Ingrese un número: " << endl;
            cin >> numero1;
            cout << "Ingrese un número: " << endl;
            cin >> numero2;
            cout << "Resultado: " << division(numero1, numero2);

    }

    return 0;
}