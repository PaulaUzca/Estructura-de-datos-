#include <iostream>
#include <time.h>
using namespace std;

/*
* En una clase se estaba decidiendo la actividad que se realizar�a como finalizaci�n de curso.
* En total se propusieron 12 actividades y cada estudiante deb�a votar por 1 de ellas.
* Los 35 estudiantes hacen su votaci�n y se representan en un arra. Como organizador de la actividad debes informar al grupo cu�l
* fue el resultado de la votaci�n indicando el n�mero de votos por cada opci�n
*/
int main()
{
    srand(time(NULL));
    int actividades[12] = {0,0,0,0,0,0,0,0,0,0,0,0};
    // Votaciones aleatorias
    for (int i = 0; i < 35; i++) {
        int randIndex = rand() % 12;
        actividades[randIndex] = actividades[randIndex] + 1;
    }

    // resultado
    int mayor = 0;
    for (int i = 0; i < 12; i++) {
        cout << i + 1 << " - " << actividades[i] << "\n";
        if (actividades[i] > actividades[mayor]) {
            mayor = i;
        }
    }
    int repetido = 0;
    for (int i = 0; i < 12; i++) {
        if (actividades[mayor] == actividades[i] && mayor != i) {
            cout << "Empate con actividad " << i + 1 << "\n";
            repetido++;
        }
    }
    if (repetido == 0) {
        cout << "Ganador es actividad " << mayor + 1;
    }
    else {
        cout << "Empate con actividad " << mayor + 1 << "\n";
    }
}
