// pixel_operations.h
 
# ifndef PIXEL_OPERATIONS_H_
# define PIXEL_OPERATIONS_H_
 
# include <stdlib.h>
# include <SDL.h>
 
Uint32 getpixel(SDL_Surface *surface, unsigned x, unsigned y);
// Prend la valeur du pixel désigné
void putpixel(SDL_Surface *surface, unsigned x, unsigned y, Uint32 pixel);
//Change la couleur du pixel
 
# endif
