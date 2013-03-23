/*
** 108monstre_sdl.c for 108monstre_sdl in /home/benzah_m//projets/math/108
** 
** Made by marc benzahra
** Login   <benzah_m@epitech.net>
** 
** Started on  Sat Mar 16 00:05:50 2013 marc benzahra
** Last update Sat Mar 23 11:41:24 2013 marc benzahra
*/

#include "monstre_sdl.h"

void	exit_error(char *function, char *file, char *block)
{
  printf("/!\\ %s failed /!\\\nfile : %s\nfunction : %s\n", function, file, block);
  exit(EXIT_FAILURE);
}

void	exit_write(char *str)
{
  printf("%s\n", str);
  exit(EXIT_FAILURE);
}

void	set_pixel(SDL_Surface *surface, int x, int y, Uint32 color)
{
  *((Uint32*)(surface->pixels)+x+(y*surface->w)) = color;
}

Mix_Music	*set_music(char *str)
{
  Mix_Music	*music;

  if ((music = Mix_LoadMUS(str)) == NULL)
    {
      printf("%s\n", Mix_GetError());
      exit(EXIT_FAILURE);
    }
  if (Mix_PlayMusic(music, -1) == -1)
    {
      printf("%s\n", Mix_GetError());
      exit(EXIT_FAILURE);
    }
  return (music);
}

void		monster(double a, double nmax)
{
  int		n;
  int		go;
  int		r;
  int		g;
  int		b;
  int		volume;
  double	x;
  double	res;
  SDL_Surface	*screen;
  SDL_Event	event;
  Mix_Music	*music;

  srand(time(NULL));
  r = rand() % 256;
  g = rand() % 256;
  b = rand() % 256;
  go = 1;
  SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO);
  if ((screen = SDL_SetVideoMode(1000, 1000, 32, SDL_HWSURFACE | SDL_DOUBLEBUF)) == NULL)
    exit_write("video mode failed");
  SDL_WM_SetCaption("GRAPH", NULL);
  x = -2;
  while (x <= 2)
    {
      n = 0;
      res = 0;
      while (n <= nmax)
	{
	  res = res + cos(pow(a, n) * M_PI * x) / pow(2, n);
	  n = n + 1;
	}
      set_pixel(screen, 500 + x * 200, 500 - res * 200, SDL_MapRGB(screen->format, r, g, b));
      x = x + 0.0001;
    }
  SDL_Flip(screen);
  if (Mix_OpenAudio(22050, AUDIO_S16, 2, 4096) == -1)
    {
      printf("%s\n", Mix_GetError());
      exit(EXIT_FAILURE);
    }
  music = set_music("gw2.wav");
  volume = Mix_VolumeMusic(-1);
  while (go)
    {
      SDL_WaitEvent(&event);
      switch (event.type)
	{
	case SDL_KEYDOWN:
	  switch (event.key.keysym.sym)
	    {
	    case SDLK_ESCAPE:
	      go = 0;
	      break;
	    case SDLK_SPACE:
	      if (Mix_VolumeMusic(-1) > 0)
		Mix_VolumeMusic(0);
	      else
		Mix_VolumeMusic(volume);
	      break;
	    case SDLK_LEFT:
	      if (volume - 10 > 0)
		Mix_VolumeMusic((volume = volume - 10));
	      break;
	    case SDLK_RIGHT:
	      if (volume + 10 < 128)
		Mix_VolumeMusic((volume = volume + 10));
	      break;
	    case SDLK_UP:
	      {
		Mix_FreeMusic(music);
		music = set_music("shit_gets_real.wav");
	      }
	      break;
	    case SDLK_DOWN:
	      {
		Mix_FreeMusic(music);
		music = set_music("call_me_maybe.wav");
	      }
	      break;
	    }
	  break;
	}
    }
  Mix_FreeMusic(music);
  Mix_CloseAudio();
  SDL_Quit();
}

double	check_a(double a)
{
  if (a <= 2)
    exit_write("Wrong a, must be > 2");
  return (a);
}

double	check_nmax(double nmax)
{
  if (nmax < 0)
    exit_write("Wrong nmax, must be >= 0");
  return (nmax);
}

void	check_arg(char *av1, char *av2)
{
  int	i;

  i = 0;
  while (av1[i] != '\0')
    if ((av1[i] >= '0' && av1[i] <= '9') || av1[i] == '.')
      i = i + 1;
    else
      exit_write("Please put correct arguments");
  i = 0;
  while (av2[i] != '\0')
    if ((av2[i] >= '0' && av2[i] <= '9') || av2[i] == '.')
      i = i + 1;
    else
      exit_write("Please put correct arguments");
}

void	main(int ac, char **av)
{
  if (ac == 3)
    {
      check_arg(av[1], av[2]);
      monster(check_a(atof(av[1])), check_nmax(atof(av[2])));
    }
  else
    exit_write("Usage : ./108monstre [a] [nmax]");
}
