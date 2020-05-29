/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_lite.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: md4 <md4@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/24 22:52:24 by md4               #+#    #+#             */
/*   Updated: 2020/05/29 02:48:24 by md4              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_motifreset(char **motif)
{
	if (*motif && !**motif)
	{
		*motif = NULL;
		return (1);
	}
	return (0);
}

/*
** Function: ft_newlinefrombuffer
** Parameters:
**		char **line:
**		char **motif:
** Description:
** ft_newLienOnHaystack is called if '\n' is present on the haystack;
** needle is a pointer to n+1 byte after '\n';
** new line from *needle untill next '\n' is copied to freshly allocated memory
** pointed by **line;
** *needle pointer is shifted on the length of copied new line + 1 byte;
*/

static int	ft_newlinefrombuffer(char **line, char **motif)
{
	int		len;
	char	*motifend;

	motifend = ft_strchr(*motif, '\n');
	len = motifend - *motif;
	if (!(*line = ft_strsub(*motif, 0, len)))
		return (-1);
	*motif += len + 1;
	ft_motifreset(motif);
	return (1);
}

/*
** function readNewLine
** Parameters:
**		int fd:
**		char *buffer:
**		char **motif:
**		char **line:
** Description:
**		Reads line in a loop untill '\n' is reached;
**		read results are concatenated to **line;
**		if a string is present in buffer, it is copied to the HEAD of **line
** Return:
**		1: if EOF not reached yet or if the buffer is not empty
**		0: if EOF reached and buffer empty
**		-1: if an error was risen
*/

static int	ft_readnewline(int fd, char *buffer, char **motif, char **line)
{
	int		rd;

	if (*motif)
		if (ft_memncat(line, *motif, ft_strlen(*motif)) == -1)
			return (-1);
	*motif = NULL;
	rd = 1;
	while (!*motif && rd > 0)
	{
		if ((rd = read(fd, buffer, BUFF_SIZE)) == -1)
			return (-1);
		buffer[rd] = '\0';
		if (rd == 0 && !*line)
			return (0);
		if ((*motif = ft_strchr(buffer, '\n')) == 0)
			rd = ft_memncat(line, buffer, ft_strlen(buffer));
		else
		{
			rd = ft_memncat(line, buffer, (*motif - buffer));
			*motif += 1;
		}
	}
	ft_motifreset(motif);
	return (1);
}

/*
** Function: get_next_line_lite
** Parameters:
**		int fd: file descriptor of the
**		char **buf: adress of the buffer
** Description:
**	Similar to get_next_line but a ligther version.
**	No multi-fd management, designed for small files.
**	Function reads of BUFF_SIZE bites from [fd].
**	a new lien in freshly allocated mamory, pointed by **line;
** Return:
**		1: if EOF not reached yet or if the buffer is not empty
**		0: if EOF reached and buffer empty
**		-1: if line is NULL or an error was risen
*/

int			get_next_line_lite(int fd, char **line)
{
	static char		buffer[BUFF_SIZE + 1] = { 0 };
	static char		*motif = NULL;
	int				ret;

	if (line == NULL)
		return (-1);
	*line = NULL;
	if (motif && ft_strchr(motif, '\n'))
		ret = ft_newlinefrombuffer(line, &motif);
	else
		ret = ft_readnewline(fd, buffer, &motif, line);
	return (ret);
}
