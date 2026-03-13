#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main(){
    fstream archivo("datos.txt");
    string nombre, edad;
    int i;

    if(!archivo.is_open()){
        cout << "Error: no se pudo abrir el archivo";
        return 1;
    }

    for(i=0;i<5;i++){
        cout << "Ingrese nombre: ";
        cin >> nombre;
        archivo<<nombre<<", ";
        cout << "Ingrese edad: ";
        cin >> edad;
        archivo<<edad<<endl;
    }

    archivo.close();
    return 0;
}