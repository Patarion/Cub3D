
#ifndef CUB3D_H
#define CUB3D_H

#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdbool.h>
#include <math.h>
#include "Libft/libft.h"
#include "../MLX42/include/MLX42/MLX42.h"

#define w 1920 //screen width
#define h 1080 //screen height

static const char *g_side_tab[7] = {"NO ", "SO ", "WE ", "EA ", "F ", "C ", NULL};
static const char *g_dir_tab[5] = {"N", "E", "S", "W", NULL};

enum e_error_code	{GOOD, PATH, COLOR, MAP, PLAYER, CUB_FILE};

typedef struct s_map {
    bool    first_line;
    bool    last_line;
    char    player;
    char    **map;
    char    direction;
    int     player_x;
    int     player_y;
	int		nb_lines;
} t_map;

typedef struct s_raycast {
    double  pos_playerX; //start position of player on x
    double  pos_playerY; //start position of player on y
    double  dir_playerX; //initial  director of vector of the player on x
    double  dir_playerY; //initial director of vector of the player on y
    double  plane_playX; //camera plane of the player on X
    double  plane_playY; //camera plane of the player on Y
    double  cameraX; //x-coordinate in camera space
    double  ray_dirX; //ray direction on x
    double  ray_dirY; //ray direction on y
    int     mapX; //current square of the map, in the x axis
    int     mapY; //current square of the map, in the y axis
} t_raycast;

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
    t_raycast           *ray;
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
int             first_parse(int fd, t_parse *data);
void            clear_data(t_parse *data);
unsigned int	ft_Uatoi(const char *str, t_parse *data);

/*      CLEAR           */
void            clear_data(t_parse *data);

/*      ERROR           */
void            error_handler(t_parse *data);
void			check_ParseInfo(t_parse *data);

/*      PARSING_MAP     */
void            ParseMap(char *line, t_parse *parse);
void			map_space_handler(char *line, int *i, t_parse *parse);
void			GetTmpMap(t_parse *data, int fd);
void			print_double_tab(char **tab);
char			*ez_gnl(int fd);
void			flood_fill(t_parse *data, int y, int x);

/*      INIT_GAME       */
void    start_mlx(t_parse *data);

/*      RAYCAST         */


#endif
