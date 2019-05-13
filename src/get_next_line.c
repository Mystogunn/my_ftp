/*
** EPITECH PROJECT, 2022
** PSU_myftp_2017
** File description:
** Created by mystogunn,
*/

#include <unistd.h>
#include <stdlib.h>
#include "get_next_line.h"

char		*get_next_line(const int fd)
{
	static	t_vars var;

	if (fd < 0)
		return (NULL);
	if ((var.idx == 0 && (var.value_read = read(fd, var.buf, READ_SIZE))
		< 1) || (var.idx_line == 0 && (var.line = malloc(SIZE_MALLOC))
		== NULL))
		return (NULL);
	while (var.idx != var.value_read) {
		if (var.buf[var.idx] == '\n' || var.buf[var.idx] == '\0') {
			var.idx = var.idx + 1;
			var.line[var.idx_line] = '\0';
			var.idx_line = 0;
			return (var.line);
		}
		var.line[var.idx_line] = var.buf[var.idx];
		var.idx_line = var.idx_line + 1;
		var.idx = var.idx + 1;
	}
	var.idx = 0;
	return (get_next_line(fd));
}
