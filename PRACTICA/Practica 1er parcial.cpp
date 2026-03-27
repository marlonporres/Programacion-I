#include <iostream>
#include <string>

using namespace std;

void intercambiar(int *a, int *b){
    int temporal = *a;
    *a=*b;
    *b=temporal;
}


int main(){
    int a, b;
    cout << "Ingrese a: " << endl;
    cin >> a;

    cout << "Ingrese b: ";
    cin >> b;

    intercambiar(&a , &b);


    cout << "Intercambio realizado. " << endl;
    cout << "Ahora a es: " << a << " y b es: " << b << endl;
    return 0;
}


