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
		printf("  %c  |", c1);
	if(l==2)
		printf("%c # %c|", c4, c2);
	if(l==3)
		printf("  %c  |", c3);
}

typedef struct						// --- Plateau ---
{
	int nbCases;
	piece* tab;
}plateau;

void affichPlateau(plateau plat)
{
	int min = 0;
	int inter = sqrt(plat.nbCases);
	int max = plat.nbCases;

	printf("_ _ _ _ _ _ _ _ _ _ _ _\n");
	while(inter<=max)
	{
		for(int i=1; i<=3; i++)
		{
			for(int j=min; j<inter; j++)
			{
				piece p = plat.tab[j];
				affichPieceP(i,p);
			}
			printf("\n");		// fin de la i-ème ligne plateau
		}
		printf("_ _ _ _ _ _ _ _ _ _ _ _|\n");// fin d'une ligne de pieces

		min = inter;
		inter = inter+sqrt(plat.nbCases);
	}
}

int main()								// --- Main ---
{
	piece p1 = { "a1", "ADDC" };	piece p2 = { "a2", "CBAD" };	piece p3 = { "a3", "DAAB" };	piece p4 = { "a4", "BCDA" };
	piece p5 = { "b1", "DBCD" };	piece p6 = { "b2", "ADBB" };	piece p7 = { "b3", "ABCD" };	piece p8 = { "b4", "DDCB" };
	piece p9 = { "c1", "CACB" };	piece p10= { "c2", "BCCA" };	piece p11= { "c3", "CABC" };	piece p12= { "c4", "CBDA" };
	piece p13= { "d1", "CDAA" };	piece p14= { "d2", "CACD" };	piece p15= { "d3", "BCDA" };	piece p16= { "d4", "DABC" };
	affichPiece(p9);
	// affichPiece(p2);
	// affichPiece(p3);
	// affichPiece(p4);
	// affichPieceP(1, p1);
	// printf("\n");
	// affichPieceP(2, p1);
	// printf("\n");
	// affichPieceP(3, p1);
	// printf("\n");


	int nbPieces = 16;
	piece* tab = (piece*)malloc(sizeof(piece)*nbPieces);
	plateau a = { nbPieces, tab };
	a.tab[0] = p1;
	a.tab[1] = p2;
	a.tab[2] = p3;
	a.tab[3] = p4;
	a.tab[4] = p5;
	a.tab[5] = p6;
	a.tab[6] = p7;
	a.tab[7] = p8;
	a.tab[8] = p9;
	a.tab[9] = p10;
	a.tab[10] = p11;
	a.tab[11] = p12;
	a.tab[12] = p13;
	a.tab[13] = p14;
	a.tab[14] = p15;
	a.tab[15] = p16;
	affichPlateau(a);

	return 0;
}
