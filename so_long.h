/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galetha <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 17:13:33 by galetha           #+#    #+#             */
/*   Updated: 2021/10/18 17:20:41 by galetha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include "get_next_line.h"
# define TOP 13
# define LEFT 0
# define RIGHT 2
# define DOWN 1
# define ESC 53

typedef struct s_data
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}			t_data;

typedef struct s_void
{
	void		*mlx;
	void		*mlx_win;
}				t_void;

typedef struct s_map
{
	void	*stn;
	void	*war;
	void	*fon;
	void	*dor;
	void	*cn;
	void	*liar;
	void	*end;
	void	*win;
	char	*wp;
	char	*ep;
	char	*lp;
	char	*cp;
	char	*sp;
	char	*pw;
	char	*fp;
	char	*dp;
	int		iw;
	int		ih;
}			t_map;
typedef struct s_it
{
	int	i;
	int	j;
	int	h;
	int	w;
	int	x_play;
	int	y_play;
}		t_it;

typedef struct st_job
{
	int		height;
	int		width;
	int		x_play;
	int		y_play;
	int		w_width;
	int		w_height;
	int		iw;
	int		end_game;
	int		ih;
	int		x_last;
	int		y_last;
	char	**ptr;
	void	*mlx;
	void	*mlx_win;
	int		count_coin;
	int		ex_coin;
	int		i;
	int		x;
	int		j;
	int		h;
	int		w;
	int		tmp_x;
	int		xp;
	int		py;
}			t_job;

void	path_sprt_bonus(t_map *map_in, t_job *lg);
void	condit_sprt_bonus(t_map map_in, t_job *lg, t_it it, char **arr);
void	condit_new_v1_bonus(t_job *lg, char **arr);
void	condit_new_v_bonus(t_job *lg, char **arr, int *fl);
void	new_value_bonus(t_job *lg);
void	end_fon_bonus(t_job *lg, char c);
void	win_arr_bonus(t_job *lg);
int		key_hook_bonus(int keycode, t_job *lg);
int		kh_exit_bonus(t_job *lg);
void	move_play_bonus(int keycode, char **arr, t_job *lg);
void	create_backgr_bonus(t_job *lg);
void	addNxM_bonus(char **arr, t_job *lg, char *av);
void	valid_value_bonus(char **arr, t_job *lg);
void	eval_string_bonus(int i, char **arr, t_job *lg);
void	eval_ft_ls_str_bonus(int i, char **arr, t_job *lg);
void	count_coins_bonus(t_job **lg);
void	valid_ber_bonus(char *av, int ac);
void	val_ber_bonus(char *str);
void	st_info_bonus(char *file_name, t_job **sl);
int		get_wid_bonus(char *file_name);
int		eval_count_bonus(char *file_name);
int		get_het_bonus(char *file_name);
void	fill_mat_bonus(char *line, char *arr, int len);
void	print_mass_bonus(t_job *lg, char **arr);
void	init_job_bonus(t_job **lg);
void	ft_no_malloc_bonus(char **arr, t_job *lg);
void	st_info(char *file_name, t_job **sl);
void	count_coins(t_job **lg);
void	eval_ft_ls_str(int i, char **arr, t_job *lg);
void	eval_string(int i, char **arr, t_job *lg);
void	valid_value(char **arr, t_job *lg);
void	addNxM(char **arr, t_job *lg, char *av);
void	init_job(t_job **lg);
void	print_mass(t_job *lg, char **arr);
void	fill_mat(char *line, char *arr, int len);
void	ft_no_malloc(char **arr, t_job *lg);
void	new_value(t_job *lg);
void	condit_new_value2(t_job *lg, char **arr, int *fl);
void	condit_new_value(t_job *lg, char **arr);
void	condit_sprites(t_map map_in, t_job *lg, t_it it, char **arr);
void	path_sprites(t_map *map_in, t_job *lg);
void	end_fon(t_job *lg, char c);
void	win_arr(t_job *lg);
void	move_play(int keycode, char **arr, t_job *lg);
void	create_backgr(t_job *lg);
void	val_ber(char *str);
void	valid_ber(char *av, int ac);
char	*ft_itoa(int n);
int		get_wid(char *file_name);
int		kh_exit(t_job *lg);
int		eval_count(char *file_name);
int		get_het(char *file_name);
int		key_hook(int keycode, t_job *lg);
#endif
