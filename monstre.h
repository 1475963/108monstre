/*
** monstre.h for monstre in /home/benzah_m//projets/math/108
** 
** Made by marc benzahra
** Login   <benzah_m@epitech.net>
** 
** Started on  Mon Mar 11 14:59:32 2013 marc benzahra
** Last update Sat Mar 16 00:10:33 2013 marc benzahra
*/

#ifndef MONSTRE_H_
# define MONSTRE_H_
# include <math.h>
# include <time.h>
# include <stdlib.h>
# include <stdio.h>
# include <mlx.h>
# include <string.h>

struct s_ptr
{
  void	*mlx;
  void	*win;
  void	*img;
};

typedef struct s_ptr t_ptr;

struct s_data
{
  int	bpp;
  int	sizeline;
  int	endian;
  char	*data;
};

typedef struct s_data t_data;

struct s_color
{
  int	r;
  int	g;
  int	b;
};

typedef struct s_color t_color;

void	exit_error(char *function, char *file, char *block);
void	exit_write(char *str);
void	my_pixel_put_to_image(int x, int y, char *data, t_color *color);
void	draw_horizontal(t_ptr *ptr, char *data, double x1, double y1, double x2, double y2);
void	draw_vertical(t_ptr *ptr, char *data, double x1, double y1, double x2, double y2);
void	draw_graph(t_ptr *ptr);
int	manage_expose(void *param);
int	manage_key(int keycode, void *param);
void	monster(double a, double nmax);
double	check_a(double a);
double	check_nmax(double nmax);
void	check_arg(char *av1, char *av2);
void	main(int ac, char **av);

#endif /* !MONSTRE_H_ */
