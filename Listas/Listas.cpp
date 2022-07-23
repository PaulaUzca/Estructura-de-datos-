#include <iostream>
#include <vector>
using namespace std;
int main()
{
    /*
    El programa de iniciar creando una Lista de N nodos.
    Debe pedirse al usuario el número N de nodos iniciales de la listay leer cada uno de los valores.
    */
    cout << "Numero de nodos de la lista: ";
    int n;
    cin >> n;
    cout << "Ingrese los valores de la lista \n";
    vector<int*> listaPunteros;
    vector<int> lista;
    int temp;
    for (int i = 0; i < n; i++) {
        cout << "lista [" << i << "]: ";
        cin >> temp;
        lista.push_back(temp);
    }
    for (int i = 0; i < n; i++) {
        if (i != n - 1) {
            listaPunteros.push_back(&lista[i + 1]);
        }
        else {
            listaPunteros.push_back(0);
        }
    }

    // Mostrar menu
    char opcion, o;
    cout << "\na.Insertar Nodo \nb.Eliminar Nodo \nc.Buscar Nodo \nd.Tamaño de la Lista \ne.Comprobar Lista Vacía \nf.Mostrar Lista \ng.Vaciar Lista\nOpcion: ";
    cin >> opcion;
    switch (opcion) {
    case 'a':
        cout << "\na.InsertarNodo al inicio \nb.Insertar Nodo al final \nc.Insertar Nodo antes del Elemento X \nd.Insertar Nodo después del Elemento X\nOpcion: ";
        cin >> o;
        switch (o) {
        case 'a':
            // Insertar nodo al inicio
            int temp;
            cout << "Nuevo elemento: ";
            cin >> temp;
            lista.insert(lista.begin(), temp);
            listaPunteros.insert(listaPunteros.begin(), &temp);
            for (int i = 0; i < lista.size(); i++) {
                if (i != lista.size() - 1) {
                    listaPunteros[i] = &lista[i + 1];
                }
                else {
                    listaPunteros[i] = 0;
                }
            }
            break;
        }
        break;
    }

    // Mostrar como quedo la lista
    for (int i = 0; i < lista.size(); i++) {
        cout << "[" << lista[i] << " | " << listaPunteros[i] << "] -> ";
        if (i != lista.size() - 1) {
            cout << "(" << *listaPunteros[i] << ") \n";
        }
        else {
            cout << "(end) \n";
        }
    }

}
