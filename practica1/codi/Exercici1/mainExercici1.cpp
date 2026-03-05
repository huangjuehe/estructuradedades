/*
 * Nom: Huang Jue
 * Cognoms: He Huang
 * Assignatura: Estructura de Dades
 * Grup E00
 */

#include <vector>
#include <iostream>
using namespace std;

/*
 * - A la funció show_menu fem servir el bucle per les opcions una mida constant de 3. 
    Pero si afegim més opcions podem passar la mida a través de la funcio amb un sizeof() al main()
 * - Per a la validació de l'entrada he utilitzat un do-while, ja que primer hem de llegir l'opció com a mínim un cop abans de comprovar si és vàlida.
 */

int show_menu(string name, vector<string> options){
    int option;

    do {
        cout << "Hola " << name << ", que vols fer?\n";

        for (int i=0; i<3; i++){
            cout << i+1 << ". " << options[i] << "\n";
        }
        cin >> option;
        
        if (option < 1 || option > 3) {
            cout << "Opcio incorrecte. Torna a provar\n";
        }
    } while (option < 1 || option > 3);
    
    return option;
}

void hello_world(string name){
    cout << "Benvingut/da a l'assignatura d'estructura de dades " << name << endl;
}
int main(int argc, char **argv){
    int option;
    string name;
    string arr_options[] = {"Sortir", "Benvinguda", "Redefinir nom"};
    vector<string> options(arr_options, arr_options + 3);
    
    cout << "Hola, com et dius?\n";
    cin >> name;

    do{
        option = show_menu(name, options);

        switch (option){
            case 1:
                cout << "Fins a la propera " << name << endl;
                break;
            case 2:
                hello_world(name);
                break;
            case 3:
                cout << "Hola, com et dius?\n";
                cin >> name;
                break;
        }
    } while (option!=1);
    
    return 0;
}