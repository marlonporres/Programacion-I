#include <iostream>
#include <fstream>
#include <string>
#include <cstring>

using namespace std;

//Declaramos un constructor para mantener los datos ordenados
struct Alumno{
    int id;
    char nombre[10];
    float nota;
};

//Declaramos las funciones que usaremos en nuestro switch
void crearArchivoTexto();
void listarTexto();
void buscarPorId();
void actualizarNota();
void crearArchivoBinario();
void leerAleatorioBinario();
void recorrerBinario();

int main(){

    int opcion;

    do{
        cout << "\n----SISTEMA DE ALUMNOS----"<<endl;
        cout << "1.Crear archivo alumnos.txt"<<endl;
        cout << "2.Listar registros (txt)"<<endl;
        cout << "3.Buscar alumno por ID (txt)"<<endl;
        cout << "4.Actualizar nota (txt)"<<endl;
        cout << "5.Crear archivo binario (.dat)"<<endl;
        cout << "6.Leer registro especifico (Binario)"<<endl;
        cout << "7.Recorrer archivo binario"<<endl;
        cout << "8.Salir"<<endl;
        cout << "Ingrese opción: ";
        cin >> opcion;

        switch(opcion){
            case 1: crearArchivoTexto(); break;
            case 2: listarTexto(); break;
            case 3: buscarPorId(); break;
            case 4: actualizarNota(); break;
            case 5: crearArchivoBinario(); break;
            case 6: leerAleatorioBinario(); break;
            case 7: recorrerBinario(); break;
            case 8: cout << "Saliendo..." << endl; break;
            default: cout << "Opcion invalida." << endl;
        }

    }while(opcion!=8);

    return 0;
}

void crearArchivoTexto(){
    //Creamos el archivo para poder agregar los datos respetando lo que ya está en el mismo.
    ofstream archivo("alumnos.txt", ios::app);
    //Validamos si el archivo está abierto.
    if(!archivo.is_open()){
        cout << "no se puede crear el archivo."<<endl;
        return;
    }
    //Creamos una variable temporal usando la estructura de alumnos 
    Alumno alumnoNuevo;
    //Pedimos al usuario que ingrese los datos
    cout << "Ingrese el ID del alumno: ";
    cin >> alumnoNuevo.id;
    cout << "Ingrese el nombre (una sola palabra, sin espacios): ";
    cin >> alumnoNuevo.nombre;
    cout << "Ingrese la nota: ";
    cin >> alumnoNuevo.nota;
    
    //Agregamos los datos al archivo
    archivo << alumnoNuevo.id << " " << alumnoNuevo.nombre << " " << alumnoNuevo.nota << "\n";
    
    //Cerramos el archivo
    archivo.close();

    cout << "¡Alumno guardado exitosamente en alumnos.txt!" << endl;
}

void listarTexto(){

    //Abrimos el archivo en modo lectura con ifstream
    ifstream archivo("alumnos.txt");

    //Validamos si el archivo está abierto.
    if(!archivo.is_open()){
        cout << "no se puede abrir el archivo."<<endl;
        return;
    }

    //Creamos una variable como contenedor temporal
    Alumno temporal;

    //Itineramos por los datos que están en el archivo
    while(archivo >> temporal.id >> temporal.nombre >> temporal.nota){
        cout << "ID: " << temporal.id << "|Nombre: " << temporal.nombre << "|Nota:  " << temporal.nota << endl;   
    }archivo.close();
}

void buscarPorId() {
    //Solicitamos al usuario el ID que quieren buscar
    int idBuscado;
    cout <<"Ingrese el ID del alumno que desea buscar: ";
    cin >>idBuscado;

    //Abrimos el archivo en modo de lectura;
    ifstream archivo("alumnos.txt");

    //Verficamos si esta abierto el archivo 
    if(!archivo.is_open()){
        cout << "Error: No se pudo abrir o encontrar el archivo alumnos.txt"<<endl;
        return;
    }

    //Asignamos una vairable limpia sin basura de memoria
    Alumno temporal = {};

    //Bandera para saber si estamos bien
    bool encontrado = false;

    //Iteramos en el archivo
    while(archivo>>temporal.nombre>>temporal.nombre>>temporal.nota){
        
        if(temporal.id==idBuscado){
            cout << "\n¡Alumno encontrado!" << endl;
            cout << "ID: " << temporal.id 
                 << " | Nombre: " << temporal.nombre 
                 << " | Nota: " << temporal.nota << endl;
            
            encontrado=true;
            break;
        }    
    }
    //Si es false le decimos al 
    if(!encontrado){
        cout << "\nEl alumno con ID " << idBuscado << " no se encuentra registrado." << endl;
    }

    //Cerramos el archivo
    archivo.close();
}

