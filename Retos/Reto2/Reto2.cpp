#include <iostream>
#include <vector>
using namespace std;


void printArray(int array[4]);
/*
*  Dado un array de enteros no ordenados, verifique si contiene una tupla de cuatro elementos(cuarteto) que tengan una suma dada.
*/
int main()
{
    int n, e;
    cout << "Ingrese el numero de elementos del arreglo: ";
    cin >> n;
    vector<int> array;

    for (int i = 0; i < n; i++) {
        cout << "Elemento [" << i << "]: ";
        cin >> e;
        array.push_back(e);
    }



    vector<int[4]> cuartetos;
    int suma;
    cout << "Ingrese una suma: ";
    cin >> suma;
    int cuarteto[4];
    // combinatoria
    int total = 0;
    for (int i = 0; i < n; i++) {
        cuarteto[0] = array[i];
        for (int j = i + 1; j < n; j++) {
            cuarteto[1] = array[j];
            total = cuarteto[0] + cuarteto[1];
            for (int k = j + 1; k < n; k++) {
                cuarteto[2] = array[k];
                total = cuarteto[0] + cuarteto[1]+ cuarteto[2];
                for (int y = k + 1; y < n; y++) {
                    cuarteto[3] = array[y];
                    total = cuarteto[0] + cuarteto[1] + cuarteto[2] + cuarteto[3];
                    if (total == suma) {
                        printArray(cuarteto);
                    }
                }
            }
        }
    }

}

void printArray(int array[4]) {
    for (int i = 0; i < 4; i++) {
        cout << array[i] << ", ";
    }
    cout << "\n";
}