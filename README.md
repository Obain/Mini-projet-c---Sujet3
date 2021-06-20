Mini-projet-c---Sujet

FUENTES Aubin
CARABIN Kémit
Groupe : S2A1

Objectif de l'appli :
	L’application que nous avons développée porte sur le langage crypté. Elle se présente comme étant composée d’un ensemble de procédures 
	qui ont pour rôle de coder et de déchiffrer une chaîne de caractère à l’aide de clés, ces derniers étant entrés par l’utilisateur de 
	l’application. Pour ce faire, nous avons fait le choix de programmer des procédures basées sur les principes de chiffrement de César et 
	de Vigenère.	

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

ps : Avec César, il y a un problème de ségmentation. On en a longtemps cherché la raison sans jamais la trouver. 
     On a donc pris la décision de rendre le projet même ainsi afin de rendre tout de même un programme et répondre un maximum aux attentes.





































































Mettez une bonne note svp je veux avoir mon semestre