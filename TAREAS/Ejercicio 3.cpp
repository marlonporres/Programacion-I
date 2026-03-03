#include <iostream>
#include <string>
using namespace std;

int main(){

    int numero;
    int original[numero];
    int inverso[numero];

    cout << "Cuántos números deseas ingresar? ";
    cin >> numero;

    for (int i = 0; i < numero; i++){
        cout << "Ingresa el número " << i + 1 << ": ";
        cin >> original[i];
        inverso[i] = -original[i];
    }

    cout << "Inversos calculados: [";
    for (int i = 0; i < numero; i++){
        cout << original[i] << " -> " << inverso[i] << (i == numero - 1 ? "" : ", ");
    }
    cout << "]" << endl;
    return 0;
}
