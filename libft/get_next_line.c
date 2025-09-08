/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbuchhol <nbuchhol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 13:06:53 by nbuchhol          #+#    #+#             */
/*   Updated: 2025/09/08 20:31:13 by nbuchhol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_strdup_gnl(const char *s1)
{
	char	*buffer;
	size_t	len;
	size_t	i;

	len = ft_strlen(s1);
	buffer = malloc(len + 1);
	if (!buffer)
		return (NULL);
	i = 0;
	while (s1[i] != '\0')
	{
		buffer[i] = s1[i];
		i++;
	}
	buffer[i] = '\0';
	return (buffer);
}

static char	*ft_free(char **buffer, char **stash)
{
	if (buffer && *buffer)
	{
		free(*buffer);
		*buffer = NULL;
	}
	if (stash && *stash)
	{
		free(*stash);
		*stash = NULL;
	}
	return (NULL);
}

static char	*read_and_stash(int fd, char *stash)
{
	char	*temp;
	char	*read_buffer;
	ssize_t	bytes_read;

	if (!stash)
		stash = ft_calloc_gnl(1, sizeof(char));
	read_buffer = ft_calloc_gnl(BUFFER_SIZE + 1, sizeof(char));
	bytes_read = 1;
	while (!ft_strchr_gnl(stash, '\n') && bytes_read != 0)
	{
		bytes_read = read(fd, read_buffer, BUFFER_SIZE);
		if (bytes_read == -1)
			return (ft_free(&read_buffer, &stash));
		read_buffer[bytes_read] = '\0';
		temp = ft_strjoin_gnl(stash, read_buffer);
		ft_free(NULL, &stash);
		stash = temp;
	}
	ft_free(&read_buffer, NULL);
	if ((stash[0] == '\0' || !stash) && bytes_read == 0)
		ft_free(NULL, &stash);
	return (stash);
}

static char	*get_line(char **stash)
{
	char	*line;
	char	*new_buffer;
	size_t	len;

	if (ft_strchr_gnl(*stash, '\n'))
	{
		len = ft_strchr_gnl(*stash, '\n') - *stash + 1;
		line = ft_substr_gnl(*stash, 0, len);
		new_buffer = ft_strdup_gnl(*stash + len);
		ft_free(NULL, stash);
		*stash = new_buffer;
	}
	else
	{
		line = ft_strdup_gnl(*stash);
		ft_free(NULL, stash);
	}
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*stash;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	stash = read_and_stash(fd, stash);
	if (!stash)
		return (NULL);
	line = get_line(&stash);
	if (!line)
		return (ft_free(NULL, &stash));
	return (line);
}
