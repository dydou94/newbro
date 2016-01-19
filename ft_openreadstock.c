/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_openreadstock.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyuzan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/05 09:05:38 by dyuzan            #+#    #+#             */
/*   Updated: 2016/01/13 12:58:55 by dyuzan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>

#define BUF_SIZE 5555

void	ft_putchar(char c)
{
	write (1, &c, 1);
}

void	ft_putstr(char *str)
{
	while (*str)
	{
		ft_putchar(*str++);
	}
}

char	*ft_stock(char *tetriminos)
{
	int				fd;
	static char		buf[BUF_SIZE];
	int				ret;

	fd = open(tetriminos, O_RDONLY);
	while ((ret = read(fd, buf, BUF_SIZE)))
	{
		buf[ret] = '\0';
	}
	return (buf);
}

int		ft_check(char *check)
{
	while (*check)
	{
		if (*check != '.' &&  *check != '#' && *check != '\n')
		{
		ft_putstr("INVALIDE TETRIMINOS");
		return (0);
		}
		check++;
	}
	return (1);
}

void	ft_check2(char *check)
{
	int octet = 0;
	int dieze = 0;
	int rline = 0;

	if(!ft_check(check))
		return ;
	while (*check)
	{
		if (*check == '#')
			dieze = dieze + 1;
		if (*check == '\n')
			rline = rline + 1;
		if (octet == 21 && dieze != 4 && rline != 5)
			{
				ft_putstr("tetriminos invalide");
				break;
			}
		if (octet == 21 && dieze == 4 && rline == 5)
		{
			octet = 0;
			dieze = 0;
			rline = 0;
		}
		check++;
		octet++;
	}
}

int main(int argc, char **argv)
{
	if (argc == 2)
		ft_check2(ft_stock(argv[1]));
	return (0);
}
