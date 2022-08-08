#include <iostream>
#include <stdexcept>
using namespace std;

/* Estructura de Nodo, contiene dos atributos:
* elemento: el numero que se guarda en el nodo
* puntero: apunta al siguiente elemento de la lista, si no hay es NULO
*/
struct Nodo {
private:
    int elemento;
    Nodo* puntero;
public:
    Nodo(int element, Nodo* pointer) {
        elemento = element;
        puntero = pointer;
    }
    void setElemento(int pElemento) {
        elemento = pElemento;
    }
    int getElemento() {
        return elemento;
    }
    void setPuntero(Nodo* pPuntero) {
        puntero = pPuntero;
    }
    Nodo* getPuntero() {
        return puntero;
    }
    int getNextElement() {
        return puntero->getElemento();
    }
    void printCompleto() {
        cout << "[" << getElemento() << " | " << getPuntero() << "] -> ";
        if (getPuntero()) {
            cout << "(" << getNextElement() << ") \n";
        }
        else {
            cout << "(end)";
        }
    }
    void print() {
        cout << "[" << getElemento() << "]";
    }
};

/* Cola de nodos, contiene el nodo inicial de la lista,
y metodos para insertra, buscar o eliminar los nodos que le siguen al primero
*/
class Cola {
private:
    Nodo* first;
public:
    Cola() {
        first = nullptr;
    }
    // Inicializar el primer nodo de la lista
    void setFirst(Nodo* primerNodo) {
        first = primerNodo;
    }
    //Obtener el tamaño de la lista
    int getSize() {
        int i = 0;
        if (first) {
            i = 1;
            Nodo* temp = first;
            while (temp->getPuntero()) {
                temp = temp->getPuntero();
                i++;
            }
        }
        return i;
    }
    // Agrega un elemento al final de la cola (encolar)
    void queue(int element) {
        Nodo *e = new Nodo(element, nullptr);
        if (first) {
            Nodo* temp = first;
            while (temp->getPuntero()) {
                temp = temp->getPuntero();
            }
            temp->setPuntero(e);
        }
        else {
            setFirst(e);
        }
    }

    // Sacar un elemento de la cola (descolar)
    void dequeue() {
        if (first == nullptr) {
            throw invalid_argument("La cola esta vacia");
        }
        first = first->getPuntero();
    }

    void imprimirCola() {
        cout << "\n";
        Nodo* nodo = first;
        for (int i = 0; i < getSize(); i++) {
            nodo->print();
            if (nodo->getPuntero()) {
                nodo = nodo->getPuntero();
            }
        }
    }

};


int main()
{
    Cola cola = Cola();
    // agregar elementos a la cola
    cout << "Agregando elementos a la cola... \n";
    for (int i = 1; i < 10; i++) {
            cola.queue(i);
            cola.imprimirCola();
    }
    cout << "\n Sacando elementos de la cola... \n";
    for (int i = 1; i < 11; i++ ) {
        try {
            cola.dequeue();
            cola.imprimirCola();
        }
        catch (invalid_argument& e) {
            cout << e.what();
        }
    }
}

