#include <iostream>
#include <vector>
using namespace std;

struct TreeNode {
private:
	int element;
	vector<TreeNode*> children;
public:
	TreeNode(int element) {
		this->element = element;
	}
	void addChild(TreeNode* child) {
		children.push_back(child);
	}
	void fillTree(TreeNode* nodo) {
		int hijos, e;
		cout << "Cuantos hijos tiene el nodo: ";
		cin >> hijos;
		for (int i = 0; i < hijos; i++) {
			cout << "Hijo " << i + 1 << ":";
			cin >> e;
			TreeNode* child = new TreeNode(e);
			fillTree(child);
			nodo->addChild(child);
		}
	}
	void printNodo() {
		cout << " [" << element <<"] ";
	}
	void printTree(TreeNode* nodo) {
		nodo->printNodo();
		if (nodo->children.size() > 0) {
			cout << "{";
			for (int i = 0; i < nodo->children.size(); i++) {
				printTree(nodo->children[i]);
			}
			cout << "}";
		}
	}
};

// Llenar un árbol desde 0
int main()
{
	int raiz, hijos, e;
	cout << "Ingrese el valor de la raiz del arbol: ";
	cin >> raiz;
	TreeNode* nodoRaiz = new TreeNode(raiz);
	nodoRaiz->fillTree(nodoRaiz);
	nodoRaiz->printTree(nodoRaiz);
}