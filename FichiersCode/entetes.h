#include <setjmp.h>
#define TAILLE_SAISIE 100 //nombre de carractères max en entrée

jmp_buf BUFA, BUFB;

//erreur si il y a des carractères spéciaux, prise en compte de cas d'erreur avec un buffer
void verifAlphanumerique(char txt[], jmp_buf BUF);

//char convertAccents(char a); --> prise en compte des accents optionnelle

//erreur si pas de clé
void chiffrerCesar(char a, char cle);
void chiffrerVigenere(char txt[], char cle[]);

//erreur si pas de clé
void dechiffrerCesar(char a, char cle);
void dechiffrerVigenere(char txt[], char cle[]);

void convertirAccents(char txt []);
