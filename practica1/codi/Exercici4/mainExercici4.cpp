/*
 * Nom: Huang Jue
 * Cognoms: He Huang
 * Assignatura: Estructura de Dades
 * Grup E00

 * - He fet servir vector<Usuari> i vector<Llibre> en lloc d'arrays normals 
 *  -> afegir i eliminar elements fàcilment amb push_back() i erase().
 * - Quan s'afegeix un usuari, comprovo si el DNI ja existeix recorrent el vector amb 
 *  la funció auxiliar cercarUsuari, que retorna la posició o un -1 si no el troba.
 * - Per garantir que el DNI i les dades dels llibres sempre es guarden i es comparen, es serveix aMiniscules()
 */

#include <iostream>
#include <string>
#include <vector>
#include <cctype> // Necessari per utilitzar la funció tolower()
#include "Usuari.h"

using namespace std;

// Funció auxiliar per passar qualsevol string a minúscules
void aMinuscules(string& text) {
    for (size_t i = 0; i < text.length(); i++) {
        text[i] = tolower(text[i]);
    }
}

int cercarUsuari(vector<Usuari>& usuaris, string dni) {
    for (size_t i = 0; i < usuaris.size(); i++) {
        if (usuaris[i].getDNI() == dni) {
            return i;
        }
    }
    return -1;
}

void afegirUsuari(vector<Usuari>& usuaris) {
    string nom, adreca, poblacio, telefon, dni;
    int edat;
    
    cout << "DNI: "; 
    cin >> dni;
    aMinuscules(dni); // Passem el DNI a minúscules

    if (cercarUsuari(usuaris, dni) != -1) {
        cout << "L'usuari ja existeix.\n";
        return;
    }

    // Netejar el buffer després d'un cin abans de fer un getline
    cin.ignore(); 

    cout << "Nom: "; getline(cin, nom);
    cout << "Adreca: "; getline(cin, adreca);
    cout << "Poblacio: "; getline(cin, poblacio);
    cout << "Telefon: "; getline(cin, telefon);
    
    cout << "Edat: "; cin >> edat;

    Usuari nouUsuari(nom, adreca, poblacio, telefon, dni, edat);

    char volLlibre;
    cout << "Vols afegir un llibre? (s/n): ";
    cin >> volLlibre;

    if (volLlibre == 's' || volLlibre == 'S') {
        string titol, autor, isbn;
        int any;
        
        cin.ignore();
        
        cout << "Titol: "; getline(cin, titol);
        aMinuscules(titol);
        
        cout << "Autor: "; getline(cin, autor);
        aMinuscules(autor);
        
        cout << "ISBN: "; cin >> isbn;
        aMinuscules(isbn);
        
        cout << "Any de publicacio: "; cin >> any;
        
        nouUsuari.afegeixLlibre(titol, autor, isbn, any);
    }

    usuaris.push_back(nouUsuari);
    cout << "Usuari afegit.\n";
}

void eliminarUsuari(vector<Usuari>& usuaris) {
    string dni;
    cout << "DNI de l'usuari a eliminar: ";
    cin >> dni;
    aMinuscules(dni);

    int pos = cercarUsuari(usuaris, dni);
    if (pos != -1) {
        usuaris.erase(usuaris.begin() + pos);
        cout << "Usuari eliminat.\n";
    } else {
        cout << "L'usuari no existeix.\n";
    }
}

void afegirLlibreUsuari(vector<Usuari>& usuaris) {
    string dni;
    cout << "DNI de l'usuari: ";
    cin >> dni;
    aMinuscules(dni);

    int pos = cercarUsuari(usuaris, dni);
    if (pos != -1) {
        string titol, autor, isbn;
        int any;
        
        cin.ignore();
        
        cout << "Titol: "; getline(cin, titol);
        aMinuscules(titol);
        
        cout << "Autor: "; getline(cin, autor);
        aMinuscules(autor);
        
        cout << "ISBN: "; cin >> isbn;
        aMinuscules(isbn);
        
        cout << "Any de publicacio: "; cin >> any;
        
        usuaris[pos].afegeixLlibre(titol, autor, isbn, any);
        cout << "Llibre afegit.\n";
    } else {
        cout << "L'usuari no existeix.\n";
    }
}

void eliminarLlibreUsuari(vector<Usuari>& usuaris) {
    string dni, titol;
    cout << "DNI de l'usuari: ";
    cin >> dni;
    aMinuscules(dni);

    int pos = cercarUsuari(usuaris, dni);
    if (pos != -1) {
        cin.ignore(); 
        
        cout << "Titol del llibre a eliminar: ";
        getline(cin, titol);
        aMinuscules(titol);
        
        usuaris[pos].eliminaLlibre(titol);
        cout << "Llibre eliminat (si existia).\n";
    } else {
        cout << "L'usuari no existeix.\n";
    }
}

void imprimirUsuaris(vector<Usuari>& usuaris) {
    for (size_t i = 0; i < usuaris.size(); i++) {
        usuaris[i].print();
    }
}

void imprimirLlibresUsuari(vector<Usuari>& usuaris) {
    string dni;
    cout << "DNI de l'usuari: ";
    cin >> dni;
    aMinuscules(dni);

    int pos = cercarUsuari(usuaris, dni);
    if (pos != -1) {
        usuaris[pos].mostraLlibres();
    } else {
        cout << "L'usuari no existeix.\n";
    }
}

void sortir() {
    cout << "Tancant l'aplicacio de la biblioteca municipal.\n";
}

int main() {
    vector<Usuari> usuaris_biblio;
    int opcio;

    do {
        cout << "\n1. Afegir Usuari\n";
        cout << "2. Eliminar Usuari\n";
        cout << "3. Afegir Llibre a un usuari\n";
        cout << "4. Eliminar Llibre d'un usuari\n";
        cout << "5. Imprimir usuaris de la biblioteca municipal\n";
        cout << "6. Imprimir els libres d'un usuari\n";
        cout << "0. Sortir\n";
        cout << "Opcio: ";
        cin >> opcio;

        switch (opcio) {
            case 1: afegirUsuari(usuaris_biblio); break;
            case 2: eliminarUsuari(usuaris_biblio); break;
            case 3: afegirLlibreUsuari(usuaris_biblio); break;
            case 4: eliminarLlibreUsuari(usuaris_biblio); break;
            case 5: imprimirUsuaris(usuaris_biblio); break;
            case 6: imprimirLlibresUsuari(usuaris_biblio); break;
            case 0: sortir(); break;
            default: cout << "Opcio incorrecta.\n"; break;
        }
    } while (opcio != 0);

    return 0;
}