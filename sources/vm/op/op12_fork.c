/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op12_fork.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asolopov <asolopov@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/17 15:02:59 by jnovotny          #+#    #+#             */
/*   Updated: 2020/07/24 17:26:18 by asolopov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "oplist_cw.h"

void	op_fork(t_vm *core, t_car *car)
{
	ssize_t	index;
	int		val;

	if (LOG)
		vm_log("Carriage[%zu] - operation \"%s\"\n", \
			car->id, g_oplist[car->op_index].opname);
	fill_args("fork", car->args);
	index = car->pc + OP_SIZE;
	if (read_args(core->arena, car->args, index % MEM_SIZE))
	{
		val = car->pc + car->args->arg[0] % IDX_MOD;
		copy_carriage(core, car, val);
	}
	get_step(car, car->args);
}
