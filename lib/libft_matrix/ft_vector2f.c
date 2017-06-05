/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vector2f.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrichard <jrichard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/10 14:31:42 by jrichard          #+#    #+#             */
/*   Updated: 2017/02/25 12:53:47 by jrichard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "ft_vector2f.h"

t_vector2f		create_vector2f(float x, float y)
{
	t_vector2f	vector;

	vector.x = x;
	vector.y = y;
	return (vector);
}

t_vector2f		add_vector2f(t_vector2f v1, t_vector2f v2)
{
	t_vector2f	new;

	new.x = v1.x + v2.x;
	new.y = v1.y + v2.y;
	return (new);
}

t_vector2f		sub_vector2f(t_vector2f v1, t_vector2f v2)
{
	t_vector2f	new;

	new.x = v1.x - v2.x;
	new.y = v1.y - v2.y;
	return (new);
}

t_vector2f		mult_vector2f(t_vector2f v1, float nb)
{
	t_vector2f	new;

	new.x = v1.x * nb;
	new.y = v1.y * nb;
	return (new);
}

t_vector2f		div_vector2f(t_vector2f v1, float nb)
{
	t_vector2f	new;

	nb = 1.0f / nb;
	new.x = v1.x * nb;
	new.y = v1.y * nb;
	return (new);
}
