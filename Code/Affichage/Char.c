# include <SDL.h>
# include <stdlib.h>
# include "pixel_operations.h"
# include "pixel_operations.c"
# include "Char.h"
# include "sdl.h"


void Char(SDL_Surface *surf, int Xmin, int Ymin, int haut, int larg){
 int booleen =  0;
 int booleen2 = 0;
 Uint8 r = 0;
 Uint8 g = 0;
 Uint8 b = 0;
 Uint32 pixel;
 int test2nd = 0;
 for(int x = 0; x < surf->w; x++)
  {
    for(int y= Ymin; y < haut; y++)
    {
      pixel = getpixel(surf, x, y);
      SDL_GetRGB(pixel, surf->format, &r, &g, &b);
      if(r==0 && g==0 && b==0) /* Si c'est noir */
      {
        booleen  = 1;
        booleen2 = 0;
      }
    }
    if(booleen == 0) /*check si c'est une colonne blanche, sinon ça part*/
    {
      if(booleen2 == 1)
      {
        larg = 0;
        Xmin = x + 1;
      }
      if(booleen2 == 0)
      {
	test2nd++;
	if(test2nd == 2){
           neurone(surf, Xmin, Ymin, haut, larg);
	}
        Xmin = x + 1;
        larg = 0;
        booleen2 = 1;
      }
    }
    larg = larg + 1;
    booleen = 0;
  }
}

void neurone(SDL_Surface *surf, int Xmin, int Ymin, int haut, int larg){
  SDL_Rect OneChar;
  OneChar.x = Xmin;
  OneChar.y = Ymin;
  OneChar.w = larg;
  OneChar.h = haut;
  SDL_Surface disp;
  SDL_BlitSurface(surf, &OneChar, &disp, NULL);
  display_image(&disp);	
}
