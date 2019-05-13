/*
** EPITECH PROJECT, 2022
** PSU_myftp_2017
** File description:
** Created by mystogunn,
*/

#include "../include/my.h"

int close_struct(arg_t *arg)
{
	if (close(arg->control_fd) == -1)
		return (1);
	return (0);
}

int change_workspace(char **av)
{
	if (chdir(av[2]) == -1)
		return (1);
	return (0);
}

int init_socket(arg_t *arg)
{
	if (bind(arg->control_fd, (const struct sockaddr *)&arg->s_in,
		sizeof(arg->s_in)) == -1) {
		if (close(arg->control_fd) == -1)
			return (1);
		return (1);
	}
	if (listen(arg->control_fd, 42) == -1) {
		if (close(arg->control_fd) == -1)
			return (1);
		return (1);
	}
	return (0);
}

int init_struct(arg_t *arg, char **av)
{
	arg->s_in_size = sizeof(struct sockaddr_in);
	arg->port = atoi(av[1]);
	arg->pe = getprotobyname("TCP");
	arg->s_in.sin_family = AF_INET;
	arg->s_in.sin_port = ntohs(arg->port);
	arg->s_in.sin_addr.s_addr = INADDR_ANY;
	arg->path = strdup(av[2]);
	arg->user = NULL;
	arg->password = NULL;
	arg->mode = 0;
	if (!arg->pe)
		return (1);
	arg->control_fd = socket(AF_INET, SOCK_STREAM, arg->pe->p_proto);
	if (arg->control_fd == -1)
		return (1);
	init_tab();
	set_tab(arg);
	return (0);
}

int init_prog(char **av)
{
	arg_t arg;

	if (change_workspace(av) == 1)
		return (1);
	if (init_struct(&arg, av) == 1)
		return (1);
	if (init_socket(&arg) == 1)
		return (1);
	if (accept_client(&arg) == 1)
		return (1);
	if (close_struct(&arg) == 1)
		return (1);
	return (0);
}