// CharCut.h
//vieux copié collé de base du Char.h

# ifndef CHARCUT_H_
# define CHARCUT_H_


# include <stdlib.h>
# include <SDL.h>
# include <stdlib.h>
# include "pixel_operations.h"


Uint32 getpixel(SDL_Surface *surface, unsigned x, unsigned y);
void Line(SDL_Surface *surf);
void Char(SDL_Surface *surf, int Xmin, int Ymin, int haut, int larg);
void neurone(SDL_Surface *surf, int Xmin, int Ymin, int haut, int larg);


# endif

