/*
** monstre_sdl.h for monstre_sdl in /home/benzah_m//projets/math/108
** 
** Made by marc benzahra
** Login   <benzah_m@epitech.net>
** 
** Started on  Sat Mar 16 00:09:42 2013 marc benzahra
** Last update Wed Mar 20 18:09:09 2013 marc benzahra
*/

#ifndef MONSTRE_SDL_H_
# define MONSTRE_SDL_H_
# include <math.h>
# include <time.h>
# include <stdlib.h>
# include <stdio.h>
# include <SDL/SDL.h>
# include <SDL/SDL_mixer.h>
# include <string.h>

void		exit_error(char *function, char *file, char *block);
void		exit_write(char *str);
void		set_pixel(SDL_Surface *surface, int x, int y, Uint32 color);
Mix_Music	*set_music(char *str);
void		monster(double a, double nmax);
double		check_a(double a);
double		check_nmax(double nmax);
void		check_arg(char *av1, char *av2);
void		main(int ac, char **av);

#endif /* !MONSTRE_SDL_H_ */
