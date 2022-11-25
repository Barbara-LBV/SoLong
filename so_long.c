#include "so_long.h"

/*int	main(void)
{
	void	*mlx;
	void	*mlx_win;

	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 1920, 1080, "Hello world!");
	mlx_loop(mlx);
	//printf("Coucou");
}*/

int	main(int ac, char **av)
{
	t_data	*game;
	int	pos = 0;

	game = malloc(sizeof(t_data));
	initiate_map(game, av[1]);
	if (check_errors(game, ac, av[1]) != 1)
		return (0);
	ft_printf("pos = %d\n", game->pos_p);
	if (check_path(game) == 0)
	{
		ft_printf("Invalid path\n");
	 	free_data(game);
	}
	else if (check_errors(game, ac, av[1]) == 1 && check_path(game) == 1)
	{
		ft_printf("-->tab start<--\n");
	 for (int i = 0 ; game->map[i] != NULL ; i++)
      		ft_printf("tab[%d]:%s\n", i, game->map[i]);
	 ft_printf("-->tab end<--\n");
	 free_data(game);
	}
	return (0);
}