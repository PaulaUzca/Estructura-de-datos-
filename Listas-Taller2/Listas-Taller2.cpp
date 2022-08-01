#include <iostream>
#include <windows.h>
#include <ctime>
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
        cout << "[" << getElemento() << "]\n";
    }
};

/* Lista de nodos, contiene el nodo inicial de la lista,
y metodos para insertra, buscar o eliminar los nodos que le siguen al primero
*/
class Lista {
private:
    Nodo* first;
public:
    Lista() {
        first = nullptr;
    }
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
                    throw invalid_argument("El elemento no se encuentra en la lista");
                }
                else {
                    nuevo->setPuntero(anterior->getPuntero());
                    anterior->setPuntero(nuevo);
                    return true;
                }
            }
        }
        else {
            throw invalid_argument("La lista esta vacia");
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
                throw invalid_argument("El elemento no se encuentra en la lista");
            }
        }
        else {
            throw invalid_argument("La lista esta vacia");
        }
    }

    // Retorna el index del elemento
    int indexOf(int element) {
        if(!first){
            throw invalid_argument("La lista esta vacia");
        }
        Nodo* temp = first;
        int index = 0;
        while (temp->getElemento() != element && temp->getPuntero()) {
            temp = temp->getPuntero();
            index++;
        }
        if (!temp->getPuntero() && temp->getElemento() != element) {
            throw invalid_argument("El elemento no se encuentra en la lista");
        }
        return index;
    }
    // Retorna true si el elemento esta en la lista
    bool isElementInList(int element) {
        if (!first) {
            return false;
        }
        Nodo* temp = first;
        while (temp->getElemento() != element && temp->getPuntero()) {
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
        throw invalid_argument("El elemento no se encuentra en la lista");
    }
    
    // Eliminar un nodo segun su posicion en la lista
    bool deleteNodoByIndex(int index) {
        if (first == nullptr || index >= getSize()) {
            throw invalid_argument("Index fuera de los limites");
        }
        if (index == 0) {
           first = first->getPuntero();
        }
        else {
            int i = 0;
            Nodo* temp = first;
            // Buscar el nodo en el index anterior al que deseo eliminar
            while (temp->getPuntero() && i != index - 1) {
                temp = temp->getPuntero();
                i++;
            }
            // Asigno al valor anterior, el nodo al que apunta el nodo que deseo eliminar
            temp->setPuntero(temp->getPuntero()->getPuntero());
        }
        return true;
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
            nodo->printCompleto();
            if (nodo->getPuntero()) {
                nodo = nodo->getPuntero();
            }
        }
        cout << "\n";
    }
    void imprimirListaIndex() {
        cout << "\nIndex\tElemento-Memoria\tApunta a\n";
        Nodo* nodo = getFirst();
        for (int i = 0; i < getSize(); i++) {
            cout << "(" << i << ") - ";
            nodo->printCompleto();
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

/* Actividad #1 de menu para modificar una lista*/
void showMenu() {
    /*
  El programa de iniciar creando una Lista de N nodos.
  Debe pedirse al usuario el numero N de nodos iniciales de la lista y leer cada uno de los valores.
  */
    cout << "Numero de nodos de la lista: ";
    int n;
    cin >> n;
    cout << "Ingrese los valores de la lista \n";
    int elem;
    Nodo* nodo;
    Lista lista;

    for (int i = 0; i < n; i++) {
        cout << "lista [" << i << "]: ";
        cin >> elem;
        nodo = new Nodo(elem, nullptr);
        lista.addEnd(nodo);
    }

Menu:
    // Mostrar menu
    char opcionMenu, opcionInsertar, opcionEliminar;
    int nuevoValor; // Valor del elemento del nuevo nodo
    int x; // Elemento X del nodo
    bool found;
    cout << "\n\nMENU:\na.Insertar Nodo \nb.Eliminar Nodo \nc.Buscar Nodo \nd.Tamaño de la Lista \ne.Comprobar Lista Vacia \nf.Mostrar Lista \ng.Vaciar Lista\nOpcion: ";
    cin >> opcionMenu;
    cout << "\n";
    switch (opcionMenu) {
    case 'a':
        // Insertar un nodo
    MenuInsertar:
        cout << "\ta.Insertar Nodo al inicio \n\tb.Insertar Nodo al final \n\tc.Insertar Nodo antes del Elemento X \n\td.Insertar Nodo despues del Elemento X\n\tOpcion: ";
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
            cout << "Insertar antes del elemento X: ";
            cin >> x;
            try {
                lista.insertaNodoAntesDeElemento(x, new Nodo(nuevoValor, nullptr));
            }
            catch (invalid_argument& e) {
                cout << e.what();
            }
            break;
        case 'd':
            // Insertar un nodo despues del elemento X
            cout << "Insertar despues del elemento de X: ";
            cin >> x;
            try {
                lista.insertaNodoDespuesDeElemento(x, new Nodo(nuevoValor, nullptr));
            }
            catch (invalid_argument& e) {
                cout << e.what();
            }
            break;
        default:
            cout << "Opcion no valida";
            goto MenuInsertar;
            break;
        }
        goto Menu;
        break;
    case 'b':
        // Eliminar un nodo
        cout << "\ta. Eliminar nodo al inicio\n\tb. Eliminar nodo al final\n\tOpcion: ";
        cin >> opcionEliminar;
        switch (opcionEliminar) {
            case 'a':
                try {
                    lista.deleteNodoByIndex(0);
                }
                catch (invalid_argument& e) {
                    cout << e.what();
                }
                break;
            case 'b':
                try {
                    lista.deleteNodoByIndex(lista.getSize() - 1);
                }
                catch (invalid_argument& e) {
                    cout << e.what();
                }
                break;
            default:
                cout << "Opción no válida";
                break;
        }
        goto Menu;
        break;
    case 'c':
        // Buscar index del nodo por elemento
        int elemento;
        cout << "Elemento: ";
        cin >> elemento;
        try {
            cout<<lista.indexOf(elemento);
        }
        catch (invalid_argument e) {
            cout << e.what();
        }
        goto Menu;
        break;
    case 'd':
        // Tamaño de la lista
        cout << "Tamano de la lista: " << lista.getSize();
        goto Menu;
        break;
        // 
    case 'e':
        // Comprobar lista vacia
        cout << "La lista esta vacia? ";
        if (lista.getFirst()) {
            cout << "No";
        }
        else {
            cout << "Si";
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

int main()
{
    // Taller #2 de listas
    showMenu();
}
