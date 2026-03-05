#include "Llibre.h"
#include <iostream>

using namespace std;

Llibre::Llibre(string t, string a, string i, int any) {
    titol = t;
    autor = a;
    isbn = i;
    anyPublicacio = any;
}

string Llibre::getTitol() { 
    return titol; 
}

string Llibre::getAutor() { 
    return autor; 
}

string Llibre::getIsbn() {
    return isbn; 
}

int Llibre::getAnyPublicacio() { 
    return anyPublicacio; 
}

void Llibre::print() {
    cout << "Titol: " << titol << ", Autor: " << autor 
              << ", ISBN: " << isbn << ", Any: " << anyPublicacio << "\n";
}