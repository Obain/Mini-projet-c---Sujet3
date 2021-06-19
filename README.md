Mini-projet-c---Sujet

FUENTES Aubin
CARABIN Kémit
Groupe : S2A1

Objectif de l'appli :
	

Détails des fonctions :

void verifAlphanumerique(char txt[], jmp_buf BUF);
	- prend en entrée un texte et un point dans le programme où "sauter" en cas d'erreur
	- pas de paramètres de sortie, c'est une procédure qui vérifie la syntaxe du texte
	- "simulation" d'erreur (jmp_buf) si détection de carractères n'étant pas des lettres ou des nombres
	  (alphanumérique)

void chiffrerCesar(char a, char cle);
void chiffrerVigenere(char txt[], char cle[]);
	- prend en entrée un texte (en clair) et une clé pour permettre de coder le texte
	- pas de paramètres de sortie, on modifie directement le texte pour le transformer en code
	- la présence d'une clé est obligatoire pour pouvoir coder le texte

void dechiffrerCesar(char a, char cle);
void dechiffrerVigenere(char txt[], char cle[]);
	- prend en entrée un texte codé et une clé pour permettre de décoder le texte (la même que celle qui a permis de coder le texte avant)
	- pas de paramètres de sortie, on modifie directement le texte codé pour le transformer en texte en clair
	- la présence de la clé adéquate est obligatoire pour pouvoir décoder le texte