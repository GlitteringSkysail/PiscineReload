/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_file.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yopeng <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/27 14:39:10 by yopeng            #+#    #+#             */
/*   Updated: 2025/04/27 19:56:15 by yopeng           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#define BUF_SIZE 4096

void	error(char *str)
{	while(*str)
	{
		write(2, str++, 1);
	}
}

int	read_and_display_file(int fd)
{
	char	buf[BUF_SIZE];
	size_t	bytes_read;

	bytes_read = read(fd, buf, BUF_SIZE);
	while (bytes_read > 0)
	{
		write(1, buf, bytes_read);
		bytes_read = read(fd, buf, BUF_SIZE);
	}
	close (fd);
	return(0);
}

int	main(int argc, char *argv[])
{
	int		fd;
	int ret;

	if (argc < 2)
	{
		error("File name missing.\n");
		return (1);
	}
	if (argc > 2)
	{
		error("Too many arguments.\n");
		return (1);
	}

	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
	{
		error("Cannot read file.\n");
		return (1);
	}
	ret = read_and_display_file(fd);
	close(fd);
	return (0);
}
