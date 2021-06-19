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

void verifAlphanumerique(char txt[], jmp_buf BUF) {
    char alphaMin[] = "abcdefghijklmnopqrstuvwxyz";
    char alphaMaj[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    char num[] = "1234567890";  
   
    for (int i=0; i<strlen(txt); i++) {
        if (strchr(alphaMin, txt[i])==NULL && strchr(alphaMaj, txt[i])==NULL && strchr(num, txt[i])==NULL) {
            //  Msg d'erreur + retour à la saisie du mot à coder
            printf("Erreur : presence d'un ou plusieurs carracteres speciaux en entree.\n");
            longjmp(BUF, 2000);
        }
    }
}

//On ne peux pas retourner un tableau donc on ne retourne rien (procédure) et on modifie la chaine saisie directement
void chiffrerVigenere(char txt[], char cle[]) {
    
    int i, j=0; // Compteurs, i pour le texte et j pour la clé
    int ASCII; // Code ASCII de la lettre
    int DecCle, DecTxt; // Décalage dans l'alphabet par rapport à a

    for(i=0; i<strlen(txt); i++) { //on passe en revue chaque lettre du texte en clair
        
        //retour au début de la clé si elle n'est pas assez longue pour coder tous le texte
        if (j>=strlen(cle)) { 
            j = 0;
        }

        DecCle = cle[j]-97; // Décalage de la lettre de la clé
        DecTxt = txt[i]-97; // Décalage de la lettre du texte

        // Code ASCII correspondant
        ASCII = DecCle + DecTxt + 97;
        if (ASCII>122 || (ASCII>90 && ASCII<97) ) { // On prend en compte les majuscules dans le texte !
            ASCII -= 26; // Le code ASCII doit correspondre à une lettre de l'alphabet 
        }

        txt[i] = ASCII;
        j++;
    }  

}

//On ne peux pas retourner un tableau donc on ne retourne rien (procédure) et on modifie la chaine saisie directement
void dechiffrerVigenere(char txt[], char cle[]) {
    
    int i, j=0; // Compteurs, i pour le texte et j pour la clé
    int ASCII, ASCIIcode; // Code ASCII de la lettre
    int DecCle, DecTxt; // Décalage dans l'alphabet par rapport à a

    for(i=0; i<strlen(txt); i++) { //on passe en revue chaque lettre du texte en clair
        
        //retour au début de la clé si elle n'est pas assez longue pour coder tous le texte
        if (j>=strlen(cle)) { 
            j = 0;
        }

        DecTxt = txt[i]-97; // Décalage de la lettre du texte
        DecCle = cle[j]-97; // Décalage de la lettre de la clé

        // Code ASCII correspondant
        ASCII = (DecTxt - DecCle) + 97;
        ASCIIcode = txt[i];
        if ( (ASCII>90 && ASCII<97) || ASCII<65 ) { // On prend en compte les majuscules dans le texte !
            ASCII += 26; // Le code ASCII doit correspondre à une lettre de l'alphabet 
        }
        if ( (ASCIIcode>97 && ASCII<97) ) { // On prend en compte les majuscules dans le texte !
            ASCII += 26; // Le code ASCII doit correspondre à une lettre de l'alphabet 
        }

        txt[i] = ASCII;
        j++;
    }  

}

