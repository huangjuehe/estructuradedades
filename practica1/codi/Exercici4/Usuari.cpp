#include "Usuari.h"
#include <iostream>

using namespace std;

Usuari::Usuari(string n, string a, string p, string t, string d, int e) {
    nom = n;
    adreca = a;
    poblacio = p;
    telefon = t;
    dni = d;
    edat = e;
}

string Usuari::getAdreca() { return adreca; }
string Usuari::getPoblacio() { return poblacio; }
string Usuari::getNom() { return nom; }
string Usuari::getTelefon() { return telefon; }
string Usuari::getDNI() { return dni; }
int Usuari::getEdat() { return edat; }

void Usuari::print() {
    cout << "DNI: " << dni << ", Nom: " << nom << ", Edat: " << edat 
              << ", Adreca: " << adreca << ", Poblacio: " << poblacio 
              << ", Telefon: " << telefon << "\n";
}

void Usuari::afegeixLlibre(string t, string a, string i, int any) {
    Llibre nouLlibre(t, a, i, any);
    llibres.push_back(nouLlibre);
}

void Usuari::eliminaLlibre(string t) {
    for (size_t i = 0; i < llibres.size(); i++) {
        if (llibres[i].getTitol() == t) {
            llibres.erase(llibres.begin() + i);
            return;
        }
    }
}

void Usuari::mostraLlibres() {
    for (size_t i = 0; i < llibres.size(); i++) {
        llibres[i].print();
    }
}