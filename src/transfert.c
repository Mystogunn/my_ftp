/*
** EPITECH PROJECT, 2022
** .
** File description:
** Created by mystogunn,
*/

#include "../include/my.h"

void list(arg_t *arg)
{
	pid_t pid;

	dprintf(arg->client_fd, "150 Here comes the directory listing.\r\n");
	if ((pid = fork()) == 0)
		execl("/bin/ls", "ls", "-l", NULL);
	else
		waitpid(pid, 0, WSTOPPED);
	close(arg->data_client_fd);
	dprintf(arg->client_fd, "226 Closing data connection.\r\n");
	arg->mode = 0;
}

int retr(arg_t *arg)
{
	int fd;
	char c[1];
	char *str = malloc(sizeof(char) * 4096);
	int i = 0;

	fd = open(recup_command(arg->input), O_RDWR);
	if (fd == 0)
		return (1);
	while (read(fd, c, 1) != 0) {
		str[i] = c[0];
		i++;
	}
	str[i] = 0;
	dprintf(arg->client_fd,
		"150 File status okay; about to open data connection.\r\n");
	dprintf(arg->data_client_fd, "%s", str);
	close(arg->data_client_fd);
	dprintf(arg->client_fd, "226 Closing data connection.\r\n");
	arg->mode = 0;
	return (0);
}