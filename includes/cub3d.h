/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/23 17:27:32 by user42            #+#    #+#             */
/*   Updated: 2021/01/27 16:44:20 by pravry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include <stddef.h>
# include <stdio.h>
# include <math.h>
# include <stdlib.h>
# include <mlx.h>
# include <string.h>

typedef struct		s_format
{
	char	*no;
	char	*so;
	char	*we;
	char	*ea;
	char	**r;
	char	*sprite;
	char	**floor;
	char	**roof;
	char	**map;
	int		size;
	int		start;
	int		end;
	int		error;
}					t_format;

typedef struct		s_cam
{
	char	dir;
	float	dirx;
	float	diry;
	float	planx;
	float	plany;
	float	posx;
	float	posy;
	float	move_speed;
	float	rot_speed;
}					t_cam;

typedef struct		s_save
{
	unsigned char	*buf;
	unsigned int	pos;
	unsigned int	size;
}					t_save;

typedef struct		s_win
{
	void	*win;
	void	*mlx;
	void	*img_ptr;
	char	*img;
	int		size_line;
	int		l;
	int		h;
	int		w;
	int		s;
	int		a;
	int		d;
	int		lar;
	int		rar;
}					t_win;

typedef struct		s_img
{
	void	*img_ptr;
	char	*img_addr;
	int		size_line;
	int		byte_px;
	int		endian;
	int		h;
	int		w;
}					t_img;

typedef struct		s_text
{
	t_img	*no_tex;
	t_img	*so_tex;
	t_img	*ea_tex;
	t_img	*we_tex;
	t_img	*sprite_tex;
}					t_text;

typedef struct		s_line
{
	float	camx;
	float	posx;
	float	posy;
	float	raydirx;
	float	raydiry;
	float	deltadistx;
	float	deltadisty;
	float	sidedistx;
	float	sidedisty;
	float	wall_size;
	float	wall_hit;
	int		mapx;
	int		mapy;
	int		draw_start;
	int		draw_end;
	int		lineh;
	int		stepx;
	int		stepy;
	int		side;
}					t_line;

typedef struct		s_sprite
{
	float	spritex;
	float	spritey;
	float	invdet;
	float	transformx;
	float	transformy;
	int		spritescreenx;
	int		spriteheight;
	int		spritewidth;
	int		drawstarty;
	int		drawendy;
	int		drawstartx;
	int		drawendx;
}					t_sprite;

typedef struct		s_game
{
	t_cam			*cam;
	t_format		*info;
	t_win			*win;
	t_text			*text;
	t_line			*line;
	int				tot_sprite;
	float			wallz[10000];
	int				bmp;
}					t_game;

t_game				*g_game;

void				ft_fill_cam(void);
void				ft_sort_spr(float *spr, int nb_sprite);
void				sprite2(void);
char				*ft_substr(char *s, int start, size_t len);
char				*ft_strjoin(char *s1, char *s2);
char				*ft_strdup(char *src);
void				*ft_memcpy(void *dest, const void *src, size_t n);
char				*ft_strncat(char *dest, const char *src, size_t len);
size_t				ft_strlen(char *src);
int					get_next_line(int fd, char **line);
int					ft_strcmp(char *s1, char *s2);
char				**ft_split(char const *s, char c);
t_format			*ft_setup(t_format *info, char *av);
void				*ft_calloc(size_t count, size_t size);
void				check_double(char *s, t_format *info);
char				*ft_strlcpy(char *dst, const char *src, size_t srcsize);
char				*ft_strjoinmap(char *src, int size);
int					ft_map(t_format *info, int size);
int					ft_max_size_map(t_format *info);
int					ft_parse_map(t_format *info, int fd);
int					ft_atoi(const char *str);
t_cam				*ft_setup_cam(t_cam *cam);
int					ft_move(void);
t_game				*ft_setup_game(t_format *info, char **av);
int					trace(void);
void				dda(void);
void				hook_init(void);
void				get_text(void);
void				draw_wall(int x);
void				ft_check_map(void);
void				save_bmp(void);
int					check_spr(float *spr, int *nb_sprite);
void				ft_swap(int *a, int *b);
void				line_sprite(int *nb_sprite, float *spr);
int					dda_algo_sprite(float *spr, int *nb_sprite);
void				line_init(int x, t_line *line);
void				ft_rotate_left(void);
void				ft_rotate_right(void);
void				ft_fill_info(t_format *info, char *av);
int					cub3(void);
int					exit_prog();
void				parse_input(char **av, int ac);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
int					check_info(t_format *info);
char				*ft_itoa(int n);
void				free_win(void);
void				free_text(void);
void				free_cam(void);
void				free_info2(void);
int					ft_add_text(char **str, t_format *info);
int					ft_add_res(char **str, t_format *info);
int					ft_add_color(char **str, t_format *info, char *line);
int					ft_add_info(char **line, t_format **info);
void				free_tab(char **tab);
char				*ft_strcpy(char *dst, char *src);
void				free_info(void);
void				free_line(void);
int					close_window(void);
void				fill_line(t_line *line);
void				dda_utils(int x, int h);
void				drw_spr(int y, int spriteheight, int texx, int stripe);
void				draw_texsprite(t_img *text, int jk[2], int texx, int texy);
void				fill_spr(float *spr);
void				drw_spr_loop(t_sprite *sprite, int stripe);
void				ft_check_pos(char c, int i, int j);
void				ft_check(int i, int j);
int					ft_mapsize(int t);
void				ft_check_error_map(void);
void				ft_check_error(char c);
void				free_i(t_format *info);
int					check_char(char **tmp);
int					ft_strlen1(char **tab);
int					check_atoi(char **param);
int					setup_game2(char **av);
void				nbr_sprite(void);
void				ft_screen(t_format *info, t_win *win);
void				ft_font(void);
int					check_ligne_vide(t_format *info, char **tmp);
void				add_color_floor(t_format *info, char *line);
void				add_color_roof(t_format *info, char *line);
void				fill_neg(char **inf);
int					check_color(char *line);
char				*join_line(char **tab);

#endif
