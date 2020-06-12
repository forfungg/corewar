#include "asm.h"

/*
** Test printer to see the contents of the linked list.
*/

void print_list(t_operation *list)
{
	while (list != NULL)
	{
		ft_printf("\nlabel: %s\n", list->label);
		ft_printf("operation: %s\n", list->operation);
		ft_printf("arg1: %s\n", list->arg1);
		ft_printf("arg2: %s\n", list->arg2);
		ft_printf("arg3: %s\n", list->arg3);
		ft_printf("op_size: %s\n", list->op_size);
		ft_printf("t_dir_size: %s\n", list->t_dir_size);
		list = list->next;
	}
}

//Copies label/operation/instruction from start pos to end pos and returns it
//Doesn't work with multiple labels on the same row, need to fix (ex. live: live2: ...)
void	save_instru(t_operation **list, char *op)
{
	t_operation *temp;

	temp = *list;
	while (temp->next != NULL)
		temp = temp->next;
	if ((op[ft_strlen(op) - 1] == ':') && temp->label == NULL)
		temp->label = ft_strdup(op);
	else if (temp->operation == NULL)
		temp->operation = ft_strdup(op);
	else if (temp->arg1 == NULL)
		temp->arg1 = ft_strdup(op);
	else if (temp->arg2 == NULL)
		temp->arg2 = ft_strdup(op);
	else if (temp->arg3 == NULL)
		temp->arg3 = ft_strdup(op);
	free(op);
}

/*
** Splits the instructions and returns them.
*/

char		*split_instru(char *line, int start, int end)
{
	char *op;
	int i;

	i = 0;
	op = (char*)malloc(sizeof(char) * (end - start + 1));
	while (start <= end)
	{
		op[i] = line[start];
		i = i + 1;
		start = start + 1;
	}
	op[i] = '\0';
	return(op);
}

//Finds positions where labels/operations/instructions should be split
//Going to shorten and rework later, maybe with char mask and do something about the damn flag lol, it's a mess

int		analysis(t_asm *core, char *line, t_operation **list)
{
	int i;
	int start;
	int end;
	int flag;

	i = 0;
	start = 0;
	end = 0;
	flag = 0;
	while (line[i] != '\0')
	{
		if (line[i] == '#' || line[i] == ';')
			line[i] = '\0';
		if (((line[i] == ' ' || line[i] == '\t' || line[i] == ',') || i == 0) &&
			(line[i + 1] != ' ' && line[i + 1] != '\t' && line[i + 1] != ','))
		{
			(i == 0 && (line[i] != ' ' && line[i] != '\t' && line[i] != ',')) ? (start = 0) :
			(start = i + 1);
		}
		if (line[i] != '\0')
			i = i + 1;
		if ((line[i] == ' ' || line[i] == '\t' || line[i] == ',' || line[i] == '\0') &&
			(line[i - 1] != ' ' && line[i - 1] != '\t' && line[i - 1] != ','))
			end = i - 1;
		if (start < end && end == i - 1)
		{
			flag = flag + 1;
			if (flag == 1)
				list_append(list);
			save_instru(list, split_instru(line, start, end));
		}
	}
	return (1);
}