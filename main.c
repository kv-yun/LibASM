#include "libasm.h"
#include <errno.h>

void	write_test()
{
	printf("\n=====\nWRITE TEST START\n=====\n");
	printf("write: %zd\n", write(1, "Hello World\n", 12));
	printf("ft_write: %zd\n", ft_write(1, "Hello world\n", 12));
	printf("write: %zd\n", write(2, "STD ERROR\n", 10));
	printf("ft_write: %zd\n", ft_write(2, "STD ERROR\n", 10));
	printf("\n=====\nTEST ERRNO\n=====\n\n");
	errno = 0;
	printf("write return: %zd\n", write(-1, "Hello World\n", 12));
	printf("write errno value: %d\n", errno);
	errno = 0;
	printf("ft_write return: %zd\n", ft_write(-1, "Hello World\n", 12));
	printf("ft_write errno value: %d\n", errno);
	errno = 0;
	printf("write return: %zd\n", write(1, "error\n", 8));
	printf("write errno value: %d\n", errno);
	errno = 0;
	printf("ft_write return: %zd\n", ft_write(1, "error\n", 8));
	printf("ft_write errno value: %d\n", errno);
	errno = 0;
	printf("=====\nWRITE TEST END\n=====\n");
}

void	read_test()
{
	char	buf[11];
	int	fd;

	fd = open("main.c", O_RDONLY);
	printf("\n=====\nREAD TEST START\n=====\n");
	printf("read: %zd\n", read(fd, buf, 10));
	buf[10] = '\0';
	printf("read buffer: [%s]\n", buf);
	close(fd);
	fd = open("main.c", O_RDONLY);
	printf("ft_read: %zd\n", ft_read(fd, buf, 10));
	buf[10] = '\0';
	printf("ft_read buffer: [%s]\n", buf);
	close(fd);
	printf("\n=====\nTEST ERRNO\n=====\n");
	errno = 0;
	printf("read return: %zd\n", read(-1, buf, 10));
	printf("read errno value: %d\n", errno);
	errno = 0;
	printf("ft_read return: %zd\n", ft_read(-1, buf, 10));
	printf("ft_read errno value: %d\n", errno);
	errno = 0;
	printf("=====\nREAD TEST END\n=====\n");
}

void	strlen_test()
{
	printf("\n=====\nSTRLEN TEST START\n=====\n");
	printf("strlen [Hello]: %zd\n", strlen("Hello"));
	printf("ft_strlen [Hello]: %zd\n", ft_strlen("Hello"));
	printf("strlen []: %zd\n", strlen(""));
	printf("ft_strlen []: %zd\n", ft_strlen(""));
	printf("strlen [1]: %zd\n", strlen("1"));
	printf("ft_strlen [1]: %zd\n", ft_strlen("1"));
	printf("=====\nSTRLEN TEST END\n=====\n");
}

void	strcmp_test()
{
	printf("\n=====\nSTRCMP TEST START\n=====\n");
	printf("strcmp [Hello] [Hello]: %d\n", strcmp("Hello", "Hello"));
	printf("ft_strcmp [Hello] [Hello]: %d\n", ft_strcmp("Hello", "Hello"));
	printf("strcmp [Hello] [World]: %d\n", strcmp("Hello", "World"));
	printf("ft_strcmp [Hello] [World]: %d\n", ft_strcmp("Hello", "World"));
	printf("strcmp [qwerty] [qwert]: %d\n", strcmp("qwerty", "qwert"));
	printf("ft_strcmp [qwerty] [qwert]: %d\n", ft_strcmp("qwerty", "qwert"));
	printf("strcmp [qwert] [qwerty]: %d\n", strcmp("qwert", "qwerty"));
	printf("ft_strcmp [qwert] [qwerty]: %d\n", ft_strcmp("qwert", "qwerty"));
	printf("strcmp [] [vide]: %d\n", strcmp("", "vide"));
	printf("ft_strcmp [] [vide]: %d\n", ft_strcmp("", "vide"));
	printf("strcmp [vide] []: %d\n", strcmp("vide", ""));
	printf("ft_strcmp [vide] []: %d\n", ft_strcmp("vide", ""));
	printf("=====\nSTRCMP TEST END\n=====\n");
}

void	strcpy_test()
{
	char	*dest;

	dest = malloc(12 * sizeof(char));
	if (!dest)
	{
		printf ("Error malloc test strcpy\n");
		return;
	}
	printf("\n=====\nSTRCPY TEST START\n=====\n");
	printf("src: Hello World\n");
	strcpy(dest, "Hello World");
	printf("strcpy dest: [%s]\n", dest);
	free(dest);
	dest = malloc(12 * sizeof(char));
	if (!dest)
	{
		printf("Error malloc test strcpy\n");
		return;
	}
	ft_strcpy(dest, "Hello World");
	printf("ft_strcpy dest: [%s]\n", dest);
	free(dest);
	printf("size src < size dest\n");
	dest = malloc (10 * sizeof(char));
	if (!dest)
	{
		printf("Error malloc test strcpy\n");
		return;
	}
	strcpy(dest, "Hello");
	printf("strcpy dest: [%s]\n", dest);
	free(dest);
	dest = malloc(10 * sizeof(char));
	if (!dest)
	{
		printf("Error malloc test strcpy\n");
		return;
	}
	ft_strcpy(dest, "Hello");
	printf("ft_strcpy dest: [%s]\n", dest);
	free(dest);
	dest = malloc(1 * sizeof(char));
	if (!dest)
	{
		printf("Error malloc test strcpy\n");
		return;
	}
	printf("src: []\n");
	strcpy(dest, "");
	printf("strcpy dest: %s\n", dest);
	free(dest);
	dest = malloc(1 * sizeof(char));
	if (!dest)
	{
		printf("Error malloc test strcpy\n");
		return;
	}
	ft_strcpy(dest, "");
	printf("ft_strcpy dest: %s\n", dest);
	printf("=====\nSTRCPY TEST END\n=====\n");
}

void	strdup_test()
{
	char	*res;

	printf("\n=====\nSTRDUP TEST START\n=====\n");
	printf("str = Hello World\n");
	res = strdup("Hello World");
	printf("strdup res: [%s]\n", res);
	free(res);
	res = ft_strdup("Hello World");
	printf("ft_strdup res: [%s]\n", res);
	free(res);
	printf("str = 1\n");
	res = strdup("1");
	printf("strdup res: [%s]\n", res);
	free(res);
	res = ft_strdup("1");
	printf("ft_strdup res: [%s]\n", res);
	free(res);
	printf("str = []\n");
	res = strdup("");
	printf("strdup res: [%s]\n", res);
	free(res);
	res = ft_strdup("");
	printf("ft_strdup res: [%s]\n", res);
	free(res);
	printf("=====\nSTRDUP TEST END\n=====\n");
}

int main()
{
	write_test();
	read_test();
	strlen_test();
	strcmp_test();
	strcpy_test();
	strdup_test();
	return (0);
}
