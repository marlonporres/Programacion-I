#include <iostream>

using namespace std;


void ascendente(int arr[], int n){
    for(int i = 0; i < n;i++){
        for (int j = 0; j < n-1;j++){
            if (arr[j]>arr[j+1]){
                int aux = arr[j];
                arr[j] = arr [j+1];
                arr[j+1] = aux;
            }
        }
    }
}
void descendente(int arr[], int n){
    for(int i = 0; i < n;i++){
        for (int j = 0; j < n-1;j++){
            if (arr[j]<arr[j+1]){
                int aux = arr[j];
                arr[j] = arr [j+1];
                arr[j+1] = aux;
            }
        }
    }
}

int main(){
    int arr[5] = {5, 1, 3, 8, 4};
    int n = 5;

    descendente(arr, n);
    
    cout << "{";
    for (int i = 0; i < n; i++){
        cout << arr[i];
        cout << " ";
    }
    cout << "}" << endl;

    ascendente(arr, n);

    cout << "{";
    for (int i = 0; i < n; i++){
        cout << arr[i];
        cout << " ";
    }
    cout << "}" << endl;
    return 0;
}