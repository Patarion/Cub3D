
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
#define texWidth 64
#define texHeight 24

static const char *g_side_tab[7] = {"NO ", "SO ", "WE ", "EA ", "F ", "C ", NULL};
static const char *g_dir_tab[5] = {"N", "E", "S", "W", NULL};

enum e_error_code	{GOOD, PATH, COLOR, MAP, PLAYER, CUB_FILE};

typedef struct s_map {
    bool    first_line;
    bool    last_line;
    char    player;
    char    **map;
    char    direction;
    int     player_x; //current square of the map, in the x axis (mapX)
    int     player_y; //current square of the map, in the y axis (mapY)
	int		nb_lines;
    int     texture_we;
    int     texture_ea;
    int     texture_so;
    int     texture_no;
    int     **array_textures;

} t_map;

typedef struct s_xpm{
    xpm_t   *NO;
    xpm_t   *SO;
    xpm_t   *EA;
    xpm_t   *WE;
}   t_xpm;
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
    double  sideX_dist; //length of ray from current pos to next x
    double  sideY_dist; //length of ray from current pos to next y
    double  furtherX_dist; //distance/length of ray from 1 x-side to the next x-side; not at starting point; further on the line
    double  furtherY_dist; //distance/length of ray from 1 y-side to the next y-side
    double  perpendicular_wallDist; //distance/length from the point hit on the wall to the "camera plane" line.
    int     step_x; //to go in x first
    int     step_y; //to go in y first
    int     hit; //flag to check if a wall was hit or not; 0 = no hit
    int     side; //flag to check if it was a NS or EW wall hit. sideX_dist < sideY_dist = side 0. sideX_dist > sideY_dist = side 1.
    int     line_height; //to know the height of the line to draw
    int     draw_start_pt;
    int     draw_end_pt;
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
    t_xpm               *xpm;
	enum e_error_code	error;
} t_parse;

/*      PARSING_INFO    */
void            ParseLine(char *line, t_parse* MapCheck);
t_parse         *ParseInfo(char *map);
void            ParsePath(t_parse* MapCheck, char *line, int j);
void            ParseColor(t_parse *data, char *line, int j);

/*      GET             */
char            *GetPath(char *line);
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
void			print_info(t_parse *data);

/*      INIT_GAME       */
void    start_mlx(t_parse *data);

/*      RAYCAST         */
void	start_raycast(t_parse *data);
void	go_raycast(t_parse *data);

/*      TEXTURE         */
void	add_texture(t_parse *data);

/*		KEY_EVENT		*/
void	key_event(struct mlx_key_data key, void *data);

#endif
