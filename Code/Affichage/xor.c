#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

float poids[7][7];
float x;	//entree x (1)
float y;	//entree y (2)
float bh;	//biais de h (3)
float h;	//neurone couche cachee (4)
float z;	//sortie (6)
float bz;	//biais de z (5)
float v; // VELOCITE

float XORtab[4][3];

int iterations;


void init() // initialise le reseau (avant apprentissage)
{
	int i = 0;
	int j = 0;
	while (i != 7)
	{
		while (j != 7)
		{
			poids[i][j] = 0;
			j++;
		}
		i++;
		j=0;
	}
	v=2.0;
	x=1;
	y=0;
	h=0.5;
	z=0.5;
	bz=1;
	bh=1;
	XORtab[0][0] = 0;
	XORtab[0][1] = 0;
	XORtab[0][2] = 0;
	XORtab[1][0] = 0;
	XORtab[1][1] = 1;
	XORtab[1][2] = 1;
	XORtab[2][0] = 1;
	XORtab[2][1] = 0;
	XORtab[2][2] = 1;
	XORtab[3][0] = 1;
	XORtab[3][1] = 1;
	XORtab[3][2] = 0;
	iterations = 0;

}

float nc(float a, float b) // calcule la valeur du neurone en couche cachee
{
	return (1/(1+exp((a*(poids[1][4]))+(bh*(poids[3][4]))+(b*(poids[2][4])))));
}

float ns(float a, float b) //calcule la valeur de sortie
{
	float nint = nc(a, b);
	return(1/(1+exp((a*(poids[1][6]))+(b*(poids[2][6]))+(nint*(poids[4][6]))+(bz*(poids[5][6])))));
}


float calcerreurfin(float a, float b) // calcule l'erreur en fonction de x et de y sur le neurone output
{
	float ok = ns(a, b);
	float der = ok*(1-ok);
	if(a != b)
	{
		return ((1-ok)*der);
	}
	else
	{
		return ((0-ok)*der);
	}

}

void majpoidsfin() // met à jour les poids reliés au neurone output
{
	poids[1][6] = (poids[1][6]) + (v*calcerreurfin(x,y)*x);
	poids[2][6] = (poids[2][6]) + (v*calcerreurfin(x,y)*y);
	poids[4][6] = (poids[4][6]) + (v*calcerreurfin(x,y)*h);
	poids[5][6] = (poids[5][6]) + (v*calcerreurfin(x,y)*bz);
}

float calcerreurcache(float a, float b) // calcule l'erreur en fonction de x et de y sur le neurone couche cachée
{
	float ok = nc(a,b);
	float der = ok*(1-ok);
	return (der*(poids[4][6])*calcerreurfin(a,b));
}

void majpoidscache() // met à jour les poids reliés au neurone caché (càd x, y et le biais h)
{
	poids[1][4] = poids[1][4] + (v*calcerreurcache(x,y)*x);
	poids[2][4] = poids[2][4] + (v*calcerreurcache(x,y)*y);
	poids[3][4] = poids[3][4] + (v*calcerreurcache(x,y)*bh);
}

void boucle(float a, float b) // Itère une fois l'algorithme d'attribution de valeurs
{
	x = a;
	y = b;
	h = nc(x,y);
	z = ns(x,y);
	majpoidsfin();
	majpoidscache();
}

void printw() // Fonction d'affichage
{
	printf("Iteration n° %d\n", iterations);
	printf("Pour x=%f et y=%f\n\n",x, y);
	printf("valeur du poids x->h : %f \n", poids[1][4]);
	printf("valeur du poids y->h : %f \n", poids[2][4]);
	printf("valeur du poids bh->h : %f \n", poids[3][4]);
	printf("valeur du poids x->z : %f\n", poids[1][6]);
	printf("valeur du poids y->z : %f\n", poids[2][6]);
	printf("valeur du poids h->z : %f\n", poids[4][6]);
	printf("valeur du poids bz->z : %f\n", poids[5][6]);
	printf("Valeur de z : %f\n",z);
	printf("___________________________\n\n");
	
}

int randab(int a, int b){ // Une fonction random qui décide quelles valeurs donner à x et y
    return rand()%(b-a) +a;
}




int main()
{
	init();
	while(z < 0.99999)
	{		
		boucle(randab(0,2), randab(0,2));
		printw();
		iterations++;
	}

	return 0;
}









