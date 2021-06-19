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
#include <string.h>
#include <stdlib.h>
#include <setjmp.h>
#include "packageFonctions.h"
#include "packageFonctions.c"

void main() {

    //  Saisie du mot en clair
    setjmp(BUFA);
    printf("Mot a coder : ");
    char saisie[TAILLE_SAISIE];
    scanf("%s",saisie);
    
    //  Vérification alphanumérique (pas de carractères spéciaux)
    verifAlphanumerique(saisie, BUFA);

    //  Chiffrement avec Vigenere, /!\ présence obligatoire d'une clé !
    char cle[TAILLE_SAISIE] = "cle";
    chiffrerVigenere(saisie, cle);
    printf("Chiffrement avec Vigenere : %s\n", saisie);
    //  Déchiffrement de Vigenere
    dechiffrerVigenere(saisie, cle);
    printf("Dechiffrement de Vigenere : %s\n", saisie);

}

