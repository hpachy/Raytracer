/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abitoun <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/24 13:48:33 by abitoun           #+#    #+#             */
/*   Updated: 2017/03/30 20:15:28 by jrichard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "light.h"
#include "inter.h"
#include "libft.h"
#include "obj.h"
#include "parser.h"

t_vector3f				calcul_light(t_obj *obj, t_ray *ray, t_inter *inter)
{
	t_vector3f			color_return;
	t_vector3f			coeffs;

	coeffs = calcul_coef(obj, inter, ray);
	color_return = mult_vector3f(mult_by_vector3f(obj->light.color,
		coeffs), obj->light.intensity);
	if (inter->obj->texture != NULL)
		color_return = div_vector3f(add_vector3f(color_return,
			mult_vector3f(mult_by_vector3f(inter->obj->texture(inter->obj,
				*inter), coeffs), obj->light.intensity)), 2.0);
	return (color_return);
}

static int				create_light2(t_kvlexer *token, t_rt *rt, t_obj *obj)
{
	(void)rt;
	if (!get_as_vector3f(token, "POS", &(obj->pos)))
		return ((int)ft_error("The LIGHT should contain a field POS"));
	if (!get_as_int(token, "ID", &(obj->id)))
		return ((int)ft_error("The LIGHT should contain a field ID"));
	if (!get_as_int(token, "IS_SRC", &(obj->is_src)))
		return ((int)ft_error("The LIGHT should contain a field IS_SRC"));
	if (obj->is_src)
		obj->light = get_light(token);
	if (!get_as_int(token, "IS_VISIBLE", &(obj->is_visible)))
		return ((int)ft_error("The LIGHT should contain a field IS_VISIBLE"));
	if (!get_as_vector3f(token, "COLOR", &(obj->light.color)))
		return ((int)ft_error("The LIGHT should contain a field COLOR"));
	if (!get_as_float(token, "INTENSITY", &(obj->light.intensity)))
		return ((int)ft_error("The LIGHT should contain a field INTENSITY"));
	return (1);
}

int						create_light(t_kvlexer *token, t_rt *rt)
{
	t_obj				obj;

	obj.data = NULL;
	obj.normal = NULL;
	obj.inter = NULL;
	obj.destroy = NULL;
	obj.texture = NULL;
	if (create_light2(token, rt, &obj))
		ft_lstadd(&rt->objs, ft_lstnew(&obj, sizeof(obj)));
	else
		return (0);
	return (1);
}
