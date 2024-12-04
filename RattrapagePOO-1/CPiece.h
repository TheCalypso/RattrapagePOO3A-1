#ifndef CPIECE_H
#define CPIECE_H

#include "CRadiateur.h"
#include <iostream>

class CPiece {
private:
    char* nom;
    float longueur;
    float largeur;
    CRadiateur* radiateurs;  // Tableau dynamique de CRadiateur
    int nbRadiateurs;

public:
    // Constructeurs et destructeur
    CPiece();  // Constructeur par défaut
    CPiece(const char* nom, float longueur, float largeur, const CRadiateur* radiateurs, int nbRadiateurs);  // Constructeur avec paramètres
    CPiece(const CPiece& autre);  // Constructeur de copie
    ~CPiece();  // Destructeur

    // Méthodes pour calculer la puissance totale
    int getPuissanceTotale() const;

    // Surcharge des opérateurs
    friend std::ostream& operator<<(std::ostream& os, const CPiece& piece);  // Surcharge de <<
    friend std::istream& operator>>(std::istream& is, CPiece& piece);       // Surcharge de >>
};

#endif // CPIECE_H
