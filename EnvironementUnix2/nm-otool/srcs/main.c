/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jflorimo <jflorimo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/04/22 16:41:36 by jflorimo          #+#    #+#             */
/*   Updated: 2014/04/22 16:41:37 by jflorimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include "nm.h"
#include "libft.h"

#include <stdio.h>
#include <sys/mman.h>
#include <mach-o/loader.h>
#include <mach-o/nlist.h>
#include <sys/stat.h>

void						print_output(int n, int s, int t, char *ptr)
{
	int						i;
	char					*stringtable;
	struct nlist_64			*el;

	el = (void *)ptr + s;
	stringtable = (void *)ptr + t;
	i = 0;
	while (i < n)
	{
		if (el[i].n_value > 0)
		{
			ft_putstr("00000000");
			ft_putnbr_base(el[i].n_value, 16);
		}
		else
			ft_putstr("                 ");
		if (!ft_strcmp(stringtable + el[i].n_type, "header"))
			ft_putstr(" T ");
		else
			ft_putstr(" U ");
		ft_putstr(stringtable + el[i].n_un.n_strx);
		ft_putstr("\n");
		i++;
	}
}

void						handle_64(void *ptr)
{
	int						ncmds;
	int						i;
	struct mach_header_64	*header;
	struct load_command		*lc;
	struct symtab_command	*sym;

	i = 0;
	header = (struct mach_header_64 *)ptr;
	ncmds = header->ncmds;
	lc = (void *)ptr + sizeof(*header);
	while (i < ncmds)
	{
		if (lc->cmd == LC_SYMTAB)
		{
			sym = (struct symtab_command *)lc;
			print_output(sym->nsyms, sym->symoff, sym->stroff, ptr);
			break ;
		}
		lc = (void *)lc + lc->cmdsize;
		i++;
	}
}

void						nm(char *ptr)
{
	int						magic_number;

	magic_number = *(int *)ptr;
	if (magic_number == MH_MAGIC_64)
	{
		handle_64(ptr);
	}
}

int							main(int ac, char **av)
{
	int						fd;
	char					*ptr;
	struct stat				buf;

	if (ac > 1)
	{
		if ((fd = open(av[1], O_RDONLY)) < 0)
		{
			return (0);
		}
		if (fstat(fd, &buf) < 0)
		{
			return (0);
		}
		if ((ptr = mmap(0, buf.st_size, PROT_READ, MAP_PRIVATE, fd, 0))
		== MAP_FAILED)
			return (0);
		nm(ptr);
		if (munmap(ptr, buf.st_size) < 0)
			return (0);
	}
	return (0);
}
