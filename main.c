#include "libasm.h"
#include <stdio.h>
#include <string.h>
#include <sys/errno.h>
#include <fcntl.h>

int main(void)
{
	printf("%zu\n", ft_strlen("hello"));
	printf("%zu\n\n", strlen("hello"));


	char dst1[] ="hello";
	char *src1 = "hello  ";
	printf("|%s|\n", ft_strcpy(dst1, src1));


	char *s1 = "hello";
	char *s2 = "hello";
	printf("\n|%d|\n", ft_strcmp(s1, s2));
	printf("|%d|\n", strcmp(s1, s2));

	char *s3 = "hello!!";
	char *s4 = "hello";
	printf("\n|%d|\n", ft_strcmp(s3, s4));
	printf("|%d|\n", strcmp(s3, s4));

	char *s5 = "";
	char *s6 = "";
	printf("\n|%d|\n", ft_strcmp(s5, s6));
	printf("|%d|\n", strcmp(s5, s6));


	printf("\n[ret:%zd]\n", ft_write(1, "\nhello !!!\n", ft_strlen("hello !!!\n")));
	printf("[err:%d]\n", errno);
	printf("\n[ret:%zd]\n", write(1, "\nhello !!!\n", ft_strlen("hello !!!\n")));
	printf("[err:%d]\n", errno);

	char buf1[10];
	int fd = open("text.txt", O_RDONLY);
	printf("\n[ret:%zd]\n", ft_read(fd, buf1, 9));
	printf("[err:%d]\n", errno);
	printf("%s\n", buf1);

	char buf2[10];
	fd = open("text.txt", O_RDONLY);
	printf("\n[ret:%zd]\n", read(fd, buf2, 9));
	printf("[err:%d]\n", errno);
	printf("%s\n", buf2);


	char *str1;
	str1 = ft_strdup("Strdup string");
	printf("\n%s\n", str1);

	char *str2;
	str2 = ft_strdup("Strdup string");
	printf("%s\n\n", str2);
	return (0);
}
