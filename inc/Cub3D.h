
#ifndef CUB3D_H
#define CUB3D_H

#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdbool.h>
#include <math.h>
#include "Libft/libft.h"
#include "../MLX42/include/MLX42/MLX42.h"

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
    mlx_t               *mlx;
    mlx_image_t         *image;
    unsigned int		FloorColor;
    unsigned int		CeilingColor;
	bool				treat_Floor;
	bool				treat_Ceiling;
	int					MapBeg;
    t_map               *map;
	enum e_error_code	error;
} t_parse;

/*      PARSING_INFO    */
void            ParseLine(char *line, t_parse* MapCheck);
int             ParseInfo(char *map);
void            ParsePath(t_parse* MapCheck, char *line, int j);
void            ParseColor(t_parse *data, char *line, int j);

/*      GET             */
char            *GetPath(char *dir, char *line);
void	        GetTmpMap(t_parse *data, int fd);

/*      INIT_DATA       */
t_parse         *InitCheck();

/*      UTILS           */
int             easy_gnl(int fd, t_parse *data);
unsigned int	ft_Uatoi(const char *str, t_parse *data);

/*      CLEAR           */
void            clear_data(t_parse *data);

/*      ERROR           */
void            error_handler(t_parse *data);
void			check_ParseInfo(t_parse *data);

/*      PARSING_MAP     */
void            ParseMap(char *line, t_parse *parse);
void			map_space_handler(char *line, int *i, t_parse *parse);

/*      INIT_GAME       */
void    start_mlx(t_parse *data);

/*      RAYCAST         */


#endif
