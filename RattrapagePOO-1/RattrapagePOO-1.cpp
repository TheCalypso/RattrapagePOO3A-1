#include "CPiece.h"
#include <iostream>
#include <windows.h>
using namespace std;

int main() {
    SetConsoleOutputCP(CP_UTF8);  // Définit l'encodage UTF-8 pour la sortie console
    SetConsoleCP(CP_UTF8);       // Définit l'encodage UTF-8 pour l'entrée console
    int nombreDePieces;

    // Demander à l'utilisateur combien de pièces il souhaite saisir
    cout << "Combien de pièces souhaitez-vous saisir ? ";
    cin >> nombreDePieces;

    // Créer un tableau dynamique de CPiece
    CPiece* tableauDePieces = new CPiece[nombreDePieces];

    // Demander à l'utilisateur de saisir toutes les pièces
    for (int i = 0; i < nombreDePieces; ++i) {
        cout << "\nSaisie de la pièce " << i + 1 << " :" << endl;
        cin >> tableauDePieces[i];
    }

    // Afficher le contenu du tableau de pièces
    cout << "\nContenu du tableau de pièces :" << endl;
    for (int i = 0; i < nombreDePieces; ++i) {
        cout << "Pièce " << i + 1 << " : " << endl;
        cout << tableauDePieces[i] << endl;
    }

    // Libérer la mémoire allouée pour le tableau dynamique
    delete[] tableauDePieces;

    return 0;
}
