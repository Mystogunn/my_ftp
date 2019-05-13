/*
** EPITECH PROJECT, 2022
** .
** File description:
** Created by mystogunn,
*/

#include "../include/my.h"

int check_authentification(arg_t *arg)
{
	if ((arg->user != NULL && strcasecmp(arg->user, "anonymous") != 0)
		|| arg->password == NULL)
		return (1);
	return (0);
}