void actualizarNota() {
    int idBuscado;
    cout << "Ingrese el ID del alumno a actualizar la nota: ";
    cin >> idBuscado;

    //Abrimos archivo original en lectura y un temporal en escritura
    ifstream archivo("alumnos.txt");
    ofstream archivoTemp("temp.txt");

    //Validamos que ambos se hayan abierto correctamente
    if(!archivo.is_open() || !archivoTemp.is_open()){
        cout << "Error: No se pudieron abrir los archivos necesarios." << endl;
        return;
    }

    Alumno temporal = {};
    bool encontrado = false;

    //Iteramos por todo el archivo original
    while (archivo >> temporal.id >> temporal.nombre >> temporal.nota){
        if(temporal.id == idBuscado) {

            // Si coincide el ID pedimos el nuevo dato
            cout << "Alumno: " << temporal.nombre << " | Nota actual: " << temporal.nota << endl;
            cout << "Ingrese la NUEVA nota: ";
            cin >> temporal.nota; // Sobrescribimos el valor en la memoria RAM
            
            // Metemos el registro actualizado al archivo temporal
            archivoTemp << temporal.id << " " << temporal.nombre << " " << temporal.nota << "\n";
            encontrado = true;
        } else {
            // Si no coincide, pasamos el registro intacto al temporal 
            archivoTemp << temporal.id << " " << temporal.nombre << " " << temporal.nota << "\n";
        }
    }

    //Cerramos los archivos
    archivo.close();
    archivoTemp.close();

    // Intercambio usando la librería <cstdio> 
    if(encontrado) {
        remove("alumnos.txt"); // Borramos el archivo viejo original 
        rename("temp.txt", "alumnos.txt"); // Renombramos el temporal para que tome su lugar
        cout << "\n¡Nota actualizada exitosamente!" << endl;
    } else {
        remove("temp.txt"); // Si no se encontró el alumno, borramos el temporal que creamos por gusto
        cout << "\nEl alumno con ID " << idBuscado << " no existe." << endl;
    }
}

void crearArchivoBinario() {
       // Abrimos en modo binario y append para no borrar registros anteriores
    ofstream archivo("alumnos.dat", ios::binary | ios::app);
    
    if(!archivo.is_open()) {
        cout << "Error: No se pudo crear o abrir el archivo binario." << endl;
        return;
    }

    // Creamos un espacio limpio de memoria
    Alumno alumnoNuevo = {}; 

    //Solicitamos la información del alumno al usuario
    cout << "Ingrese el ID del alumno: ";
    cin >> alumnoNuevo.id;
    
    cout << "Ingrese el nombre (una sola palabra): ";
    cin >> alumnoNuevo.nombre;
    
    cout << "Ingrese la nota: ";
    cin >> alumnoNuevo.nota;

    // Metemos el bloque de memoria completo
    archivo.write(reinterpret_cast<char*>(&alumnoNuevo), sizeof(Alumno));

    //Cerramos el archivo
    archivo.close();
    cout << "¡Registro binario guardado exitosamente en alumnos.dat!" << endl;
}

void leerAleatorioBinario() {
    int indice;

    // Pedimos la "fila" o índice. 
    cout << "Ingrese la posicion del registro a leer (0 para el 1ro, 1 para el 2do...): ";
    cin >> indice;

    // Abrimos en modo lectura y estrictamente binario
    ifstream archivo("alumnos.dat", ios::binary);

    if(!archivo.is_open()) {
        cout << "Error: No se pudo abrir el archivo binario." << endl;
        return;
    }

    Alumno temporal = {}; // Establecemos espacio de memoria
 
    // Multiplicamos la posición deseada por el tamaño en bytes de nuestro struct
    // ios::beg le indica que cuente esos bytes desde el puro inicio del archivo.
    archivo.seekg(indice * sizeof(Alumno), ios::beg);


    // Como ya estamos parados en el byte exacto, leemos el bloque de memoria.
    // Metemos esto en un if para validar que el salto no se haya salido de los limites del archivo.
    if(archivo.read(reinterpret_cast<char*>(&temporal), sizeof(Alumno))) {
        cout << "\n¡Registro Encontrado!" << endl;
        cout << "ID: " << temporal.id 
             << " | Nombre: " << temporal.nombre 
             << " | Nota: " << temporal.nota << endl;
    } else {
        cout << "\nError: El registro no existe o esta fuera de los limites del archivo." << endl;
    }

    archivo.close();
}

void recorrerBinario() {
    ifstream archivo("alumnos.dat", ios::binary);

    if(!archivo.is_open()) {
        cout << "Error: No se pudo abrir el archivo binario." << endl;
        return;
    }

    Alumno temporal = {};
    int contador = 0; // Para mostrar el numero de registro

    cout << "\n--- RECORRIDO DE ARCHIVO BINARIO ---" << endl;

    // El ciclo se repite mientras logre leer bloques completos del tamaño de Alumno 
    while(archivo.read(reinterpret_cast<char*>(&temporal), sizeof(Alumno))) {
        cout << "Posicion [" << contador << "] -> "
             << "ID: " << temporal.id 
             << " | Nombre: " << temporal.nombre 
             << " | Nota: " << temporal.nota << endl;
        contador++;
    }

    if(contador == 0) {
        cout << "El archivo binario esta vacio." << endl;
    }

    archivo.close();
}