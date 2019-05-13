/*
** EPITECH PROJECT, 2022
** PSU_myftp_2017
** File description:
** Created by mystogunn,
*/

#include "../include/my.h"

void init_port(arg_t *arg, char *ip, char *port)
{
	arg->data_client_fd = socket(AF_INET, SOCK_STREAM, arg->pe->p_proto);
	arg->s_in_data.sin_family = AF_INET;
	arg->s_in_data.sin_port = htons(atoi(port));
	arg->s_in_data.sin_addr.s_addr = inet_addr(ip);
	connect(arg->data_client_fd, (struct sockaddr *)&arg->s_in_data,
		sizeof(arg->s_in_data));
}

int check_message_port(char *str)
{
	int i = 0;

	for (int count = 0; str[count]; count++) {
		if (str[count] == ',')
			i++;
	}
	if (i != 5)
		return (1);
	return (0);
}

int decode_message(arg_t *arg)
{
	char *tmp;
	char *tmp2;
	char *ip;
	char port[32];


	if (check_message_port(recup_command(arg->input)) == 1)
		return (1);
	tmp = recup_port(recup_command(arg->input), 4);
	tmp2 = recup_port(recup_command(arg->input), 5);
	ip = recup_ip(recup_command(arg->input));
	sprintf(port, "%d", atoi(tmp) * 256 + atoi(tmp2));
	init_port(arg, ip, port);
	return (0);
}

void init_data(arg_t *arg)
{
	arg->data_fd = socket(AF_INET, SOCK_STREAM, arg->pe->p_proto);
	arg->s_in_data.sin_family = AF_INET;
	arg->s_in_data.sin_port = 0;
	arg->s_in_data.sin_addr.s_addr = INADDR_ANY;
	bind(arg->data_fd, (const struct sockaddr *)&arg->s_in_data,
		sizeof(arg->s_in_data));
	listen(arg->data_fd, 1);
	arg->len = sizeof(arg->s_in_data);
	getsockname(arg->data_fd, (struct sockaddr *)&arg->s_in_data,
		&arg->len);
	arg->port_data = ntohs(arg->s_in_data.sin_port);
	dprintf(arg->client_fd, "227 Entering Passive Mode (127,0,0,1,%d,%d)"
		".\r\n", arg->port_data / 256, arg->port_data % 256);
	arg->data_client_fd = accept(arg->data_fd,
		(struct sockaddr *)&arg->s_in_data_client, &arg->s_in_size);
}

int accept_client(arg_t *arg)
{
	while (42) {
		arg->client_fd = accept(arg->control_fd,
			(struct sockaddr *)&arg->s_in_client,
			&arg->s_in_size);
		if (arg->client_fd == -1) {
			if (close(arg->control_fd) == -1)
				return (1);
			return (1);
		}
		if (fork() == 0)
			if (loop_connection(arg) == 1)
				return (1);
		close(arg->client_fd);
	}
	return (0);
}