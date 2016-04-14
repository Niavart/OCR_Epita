
#include <stdio.h>
#include <stdlib.h> 
#include <assert.h>
#include <err.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>

void wait_for_keypressed(void);
//Attend qu'une touche soit pressée.

void init_sdl(void);
//initialise SDL.

SDL_Surface* load_image(char *path);
//Charge une image depuis un fichier.

SDL_Surface* display_image(SDL_Surface *img);
//Règle une surface en fonction de la taille de l'image, met l'image dedans, et attend qu'une touche soit pressée.


Uint32 getpixel(SDL_Surface *surface, unsigned x, unsigned y);
void Line(SDL_Surface *surf);
void Char(SDL_Surface *surf, int Xmin, int Ymin, int haut, int larg);
void neurone(SDL_Surface *surf, int Xmin, int Ymin, int haut, int larg);
void SavePartScreen(const char* nom, SDL_Surface *ecran, int Xmin, int Ymin, int larg, int haut);
