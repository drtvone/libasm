#include "libasm.h"

int main(void)
{
	char *s = "abcdefl";
	char *s1 = "abcdefg";
	char *s2 = "abcdef";
	char *ss = NULL;
	int fd;
	char *buf = (char *)malloc(1000);
	char *s3 = "abcdefabcdefabcdefabcdefabcdefabcdefabcdefabcdefabcdefabcdef \
	abcdefabcdefabcdefabcdefabcdefabcdefabcdefabcdefabcdefabcdefabcdefabcdefabcdef\
	abcdefabcdefabcdefabcdefabcdefabcdefabcdefabcdefabcdefabcdefabcdefabcdefabcdef\
	abcdefabcdefabcdefabcdefabcdefabcdefabcdefabcdefabcdefabcdefabcdefabcdefabcdef";
	printf("======================CHECK FT_STRCMP======================\n");
	printf("\nstr1 =%s\nstr2 =%s\n", s, s1);
	printf("--------\nft_strcmp=%d\n", ft_strcmp(s, s1));
	printf("strcmp=%d\n--------\n", (int)strcmp(s, s1));
	printf("\nstr1 =%s\nstr2 =%s\n", s, s);
	printf("--------\nft_strcmp=%d\n", ft_strcmp(s, s));
	printf("strcmp=%d\n--------\n", (int)strcmp(s, s));
	printf("\nstr1 =%s\nstr2 =%s\n", s1, s2);
	printf("--------\nft_strcmp=%d\n", ft_strcmp(s1, s2));
	printf("strcmp=%d\n--------\n", (int)strcmp(s1, s2));
	printf("\nstr1 =%s\nstr2 =%s\n", s2, s1);
	printf("--------\nft_strcmp=%d\n", ft_strcmp(s2, s1));
	printf("strcmp=%d\n--------\n", (int)strcmp(s2, s1));
	printf("\n\n");
	printf("======================CHECK FT_STRLEN======================\n");
	printf("\nstr1 =%s\n", s);
	printf("------\nft_strlen=%d\n", ft_strlen(s));
	printf("strlen=%d\n------\n", (int)strlen(s));
	printf("\nstr1 =%s\n", s3);
	printf("------\nft_strlen=%d\n", ft_strlen(s3));
	printf("strlen=%d\n------\n", (int)strlen(s3));
	printf("\nstr1 =%s\n", ss);
	printf("------\nft_strlen=%d\n", ft_strlen(ss));
	printf("strlen = segv\n------\n");
	printf("\n\n");
	printf("======================CHECK FT_STRDUP======================\n");
	printf("\nstr1 =%s\n", s);
	printf("\nft_strdup =%s\n", ft_strdup(s));
	printf("\nstrdup =%s\n----------\n", strdup(s));
	printf("\nstr1 =%s\n", ss);
	printf("\nft_strdup =%s\n", ft_strdup(ss));
	printf("\nstrdup =segv\n");
	printf("======================CHECK FT_WRITE======================\n");
	fd = open("test_write.txt", O_RDWR);
	ft_write(fd, s3, 90);
	printf("\nft_write_out:\n");
	ft_write(1, s1, 20);
	printf("\nwrite_out:\n");
	write(1, s1, 20);
	printf("\n");
	write(fd, NULL, 1);
	printf("write error buff = NULL: %s\n", strerror(errno));
	write(-1, buf, 123);
	printf("write error fd = -1: %s\n", strerror(errno));
	write(fd, buf, -1);
	printf("write error size = -1: %s\n", strerror(errno));
	printf("\n\n");
	ft_write(fd, NULL, 1);
	printf("ft_write error buff = NULL: %s\n", strerror(errno));
	ft_write(-1, buf, 123);
	printf("ft_write error fd = -1: %s\n", strerror(errno));
	ft_write(fd, buf, -1);
	printf("ft_write error size = -1: %s\n", strerror(errno));
	close(fd);
	printf("\n\n");
	printf("======================CHECK FT_STRCPY======================\n");
	printf("\nstr1 =%s\nstr2 =%s\n", buf, s2);
	printf("--------\nft_strcpy=%s\n", ft_strcpy(buf, s1));
	printf("strcpy=%s\n--------\n", strcpy(buf, s1));
	printf("\nstr1 =%s\nstr2 =%s\n", buf, s2);
	printf("--------\nft_strcpy=%s\n", ft_strcpy(buf, s3));
	printf("strcpy=%s\n--------\n", strcpy(buf, s3));
	printf("\n\n");
	printf("======================CHECK FT_READ======================\n");
	int fd2;
	fd2 = open("test_read.txt", O_RDONLY);
	char *buf0 = (char *)malloc(124);
	char *buf1 = (char *)malloc(160);
	read(fd2, buf0, 123);
	printf("read from file:\n%s\n", buf0);
	printf("\n\n\n");
	close(fd2);
	fd2 = open("test_read.txt", O_RDONLY);
	ft_read(fd2, buf1, 123);
	printf("ft_read from file:\n%s\n", buf1);
	printf("\n\n");
	read(fd2, NULL, 1);
	printf("read error buff = NULL: %s\n", strerror(errno));
	read(-1, buf0, 123);
	printf("read error fd = -1: %s\n", strerror(errno));
	read(fd2, buf0, -1);
	printf("read error size = -1: %s\n", strerror(errno));
	printf("\n\n");
	ft_read(fd2, NULL, 1);
	printf("ft_read error buff = NULL: %s\n", strerror(errno));
	ft_read(-1, buf1, 129);
	printf("ft_read error fd = -1: %s\n", strerror(errno));
	ft_read(fd2, buf1, -1);
	printf("ft_read error size = -1: %s\n", strerror(errno));
	close(fd2);
	free(buf);
	free(buf0);
	free(buf1);
	return(0);
}