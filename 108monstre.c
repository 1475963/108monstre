/*
** 108monstre.c for monstre in /home/benzah_m//projets/math/108
** 
** Made by marc benzahra
** Login   <benzah_m@epitech.net>
** 
** Started on  Mon Mar 11 15:04:18 2013 marc benzahra
** Last update Sat Mar 16 00:14:37 2013 marc benzahra
*/

#include "monstre.h"

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

void    my_pixel_put_to_image(int x, int y, char *data, t_color *color)
{
  int   xmem;

  xmem = (4 * (1000 * y)) + (4 * x);
  data = data + xmem;
  data[0] = color->r;
  data[1] = color->g;
  data[2] = color->b;
}

void		draw_horizontal(t_ptr *ptr, char *data, double x1, double y1, double x2, double y2)
{
  double	x;
  double	mem;
  t_color	color;

  color.r = 255;
  color.g = 255;
  color.b = 255;
  x = x1;
  if (y1 == y2)
    {
      if (x > x2)
	{
	  mem = x;
	  x = x2;
	  x2 = mem;
	}
      while (x <= x2)
	{
	  my_pixel_put_to_image(x, y1, data, &color);
	  x = x + 1;
	}
      mlx_put_image_to_window(ptr->mlx, ptr->win, ptr->img, 0, 0);
    }
}

void		draw_vertical(t_ptr *ptr, char *data, double x1, double y1, double x2, double y2)
{
  double	y;
  t_color	color;

  color.r = 255;
  color.g = 255;
  color.b = 255;
  if (x1 == x2)
    {
      y = y1;
      if (y1 < y2)
	{
	  y = y2;
	  y2 = y1;
	}
      while (y >= y2)
	{
	  my_pixel_put_to_image(x1, y, data, &color);
	  y = y - 1;
	}
      mlx_put_image_to_window(ptr->mlx, ptr->win, ptr->img, 0, 0);
    }
}

void	draw_graph(t_ptr *ptr)
{
  mlx_string_put(ptr->mlx, ptr->win, 100, 915, 000255255255, "-2.0");
  mlx_string_put(ptr->mlx, ptr->win, 200, 915, 000255255255, "-1.5");
  mlx_string_put(ptr->mlx, ptr->win, 300, 915, 000255255255, "-1.0");
  mlx_string_put(ptr->mlx, ptr->win, 400, 915, 000255255255, "-0.5");
  mlx_string_put(ptr->mlx, ptr->win, 500, 915, 000255255255, "0.0");
  mlx_string_put(ptr->mlx, ptr->win, 600, 915, 000255255255, "0.5");
  mlx_string_put(ptr->mlx, ptr->win, 700, 915, 000255255255, "1.0");
  mlx_string_put(ptr->mlx, ptr->win, 800, 915, 000255255255, "1.5");
  mlx_string_put(ptr->mlx, ptr->win, 900, 915, 000255255255, "2");
  mlx_string_put(ptr->mlx, ptr->win, 75, 900, 000255255255, "-2.0");
  mlx_string_put(ptr->mlx, ptr->win, 75, 800, 000255255255, "-1.5");
  mlx_string_put(ptr->mlx, ptr->win, 75, 700, 000255255255, "-1.0");
  mlx_string_put(ptr->mlx, ptr->win, 75, 600, 000255255255, "-0.5");
  mlx_string_put(ptr->mlx, ptr->win, 80, 500, 000255255255, "0.0");
  mlx_string_put(ptr->mlx, ptr->win, 80, 400, 000255255255, "0.5");
  mlx_string_put(ptr->mlx, ptr->win, 80, 300, 000255255255, "1.0");
  mlx_string_put(ptr->mlx, ptr->win, 80, 200, 000255255255, "1.5");
  mlx_string_put(ptr->mlx, ptr->win, 80, 100, 000255255255, "2.0");
}

int	manage_expose(void *param)
{
  t_ptr	*p;

  p = (t_ptr *)param;
  mlx_put_image_to_window(p->mlx, p->win, p->img, 0, 0);
  draw_graph(p);
  return (0);
}

int	manage_key(int keycode, void *param)
{
  if (keycode == 65307)
    exit(0);
  return (0);
}

void		monster(double a, double nmax)
{
  int		n;
  double	x;
  double	res;
  double	min;
  double	max;
  t_ptr		ptr;
  t_data	data;
  t_color	color;

  srand(time(NULL));
  color.r = rand() % 256;
  color.g = rand() % 256;
  color.b = rand() % 256;
  ptr.mlx = mlx_init();
  ptr.win = mlx_new_window(ptr.mlx, 1000, 1000, "GRAPH");
  ptr.img = mlx_new_image(ptr.mlx, 1000, 1000);
  data.data = mlx_get_data_addr(ptr.img, &data.bpp, &data.sizeline, &data.endian);
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
      if (x == -2)
	{
	  min = res;
	  max = res;
	}
      if (res < min)
	min = res;
      if (res > max)
	max = res;
      printf("x = (%f)\ty = (%f)\n", x, res);
      my_pixel_put_to_image(500 + x * 200, 500 - res * 200, data.data, &color);
      x = x + 0.0001;
    }
  //  printf("min = (%f)\tmax = (%f)\nround min = (%f)\tround max = (%f)\n", min, max, floor(min), ceil(max));
  mlx_put_image_to_window(ptr.mlx, ptr.win, ptr.img, 0, 0);
  draw_horizontal(&ptr, data.data, 100, 900, 900, 900);
  draw_vertical(&ptr, data.data, 100, 900, 100, 100);
  draw_graph(&ptr);
  mlx_expose_hook(ptr.win, manage_expose, (void *)&ptr);
  mlx_key_hook(ptr.win, manage_key, (void *)&ptr);
  mlx_loop(ptr.mlx);
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
