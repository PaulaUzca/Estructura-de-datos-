#include <iostream>
#include <vector>
using namespace std;

/*
* Dado un array de enteros, reorganice sus elementos de manera que cada segundo elemento
* sea mayor que sus elementos izquierdo y derecho. Suponga que no hay elementos duplicados.
*/
bool isRepetido(vector<int> array, int n, int elemento);

int main()
{
    int n, e, aux;
    cout << "Ingrese el numero de elementos del arreglo: ";
    cin >> n;
    vector<int> array;

    for (int i = 0; i < n; i++) {
        Ingreso:
        cout << "Elemento [" << i << "]";
        cin >> e;
        if (isRepetido(array, i, e)) {
            cout << "Elemento repetido, ingrese otro \n";
                goto Ingreso;
        }
        array.push_back(e);
    }

    // Imprimir array
    cout << "Array: \n";
    for (int i = 0; i < n; i++) {
        cout << array[i] << ", ";
    }
    
    // Reordenar array
    for (int i = 1; i < n; i = i + 2) {
        if (i + 1 < n) {
            if (array[i - 1] > array[i]) {
                aux = array[i - 1];
                array[i - 1] = array[i];
                array[i] = aux;
            }
            if (array[i] < array[i + 1]) {
                aux = array[i + 1];
                array[i + 1] = array[i];
                array[i] = aux;
            }
        }
    }

    cout << " \n Resultado: \n";
    // Imprimir resultado
    for (int i = 0; i < n; i++) {
        cout << array[i] << ", ";
    }

}

bool isRepetido(vector<int> array, int n, int element) {
    for (int i = 0; i < n; i++) {
        if (array[i] == element) {
            return true;
        }
    }
    return false;
}
