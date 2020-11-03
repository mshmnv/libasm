/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main-2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbagg <lbagg@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/27 23:10:32 by sfrederi          #+#    #+#             */
/*   Updated: 2020/11/03 03:11:10 by lbagg            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libasm.h"
#include <stdio.h>
#include <string.h>
#include <sys/errno.h>
#include <fcntl.h>

int main(void)
{	
	printf("         TEST LIBASM            \n\n");
	printf("________________________________\n");
	printf("          FT_STRLEN\n\n");
	char *s;
	s = "123121231234123412341234123123412341234123412312341234123412341231234123412341234123123412341234123412312341234123412341231234123412341234123123412341234123412312341234123412341231234123412341234123123412341234123412312341234123412341231234123412341234123123412341234123412312341234123412341231234123412341234123123412341234123412312341234123412341231234123412341234123123412341234121231212312341234123412341231234123412341234123123412341234123412312341234123412341231234123412341234123123412341234123412312341234123412341231234123412341234123123412341234123412312341234123412341231234123412341234123123412341234123412312341234123412341231234123412341234123123412341234123412312341234123412341231234123412341234123123412341234123412312341234123412341231234123412341234123123412341234123412312341234123412343412341234123412312123123412341234123412312341234123412341231234123412341234123123412341234123412312341234123412341231234123412341234123123412341234123412312341234123412341231234123412341234123123412341234123412312341234123412341231234123412341234123123412341234123412312341234123412341223412341234123121231234123412341234123123412341234123412312341234123412341231234123412341234123123412341234123412312341234123412341231234123412341234123123412341234123412312341234123412341231234123412341234123123412341234123412312341234123412341231234123412341234123123412341234123412312341234123412341231234123412341234123123412341234123412312341234123412341231234123412341234123123412341234123412312341234123412341231234123412341234341234123412341231212312341234123412341231234123412341234123123412341234123412312341234123412341231234123412341234123123412341234123412312341234123412341231234123412341234123123412341234123412312341234123412341231234123412341234123123412341234123412312341234123412341231234123412341234123123412341234123412312341234123412341234123412341234";
	printf("|-very long my_strlen:     |%zu|\n", ft_strlen(s));
	printf("|-very long system strlen: |%lu|\n", strlen(s));
	printf("|-empty line my_strlen:     |%zu|\n", ft_strlen(""));
	printf("|-empty line system strlen: |%lu|\n\n", strlen(""));
	
	printf("\n____________________________________________\n");
	
	printf("          FT_STRCPY\n\n");
	char *d1 = malloc(20);
	char *s1 = malloc(20);
	memset(s1, 's', 20);
	memset(d1, 'd', 20);
	d1[19] = '\0';
	s1[19] = '\0';
	printf("|very long my  |%s|\n", ft_strcpy(d1, s1));
	char *d2 = malloc(20);
	char *s2 = malloc(20);
	memset(s2, 's', 20);
	memset(d2, 'd', 20);
	d2[19] = '\0';
	s2[19] = '\0';
	printf("|very long sys |%s|\n", strcpy(d2, s2));
	memset(s1, 's', 1);
	s1[0] = '\0';
	printf("|empty my_strcpy     |%s|\n", ft_strcpy(d1, s1));
	printf("|empty system stlcpy |%s|\n", strcpy(d1, s1));
	
	printf("\n_____________________________________________\n");
	
	printf("          FT_STRCMP\n\n");
	
	char q[] = "\0";
	char w[] = "\0";
	printf("	2 empty str\n\n");
	printf("|ft_strcmp |%i|\n", ft_strcmp(q,w));
	printf("|strcmp    |%i|\n\n",strcmp(q,w));
	char e[] = "\0";
	char r[] = "1";
	printf("	1 empty str first arg\n\n");
	printf("|ft_strcmp |%i|\n", ft_strcmp(e,r));
	printf("|strcmp    |%i|\n\n",strcmp(e,r));
	char t[] = "1";
	char y[] = "";
	printf("	1 empty str second arg\n\n");
	printf("|ft_strcmp |%i|\n", ft_strcmp(t,y));
	printf("|strcmp    |%i|\n\n",strcmp(t,y));
	char u[] = "11119";
	char p[] = "11110";
	printf("	1 empty str first arg\n\n");
	printf("|ft_strcmp |%i|\n", ft_strcmp(u,p));
	printf("|strcmp    |%i|\n\n",strcmp(u,p));
	
	printf("\n_________________________________________________\n");
	
	printf("          FT_WRITE\n\n");
	errno = 0;
	char *qw = "12341234";
	printf("	With stdout\n\n");
	printf(" |system write |%zi|\n", write(1, qw, strlen(qw)));
	printf(" |errno =      |%i|\n\n", errno);
	printf(" |my ft_write  |%zi|\n", ft_write(1, qw, strlen(qw)));
	printf(" |errno =      |%i|\n\n", errno);
	
	int fd;
	errno = 0;
	fd = open("text.txt", O_WRONLY | O_CREAT | O_TRUNC,
    S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);
	printf(" Open file des\n");
	printf(" |system write |%zi|\n", write(fd, qw, strlen(qw)));
	printf(" |errno =      |%i|\n\n", errno);
	printf(" |my ft_write  |%zi|\n", ft_write(fd, qw, strlen(qw)));
	printf(" |errno =      |%i|\n\n", errno);
	errno = 0;
	fd = 600;
	printf(" 	Wrong file des\n\n");
	printf(" |system write |%zi|\n", write(fd, qw, strlen(qw)));
	printf(" |errno =      |%i|\n\n", errno);
	printf(" |my ft_write  |%zi|\n", ft_write(fd, qw, strlen(qw)));
	printf(" |errno =      |%i|\n\n", errno);
	
	printf("\n_________________________________________________\n");
	printf("          FT_READ\n\n");
	errno = 0;
	char buf[5000];
	int i;
	printf("	With stdout\n\n");
	printf("|system read |%i| buf = |%s|\n", i = read(0, buf, 50), buf);
	printf(" |errno =      |%i|\n\n", errno);
	printf("|my ft_read  |%i| buf = |%s|\n", i = ft_read(0, buf, 50), buf);
	printf(" |errno =      |%i|\n\n", errno);
	errno = 0;
	fd = open("test.txt", O_RDONLY);
	printf(" Open file des\n");
	printf("|system read |%i| buf = |%s|\n", i = read(fd, buf, 50), buf);
	printf(" |errno =      |%i|\n\n", errno);
	fd = open("test_2.txt", O_RDONLY);
	printf("|my ft_read  |%i| buf = |%s|\n", i = ft_read(fd, buf, 50), buf);
	printf(" |errno =      |%i|\n\n", errno);
	errno = 0;
	fd = 600;
	printf(" 	Wrong file des\n\n");
	printf("|system read |%i| buf = |%s|\n", i = read(fd, buf, 50), buf);
	printf(" |errno =      |%i|\n\n", errno);
	printf("|my ft_read  |%i| buf = |%s|\n", i = ft_read(fd, buf, 50), buf);
	printf(" |errno =      |%i|\n\n", errno);
	errno = 0;
	
	printf("\n__________________________________________________\n");
	printf("          FT_STRDUP\n\n");
	char *src_d;
	src_d = "";
	printf("   With an empty string\n\n");
	printf("|system strdup |%s|\n",strdup(src_d));
	printf("|my ft_strdup  |%s|\n\n",ft_strdup(src_d));
	src_d = "123456789sdtfyguyhiu786543aextrcytuyguerwpo86dtfcefbq;owuenfceitwvcr57qfwtgyrlchqwiuh gfjgh jdgf jgf jsjsfg jsgj ";
	printf("   With an very long string\n\n");
	printf("|system strdup |%s|\n",strdup(src_d));
	printf("|my ft_strdup  |%s|\n\n",ft_strdup(src_d));

	printf("\n!!!!!!!!!!!!!!!!!!!!DONE!!!!!!!!!!!!!!!!!!!!!!!\n");

}