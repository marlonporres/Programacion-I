#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main(){
    string texto;
    int a, b;

    cout << "Ingrese la cadena: ";
    getline(cin, texto);
    cout << "Ingrese indice inicial (a) e indice final (b): ";
    cin >> a >> b;

    if (b >= texto.length()){
        b = texto.length() - 1;
    }
    int i = a;
    int j = b;
    while (i < j){
        swap(texto[i], texto[j]);
        i++;
        j--;
    }
    cout << "Resultado: " << texto << endl;
    return 0;
}
