#ifndef CRADIATEUR_H
#define CRADIATEUR_H

#include <iostream>

class CRadiateur {
private:
    float hauteur;
    float largeur;
    int puissance;
    char* type;

public:
    // Constructeurs et destructeur
    CRadiateur();  // Constructeur par défaut
    CRadiateur(float h, float l, int p, const char* t);  // Constructeur avec paramètres
    CRadiateur(const CRadiateur& autre);  // Constructeur de copie
    ~CRadiateur();  // Destructeur

    // Accesseurs en lecture
    float getHauteur() const;
    float getLargeur() const;
    int getPuissance() const;
    const char* getType() const;

    // Surcharge des opérateurs
    friend std::ostream& operator<<(std::ostream& os, const CRadiateur& radiateur);
    friend std::istream& operator>>(std::istream& is, CRadiateur& radiateur);
    CRadiateur operator+(int puissanceAdditionnelle) const;  // Pour un entier et un CRadiateur
    friend int operator+(const CRadiateur& r1, const CRadiateur& r2);  // Pour deux CRadiateur

};

#endif // CRADIATEUR_H
