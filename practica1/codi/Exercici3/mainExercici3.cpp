/*
 * Nom: Huang Jue
 * Cognoms: He Huang
 * Assignatura: Estructura de Dades
 * Grup E00
 */

#include <iostream>
#include <string>
#include <stdexcept>
#include <fstream>
#include "Estudiant.h"

using namespace std;

/*
 * - Mateixa lògica que mainExercici3.cpp
 */

int show_menu(string options[], int num_options) {
    int option;
    do {
        cout << "Hola, que vols fer?\n";
        for (int i = 0; i < num_options; i++) {
            cout << i + 1 << ". " << options[i] << "\n";
        }
        cin >> option;
    } while (option < 1 || option > num_options);
    return option;
}

void informar_estudiant(int &comptador) {
    string nom;
    int any, assignatures;
    cout << "Nom? ";
    cin >> nom;
    cout << "Any naixement? ";
    cin >> any;
    cout << "Assignatures? ";
    cin >> assignatures;

    try {
        Estudiant e(nom, any, assignatures);
        e.print();
        comptador++;
    } catch (const std::invalid_argument& ex) {
        cout << "Any de naixement incorrecte\n";
    }
}

void llegir_fitxer(int &comptador) {
    string ruta;
    cout << "Ruta arxiu:\n";
    cin >> ruta;

    ifstream fitxer(ruta);
    if (!fitxer.is_open()) {
        return;
    }

    string nom;
    int any, assignatures;
    while (fitxer >> nom >> any >> assignatures) {
        try {
            Estudiant e(nom, any, assignatures);
            e.print();
            comptador++;
        } catch (const std::invalid_argument& ex) {
        }
    }
    fitxer.close();
}

void resum_estudiants(int comptador) {
    cout << "Estudiants creats: " << comptador << "\n";
}

int main() {
    int option;
    int comptador = 0;
    string arr_options[] = {"Sortir", "Afegir estudiant", "Llegir fitxer", "Resum estudiants"};
    int mida = 4;

    do {
        option = show_menu(arr_options, mida);
        switch (option) {
            case 1:
                cout << "Fins a la propera\n";
                break;
            case 2:
                informar_estudiant(comptador);
                break;
            case 3:
                llegir_fitxer(comptador);
                break;
            case 4:
                resum_estudiants(comptador);
                break;
        }
    } while (option != 1);

    return 0;
}