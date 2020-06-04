/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanup.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnovotny <jnovotny@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/04 11:20:45 by jnovotny          #+#    #+#             */
/*   Updated: 2020/06/04 11:22:00 by jnovotny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void	clear_t_asm(t_asm *object)
{
	free(object);
}