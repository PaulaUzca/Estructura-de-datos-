#include <iostream>
#include <string>
using namespace std;

// Estructura para los nodos del arbol
struct Nodo {
private:
    int elemento;
    Nodo* left;
    Nodo* right;
public:
    Nodo(int elemento) {
        this->elemento = elemento;
        this->right = nullptr;
        this->left = nullptr;
    }
    void setLeft(Nodo* left) {
        this->left = left;
    }
    void setRight(Nodo* right) {
        this->right = right;
    }
    Nodo* getRight() {
        return right;
    }
    Nodo* getLeft() {
        return left;
    }
    int getElemento() {
        return elemento;
    }
    void setElemento(int elemento) {
        this->elemento = elemento;
    }

    void printNode(Nodo* root) {
        cout << root->getElemento() << "\n";
        if (root->getLeft()) {
            printNode(root->getLeft());
        }
        else {
            cout << "[ ]";
        }
        if (root->getRight()) {
            printNode(root->getRight());
        }
        else {
            cout << "[ ]";
        }
        cout << "\n";
    }

    void addElement(int e) {
        insertElement(this, e);
    }
    // Insertar un elemento
    Nodo* insertElement(Nodo* root, int e) {
        if (root == nullptr) {
            root = new Nodo(e);
        }
        else {
            if (root->getElemento() > e)
                root->setLeft(insertElement(root->getLeft(), e));

            if (root->getElemento() < e)
                root->setRight(insertElement(root->getRight(), e));
        }

        return root;

    }

    // Buscar un elemento en el arbol, si no esta retorna a su padre
    Nodo* buscarElemento(Nodo* root, int e) {
        if (!root || root->getElemento() == e)
            return root;
        if (root->getElemento() < e && root->getRight())
            return buscarElemento(root->getRight(), e);

        if (root->getElemento() > e && root->getLeft())
            return buscarElemento(root->getLeft(), e);

        else return root;
    }

    // Eliminar un nodo en el arbol
    Nodo* eliminarNodo(Nodo* root, int e) {
        if (root == nullptr) {
            return root;
        }

        // Si el elemento a eliminar es MAYOR que la raiz, entonces debe estar a la derecha
        if (root->getElemento() < e)
            root->setRight(eliminarNodo(root->getRight(), e));

        // Si el elemento a eliminar es MENOR que la raiz, entonces debe estar a la izquierda
        if (root->getElemento() > e)
            root->setLeft(eliminarNodo(root->getLeft(), e));

        // Si el elemento que estoy viendo es el que deseo eliminar
        if (root->getElemento() == e) {

            // si es un nodo hoja entonces al padre simplemente lo apunto a NULL
            if (!root->getLeft() && !root->getRight())
                return nullptr;

            // si tiene un hijo izquierdo PERO NO tiene uno derecho
            if (root->getLeft() && !root->getRight())
                return root->getLeft();

            // si tiene un hijo derecho PERO NO tiene uno izquierdo
            if (root->getRight() && !root->getLeft())
                return root->getRight();

            // Si tiene 2 hijos
            if (root->getRight() && root->getLeft()) {
                // Vamos a remplazar por el más pequeño del subarbol derecho
                int nuevaRoot = findMin(root->getRight());
                eliminarNodo(root, nuevaRoot);
                root->setElemento(nuevaRoot);
            }
        }
    }

    // Encontrar el elemento mas pequeño partiendo de una raiz
    int findMin(Nodo* root) {
        if (root->getLeft())
            return findMin(root->getLeft());
        else
            return root->getElemento();
    }

    // Encontrar el elemento mas grande partiendo de una raiz
    int findMax(Nodo* root) {
        if (root->getRight())
            return findMax(root->getRight());
        else
            return root->getElemento();
    }
};


int main()
{
    Nodo* raiz = new Nodo(3);
    raiz->addElement(5);
    raiz->printNode(raiz);
    raiz->addElement(4);
    raiz->printNode(raiz);
    raiz->addElement(7);
    raiz->printNode(raiz);
    raiz->addElement(10);
    raiz->printNode(raiz);
    raiz->addElement(12);
    raiz->printNode(raiz);
}