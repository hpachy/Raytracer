/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abitoun <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/09 14:57:55 by abitoun           #+#    #+#             */
/*   Updated: 2017/03/31 17:35:37 by jrichard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "light.h"
#include "parser.h"
#include "thread_manager.h"

static void		del_obj(void *data, size_t size)
{
	t_obj		*obj;

	(void)size;
	obj = (t_obj *)data;
	if (obj->destroy)
		obj->destroy(obj);
	ft_memdel(&(obj->data));
	ft_memdel(&data);
}

void			refresh_rt(t_rt *rt)
{
	Uint32	size_pic;

	SDL_QueryTexture(rt->env.text, &size_pic, NULL, &rt->env.wh[0],
		&rt->env.wh[1]);
	SDL_LockTexture(rt->env.text, NULL, (void**)&rt->env.pixels,
		&rt->env.pitch);
	thread_manager(rt);
	SDL_UnlockTexture(rt->env.text);
}

void			render_rt(t_rt *rt)
{
	SDL_RenderClear(rt->env.rend);
	SDL_RenderCopy(rt->env.rend, rt->env.text, NULL, NULL);
	SDL_RenderPresent(rt->env.rend);
}

void			destroy_rt(t_rt *rt)
{
	if (rt)
	{
		rt->env.text ? SDL_DestroyTexture(rt->env.text) : 0;
		rt->env.rend ? SDL_DestroyRenderer(rt->env.rend) : 0;
		rt->env.win ? SDL_DestroyWindow(rt->env.win) : 0;
		SDL_Quit();
		ft_memdel((void **)(&rt->camera));
		ft_lstdel(&rt->materials, &del_material);
		ft_lstdel(&rt->textures, &del_tex);
		ft_lstdel(&rt->objs, &del_obj);
	}
}

t_rt			*create_rt(int x, int y, char *name)
{
	t_rt				*rt;

	if (!(rt = ft_memalloc(sizeof(*rt))))
		return (ft_error("Failed to create main structure"));
	rt->env.size = create_vector2f(x, y);
	if (!parser(name, rt))
		return (NULL);
	if (SDL_Init(SDL_INIT_VIDEO) < 0)
		return (ft_error("Failed to launch sdl"));
	rt->env.win = SDL_CreateWindow("RT", SDL_WINDOWPOS_UNDEFINED,
			SDL_WINDOWPOS_UNDEFINED,
			x, y,
			SDL_WINDOW_SHOWN);
	rt->env.rend = SDL_CreateRenderer(rt->env.win, -1,
		SDL_RENDERER_ACCELERATED);
	rt->env.text = SDL_CreateTexture(rt->env.rend, SDL_PIXELFORMAT_RGBA32,
			SDL_TEXTUREACCESS_STREAMING,
			x + 1, y + 1);
	if (!(rt->env.win && rt->env.text && rt->env.rend))
		return (ft_error("Failed to initialize sdl environment"));
	return (rt);
}
