#include <iostream>
#include <vector>
using namespace std;

struct Nodo {
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
    Nodo* getPosicion() {
        return this;
    }
    int getNextElement() {
        return puntero->getElemento();
    }
};

class Lista {
private:
    Nodo* first;
public:
    // Inicializar el primer nodo de la lista
    void setFirst(Nodo* primerNodo) {
        first = primerNodo;
    }
    // Obtener el primer nodo
    Nodo* getFirst() {
        return first;
    }
    // Agrega un elemento al final de la lista
    void addEnd(Nodo* e) {
        Nodo* temp = first;
        while (temp->getPuntero()) {
            temp = temp->getPuntero();
        }
        temp->setPuntero(e);
    }
    // Agregar un elemento al comienzo de la lista
    void addStart(Nodo* e) {
        e->setPuntero(first);
        first = e;
    }
    //Obtener el tamaño de la lista
    int getSize() {
        int i = 1;
        Nodo* temp = first;
        while (temp->getPuntero()) {
            temp = temp->getPuntero();
            i++;
        }
        return i;
    }
    // Insertar un nodo antes del elemento X
    bool insertaNodoAntesDeElemento(int x, Nodo* nuevo) {
        Nodo* anterior = first;
        while (anterior->getPuntero() && anterior->getPuntero()->getElemento() != x) {
            anterior = anterior->getPuntero();
        }
        if (!anterior->getPuntero()) {
            return false;
        }
        else {
            nuevo->setPuntero(anterior->getPuntero());
            anterior->setPuntero(nuevo);
            return true;
        }
    }
    // Insertar un nodo antes del elemento X
    bool insertaNodoDespuesDeElemento(int x, Nodo* nuevo) {
        Nodo* anterior = first;
        bool found = false;
        while (anterior->getPuntero() && found) {
            if (anterior->getElemento() == x) {
                found = true;
            }
            else {
                anterior = anterior->getPuntero();
            }
        }
        if (anterior->getElemento() == x) {
            if (!anterior->getPuntero()) {
                addEnd(nuevo);
            }
            else {
                nuevo->setPuntero(anterior->getPuntero());
                anterior->setPuntero(nuevo);
                return true;
            }
        }
        else {
            return false;
        }
    }
    bool isElementInList(int element) {
        Nodo* temp = first;
        bool found = false;
        while (temp->getPuntero()) {
            temp = temp->getPuntero();
        }
    }

};

int main()
{
    /*
    El programa de iniciar creando una Lista de N nodos.
    Debe pedirse al usuario el número N de nodos iniciales de la lista y leer cada uno de los valores.
    */
    cout << "Numero de nodos de la lista: ";
    int n;
    cin >> n;
    cout << "Ingrese los valores de la lista \n";
    int elem;
    cout << "lista [" << 0 << "]: ";
    cin >> elem;
    Nodo* nodo = new Nodo(elem, nullptr);
    Lista lista;
    lista.setFirst(nodo);

    for (int i = 1; i < n; i++) {
        cout << "lista [" << i << "]: ";
        cin >> elem;
        nodo = new Nodo(elem, nullptr);
        lista.addEnd(nodo);
    }

    Menu:
    // Mostrar menu
    char opcion, o;
    int temp, x;
    cout << "\na.Insertar Nodo \nb.Eliminar Nodo \nc.Buscar Nodo \nd.Tamaño de la Lista \ne.Comprobar Lista Vacía \nf.Mostrar Lista \ng.Vaciar Lista\nOpcion: ";
    cin >> opcion;
    switch (opcion) {
    case 'a':
        cout << "\na.Insertar Nodo al inicio \nb.Insertar Nodo al final \nc.Insertar Nodo antes del Elemento X \nd.Insertar Nodo después del Elemento X\nOpcion: ";
        cin >> o;
        cout << "Nuevo elemento: ";
        cin >> temp;
        switch (o) {
        case 'a':
            // Insertar nodo al inicio
            nodo = new Nodo(temp, nullptr);
            lista.addStart(nodo);
            break;
        case 'b':
            // Insertar nodo al final
            lista.addEnd(new Nodo(temp, nullptr));
            break;
        case 'c':
            // Insertar un nodo antes del elemento X
            cout << "Insertar antes del elemento de X: ";
            cin >> x;
            bool found = lista.insertaNodoAntesDeElemento(x, new Nodo(temp, nullptr));
            if (!found) {
                cout << "No se ha encontrado el elemento X = " << x<< "\n";
            }
            break;
        case 'd':
            // Insertar un nodo despues del elemento X
            cout << "Insertar antes del elemento de X: ";
            cin >> x;
            bool found = lista.insertaNodoDespuesDeElemento(x, new Nodo(temp, nullptr));
            if (!found) {
                cout << "No se ha encontrado el elemento X = " << x << "\n";
            }
            break;
        }
        goto Menu;
        break;
    case 'f':
        // Mostrar como quedo la lista
        nodo = lista.getFirst();
        for (int i = 0; i < lista.getSize(); i++) {
            cout << "[" << nodo->getElemento() << " | " << nodo->getPuntero() << "] -> ";
            if (nodo->getPuntero()) {
                nodo = nodo->getPuntero();
                cout << "(" << nodo->getElemento() << ") \n";
            }
            else {
                cout << "(end)";
            }
        }
        goto Menu;
        break;
    }
}
