/*
 * Nom: Huang Jue
 * Cognoms: He Huang
 * Assignatura: Estructura de Dades
 * Grup E00
 */

#include <iostream>
#include <string>
#include <stdexcept>
#include "Estudiant.h"

/*
 * - Servim try-catch al main per l'excepció invalid_argument de l'any de naixement que llança el constructor d'Estudiant.
 * - El comptador d'estudiants el passo per referència (int &comptador) a les funcions perquè el seu valor s'actualitzi correctament al main.
 */

using namespace std;

int show_menu(string options[], int num_options) {
    int option;
    do {
        cout << "Hola, que vols fer?\n";
        for (int i = 0; i < num_options; i++) {
            cout << i + 1 << ". " << options[i] << "\n";
        }
        cin >> option;
        if (option < 1 || option > num_options) {
            cout << "Opcio incorrecte. Torna a provar\n";
        }
    } while (option < 1 || option > num_options);
    return option;
}

void informar_estudiant(int &comptador) {
    string nom;
    int any, assignatures;

    cout << "Estudiant: " << comptador + 1 << "\n";
    cout << "Nom? ";
    cin >> nom;
    cout << "Any naixement? ";
    cin >> any;
    cout << "Assignatures? ";
    cin >> assignatures;

    try {
        Estudiant e(nom, any, assignatures);
        e.print();
        cout << "Edat del nou estudiant: " << e.getEdat() << "\n";
        comptador++;
    } catch (const invalid_argument& ex) {
        cout << ex.what() << "\n";
    }
}

int main() {
    int option;
    int comptador = 0;
    string arr_options[] = {"Sortir", "Informar estudiant"};
    int mida = 2;

    do {
        option = show_menu(arr_options, mida);
        switch (option) {
            case 1:
                cout << "Fins a la propera\n";
                break;
            case 2:
                informar_estudiant(comptador);
                break;
        }
    } while (option != 1);

    return 0;
}