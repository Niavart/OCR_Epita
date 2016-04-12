#include <stdio.h>
#include <stdlib.h>
#include <math.h>


float poids[7][7];
float x;	//entree x
float y;	//entree y
float bh;	//biais de h
float h;	//neurone couche cachee
float z;	//sortie
float bz;	//biais de z

float XORtab[4][3];

float init() // initialise le reseau (avant apprentissage)
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
x=1;
y=0;
h=0.5;
z=0.5
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

float calcerreur(float a, float b) // calcule l'erreur en fonction de x et de y
{
	float nint = nc(a, b);
	float ok = ns(a, b, nint);
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

float changerpoids(float sortie, float n)
{
	
}
















int main()
{
	
	
	
}
