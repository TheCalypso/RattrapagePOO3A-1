#include "CRadiateur.h"
#include <cstring>
#include <iostream>
using namespace std;

// Constructeur par défaut
CRadiateur::CRadiateur() : hauteur(0), largeur(0), puissance(0), type(nullptr) {
    cout << "Constructeur par défaut appelé." << endl;
}

// Constructeur avec paramètres
CRadiateur::CRadiateur(float h, float l, int p, const char* t)
    : hauteur(h), largeur(l), puissance(p) {
    type = new char[strlen(t) + 1];
    strcpy_s(type, strlen(t) + 1, t);
    cout << "Constructeur avec paramètres appelé." << endl;
}

// Constructeur de copie
CRadiateur::CRadiateur(const CRadiateur& autre)
    : hauteur(autre.hauteur), largeur(autre.largeur), puissance(autre.puissance) {
    if (autre.type != nullptr) {
        type = new char[strlen(autre.type) + 1];
        strcpy_s(type, strlen(autre.type) + 1, autre.type);
    }
    else {
        type = nullptr;
    }
    cout << "Constructeur de copie appelé." << endl;
}

// Destructeur
CRadiateur::~CRadiateur() {
    delete[] type;
    cout << "Destructeur appelé." << endl;
}

// Accesseurs en lecture
float CRadiateur::getHauteur() const { return hauteur; }
float CRadiateur::getLargeur() const { return largeur; }
int CRadiateur::getPuissance() const { return puissance; }
const char* CRadiateur::getType() const { return type; }

// Surcharge de l'opérateur <<
ostream& operator<<(ostream& os, const CRadiateur& radiateur) {
    os << "Hauteur: " << radiateur.hauteur << " cm, "
        << "Largeur: " << radiateur.largeur << " cm, "
        << "Puissance: " << radiateur.puissance << " W, "
        << "Type: " << (radiateur.type ? radiateur.type : "N/A");
    return os;
}

// Surcharge de l'opérateur >>
istream& operator>>(istream& is, CRadiateur& radiateur) {
    char buffer[100];
    cout << "Entrez la hauteur: ";
    is >> radiateur.hauteur;
    cout << "Entrez la largeur: ";
    is >> radiateur.largeur;
    cout << "Entrez la puissance: ";
    is >> radiateur.puissance;
    cout << "Entrez le type: ";
    is >> buffer;
    delete[] radiateur.type;
    radiateur.type = new char[strlen(buffer) + 1];
    strcpy_s(radiateur.type, strlen(buffer) + 1, buffer);
    return is;
}

// Surcharge de l'opérateur + (entier + CRadiateur)
CRadiateur CRadiateur::operator+(int puissanceAdditionnelle) const {
    CRadiateur resultat(*this);  // Crée une copie de l'objet courant
    resultat.puissance += puissanceAdditionnelle;  // Ajoute la puissance
    return resultat;
}

// Surcharge de l'opérateur + (CRadiateur + CRadiateur)
int operator+(const CRadiateur& r1, const CRadiateur& r2) {
    return r1.puissance + r2.puissance;  // Additionne les puissances des deux radiateurs
}
