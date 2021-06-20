#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void chiffrerCesar(char txt[], int cle) {
    char alphaNum[] = "abcdefghijklmnopqrstuvwxyz0123456789";
    int a=0; // Entier qu'on utilisera pour se positionner dans les différentes chaînes

    // Boucle for qui va sonder le texte entré par l'utilisateur
    for(int i=0 ; i<=strlen(txt) ; i++) {
         a = txt[i] - 97; // a va prendre la valeur du rang, dans la chaîne AlphaNum, de l'occurence entre le caractère de txt et celui de AlphaNum

        // Cas de figure où a est associée à une lettre, mais que la clé fait dépasser son rang de 25 (notion de modulo)
        if (a<26 && a+cle>25) {
            a = a + cle;
            a= a - 26;
            txt[i] = alphaNum[a]; // On ajoute le caractère dans la chaîne résultat
        }

        // Cas de figure où a est associée à un chiffre
        else if (a>25) {
            txt[i] = alphaNum[a];
        }

        // Cas où a est associée à une lettre
        a = a + cle;
        txt[i] = alphaNum[a];
    }
}

void dechiffrerCesar(char txt[], int cle) {
    char alphaNum[] = "abcdefghijklmnopqrstuvwxyz0123456789";
    int a=0; // Entier qu'on utilisera pour se positionner dans les différentes chaînes

    for(int i=0; i<=strlen(txt); i++){
        a = txt[i] - 97; // a va prendre la valeur du rang, dans la chaîne AlphaNum, de l'occurence entre le caractère de txt et celui de AlphaNum

        // Cas de figure où a est associée à un chiffre
        if (a>25) {
            txt[i] = alphaNum[a]; // On change le caractère dans la chaîne
        }

        // Cas de figure où la clé est supérieure à a (notion de modulo)
        else if(cle>a) {
            a = a - cle;
            while(a<0) {
                a = a + 26;
            }
            txt[i] = alphaNum[a];
        }

        // Cas de figure où a est associée à une lettre
        a = a - cle;
        txt[i] = alphaNum[a];
    }

}