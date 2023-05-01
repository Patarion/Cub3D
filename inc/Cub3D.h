
#ifndef CUB3D_H
#define CUB3D_H

#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdbool.h>
#include "Libft/libft.h"

static const char *g_side_tab[7] = {"NO ", "SO ", "WE ", "EA ", "F ", "C ", NULL};
static const char *g_dir_tab[5] = {"N", "E", "S", "W", NULL};

enum e_error_code	{GOOD, PATH, COLOR, MAP};

typedef struct s_map_line {
    char    *line;
    int     line_nbr;
    int     len;
    bool    player;
    int     player_x;
} t_map_line;

typedef struct s_map {
    char    *adj_line_len;
    char    player;
    bool    first_line;
    bool    last_line;
    char    *map_layout;
    char    direction;
    int     player_x;
    int     player_y;
} t_map;

typedef struct s_parse {
    char    			*NO;
    char    			*SO;
    char    			*WE;
    char    			*EA;
    unsigned int		FloorColor;
    unsigned int		CeilingColor;
    t_map               *map;
	enum e_error_code	error;
} t_parse;

void            ParseLine(char *line, t_parse* MapCheck);
int             ParseInfo(char *map);
void            ParsePath(t_parse* MapCheck, char *line, int j);
void            ParseColor(t_parse *data, char *line, int j);
char            *GetPath(char *dir, char *line);
t_parse         *InitCheck();
int             easy_gnl(int fd, t_parse *data);
void            clear_data(t_parse *data);
unsigned int	ft_Uatoi(const char *str, t_parse *data);
void            error_handler(t_parse *data);
void            ParseMap(char *line, t_parse *parse);

#endif
