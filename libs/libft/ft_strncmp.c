/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anruland <anruland@students.42wolfsburg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/09 09:58:07 by anruland         #+#    #+#             */
/*   Updated: 2022/03/22 10:12:28 by anruland         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* The strncmp() function shall compare not more than n bytes (bytes
       that follow a NUL character are not compared) from the array
       pointed to by s1 to the array pointed to by s2. */

int	ft_strncmp(const char *s1, const char *s2, unsigned int n)
{
	unsigned int	i;

	i = 0;
	while (i < n)
	{
		if (*(s1 + i) != *(s2 + i))
			return ((unsigned char) *(s1 + i) - (unsigned char) *(s2 + i));
		if (*(s1 + i) == '\0')
			return (0);
		i++;
	}
	return (0);
}
