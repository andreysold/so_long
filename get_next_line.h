#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 30
#endif
char	*ft_strchr(const char *s, int c);
char	*ft_strjoin(char const *s1, char const *s2);
size_t	ft_strlen(const char *s);
char	*ft_strdup(const char *s1);
void	*ft_call(size_t count, size_t size);
int		get_next_line(int fd, char **line);
void	*ft_memset(void *dest, int c, size_t len);
// void	st_info(char *file_name, t_job **sl);
// int		get_wid(char *file_name);
// int		get_het(char *file_name);
#endif
