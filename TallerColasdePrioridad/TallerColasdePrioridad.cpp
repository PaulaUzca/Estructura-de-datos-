#include <iostream>
#include <vector>
#include <exception>
#include <string>
using namespace std;


class Paciente {
private:
    string nombre;
    int edad;
    string sintomas;
    int gravedad;
public:
    Paciente() {

    }
    Paciente(string nombre, int edad, string sintomas, int gravedad) {
        this->nombre= nombre;
        this->edad = edad;
        this->sintomas = sintomas;
        this->gravedad = gravedad;
    }
    int getGravedad() {
        return gravedad;
    }
    int getEdad() {
        return edad;
    }
    string getSintomas() {
        return sintomas;
    }
    void setGravedad(int gravedad) {
        this->gravedad = gravedad;
    }
    string getNombre() {
        return nombre;
    }
    void imprimirPaciente() {
        cout << nombre << "(Edad: " << edad <<" Gravedad: "<< gravedad <<")\n";
    }
};

struct Nodo {
private:
    Paciente elemento;
    Nodo* next;
    Nodo* prev;
public:
    Nodo(Paciente elemento) {
        this->elemento=elemento;
        this->next = nullptr;
        this->prev = nullptr;
    }
    Nodo* getNext() {
        return next;
    }
    Nodo* getPrev() {
        return prev;
    }

    Paciente getElemento() {
        return elemento;
    }
    void setNext(Nodo* nodo ) {
        this->next = nodo;
    }
    void setPrev(Nodo* nodo) {
        this->prev = nodo;
    }
};

class Cola {
private:
    Nodo* first;
    // Encontrar el nodo con gravedad menor que el paciente
    void agregaAntesDeNodoConGravedadMenorQue(Nodo* paciente){
        Nodo* menor = first;
        while (menor->getNext() != nullptr && menor->getElemento().getGravedad() <= paciente->getElemento().getGravedad()) {
            menor = menor->getNext();
        }
        if (menor->getElemento().getGravedad() > paciente->getElemento().getGravedad()) {
            if (menor == first) {
                setFirst(paciente);
            }
            else {
                paciente->setNext(menor);
                paciente->setPrev(menor->getPrev());
                menor->getPrev()->setNext(paciente);
                menor->setPrev(paciente);
            }
        }
        else {
            menor->setNext(paciente);
            paciente->setPrev(menor);
            paciente->setNext(nullptr);
        }
    }

public:
    Cola() {
        first = nullptr;
    }
    void setFirst(Nodo* newNodo) {
        Nodo* aux = first;
        newNodo->setNext(aux);
        newNodo->setPrev(nullptr);
        aux->setPrev(newNodo);
        first = newNodo;
    }

    void queue(Paciente newPaciente) {
        Nodo* newNodo = new Nodo(newPaciente);
        if (first) {
            agregaAntesDeNodoConGravedadMenorQue(newNodo);
        }
        else {
            first = newNodo;
        }
        cout << "Turno " << posicionPaciente(newNodo) << " de " << getSize() << "\n";
    }

    Nodo dequeue() {
        if (first) {
            Nodo aux = *first;
            first = first->getNext();
            return aux;
        }
        else {
            throw invalid_argument("Cola vacia");
        }
    }

    // muestra la posicion de un paciente en la cola
    int posicionPaciente(Nodo* paciente) {
        if (first) {
            Nodo* aux = first;
            int i = 0;
            while (aux->getNext() != nullptr) {
                i++;
                if (paciente == aux) {
                    return i;
                }
                aux = aux->getNext();
            }
            return i + 1;
        }
        throw invalid_argument("Paciente no esta en la cola");
    }

    // Tamaño de la cola
    int getSize() {
        if (first) {
            Nodo* aux = first;
            int i = 1;
            while (aux->getNext() != nullptr) {
                aux = aux->getNext();
                i++;
            }
            return i;
        }
        else {
            throw invalid_argument("cola esta vacia");
        }
    }

    // Retorna true si otro paciente tiene la misma gravedad
    bool gravedadRepetida(Paciente paciente) {
        if (first) {
            Nodo* aux = first;
            while (aux->getNext() != nullptr && aux->getElemento().getGravedad() != paciente.getGravedad()) {
                aux = aux->getNext();
            }
            if (aux->getElemento().getGravedad() == paciente.getGravedad()) {
                return true;
            }
        }
        return false;
    }

    // Cambiar la gravedad segun la edad del paciente. Si esta entre 12 y 65 años pongale gravedad 4
    int getGravedadPorEdad(Paciente paciente) {
        if (gravedadRepetida(paciente)) {
            if (paciente.getEdad() < 12) {
                return 1;
            }
            if (paciente.getEdad() > 65) {
                return 2;
            }
            return 4;
        }
        return paciente.getGravedad();
    }

    void imprimirCola() {
        if (first) {
            Nodo* aux = first;
            for (int i = 0; i < getSize(); i++) {
                cout << i + 1 <<". ";
                aux->getElemento().imprimirPaciente();
                aux = aux->getNext();
            }
        }
        else {
            throw invalid_argument("cola esta vacia");
        }
    }
};


int main()
{
    Cola cola;
    // Registro de pacientes
    int opcion;
    Paciente paciente;
    Menu:
    cout << "\nMENU :\n 1. Ingresar paciente \n 2. Pasar siguiente paciente \n 3. Mostrar cola \nOpcion: ";
    cin >> opcion;
    switch (opcion) {
        case 1:
        {
            string nombre, sintomas;
            int edad, gravedad;
            cout << "REGISTRO \nNombre completo: ";
            getline(cin >> ws, nombre);
            cout << "Edad: ";
            cin >> edad;
            cout << "Sintomas o motivo de la consulta: ";
            getline(cin >> ws, sintomas);
            Gravedad:
            cout << "Gravedad (Escala numérica de 1 a 5 siendo 1 la mayor gravedad): ";
            cin >> gravedad;
            if (gravedad > 5 || gravedad < 1) {
                cout << "Gravedad debe ser entre 1 y 5\n";
                goto Gravedad;
            }
            paciente = Paciente(nombre, edad, sintomas, gravedad);

            // Asignar gravedad por prioridad
            paciente.setGravedad(cola.getGravedadPorEdad(paciente));

            cola.queue(paciente);
        }
            break;
        case 2:
            try {
                cout << "Turno de:";
                cola.dequeue().getElemento().imprimirPaciente();
            }
            catch (invalid_argument& e) {
                cout << e.what();
            }
            break;
        case 3:
            try {
                cola.imprimirCola();
            }
            catch (invalid_argument& e) {
                cout << e.what();
            }
            break;
        default:
            cout << "Opcion no valida";
            break;
    }
    goto Menu;
}
