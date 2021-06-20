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
*  Nom du fichier : Vigenere.c                                                *
*                                                                             *
******************************************************************************/

#include "entetes.h"

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
        } else if ( (ASCIIcode>97 && ASCII<97) ) { // On prend en compte les majuscules dans le texte !
            ASCII += 26; // Le code ASCII doit correspondre à une lettre de l'alphabet 
        }

        txt[i] = ASCII;
        j++;
    }  

}
