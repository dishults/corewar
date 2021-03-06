#include "asm.h"

void		print_tab(t_data *d)
{
	int	i;

	i = 0;
	ft_putstr("--------------------------------\n");
	while (d->tab[i])
	{
		printf("%s\n", d->tab[i]);
		i++;
	}
	ft_putstr("--------------------------------\n");
}

void	show_op_param_types(t_op *op)
{
	int	i;
	int	n;

	i = 0;
	while (op[i].id < 17)
	{
		n = 0;
		printf("%s :\t", op[i].name);
		while (n < op[i].params_nb)
		{
			printf("%i ", op[i].params_types[n]);
			n++;
		}
		printf("\n");
		i++;
	}
}

void	show_bytes_till_label(t_data *d)
{
	t_labels *current = d->first_label;
	int	line = 0;
	int	label = 0;

	while (line--)
		current = current->next;
	printf("bytes from "S" till label "S" in hex : %x\n\n",\
			current->op_code, current->args[label],\
			bytes_till_label(d->first_label, current, label));
}

void    show_labels(t_data *d)
{
	t_labels *tmp;
	int		i;

	tmp = d->first_label;
	ft_putstr("\n\tLABELS\n\n");
	while (tmp)
	{
		i = 0;
		printf("NAME:\t\t%s\
				\nop_code:\t%s\
				\nop_nb:\t\t%i\
				\nargs:", tmp->name, tmp->op_code, tmp->op_nb);
		while (tmp->op_nb != 0 && tmp->args[i])
		{
			printf("\t\t%s\n", tmp->args[i]);
			i++;
		}
		if (tmp->op_nb != 0)
		{
			printf("position:\t%i\
					\nencoded_byte:\t%i\
					\ndir_as_ind:\t%i\
					\nbytes:\t\t%i\n\n\n",\
					tmp->position, d->op[tmp->op_nb - 1].encoded_byte,\
					d->op[tmp->op_nb - 1].dir_as_ind, tmp->bytes);
		}
		else
		{
			printf("\t\t%s\nposition:\t%i\
					\nencoded_byte:\t%i\
					\ndir_as_ind:\t%i\
					\nbytes:\t\t%i\n\n\n",\
					(char*)0, tmp->position, d->op[tmp->op_nb].encoded_byte,\
					d->op[tmp->op_nb].dir_as_ind, tmp->bytes);
		}
		tmp = tmp->next;
	}
	printf("total number of bytes : %zu\n\n", d->total_bytes);
	print_tab(d);
}
