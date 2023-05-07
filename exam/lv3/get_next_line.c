#include "gnl.h"

size_t	ft_strlen(const char *s)
{
	size_t	i = 0;

	if (!s)
		return (0);
	while (s[i])
		i++;
	return (i);
}

char	*ft_strchr(const char *str, int c)
{
	if (!str)
		return (NULL);
	while (*str)
	{
		if (*str == (char)c)
			return ((char *)str);
		str++;
	}
	return (NULL);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*new;
	size_t	i,j;
	size_t	a = ft_strlen(s1);
	size_t	b = ft_strlen(s2);

	new = malloc(a + b + 1);
	i = 0;
	j = 0;
	while (i < a)
		new[i++] = s1[j++];
	j = 0;
	while (j < b)
		new[i++] = s2[j++];
	new[i] = '\0';
	free (s1);
	return (new);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i = 0;

	if (dstsize == 0)
		return (ft_strlen(src));
	while (src[i] && i < dstsize - 1)
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (ft_strlen(src));
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*str;
	size_t	new_len;

	if (!s)
		return (NULL);
	if (ft_strlen(s) < (size_t)start)
		len = 0;
	new_len = ft_strlen(s + start);
	if (new_len < len)
		len = new_len;
	str = malloc(len + 1);
	ft_strlcpy(str, s + start, len + 1);
	return (str);
}

static char	*ft_getline(int fd, char *save)
{
	char	*buff;
	ssize_t	read_fd;

	buff = malloc(BUFFER_SIZE + 1);
	read_fd = 1;
	while (!ft_strchr(save, '\n') && read_fd != 0)
	{
		read_fd = read(fd, buff, BUFFER_SIZE);
		if (read_fd == -1)
		{
			free(buff);
			return (NULL);
		}
		buff[read_fd] = '\0';
		save = ft_strjoin(save, buff);
	}
	free(buff);
	return (save);
}

static char	*ft_line(char *save)
{
	size_t	i = 0;

	if (!save[0])
		return (NULL);
	while (save[i] != '\n' && save[i])
		i++;
	return (ft_substr(save, 0, i + 1));
}

static char	*ft_save(char *save)
{
	size_t	i = 0;
	char	*str;

	if (!save)
		return (NULL);
	while (save[i])
	{
		if (save[i] == '\n')
		{
			str = ft_substr(save, i + 1, ft_strlen(save));
			free(save);
			return (str);
		}
		i++;
	}
	free (save);
	return (NULL);
}

char	*get_next_line(int fd)
{
	static char	*save;
	char		*line;

	if (fd < 0 || BUFFER_SIZE < 1 || INT_MAX <= BUFFER_SIZE)
		return (NULL);
	save = ft_getline(fd, save);
	if (!save)
		return (NULL);
	line = ft_line(save);
	save = ft_save(save);
	return (line);
}

int	main(void)
{
	int		fd;
	char	*buf;

	fd = open("get_next_line.c", O_RDONLY);
	while (1)
	{
		buf = get_next_line(fd);
		printf("%s", buf);
		free(buf);
		if (!buf)
			break ;
	}
	close(fd);
	return (0);
}