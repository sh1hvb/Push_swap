#include "libft.h"
#include <stdlib.h>

static int	word_count(const char *s, char c)
{
    int count = 0;
    int i = 0;
    while (s[i])
    {
        if (s[i] == c && s[i])
        {
            i++;
            continue;
        }
        count++;
        while (s[i] != c && s[i])
        {
            i++;
        }
    }
    return (count);
}

static int	word_length(const char *s, char c)
{
    int len = 0;
    while (*s != c && *s != '\0')
    {
        s++;
        len++;
    }
    return (len);
}

static char	**fill_arr(char **arr, const char *s, char c, int words_count)
{
    int i = -1;
    while (++i < words_count)
    {
        while (*s == c)
            s++;
        int j = 0;
        int word_len = word_length(s, c);
        arr[i] = (char *)malloc(sizeof(char) * (word_len + 1));
        if (!(arr[i]))
        {
            // Free memory in case of allocation failure
            while (--i >= 0)
                free(arr[i]);
            free(arr);
            return (NULL);
        }
        while (j < word_len)
        {
            arr[i][j] = *s;
            s++;
            j++;
        }
        arr[i][j] = '\0';
    }
    return (arr);
}

char	**ft_split(char const *s, char c)
{
    char	**result;
    int		words_count;

    if (!s)
        return (NULL);
    words_count = word_count(s, c);
    result = (char **)malloc(sizeof(char *) * (words_count + 1));
    if (!(result))
        return (NULL);
    result = fill_arr(result, s, c, words_count);
    if (!result)
        return (NULL); // Allocation failure handled in the helper function
    result[words_count] = NULL;
    return (result);
}

// Add a function to free the memory allocated by ft_split
void	free_split_result(char **result)
{
    int i = 0;
    while (result[i])
    {
        free(result[i]);
        i++;
    }
    free(result);
}
