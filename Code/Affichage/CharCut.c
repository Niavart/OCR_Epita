#include <SDL.h>
#include <stdlib.h>

Uint32 getpixel(SDL_Surface *surface, unsigned x, unsigned y) {
  Uint8 *p = pixelref(surface, x, y)
  switch(surface->format->BytesPerPixel) {
  case 1:
    return *p;
  case 2:
    return *(Uint16 *)p;
  case 3:
    if(SDL_BYTEORDER == SDL_BIG_ENDIAN)
      return p[0] << 16 | p[1] << 8 | p[2];
    else
      return p[0] | p[1] << 8 | p[2] << 16;
  case 4:
      return *(Uint32 *)p;
  }				  }
  return 0;
}

void Line(SDL_Surface *surf)
{
  int Xmin=0;
  int Ymin=0;
  int larg=surface->w;
  int haut=0;
  int booleen = 0;
  Uint32 pixel;
  SDL_LockSurface(surf);
  for(y=0;y<surface->h;y++)
  {
    for(x=0;x<surface->w;x++)
    {
      if() /* Si c'est noir */
      {
	booleen = booleen + 1;
      }
    }
    if(booleen == 0)
    {
      SavePartScreen(
    }
    booleen = 0;
  }
}

void SavePartScreen(const char* nom, SDL_Surface *ecran, int Xmin, int Ymin, int larg, int haut){
  SDL_Surface *image = NULL;
  SDL_Rect rect1, rect2;
  image = SDL_CreateRGBSurface (SDL_HWSURFACE, larg, haut, 32, 0, 0, 0, 0);
  SDL_FillRect(image, NULL, SDL_MapRGB(ecran->format, 250, 250, 250));
  rect1.x = Xmin, rect1.y = Ymin, rect1.w = larg, rect1.h = haut;
  SDL_SaveBMP(image, nom);
  SDL_FreeSurface(image);
}
