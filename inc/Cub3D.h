
#ifndef CUB3D_H
#define CUB3D_H

#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdbool.h>
#include "Libft/libft.h"

static const char *g_side_tab[7] = {"NO ", "SO ", "WE ", "EA ", "F ", "C ", NULL};
static const char *g_dir_tab[5] = {"N", "E", "S", "W", NULL};

enum e_error_code	{GOOD, PATH, COLOR, MAP, CUB_FILE};

typedef struct s_map {
    bool    first_line;
    bool    last_line;
    char    player;
    char    **map_layout;
    char    direction;
    int     player_x;
    int     player_y;
	int		nb_lines;
} t_map;

typedef struct s_parse {
    char    			*NO;
    char    			*SO;
    char    			*WE;
    char    			*EA;
    unsigned int		FloorColor;
    unsigned int		CeilingColor;
	bool				treat_Floor;
	bool				treat_Ceiling;
	int					MapBeg;
    t_map               *map;
	enum e_error_code	error;
} t_parse;

void            ParseLine(char *line, t_parse* MapCheck);
int             ParseInfo(char *map);
void            ParsePath(t_parse* MapCheck, char *line, int j);
void            ParseColor(t_parse *data, char *line, int j);
char            *GetPath(char *dir, char *line);
t_parse         *InitCheck();
int             first_parse(int fd, t_parse *data);
void            clear_data(t_parse *data);
unsigned int	ft_Uatoi(const char *str, t_parse *data);
void            error_handler(t_parse *data);
void            ParseMap(char *line, t_parse *parse);
void			check_ParseInfo(t_parse *data);
void			map_space_handler(char *line, int *i, t_parse *parse);
void			GetTmpMap(t_parse *data, int fd);
void			print_double_tab(char **tab);
char			*ez_gnl(int fd);

#endif
