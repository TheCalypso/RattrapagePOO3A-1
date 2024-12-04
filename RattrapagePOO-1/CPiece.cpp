#include "CPiece.h"
#include <cstring>
#include <iostream>
using namespace std;

// Constructeur par défaut
CPiece::CPiece() : nom(nullptr), longueur(0), largeur(0), radiateurs(nullptr), nbRadiateurs(0) {
    cout << "Constructeur par défaut de CPiece appelé." << endl;
}

// Constructeur avec paramètres
CPiece::CPiece(const char* nom, float longueur, float largeur, const CRadiateur* radiateurs, int nbRadiateurs)
    : longueur(longueur), largeur(largeur), nbRadiateurs(nbRadiateurs) {
    this->nom = new char[strlen(nom) + 1];
    strcpy_s(this->nom, strlen(nom) + 1, nom);

    if (nbRadiateurs > 0) {
        this->radiateurs = new CRadiateur[nbRadiateurs];
        for (int i = 0; i < nbRadiateurs; ++i) {
            this->radiateurs[i] = radiateurs[i];
        }
    }
    else {
        this->radiateurs = nullptr;
    }
    cout << "Constructeur avec paramètres de CPiece appelé." << endl;
}

// Constructeur de copie
CPiece::CPiece(const CPiece& autre)
    : longueur(autre.longueur), largeur(autre.largeur), nbRadiateurs(autre.nbRadiateurs) {
    nom = new char[strlen(autre.nom) + 1];
    strcpy_s(nom, strlen(autre.nom) + 1, autre.nom);

    if (nbRadiateurs > 0) {
        radiateurs = new CRadiateur[nbRadiateurs];
        for (int i = 0; i < nbRadiateurs; ++i) {
            radiateurs[i] = autre.radiateurs[i];
        }
    }
    else {
        radiateurs = nullptr;
    }
    cout << "Constructeur de copie de CPiece appelé." << endl;
}

// Destructeur
CPiece::~CPiece() {
    delete[] nom;
    delete[] radiateurs;
    cout << "Destructeur de CPiece appelé." << endl;
}

// Méthode pour calculer la puissance totale
int CPiece::getPuissanceTotale() const {
    int total = 0;
    for (int i = 0; i < nbRadiateurs; ++i) {
        total += radiateurs[i].getPuissance();
    }
    return total;
}

// Surcharge de l'opérateur <<
ostream& operator<<(ostream& os, const CPiece& piece) {
    os << "Nom: " << (piece.nom ? piece.nom : "N/A") << ", "
        << "Longueur: " << piece.longueur << " m, "
        << "Largeur: " << piece.largeur << " m, "
        << "Puissance totale: " << piece.getPuissanceTotale() << " W, "
        << "Nombre de radiateurs: " << piece.nbRadiateurs;
    return os;
}

// Surcharge de l'opérateur >>
istream& operator>>(istream& is, CPiece& piece) {
    char buffer[100];
    cout << "Entrez le nom de la pièce: ";
    is >> buffer;
    delete[] piece.nom;
    piece.nom = new char[strlen(buffer) + 1];
    strcpy_s(piece.nom, strlen(buffer) + 1, buffer);

    cout << "Entrez la longueur de la pièce: ";
    is >> piece.longueur;
    cout << "Entrez la largeur de la pièce: ";
    is >> piece.largeur;
    cout << "Entrez le nombre de radiateurs: ";
    is >> piece.nbRadiateurs;

    delete[] piece.radiateurs;
    if (piece.nbRadiateurs > 0) {
        piece.radiateurs = new CRadiateur[piece.nbRadiateurs];
        for (int i = 0; i < piece.nbRadiateurs; ++i) {
            cout << "Saisir les données pour le radiateur " << i + 1 << ":" << endl;
            is >> piece.radiateurs[i];
        }
    }
    else {
        piece.radiateurs = nullptr;
    }
    return is;
}
