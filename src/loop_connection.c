/*
** EPITECH PROJECT, 2022
** PSU_myftp_2017
** File description:
** Created by mystogunn,
*/

#include "../include/my.h"

char *recup_command(char *str)
{
	int count = 0;
	int i = 0;
	char *str2;

	str2 = malloc(255);
	while (str[count] != ' ')
		count++;
	count = count + 1;
	while (str[count] != '\0' && str[count] != '\r') {
		str2[i] = str[count];
		count++;
		i++;
	}
	str2[i] = 0;
	return (str2);
}

void bad_command(arg_t *arg)
{
	if (arg->user != NULL && arg->password != NULL)
		dprintf(arg->client_fd, "500 Unknown command.\r\n");
	else
		dprintf(arg->client_fd,
			"530 Please login with USER and PASS.\r\n");
}

int choose_function(char *str, arg_t *arg)
{
	int count = 0;

	while (strcasecmp(arg->tab[count], str) != 0) {
		count++;
		if (count > 13)
			return (1);
	}
	flag[count](arg);
	return (0);
}

char *argument(char *string)
{
	char *str;
	int count = 0;

	str = malloc(sizeof(char) * 255);
	while (string[count] != ' ' && string[count] != '\0' &&
		string[count] != '\n' && string[count] != '\r') {
		str[count] = string[count];
		count++;
		if (string[count] == ' ' || string[count] == '\0' ||
			string[count] == '\n')
			break;
	}
	str[count] = '\0';
	return (str);
}

int loop_connection(arg_t *arg)
{
	char *str;

	dprintf(arg->client_fd, "220 Service ready for new user.\r\n");
	while (42) {
		arg->input = get_next_line(arg->client_fd);
		str = argument(arg->input);
		if (strcasecmp(str, "QUIT") == 0)
			break;
		if (choose_function(str, arg) == 1)
			bad_command(arg);
	}
	dprintf(arg->client_fd, "221 Service closing control connection.\r\n");
	close(arg->client_fd);
	close(arg->data_fd);
	close(arg->data_client_fd);
	exit(0);
	return (0);
}