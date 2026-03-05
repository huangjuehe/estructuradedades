/*
 * Nom: Huang Jue
 * Cognoms: He Huang
 * Assignatura: Estructura de Dades
 * Grup E00
 */

#include "Estudiant.h"
#include <iostream>
#include <stdexcept>
using namespace std;

Estudiant::Estudiant(string n, int any, int assignatures) {
    if (any <= 0 || any > ANY_ACTUAL)
        throw invalid_argument("Any de naixement incorrecte");
    
    nom = n;
    anyNaixement = any;
    numAssignatures = assignatures;
}

int Estudiant::getEdat() {
    return ANY_ACTUAL - anyNaixement;
}

void Estudiant::print() {
    cout << "Estudiant (Nom ==> " << nom << ", Naixement ==> " << anyNaixement 
        << ", Assignatures ==> " << numAssignatures << ")" << endl; 
}