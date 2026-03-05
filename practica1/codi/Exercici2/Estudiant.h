/*
 * Nom: Huang Jue
 * Cognoms: He Huang
 * Assignatura: Estructura de Dades
 * Grup E00
 */

#ifndef ESTUDIANT_H
#define ESTUDIANT_H
#include <string>

/* 
* Com es un .h file, no serveix using namespace std donat que altres arxius serveixen h com capçalera
*/

class Estudiant {
private:
    std::string nom;
    int anyNaixement;
    int numAssignatures;
    const int ANY_ACTUAL = 2026;

public:
    Estudiant(std::string n, int any, int assignatures);
    
    int getEdat();
    void print();
};

#endif