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
    CPiece();  // Constructeur par d�faut
    CPiece(const char* nom, float longueur, float largeur, const CRadiateur* radiateurs, int nbRadiateurs);  // Constructeur avec param�tres
    CPiece(const CPiece& autre);  // Constructeur de copie
    ~CPiece();  // Destructeur

    // M�thodes pour calculer la puissance totale
    int getPuissanceTotale() const;

    // Surcharge des op�rateurs
    friend std::ostream& operator<<(std::ostream& os, const CPiece& piece);  // Surcharge de <<
    friend std::istream& operator>>(std::istream& is, CPiece& piece);       // Surcharge de >>
};

#endif // CPIECE_H
