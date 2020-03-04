#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct						// --- Pieces ---
{
	char position[2];				// ex : "a1"
	char sens[4];						// ex : "ADDC"
}piece;

void affichPiece(piece p)
{
	char c1 = p.sens[0];		// "A"
	char c2 = p.sens[1];		// "D"
	char c3 = p.sens[2];		// "D"
	char c4 = p.sens[3];		// "C"

	printf("  %c  \n%c # %c\n  %c  \n", c1, c4, c2, c3);
}

void affichPieceP(int l, piece p)	// l = n° ligne à afficher
{
	char c1 = p.sens[0];
	char c2 = p.sens[1];
	char c3 = p.sens[2];
	char c4 = p.sens[3];

	if(l==1)
		printf("  %c   ", c1);
	if(l==2)
		printf("%c # %c ", c4, c2);
	if(l==3)
		printf("  %c   ", c3);
}

typedef struct						// --- Plateau ---
{
	int nbCases;
	piece* tab;
}plateau;

void affichPlateau(plateau plat)
{
	for(int i=1; i<=3; i++)
	{
		for(int j=0; j<sqrt(plat.nbCases); j++)
		{
			piece p = plat.tab[j];
			affichPieceP(i,p);
		}
		printf("\n");		// fin de la i-ème ligne plateau
	}
	// fin de la 1ère ligne de pieces

	for(int i=1; i<=3; i++)
	{
		for(int j=sqrt(plat.nbCases); j<plat.nbCases; j++)
		{
			piece p = plat.tab[j];
			affichPieceP(i,p);
		}
		printf("\n");		// fin de la i-ème ligne plateau
	}
}

int main()								// --- Main ---
{
	piece p1 = { "a1", "ADDC" };
	piece p2 = { "a2", "CBAD" };
	piece p3 = { "b1", "DBCD" };
	piece p4 = { "b2", "ADBB" };
	affichPiece(p1);
	// affichPiece(p2);
	// affichPiece(p3);
	// affichPiece(p4);
	// affichPieceP(1, p1);
	// printf("\n");
	// affichPieceP(2, p1);
	// printf("\n");
	// affichPieceP(3, p1);
	// printf("\n");


	int nbPieces = 4;
	piece* tab = (piece*)malloc(sizeof(piece)*nbPieces);
	plateau a = { nbPieces, tab };
	a.tab[0] = p1;
	a.tab[1] = p2;
	a.tab[2] = p3;
	a.tab[3] = p4;
	affichPlateau(a);

	return 0;
}

test jej
