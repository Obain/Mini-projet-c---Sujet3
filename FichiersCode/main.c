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
jmp_buf BUFA;

void main() {

    //  Saisie du mot en clair
    setjmp(BUFA);
    printf("Mot a coder : ");
    char saisie[TAILLE_SAISIE];
    scanf("%s",saisie);
    
    //  Vérification alphanumérique (pas de carractères spéciaux)
    verifAlphanumerique(saisie, BUFA);

    //  Chiffrement avec César et Vigenere, /!\ présence obligatoire d'une clé !
    char cleV[TAILLE_SAISIE] = "cle"; // Clé pour Vigenere
	int cleC = 3; // Clé pour César
	chiffrerCesar(saisie, cleC);
    printf("Chiffrement avec Cesar : %s\n", saisie);
    chiffrerVigenere(saisie, cleV);
    printf("Chiffrement avec Vigenere : %s\n", saisie);
    //  Déchiffrement de Vigenere et Cesar, réutilisation des mêmes clés que pour chiffrer
    dechiffrerVigenere(saisie, cleV);
    printf("Dechiffrement de Vigenere : %s\n", saisie);
	dechiffrerCesar(saisie, cleC);
    printf("Dechiffrement de Cesar : %s\n", saisie);

}