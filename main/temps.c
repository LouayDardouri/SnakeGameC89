//le programe n'est pas encore fini
#include <stdio.h>
#include <stdlib.h>
#include <graph.h>
#define CYCLE 10000L

void EcrireTexte(int x, int y, char *texte, int taille) {
    ChoisirCouleurDessin(CouleurParComposante(255, 255, 255)); // Couleur blanche
    ChoisirTaille(1, taille);
    EcrireTexte(x, y, texte);
}

int main(void) {
    InitialiserGraphique();
    CreerFenetre(10, 10, 600, 400);

    int suivant = Microsecondes() + CYCLE;
    int Secondes = 0;

    // boucle principale du programme
    while (1) {
        ChoisirEcran(1);
        EffacerEcran(CouleurParComposante(0, 0, 0)); // Effacer l'écran avec couleur noire

        int minutes = Secondes / 60;
        int resteSecondes = Secondes % 60;

        char tempsTexte[20];
        sprintf(tempsTexte, "Temps : %d;%02d", minutes, resteSecondes);
        EcrireTexte(10, 10, tempsTexte, 2);

        if (Microsecondes() > suivant) {
            suivant = Microsecondes() + CYCLE;
            Secondes++;
        }

        ActualiserGraphique();
    }

    FermerGraphique();
    return EXIT_SUCCESS;
}
