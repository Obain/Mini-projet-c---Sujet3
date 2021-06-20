#include <setjmp.h>

//erreur si il y a des carractères spéciaux, prise en compte de cas d'erreur avec un buffer
void verifAlphanumerique(char txt[], jmp_buf BUF);

//erreur si pas de clé
void chiffrerCesar(char txt[], int cle);
void dechiffrerCesar(char txt[], int cle);

//erreur si pas de clé
void chiffrerVigenere(char txt[], char cle[]);
void dechiffrerVigenere(char txt[], char cle[]);

//prise en compte optionnelle des accents
void convertirAccents(char txt []);