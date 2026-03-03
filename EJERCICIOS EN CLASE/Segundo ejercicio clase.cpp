#include <iostream>

using namespace std;

int suma(int n1, int n2);

int main()
{
    int n1, n2;

    cout << "Ingrese dos números: " << endl;
    cin >> n1 >> n2;

    cout << "El resultado es: " << suma(n1,n2) << endl;

    return 0;
}

int suma(int n1, int n2){
    return n1+n2;
}