/*
** EPITECH PROJECT, 2022
** .
** File description:
** Created by mystogunn,
*/

#include "../include/my.h"

char *recup_ip(char *str)
{
	char *ip = malloc(sizeof(char) * 255);
	int count = 0;
	int comma = 0;

	while (comma != 4) {
		if (str[count] == ',') {
			comma++;
			ip[count] = '.';
		}
		else
			ip[count] = str[count];
		count++;
	}
	ip[count - 1] = 0;
	return (ip);
}

char *recup_port(char *str, int i)
{
	char *port = malloc(sizeof(char) * 255);
	int count = 0;
	int y = 0;

	for (int z = 0; z != i; z = z) {
		if (str[count] == ',')
			z++;
		count++;
	}
	while (str[count] != ',' && str[count] != '\r' && str[count] != '\0') {
		port[y] = str[count];
		y++;
		count++;
	}
	port[y] = 0;
	return (port);
}