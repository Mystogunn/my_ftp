/*
** EPITECH PROJECT, 2022
** PSU_myftp_2017
** File description:
** Created by mystogunn,
*/

#ifndef		MY_H_
# define	MY_H_

# define	READ_SIZE (1)
# define	SIZE_MALLOC (4096)

typedef struct	s_vars
{
	int	idx;
	int	idx_line;
	int	k;
	int	value_read;
	char	buf[READ_SIZE + 1];
	char	*line;
}		t_vars;

char	*get_next_line(const int fd);

#endif /* !MY_H_ */
