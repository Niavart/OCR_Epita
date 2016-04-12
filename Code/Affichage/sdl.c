#include "SDL/SDL.h"
#include "SDL/SDL_image.h"
#include "sdl.h"
#include "pixel_operations.h"
#include "pixel_operations.c"
/*
#include "CharCut.h"
#include "CharCut.c"
*/

void wait_for_keypressed(void) {
  SDL_Event             event;
  // Infinite loop, waiting for event
  for (;;) {
    // Take an event
    SDL_PollEvent( &event );
    // Switch on event type
    switch (event.type) {
    // Someone pressed a key -> leave the function
    case SDL_KEYDOWN: return;
    default: break;
    }
  // Loop until we got the expected event
  }
}

void init_sdl(void) {
  // Init only the video part
  if( SDL_Init(SDL_INIT_VIDEO)==-1 ) {
    // If it fails, die with an error message
    errx(1,"Could not initialize SDL: %s.\n", SDL_GetError());
  }
  // We don't really need a function for that ...
}

SDL_Surface* load_image(char *path) {
  SDL_Surface          *img;
  // Load an image using SDL_image with format detection
  img = IMG_Load(path);
  if (!img)
    // If it fails, die with an error message
    errx(3, "can't load %s: %s", path, IMG_GetError());
  return img;
}



SDL_Surface* display_image(SDL_Surface *img) {
  SDL_Surface          *screen;
  // Set the window to the same size as the image
  screen = SDL_SetVideoMode(img->w, img->h, 0, SDL_SWSURFACE|SDL_ANYFORMAT);
  if ( screen == NULL ) {
    // error management
    errx(1, "Couldn't set %dx%d video mode: %s\n",
         img->w, img->h, SDL_GetError());
  }
 
  /* Blit onto the screen surface */
  if(SDL_BlitSurface(img, NULL, screen, NULL) < 0)
    warnx("BlitSurface error: %s\n", SDL_GetError());
 
  // Update the screen
  SDL_UpdateRect(screen, 0, 0, img->w, img->h);
 
  // wait for a key
  wait_for_keypressed();
 
  // return the screen for further uses
  return screen;
}

int main ()
{
	SDL_Surface *img = load_image("Boucher.bmp");
	Uint8 r = 0;
	Uint8 g = 0;
	Uint8 b = 0;
	int x = 0;
	int y = 0;
	Uint32 pixel;
	while (x != img->w)
	{
		while (y != img->h)											// Doit y avoir une erreur dans le main,...
		{
			pixel = getpixel(img, x, y);
			SDL_GetRGB(pixel, img->format, &r, &g, &b);
			if ((r + g + b)/3 >= 127)
			{
			r = 255;
			g = 255;
			b = 255;
			pixel = SDL_MapRGB(img->format, r, g, b);			// La double boucle est 100% correcte (certain)
			putpixel(img, x, y, pixel);
			}
			else
			{
			r = 0;
			g = 0;
			b = 0;
			pixel = SDL_MapRGB(img->format, r, g, b);			// La double boucle est 100% correcte (certain)
			putpixel(img, x, y, pixel);
			}
			y++;	
		}
		y = 0;
		x++;
	}
	Line(img);
	//display_image(img);												// ... Parce que ce display affiche un cheval vert mdr
	return 0;
}



void Line(SDL_Surface *surf)
{
  //int Xmin= 0;
  int Ymin= 0;
  //int larg = 0;
  int haut = 0;
  int booleen = 0;
  int booleen2 = 0;
  Uint8 r = 0;
  Uint8 g = 0;
  Uint8 b = 0;
  Uint32 pixel;
  SDL_LockSurface(surf);
  for(int y=0;y<surf->h;y++)
  {
    for(int x=0;x<surf->w;x++)
    {
      pixel = getpixel(surf, x, y);
      SDL_GetRGB(pixel, surf->format, &r, &g, &b);
      if(r==0 && g==0 && b==0) /* Si c'est noir */
      {
        booleen  = 1;
        booleen2 = 0;
      }
    }
    if(booleen == 0) /*check si c'est une ligne blanche, sinon ça part*/
    {
      if(booleen2 == 1)
      {
        //éviter les doubles lignes blanches: si b2 = 1 alors, on a pas eu un seul pixel noir depuis le dernier envoi
        haut = 0;
        Ymin = y + 1;
      }
      if(booleen2 == 0)
      {
 /*             SDL_Rect *tile;
        SDL_Rect *positionExt = NULL;
        SDL_Surface *temp_surface;

        tile.x = Xmin;
        tile.y = Ymin;
        tile.h = haut;
        tile.w = larg;*/ //useless 

        Char(surf, 0/*Xmin*/, Ymin, haut, 0 /*larg*/);
        Ymin = y + 1;
        haut = 0;
        booleen2 = 1;
      }
    }
        //else (tant que il y a du noir)
    haut = haut + 1;
    booleen = 0;
  }
}
/*
void SavePartScreen(const char* nom, SDL_Surface *ecran, int Xmin, int Ymin, int larg, int haut){
  SDL_Surface *image = NULL;
  SDL_Rect rect1, rect2;
  image = SDL_CreateRGBSurface (SDL_HWSURFACE, larg, haut, 32, 0, 0, 0, 0);
  SDL_FillRect(image, NULL, SDL_MapRGB(ecran->format, 250, 250, 250));
  rect1.x = Xmin, rect1.y = Ymin, rect1.w = larg, rect1.h = haut;
  SDL_SaveBMP(image, nom);
  SDL_FreeSurface(image);
}*/

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
//  char *name = "test.bmp";
  SDL_BlitSurface(surf, &OneChar, &disp, NULL);
//  SDL_SaveBMP(&disp, &name);
  display_image(&disp);
  SDL_FreeSurface(&disp);
}






