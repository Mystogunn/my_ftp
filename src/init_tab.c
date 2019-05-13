/*
** EPITECH PROJECT, 2022
** PSU_myftp_2017
** File description:
** Created by mystogunn,
*/

#include "../include/my.h"

void init_tab(void)
{
	flag[0] = user_command;
	flag[1] = pass_command;
	flag[2] = cwd_command;
	flag[3] = cdup_command;
	flag[4] = quit_command;
	flag[5] = dele_command;
	flag[6] = pwd_command;
	flag[7] = pasv_command;
	flag[8] = port_command;
	flag[9] = help_command;
	flag[10] = noop_command;
	flag[11] = retr_command;
	flag[12] = stor_command;
	flag[13] = list_command;
}

void set_tab(arg_t *arg)
{
	arg->tab = malloc(sizeof(char *) * 15);
	arg->tab[0] = strdup("USER");
	arg->tab[1] = strdup("PASS");
	arg->tab[2] = strdup("CWD");
	arg->tab[3] = strdup("CDUP");
	arg->tab[4] = strdup("QUIT");
	arg->tab[5] = strdup("DELE");
	arg->tab[6] = strdup("PWD");
	arg->tab[7] = strdup("PASV");
	arg->tab[8] = strdup("PORT");
	arg->tab[9] = strdup("HELP");
	arg->tab[10] = strdup("NOOP");
	arg->tab[11] = strdup("RETR");
	arg->tab[12] = strdup("STOR");
	arg->tab[13] = strdup("LIST");
	arg->tab[14] = NULL;
}