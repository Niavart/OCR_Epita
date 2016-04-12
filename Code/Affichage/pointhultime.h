
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
                                                                            
# ifndef PIXEL_OPERATIONS_H_
# define PIXEL_OPERATIONS_H_

# include <stdlib.h>
# include <SDL.h>

Uint32 getpixel(SDL_Surface *surface, unsigned x, unsigned y);
// Prend la valeur du pixel désigné
void putpixel(SDL_Surface *surface, unsigned x, unsigned y, Uint32 pixel);
//Change la couleur du pixel
Uint8* pixelref(SDL_Surface *surf, unsigned x, unsigned y);
# endif   

# ifndef CHARCUT_H_
# define CHARCUT_H_


# include <stdlib.h>
# include <SDL.h>
# include <stdlib.h>


Uint32 getpixel(SDL_Surface *surface, unsigned x, unsigned y);
void Line(SDL_Surface *surf);
# endif

# ifndef CHAR_H_
# define CHAR_H_


# include <stdlib.h>
# include <SDL.h>
# include <stdlib.h>

void Char(SDL_Surface *surf, int Xmin, int Ymin, int haut, int larg);

void neurone(SDL_Surface *surf, int Xmin, int Ymin, int haut, int larg);

# endif

                                                  
