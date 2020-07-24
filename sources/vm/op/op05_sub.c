/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op05_sub.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asolopov <asolopov@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/17 15:02:59 by jnovotny          #+#    #+#             */
/*   Updated: 2020/07/24 17:23:10 by asolopov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "oplist_cw.h"

static void	do_sub(t_args *args, t_car *car)
{
	int	val[3];

	val[0] = car->reg[args->arg[0] - 1];
	val[1] = car->reg[args->arg[1] - 1];
	car->reg[args->arg[2] - 1] = val[0] - val[1];
	car->carry = car->reg[args->arg[2] - 1] ? 0 : 1;
}


void	op_sub(t_vm *core, t_car *car)
{
	ssize_t	index;

	if (LOG)
		vm_log("Carriage[%zu] - operation \"%s\"\n", \
			car->id, g_oplist[car->op_index].opname);
	fill_args("sub", car->args);
	index = car->pc + OP_SIZE;
	if (read_arg_type(core->arena, car->args, index % MEM_SIZE))
	{
		index += ARG_SIZE;
		if (read_args(core->arena, car->args, index % MEM_SIZE))
			do_sub(car->args, car);
	}
	get_step(car, car->args);
}
