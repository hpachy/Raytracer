/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   half_sphere.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jqueyrou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/30 14:51:08 by jqueyrou          #+#    #+#             */
/*   Updated: 2017/03/30 20:12:03 by jrichard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "rt.h"
#include "half_sphere.h"
#include "quadratic.h"
#include "parser.h"
#include "inter.h"
#include "libft.h"
#include "cut.h"
#define SPHERE ((t_half_sphere *)obj->data)

static	t_vector3f	half_sphere_tex(t_obj *self, t_inter inter)
{
	t_vector3f		color;
	t_vector3f		pos;
	t_vector3f		uv;

	pos = sub_vector3f(inter.obj->pos, inter.impact);
	pos = normalize_vector3f(pos);
	uv.x = asinf(pos.x) / M_PI + 0.5f;
	uv.y = asinf(pos.y) / M_PI + 0.5f;
	color = get_tex_point(self->tex, uv.x, uv.y);
	return (color);
}

static float		inter_half_sphere(t_obj *obj, t_ray *ray)
{
	t_quadratic		var;
	t_vector3f		tmp;

	tmp = sub_vector3f(obj->pos, ray->start);
	var.a = dot_vector3f(tmp, ray->dir);
	var.b = var.a * var.a - dot_vector3f(tmp, tmp) + SPHERE->radius
	* SPHERE->radius;
	if (var.b < 0)
		return (NAN);
	var.sol_1 = var.a - sqrt(var.b);
	var.sol_2 = var.a + sqrt(var.b);
	if (var.sol_1 > var.sol_2)
		var.result = var.sol_2;
	else
		var.result = var.sol_1;
	return (cut_sphere(obj, ray, &var));
}

static t_vector3f	normal_half_sphere(struct s_obj *obj, t_vector3f *impact)
{
	float d;

	d = dot_vector3f(SPHERE->dir, obj->pos);
	if (((dot_vector3f(*impact, SPHERE->dir) - d) < 0.0005f)
		&& ((dot_vector3f(*impact, SPHERE->dir) - d) > -0.0005f))
		return (mult_vector3f(SPHERE->dir, -1));
	return (normalize_vector3f(sub_vector3f(*impact, obj->pos)));
}

static int			create_half_sphere2(t_kvlexer *token, t_rt *rt, t_obj *obj)
{
	if (!get_material(token, rt, &(obj->mat)))
		return (0);
	if (!get_texture(token, rt, &(obj->tex)))
		obj->texture = NULL;
	if (!get_as_vector3f(token, "POS", &(obj->pos)))
		return ((int)ft_error("The HALF_SPHERE should contain a field POS"));
	if (!get_as_int(token, "ID", &(obj->id)))
		return ((int)ft_error("The HALF_SPHERE should contain a field ID"));
	if (!get_as_int(token, "IS_SRC", &(obj->is_src)))
		return ((int)ft_error("The HALF_SPHERE should contain a field IS_SRC"));
	if (obj->is_src)
		obj->light = get_light(token);
	if (!get_as_int(token, "IS_VISIBLE", &(obj->is_visible)))
		return ((int)ft_error("The HALF_SPHERE should contain a "
		"field IS_VISIBLE"));
	if (!get_as_float(token, "RADIUS", &(SPHERE->radius)))
		return ((int)ft_error("The HALF_SPHERE should contain a field RADIUS"));
	if (!get_as_vector3f(token, "DIR", &(SPHERE->dir)))
		return ((int)ft_error("The HALF_SPHERE should contain a field DIR"));
	return (1);
}

int					create_half_sphere(t_kvlexer *token, t_rt *rt)
{
	t_obj			obj;

	if (!(obj.data = ft_memalloc(sizeof(t_half_sphere))))
		return (0);
	obj.normal = &normal_half_sphere;
	obj.inter = &inter_half_sphere;
	obj.texture = &half_sphere_tex;
	obj.destroy = NULL;
	if (create_half_sphere2(token, rt, &obj))
		ft_lstadd(&rt->objs, ft_lstnew(&obj, sizeof(obj)));
	else
	{
		free(obj.data);
		return (0);
	}
	return (1);
}
