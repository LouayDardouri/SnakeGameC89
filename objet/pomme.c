#include <stdio.h>
#include <stdlib.h>
#include <graph.h>

#define TAILLE_SERPENT 5
#define TAILLE_GRILLE 50
#define TAILLE_CASE 10

struct Point {
    int x;
    int y;
};

void DessinerPomme(int x, int y, int taille) {
    int i, j;
    for (i = 0; i < taille; i++) {
        for (j = 0; j < taille; j++) {
            DessinerPixel(x + i, y + j);
        }
    }
}

int VerifierCollisionAvecSerpent(struct Point serpent[], int tailleSerpent, int x, int y) {
    int i;
    for (i = 0; i < tailleSerpent; i++) {
        if (serpent[i].x == x && serpent[i].y == y) {
            return 1;  /* Collision détectée */
        }
    }
    return 0;  /* Pas de collision */
}

int AttendreAppuiTouche() {
    while (!SourisCliquee()) {
        /* Attendre qu'une touche soit cliquée */
    }
    return Touche();
}

int main() {
    /* Initialiser le mode graphique */
    InitialiserGraphique();

    /* Créer la fenêtre graphique */
    CreerFenetre(0, 0, TAILLE_GRILLE * TAILLE_CASE, TAILLE_GRILLE * TAILLE_CASE);

    /* Charger l'image de fond (facultatif) */
    ChargerImageFond("imageg.png");

    /* Initialiser le générateur de nombres aléatoires */
    srand(time(NULL));

    /* Initialiser les positions du serpent */
    struct Point serpent[TAILLE_SERPENT];
    int i;

    for (i = 0; i < TAILLE_SERPENT; i++) {
        serpent[i].x = 20;  /* Remplacez par les positions réelles du serpent */
        serpent[i].y = 20;
    }

    /* Dessiner le serpent (à remplacer par votre propre logique de dessin de serpent) */
    for (i = 0; i < TAILLE_SERPENT; i++) {
        DessinerPixel(serpent[i].x, serpent[i].y);
    }

    /* Dessiner 5 pommes de manière aléatoire sur la grille */
    for (i = 0; i < 5; i++) {
        int x, y;

        do {
            x = (rand() % TAILLE_GRILLE) * TAILLE_CASE;  /* Position x aléatoire sur la grille */
            y = (rand() % TAILLE_GRILLE) * TAILLE_CASE;  /* Position y aléatoire sur la grille */
        } while (VerifierCollisionAvecSerpent(serpent, TAILLE_SERPENT, x, y));

        DessinerPomme(x, y, TAILLE_CASE);
    }

    /* Attendre une touche */
    AttendreAppuiTouche();

    /* Fermer le mode graphique */
    FermerGraphique();

    return EXIT_SUCCESS;
}