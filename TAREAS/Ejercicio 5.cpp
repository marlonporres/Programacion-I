#include <iostream>
#include <string>
using namespace std;


int addFive(int num){
    return num + 5;
}

int main(){
    int num;
    cout << "Ingrese un número: ";
    cin >> num;

    cout << "El resultado es: " << addFive(num) << endl;
    
    return 0;
}
