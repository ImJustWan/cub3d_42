#include "keys.h"
#include "hooks.h"

int	keys_release(int button, t_world *world)
{
	if (button == RIGHT && world->player->rotate <= 1)
		world->player->rotate = 0;
	if (button == LEFT && world->player->rotate >= 1)
		world->player->rotate = 0;
	if (button == KEY_W && world->player->move.y == 1)
		world->player->move.y = 0;
	if (button == KEY_A && world->player->move.x == -1)
		world->player->move.x = 0;
	if (button == KEY_S && world->player->move.y == -1)
		world->player->move.y = 0;
	if (button == KEY_D && world->player->move.x == 1)
		world->player->move.x = 0;
	return (0);
}

int	keys_press(int button, t_world *world)
{
	if (button == RIGHT)
		world->player->rotate -= 1;
	if (button == LEFT)
		world->player->rotate += 1;
	if (button == KEY_W)
		world->player->move.y = 1;
	if (button == KEY_A)
		world->player->move.x = -1;
	if (button == KEY_S)
		world->player->move.y = -1;
	if (button == KEY_D)
		world->player->move.x = 1;
	if (button == ESC)
		clean_exit(world);
	return (0);
}
