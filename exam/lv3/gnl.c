#include "gnl.h"


char	*ft_strchr(char *s, int c)
{
	size_t	i = 0;

	if (!s)
		return (NULL);
	while (s[i])
	{
		if (s[i] == (char)c)
			return (&s[i]);
		i++;
	}
	return (NULL);
}

size_t	ft_strlen(char *s)
{
	size_t	len = 0;
	if (!s)
		return (0);
	while (s[len])
		len++;
	return (len);
}

char	*ft_strjoin(char *save, char *buf)
{
	char	*tmp;
	size_t	len = ft_strlen(save) + ft_strlen(buf);
	size_t	i = 0, j = 0;

	tmp = (char *)malloc(len + 1);
	if (!tmp)
		return (NULL);
	while(save[j])
		tmp[i++] = save[j++];
	j = 0;
	while (buf[j])
		tmp[i++] = buf[j++];
	tmp[i] = '\0';
	free(save);
	return (tmp);
}

char	*get_line(int fd, char *save)
{
	char	*buf;
	ssize_t	ret;

	ret = 1;
	while (ret > 0 && ft_strchr(save, '\n') == NULL)
	{
		buf = (char *)malloc(BUFFER_SIZE + 1);
		if (!buf)
			return (NULL);
		ret = read(fd, buf, BUFFER_SIZE);
		buf[ret] = '\0';
		save = ft_strjoin(save, buf);
		free(buf);
	}
	return (save);
}

void	ft_strlcpy(char *tmp, char *s, size_t len)
{
	size_t	i = 0;
	while (s[i] && i < len - 1)
	{
		tmp[i] = s[i];
		i++;
	}
	tmp[i] = '\0';
}

char	*ft_substr(char *s, size_t start, size_t len)
{
	char	*tmp;
	size_t	new_len;

	if (!s)
		return (NULL);
	if (ft_strlen(s) < start)
		len = 0;
	new_len = ft_strlen(s + start);
	if (new_len < len)
		len = new_len;
	tmp = (char *)malloc(len + 1);
	ft_strlcpy(tmp, s + start, len + 1);
	return (tmp);
}

char	*ft_line(char *save)
{
	size_t	i = 0;

	if (!save)
		return (NULL);
	while (save[i] && save[i] != '\n')
		i++;
	return (ft_substr(save, 0, i + 1));
}

char	*ft_save(char *save)
{
	size_t	i = 0;
	char 	*tmp;

	if (!save)
		return (NULL);
	while (save[i])
	{
		if (save[i] == '\n')
		{
			tmp = ft_substr(save, i + 1, ft_strlen(save));
			free(save);
			return (tmp);
		}
		i++;
	}
	free(save);
	return (NULL);
}

char	*get_next_line(int fd)
{
	static char	*save;
	char		*line;

	if (fd < 0 || BUFFER_SIZE < 1 || BUFFER_SIZE > INT_MAX)
		return (NULL);
	save = get_line(fd, save);
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