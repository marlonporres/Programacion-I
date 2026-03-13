#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main(){

    ifstream archivo("datos.txt", ios::app);
    string linea;

    if(!archivo.is_open()){
        cout << "Error: no se pudo abrir el archivo";
        return 1;
    }

    while (getline(archivo, linea)){
        cout << linea << endl;
    }
    archivo.close();
    return 0;
}