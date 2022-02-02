/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-hiou <ael-hiou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/12 17:00:43 by ael-hiou          #+#    #+#             */
/*   Updated: 2021/12/18 17:51:11 by ael-hiou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include "mlx.h"
# define WALL_IMG "./images/wall.xpm"
# define PLAYER_IMG "./images/player.xpm"
# define COLLECTIBLE_IMG "./images/collectible.xpm"
# define EXIT_IMG "./images/exit.xpm"
# define BLACK_IMG "./images/black.xpm"
# define ENEMY_IMG "./images/enemy.xpm"
# define GAME_OVER_IMG "./images/gameover.xpm"
# define BUFFER_SIZE 10
# define MAP_UNITY 50
# define COUNTER_COLOR 0xFFDDFFF
# define COUNTER_POSITION 20

typedef struct s_list
{
	char			character;
	int				counter;
	struct s_list	*next;
}					t_list;

typedef struct mlx_info
{
	void	*mlx;
	void	*win;
	void	*img;
	char	**string;
	int		playerx;
	int		playery;
	int		movescounter;
}					t_mlx_lst;

typedef struct variables
{
	int		i;
	int		j;
	int		window_height;
	int		window_width;
	char	*str;
}		t_variables_list;

int			ft_length(char **str);
int			ft_destroy(void);
void		ft_lstclear(t_list **lst);
char		*ft_get_all_lines(int fd);
int			ft_isrectangle(char **s);
int			ft_check(char *str, char a);
int			ft_check_wall(char *s);
int			ft_collectibles_counter(char **str);
int			ft_check_for_characters(t_list *head);
void		ft_move_x(t_mlx_lst *list, int \
collectible_count, int direction, int *movescounter);
void		ft_move_y(t_mlx_lst *list, int \
collectible_count, int direction, int *movescounter);
int			check_player_counter(t_list *head);
void		ft_check_enemy_facing(t_mlx_lst *list, int direction, char a);
void		ft_create_player(t_mlx_lst *list, int i, int j);
void		ft_increment(char character, t_list *head);
void		ft_which_one_to_increment(char a, t_list *head);
char		*check_isvalidemap(int fd);
void		ft_create_elements(t_mlx_lst *list, int \
positionx, int positiony, char *imagepath);
char		*ft_itoa(int n);
int			ft_moveit(int key, t_mlx_lst *list);
char		*fill(char *str, long n, int size);
int			ft_get_size(long c);
t_list		*ft_lstnew(char character, int counter);
t_list		*ft_create_nodes(void);
void		ft_lstadd_back(t_list **lst, t_list *newone);
char		*ft_strrchr(char *s, int c);
int			ft_strncmp(const char *s1, const char *s2, size_t n);
void		free_it(char **str);
void		ft_check_elements(char *str, int i);
char		**ft_split(char *s, char c);
void		ft_printing_no_rectangle(void);
#endif
