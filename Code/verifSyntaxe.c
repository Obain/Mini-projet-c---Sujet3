/******************************************************************************
*  ASR => M2101                                                               *
*******************************************************************************
*                                                                             *
*  N° de Sujet : 3                                                            *
*                                                                             *
*******************************************************************************
*                                                                             *
*  Intitulé : Sujet 3 - Chiffrement de messages                               *
*                                                                             *
*******************************************************************************
*                                                                             *
*  Nom-prénom1 : CARABIN Kémit                                                *
*                                                                             *
*  Nom-prénom2 : FUENTES Aubin                                                *
*                                                                             *
*******************************************************************************
*                                                                             *
*  Nom du fichier : verifSyntaxe.c                                            *
*                                                                             *
******************************************************************************/

#include <string.h>
#include <setjmp.h>
#include "entetes.h"


void verifAlphanumerique(char txt[], jmp_buf BUF) {
    char alphaMin[] = "abcdefghijklmnopqrstuvwxyz";
    char alphaMaj[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    char num[] = "1234567890";  
   
    for (int i=0; i<strlen(txt); i++) {
        if (strchr(alphaMin, txt[i])==NULL && strchr(alphaMaj, txt[i])==NULL && strchr(num, txt[i])==NULL) {
            //  Msg d'erreur + retour à la saisie du mot à coder
            printf("Erreur : presence d'un ou plusieurs carracteres speciaux en entree.\n");
            longjmp(BUF, 2002);
        }
    }
}