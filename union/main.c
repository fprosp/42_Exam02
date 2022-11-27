/*Example:

$>./union zpadinton "paqefwtdjetyiytjneytjoeyjnejeyj" | cat -e
zpadintoqefwjy$
$>./union ddf6vewg64f gtwthgdwthdwfteewhrtag6h4ffdhsd | cat -e
df6vewg4thras$
$>./union "rien" "cette phrase ne cache rien" | cat -e
rienct phas$
$>./union | cat -e
$
$>
$>./union "rien" | cat -e
$
$>
*/

#include <unistd.h>

/*int main (int argc, char **argv)
{
    int used[9999];
    int i;
    int j;

    if (argc == 3)
    {
        i = 0;
        while (i <9999)
        {
            used[i] = 0;
            i++;
        }
        i = 1;
        while (i < 3)
        {
            j = 0;
            while (argv[i][j])
            {
                if (used[(unsigned char)argv[i][j]] == 0)
                {
                    write(1, &argv[i][j], 1);
                    used[(unsigned char)argv[i][j]] = 1;
                }
                j++;
            }
            i++;
        }
    }
    write (1, "\n", 1);
    return (0);
}*/

int main(int argc, char **argv)
{
	if (argc == 3)
	{
		int i;
		int j;
		int used[9999];

		i = 0;
		while (i < 9999)
		{
			used[i] = 0;
			i++;
		}
		i = 1;
		while (i < 3)
		{
			j = 0;
			while (argv[i][j])
			{
				if (used[(unsigned int)argv[i][j]] == 0)
				{
					write (1, &argv[i][j], 1);
					used[(unsigned int)argv[i][j]] = 1;
				}
				j++;
			}
			i++;
		}
	}
	write (1, "\n", 1);
	return (0);
}