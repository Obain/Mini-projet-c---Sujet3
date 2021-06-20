/******************************************************************************
*  ASR => M2101                                                               *
*******************************************************************************
*                                                                             *
*  N° de Sujet : 3                                                            *
*                                                                             *
*******************************************************************************
*                                                                             *
*  Intitulé :                                                                 *
*                                                                             *
*******************************************************************************
*                                                                             *
*  Nom-prénom1 : CARABIN Kémit                                                *
*                                                                             *
*  Nom-prénom2 : FUENTES Aubin                                                *
*                                                                             *
*******************************************************************************
*                                                                             *
*  Nom du fichier : main.c                                                    *
*                                                                             *
******************************************************************************/

#include <stdio.h>
#include <setjmp.h>
#include "entetes.h"
#include "verifSyntaxe.c"
#include "cesar.c"
#include "Vigenere.c"

#define TAILLE_SAISIE 100 //nombre de carractères max en entrée
jmp_buf BUFA, BUFB;

void main() {

    setjmp(BUFA);
    printf("Quelle action effectuer ? (options: coderCesar, decoderCesar, coderVigenere, decoderVigenere) :\n");
    char action[TAILLE_SAISIE]; //  Action à effectuer
    scanf("%s", action);

    //  Saisie du texte à coder ou décoder
    setjmp(BUFB);
    printf("Mot a coder ou decoder : ");
    char saisie[TAILLE_SAISIE];
    scanf("%s",saisie);
    //  Vérification alphanumérique (pas de carractères spéciaux)
    verifAlphanumerique(saisie, BUFB);

    int cleC;
    char cleV[TAILLE_SAISIE];

    if ( strcmp(action, "coderCesar") == 0 ) {
        printf("Entrez la cle (entier) : ");
        scanf("%d", cleC);
        chiffrerCesar(saisie, cleC);
        printf("Chiffrement avec Cesar : %s\n", saisie);

    } else if ( strcmp(action, "decoderCesar") == 0 ) {
        printf("Entrez la cle (entier) : ");
        scanf("%d", cleC);
        dechiffrerCesar(saisie, cleC);
        printf("Dechiffrement avec Cesar : %s\n", saisie);

    }else if ( strcmp(action, "coderVigenere") == 0 ) {
        printf("Entrez la cle (chaine de carracteres) : ");
        scanf("%s", cleV);
        chiffrerVigenere(saisie, cleV);
        printf("Chiffrement avec Vegenere : %s\n", saisie);

    } else if ( strcmp(action, "decoderVigenere") == 0 ) {
        printf("Entrez la cle (chaine de carracteres) : ");
        scanf("%s", cleV);
        dechiffrerVigenere(saisie, cleV);
        printf("Dechiffrement avec Vegenere : %s\n", saisie);
    } else {
        printf("Action non definie demandee\n");
        longjmp(BUFA, 2001);
    }

}