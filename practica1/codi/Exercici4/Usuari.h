/*
 * Nom: Huang Jue
 * Cognoms: He Huang
 * Assignatura: Estructura de Dades
 * Grup E00
 */

#ifndef USUARI_H
#define USUARI_H
#include <string>
#include <vector>
#include "Llibre.h"

/* 
* Com es un .h file, no serveix using namespace std donat que altres arxius serveixen h com capçalera
*/

class Usuari {
private:
    std::string nom;
    std::string adreca;
    std::string poblacio;
    std::string telefon;
    std::string dni;
    int edat;
    std::vector<Llibre> llibres;

public:
    Usuari(std::string n, std::string a, std::string p, std::string t, std::string d, int e);
    std::string getAdreca();
    std::string getPoblacio();
    std::string getNom();
    std::string getTelefon();
    std::string getDNI();
    int getEdat();
    void print();
    void afegeixLlibre(std::string t, std::string a, std::string i, int any);
    void eliminaLlibre(std::string t);
    void mostraLlibres();
};

#endif