/*
** EPITECH PROJECT, 2022
** .
** File description:
** Created by mystogunn,
*/

#include "../include/my.h"

int noop_command(arg_t *arg)
{
	if (check_authentification(arg) == 1)
		dprintf(arg->client_fd,
			"530 Please login with USER and PASS.\r\n");
	else
		dprintf(arg->client_fd, "200 Command okay.\r\n");
	return (0);
}

int retr_command(arg_t *arg)
{
	if (check_authentification(arg) == 1)
		dprintf(arg->client_fd,
			"530 Please login with USER and PASS.\r\n");
	else if (arg->mode == 0)
		dprintf(arg->client_fd, "425 Use PORT or PASV first.\r\n");
	else
		if (retr(arg) == 1)
			dprintf(arg->client_fd, "550 Permission denied.\r\n");
	return (0);
}

int stor_command(arg_t *arg)
{
	if (check_authentification(arg) == 1)
		dprintf(arg->client_fd,
			"530 Please login with USER and PASS.\r\n");
	else if (arg->mode == 0)
		dprintf(arg->client_fd, "425 Use PORT or PASV first.\r\n");
	else
		return (0);
	return (0);
}

int list_command(arg_t *arg)
{
	if (check_authentification(arg) == 1)
		dprintf(arg->client_fd,
			"530 Please login with USER and PASS.\r\n");
	else if (arg->mode == 0)
		dprintf(arg->client_fd, "425 Use PORT or PASV first.\r\n");
	else
		list(arg);
	return (0);
}