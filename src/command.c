/*
** EPITECH PROJECT, 2022
** PSU_myftp_2017
** File description:
** Created by mystogunn,
*/

#include "../include/my.h"

int user_command(arg_t *arg)
{
	if (arg->user != NULL && strcasecmp(arg->user, "anonymous") == 0)
		dprintf(arg->client_fd, "230 User logged in, proceed.\r\n");
	else {
		free(arg->user);
		arg->user = recup_command(arg->input);
		dprintf(arg->client_fd,
			"331 User name okay, need password.\r\n");
	}
	return (0);
}

int pass_command(arg_t *arg)
{
	if (strcasecmp(arg->user, "anonymous") != 0)
		dprintf(arg->client_fd, "530 Login incorrect.\r\n");
	else if (arg->password != NULL)
		dprintf(arg->client_fd, "332 Need account for login.\r\n");
	else {
		arg->password = strdup("toto");
		dprintf(arg->client_fd,"230 User logged in, proceed.\r\n");
	}
	return (0);
}

int cwd_command(arg_t *arg)
{
	if (check_authentification(arg) == 1)
		dprintf(arg->client_fd,
			"530 Please login with USER and PASS.\r\n");
	else {
		arg->path = recup_command(arg->input);
		chdir(arg->path);
		arg->path = getcwd(arg->path, 4096);
		dprintf(arg->client_fd,
			"250 Requested file action okay, completed.\r\n");
	}
	return (0);
}

int cdup_command(arg_t *arg)
{
	if (check_authentification(arg) == 1)
		dprintf(arg->client_fd,
			"530 Please login with USER and PASS.\r\n");
	else {
		chdir("../");
		arg->path = getcwd(arg->path, 4096);
		dprintf(arg->client_fd, "200 command okay.\r\n");
	}
	return (0);
}

int quit_command(arg_t *arg)
{
	(void)arg;
	return (0);
}