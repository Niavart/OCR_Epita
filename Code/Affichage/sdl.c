#include "SDL/SDL.h"
#include "SDL/SDL_image.h"
#include "sdl.h"
#include "pixel_operations.h"
#include "pixel_operations.c"
#include "CharCut.h"
#include "CharCut.c"


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

