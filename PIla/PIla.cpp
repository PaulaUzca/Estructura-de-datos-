#include <iostream>
#include <stdexcept>
using namespace std;

class Pila {
private:
    int *array;
    int tope = 0;
    int max = 0;
public:
    Pila(int *arr, int size) {
        array = arr;
        max = size;
    }
    void push(int element) {
        if (tope == max) {
            throw invalid_argument("Pila is full");
        }
        array[tope] = element;
        tope++;
    }

    void pop() {
        if (tope == 0) {
            throw invalid_argument("Pila is empty");
        }
        tope--;
        array[tope] = NULL;
    }

    void printPila() {
        for (int i = 0; i < tope; i++) {
             cout << array[i];
             if (i != tope - 1) {
                 cout << " -> ";
             }
        }
        cout << "\n";
    }
};

int main()
{
    /**
     * Implementar la función push y pop usando arrays
     */
    int array[15];
    Pila pila = Pila(array, 15);
    cout << "Ingresando elementos a la pila...\n";
    for (int i = 1; i < 12; i++) {
        try {
            pila.push(i);
            pila.printPila();
        }
        catch (invalid_argument& e) {
            cout << e.what() << "\n";
        }
    }
    cout << "Eliminando elementos de la pila...\n";
    for (int i = 0; i < 3; i++) {
        try {
            pila.pop();
            pila.printPila();
        }
        catch (invalid_argument& e) {
            cout << e.what() << "\n";
        }
    }

    pila.push(99);
    pila.printPila();
   
}