/*
** EPITECH PROJECT, 2022
** PSU_myftp_2017
** File description:
** Created by mystogunn,
*/

#include "../include/my.h"

void print_help(void)
{
	printf("USAGE: "
		"./server port path\n\t"
	"port is the port number on which the server socket listens\n\t"
	"path is the path to the home directory for the Anonymous user\n");
}

int main(int ac, char **av)
{
	if (ac != 3) {
		print_help();
		return (84);
	}
	if (init_prog(av) == 1)
		return (84);
	return (0);
}