#ifndef LIBASM_H
# define LIBASM_H

# include <unistd.h>
# include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <stdlib.h>
#include <errno.h>

int		ft_strlen(const char *s);
int		ft_strcmp(const char *s, const char *s1);
ssize_t	ft_write(int fd, void const *buf, size_t n);
char	*ft_strdup(const char *s1);
char	*ft_strcpy(char *dest, const char *src);
ssize_t	ft_read(int fd, void *buf, size_t n);

#endif