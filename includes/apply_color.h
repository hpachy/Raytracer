/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_color.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abitoun <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/09 14:50:04 by abitoun           #+#    #+#             */
/*   Updated: 2017/03/09 14:50:06 by abitoun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef APPLY_COLOR_H
# define APPLY_COLOR_H
# include "rt.h"
# include "obj.h"

int					get_color_value(t_vector3f c);
void				put_in_image(t_rt *rt, int x, int y, t_vector3f *color);
t_vector3f			apply_light(t_rt *rt, t_ray *ray, int rec_count);
int					is_shadow(t_obj *obj
								, t_inter *inter,
								t_list *list,
								t_ray *ray_obj);

t_vector3f			cylinder_mapping(t_inter inter_obj,
									t_vector3f **texture);
t_vector3f			**create_texture_tab(char *type);
t_vector3f			apply_color_2_annex(t_inter *inter,
										t_obj *obj,
										t_ray *ray,
										t_rt *rt);
#endif
