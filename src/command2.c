/*
** EPITECH PROJECT, 2022
** .
** File description:
** Created by mystogunn,
*/

#include "../include/my.h"

int dele_command(arg_t *arg)
{
	if (check_authentification(arg) == 1)
		dprintf(arg->client_fd,
			"530 Please login with USER and PASS.\r\n");
	else {
		if (remove(recup_command(arg->input)) == -1)
			dprintf(arg->client_fd,
				"552 Requested file action aborted.\r\n");
		else
			dprintf(arg->client_fd, "250 "
				"Requested file action okay, completed.\r\n");
	}
	return (0);
}

int pwd_command(arg_t *arg)
{
	if (check_authentification(arg) == 1) {
		dprintf(arg->client_fd,
			"530 Please login with USER and PASS.\r\n");
	}
	else
		dprintf(arg->client_fd, "257 \"%s\" created.\r\n", arg->path);
	return (0);
}

int pasv_command(arg_t *arg)
{
	if (check_authentification(arg) == 1)
		dprintf(arg->client_fd,
			"530 Please login with USER and PASS.\r\n");
	else {
		arg->mode = 1;
		arg->data_fd = socket(AF_INET, SOCK_STREAM, arg->pe->p_proto);
		if (arg->data_fd == -1)
			return (1);
		init_data(arg);
	}
	return (0);
}

int port_command(arg_t *arg)
{
	if (check_authentification(arg) == 1)
		dprintf(arg->client_fd,
			"530 Please login with USER and PASS.\r\n");
	else {
		if (decode_message(arg) == 1)
			dprintf(arg->client_fd, "500 "
				"Illegal PORT command.\r\n");
		else {
			arg->mode = 2;
			dprintf(arg->client_fd, "200 Command okay.\r\n");
		}
	}
	return (0);
}

int help_command(arg_t *arg)
{
	if (check_authentification(arg) == 1)
		dprintf(arg->client_fd,
			"530 Please login with USER and PASS.\r\n");
	else
		dprintf(arg->client_fd, "214 Good luck.\r\n");
	return (0);
}