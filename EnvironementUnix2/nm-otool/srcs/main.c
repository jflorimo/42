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

void	print_output(int nyms, int symoff, int stroff, char *ptr)
{
	int i;
	char *stringtable;
	struct nlist_64 *el;

	el = (void *)ptr + symoff;
	stringtable = (void *)ptr + stroff;

	for (i = 0; i < nyms; ++i)
	{
		if (el[i].n_value > 0)
			printf("%016llx ", el[i].n_value);
		else
			printf("                 ");
		if (!ft_strcmp(stringtable + el[i].n_type, "header"))
		{
			printf("T");
		}
		else
			printf("%s", stringtable + el[i].n_type);
		printf(" %s\n", stringtable + el[i].n_un.n_strx);
	}
}

void 	handle_64(void *ptr)
{
	int						ncmds;
	int						i;
	struct mach_header_64	*header;
	struct load_command		*lc;
	struct symtab_command	*sym;

	i = 0;
	header =(struct mach_header_64 *)ptr;
	ncmds = header->ncmds;
	lc = (void *)ptr + sizeof(*header);
	for (i = 0; i < ncmds; i++)
	{
		if(lc->cmd == LC_SYMTAB)
		{
			sym = (struct symtab_command *) lc;
			print_output(sym->nsyms, sym->symoff, sym->stroff, ptr);
			break ;
		}
		lc = (void *)lc + lc->cmdsize;
	}
}

void	nm(char *ptr)
{
	int magic_number;

	magic_number = *(int *)ptr;
	if (magic_number == MH_MAGIC_64)
	{
		handle_64(ptr);
	}
}

int main(int ac, char **av)
{
	int fd;
	char *ptr;
	struct stat buf;
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
		if ((ptr = mmap(0, buf.st_size, PROT_READ, MAP_PRIVATE, fd, 0)) == MAP_FAILED)
			return (0);
		nm(ptr);
		if (munmap(ptr, buf.st_size) < 0)
			return (0);
	}
	return (0);
}
// void		ft_read_file(char *s)
// {
// 	int		fd;
// 	char	*line;

// 	fd = open(s, O_RDONLY);
// 	line = NULL;
// 	while(get_next_line(fd, &line))
// 	{
// 		ft_putstr(line);
// 		ft_putstr("\n");
// 		free(line);
// 	}
// }

// int 		main(int ac, char **av)
// {
// 	int		i;

// 	i = 1;
// 	if (ac > 1)
// 	{
// 		while(av[i])
// 		{
// 			ft_putstr(av[i]);
// 			ft_putstr("\n");
// 			ft_read_file(av[i]);
// 			i++;
// 		}
// 	}
// 	return (0);
// }