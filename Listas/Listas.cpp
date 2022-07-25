#include <iostream>
#include <vector>
#include <windows.h>
#include <ctime>
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
    void print() {
        cout << "[" << getElemento() << " | " << getPuntero() << "] -> ";
        if (getPuntero()) {
            cout << "(" << getNextElement() << ") \n";
        }
        else {
            cout << "(end)";
        }
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
    // Agregar un elemento al comienzo de la lista
    void addStart(Nodo* e) {
        if (first) {
            e->setPuntero(first);
            first = e;
        }
        else {
            setFirst(e);
        }
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
    // Insertar un nodo antes del elemento X
    bool insertaNodoAntesDeElemento(int x, Nodo* nuevo) {
        if (first) {
            Nodo* anterior = first;
            // Si el elemento esta en la primera posicion
            if (first->getElemento() == x) {
                nuevo->setPuntero(first);
                first = nuevo;
                return true;
            }
            else {
                while (anterior->getPuntero() && anterior->getNextElement() != x) {
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
        }
        else {
            return false;
        }
    }
    // Insertar un nodo despues del elemento X
    bool insertaNodoDespuesDeElemento(int x, Nodo* nuevo) {
        if (first) {
            Nodo* anterior = first;
            while (anterior->getPuntero() && anterior->getElemento() != x) {
                anterior = anterior->getPuntero();
            }
            if (anterior->getElemento() == x) {
                if (!anterior->getPuntero()) {
                    addEnd(nuevo);
                }
                else {
                    nuevo->setPuntero(anterior->getPuntero());
                    anterior->setPuntero(nuevo);
                }
                return true;
            }
            else {
                return false;
            }
        }
        else {
            return false;
        }
    }
    // Retorna true si el elemento esta en la lista
    bool isElementInList(int element) {
        Nodo* temp = first;
        while (temp->getElemento()!=element && temp->getPuntero()) {
            temp = temp->getPuntero();
        }
        if (!temp->getPuntero() && temp->getElemento() != element) {
            return false;
        }
        return true;
    }
    // Eliminar un nodo por el elemento
    bool deleteNodo(int element) {
        if (isElementInList(element)) {
            // Si desea eliminar el primer nodo
            if (first->getElemento() == element) {
                first = first->getPuntero();
            }
            else {
                Nodo* anterior = first;
                // Buscar el elemento anterior al que se desea eliminar
                while (anterior->getPuntero() && anterior->getNextElement() != element) {
                    anterior = anterior->getPuntero();
                }
                // Hacer que el elemento anterior apunte al siguiente del que se desea eliminar. Si no hay siguiente que apunte a nulo
                Nodo* nodoToDelete = anterior->getPuntero();
                if (!nodoToDelete->getPuntero()) {
                    anterior->setPuntero(nullptr);
                }
                else {
                    anterior->setPuntero(nodoToDelete->getPuntero());
                }
            }
            return true;
        }
        return false;
    }

    Nodo* buscarPorIndex(int index) {
        int i = 0;
        Nodo* temp = first;
        while (temp->getPuntero() && i != index) {
            temp = temp->getPuntero();
            i++;
        }
        return temp;
    }

    void imprimirLista() {
        cout << "\n";
        Nodo* nodo = getFirst();
        for (int i = 0; i < getSize(); i++) {
            nodo->print();
            if (nodo->getPuntero()) {
                nodo = nodo->getPuntero();
            }
        }
        cout << "\n";
    }

};


//Mostrar un mensaje de error en color rojo en la consola
void mostrarError(string mensaje) {
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
    cout << mensaje << "\n";
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
}

/*
* Una función que genere al iniciar una lista de N nodos,
  N = (último dígito del código de estudiante) * 3
  Los valores de cada nodo deben ser generados de forma aleatoria.
  Realizar la comprobación de la función Insertar Nodo así:
  Insertar el nodo H = (penúltimodigito del código) * 16, al inicio de la lista
  Insertar el nodo I = (quinto digito del código) * 8, al final de la lista
  Insertar el nodo J = (tercer digito del código) * 40, después del nodo con valor H
  Insertar el nodo K = (cuartodigito del código) * 3, antes del nodo con valor I
  */
Lista testEstructura() {
    Lista lista;
    // Codigo estudiante: 2211475
    int N = 5 * 3;
    srand(time(0));
    for (int i = 1; i < N; i++) {
        lista.addEnd(new Nodo(rand(), nullptr));
    }
    lista.imprimirLista();

}


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
    Nodo* nodo = new Nodo(elem, nullptr);
    Lista lista;

    for (int i = 0; i < n; i++) {
        cout << "lista [" << i << "]: ";
        cin >> elem;
        nodo = new Nodo(elem, nullptr);
        lista.addEnd(nodo);
    }

    Menu:
    // Mostrar menu
    char opcionMenu, opcionInsertar, opcionBuscar;
    int nuevoValor; // Valor del elemento del nuevo nodo
    int x; // Elemento X del nodo
    bool found;
    cout << "\n\n\tMENU:\na.Insertar Nodo \nb.Eliminar Nodo \nc.Buscar Nodo \nd.Tamaño de la Lista \ne.Comprobar Lista Vacía \nf.Mostrar Lista \ng.Vaciar Lista\nOpcion: ";
    cin >> opcionMenu;
    cout << "\n";
    switch (opcionMenu) {
    case 'a':
        // Insertar un nodo
        MenuInsertar:
        cout << "\ta.Insertar Nodo al inicio \n\tb.Insertar Nodo al final \n\tc.Insertar Nodo antes del Elemento X \n\td.Insertar Nodo después del Elemento X\n\tOpcion: ";
        cin >> opcionInsertar;
        cout << "Nuevo elemento: ";
        cin >> nuevoValor;
        switch (opcionInsertar) {
        case 'a':
            // Insertar nodo al inicio
            nodo = new Nodo(nuevoValor, nullptr);
            lista.addStart(nodo);
            break;
        case 'b':
            // Insertar nodo al final
            lista.addEnd(new Nodo(nuevoValor, nullptr));
            break;
        case 'c':
            // Insertar un nodo antes del elemento X
            cout << "Insertar antes del elemento de X: ";
            cin >> x;
            found = lista.insertaNodoAntesDeElemento(x, new Nodo(nuevoValor, nullptr));
            if (!found) {
                mostrarError("No se ha encontrado el elemento X = " + x);
            }
            break;
        case 'd':
            // Insertar un nodo despues del elemento X
            cout << "Insertar despues del elemento de X: ";
            cin >> x;
            found = lista.insertaNodoDespuesDeElemento(x, new Nodo(nuevoValor, nullptr));
            if (!found) {
                mostrarError("No se ha encontrado el elemento X = " + x);
            }
            break;
        default:
            cout << "Opción no valida";
            goto MenuInsertar;
            break;
        }
        goto Menu;
        break;
    case 'b':
        // Eliminar un nodo
        cout << "Elemento que desea eliminar: ";
        cin >> x;
        found = lista.deleteNodo(x);
        if (!found) {
            mostrarError("El elemento que desea eliminar no se encuentra en la lista = " + x);
        }
        goto Menu;
        break;
    case 'c':
        // Buscar nodo
        MenuBuscar:
        cout << "\t\ta. Buscar por posicion\n\t\tb. Buscar por elemento\n\t\tOpcion: ";
        cin >> opcionBuscar;
        switch (opcionBuscar) {
        case 'a':
            int index;
            cout << "Index (empezando en 0): ";
            cin >> index;
            if (index > lista.getSize()) {
                cout << "El index esta fuera de los limites";
            }
            else {
                lista.buscarPorIndex(index)->print();
            }
            break;
        case 'b':
            int elemento;
            cout << "Elemento: ";
            cin >> elemento;
            if (lista.isElementInList(elemento)) {
                cout << elemento <<" esta en la lista";
            }
            else {
                cout << elemento << " no esta en la lista";
            }
        default:
            cout << "Opcion no valida";
            goto MenuBuscar;
            break;
        }
        goto Menu;
        break;
    case 'd':
        // Tamaño de la lista
        cout << "Tamaño de la lista: " << lista.getSize();
        goto Menu;
        break;
        // 
    case 'e':
        // Comprobar lista vacia
        if (lista.getFirst()) {
            cout << "Lista NO vacia";
        }
        else {
            cout << "Lista vacia";
        }
        goto Menu;
        break;
    case 'f':
        // Mostrar como quedo la lista
        lista.imprimirLista();
        goto Menu;
        break;
    case 'g':
        // Vaciar lista
        if (lista.getSize()) {
            lista.setFirst(nullptr);
            cout << "Se ha vaciado la lista";
        }
        else {
            cout << "La lista ya estaba vacia";
        }
        goto Menu;
        break;
    default:
        cout << "Opcion no valida";
        goto Menu;
        break;
    }
}

