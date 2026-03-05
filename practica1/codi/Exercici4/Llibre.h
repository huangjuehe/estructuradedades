/*
 * Nom: Huang Jue
 * Cognoms: He Huang
 * Assignatura: Estructura de Dades
 * Grup E00
 */

#ifndef LLIBRE_H
#define LLIBRE_H
#include <string>

/* 
* Com es un .h file, no serveix using namespace std donat que altres arxius serveixen h com capçalera
*/

class Llibre {
private:
    std::string titol;
    std::string autor;
    std::string isbn;
    int anyPublicacio;

public:
    Llibre(std::string t, std::string a, std::string i, int any);
    std::string getTitol();
    std::string getAutor();
    std::string getIsbn();
    int getAnyPublicacio();
    void print();
};

#endif