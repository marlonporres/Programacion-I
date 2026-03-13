#include <iostream>
#include <fstream>

using namespace std;

int main(){
    
    ofstream archivo("datos.txt");

    if(!archivo.is_open()){
        cout << "no se puede crear el archivo."<<endl;
        return 1;
    }

    archivo<<"Juan Perez"<<endl;
    archivo<<"Maria Lopez"<<endl;
    archivo<<"Carlos Ruiz"<<endl;
    archivo<<"Pedro"<<endl;

    archivo.close();

    cout << "Archivo creado correctamente"<<endl;
    return 0;
}