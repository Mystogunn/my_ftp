/*
** EPITECH PROJECT, 2022
** PSU_myftp_2017
** File description:
** Created by mystogunn,
*/

#ifndef PSU_MYFTP_2017_MY_H
#define PSU_MYFTP_2017_MY_H

#include <sys/types.h>
#include <sys/socket.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <netdb.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <string.h>
#include <stdio.h>
#include "get_next_line.h"

typedef struct arg {
	struct protoent *pe;
	int control_fd;
	int data_fd;
	int data_client_fd;
	int client_fd;
	struct sockaddr_in s_in;
	struct sockaddr_in s_in_data;
	struct sockaddr_in s_in_client;
	struct sockaddr_in s_in_data_client;
	socklen_t s_in_size;
	socklen_t len;
	int port_data;
	int port;
	char *path;
	char **tab;
	char *input;
	char *user;
	char *password;
	int mode;
} arg_t;

int (*flag[14])(arg_t *);

int init_prog(char **av);
int accept_client(arg_t *arg);
int loop_connection(arg_t *arg);
void init_tab(void);
void set_tab(arg_t *arg);
int user_command(arg_t *arg);
int pass_command(arg_t *arg);
int cwd_command(arg_t *arg);
int cdup_command(arg_t *arg);
int quit_command(arg_t *arg);
int dele_command(arg_t *arg);
int pwd_command(arg_t *arg);
int pasv_command(arg_t *arg);
int port_command(arg_t *arg);
int help_command(arg_t *arg);
int noop_command(arg_t *arg);
int retr_command(arg_t *arg);
int stor_command(arg_t *arg);
int list_command(arg_t *arg);
char *recup_command(char *str);
int check_authentification(arg_t *arg);
void init_data(arg_t *arg);
int decode_message(arg_t *arg);
char *recup_port(char *str, int i);
char *recup_ip(char *str);
int retr(arg_t *arg);
void list(arg_t *arg);

#endif //PSU_MYFTP_2017_MY_H
