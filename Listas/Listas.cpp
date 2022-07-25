#include <iostream>
#include <vector>
using namespace std;

class Nodo {
private:
    int elemento;
    int* puntero;
public:
    Nodo(int element, int* pointer) {
        elemento = element;
        puntero = pointer;
    }
    void setElemento(int pElemento) {
        elemento = pElemento;
    }
    int getElemento() {
        return elemento;
    }
    void setPuntero(int* pPuntero) {
        puntero = pPuntero;
    }
    int* getPuntero() {
        return puntero;
    }
    int* getPosicionElemento() {
        return &elemento;
    }
    int getNextElement() {
        return *puntero;
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
    vector<Nodo> lista;
    int elem;
    for (int i = 0; i < n; i++) {
        cout << "lista [" << i << "]: ";
        cin >> elem;
        lista.push_back(Nodo(elem, 0));
    }
    for (int i = 0; i < n; i++) {
        if (i != n - 1) {
            lista[i].setPuntero(lista[i + 1].getPosicionElemento());
        }
        else {
            lista[i].setPuntero(0);
        }
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
            lista.insert(lista.begin(), Nodo(temp, lista[0].getPosicionElemento()));
            // Toca volver a asignar las posiciones de los nodos (?)
            for (int i = 0; i < lista.size(); i++) {
                if (i != lista.size() - 1) {
                    lista[i].setPuntero(lista[i + 1].getPosicionElemento());
                }
                else {
                    lista[i].setPuntero(0);
                }
            }
            break;
        case 'b':
            // Insertar nodo al final
            lista.push_back(Nodo(temp, 0));
            // Asignar la posicion del ultimo elemento a este
            lista[lista.size() - 2].setPuntero(lista[lista.size() - 2].getPosicionElemento());
            break;
        case 'c':
        ElementoX:
            // Insertar un nodo antes del elemento X
            cout << "Insertar antes del elemento de X: ";
            cin >> x;
            int posicion, i = 0;
            bool found = false, salir = false;
            while (!found) {
                if (lista[i].getElemento() == x) {
                    posicion = i;
                    found = true;
                }
                i++;
                if (i == lista.size()) {
                    cout << "No se ha encontrado el elemento " << x << "en la lista \nDesea volver  ingresar x (0) o volver al menu (1)";
                    cin >> salir;
                    if (!salir) {
                        goto Menu;
                    }
                    else {
                        goto ElementoX;
                    }
                }
            }
            if (posicion == 0) {
                lista.insert(lista.begin(), Nodo(temp, lista[posicion].getPosicionElemento()));
            }
            else {
                lista.insert(lista.begin() + posicion - 1, Nodo(temp, lista[posicion].getPosicionElemento()));
            }
            break;
        }
        goto Menu;
        break;
    case 'f':
        // Mostrar como quedo la lista
        for (int i = 0; i < lista.size(); i++) {
            cout << "[" << lista[i].getElemento() << " | " << lista[i].getPuntero() << "] -> ";
            if (i != lista.size() - 1) {
                cout << "(" << lista[i].getNextElement() << ") \n";
            }
            else {
                cout << "(end) \n";
            }
        }
        goto Menu;
        break;
    }

}
