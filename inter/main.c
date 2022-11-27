/*Examples:

$>./inter "padinton" "paqefwtdjetyiytjneytjoeyjnejeyj" | cat -e
padinto$
$>./inter ddf6vewg64f gtwthgdwthdwfteewhrtag6h4ffdhsd | cat -e
df6ewg4$
$>./inter "nothing" "This sentence hides nothing" | cat -e
nothig$
$>./inter | cat -e
$
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
		while (i < 9999)
		{
			used[i] = 0;
			i++;
		}
		i = 2;
		while (i > 0)
		{
			j = 0;
			while (argv[i][j])
			{
				if (i == 2 && used[(unsigned char)argv[i][j]] == 0)
				{
					used[(unsigned char)argv[i][j]] = 1;
				}
				else if (i == 1 && used[(unsigned char)argv[i][j]] == 1)
				{
					write (1, &argv[i][j], 1);
					used[(unsigned char)argv[i][j]] = 2;
				}
				j++;
			}
			i--;
		}
	}
	write (1, "\n", 1);
	return (0);
}*/

int main(int argc, char **argv)
{
	int i;
	int j;
	int used[9999];

	if (argc == 3)
	{
		i = 0;
		while (i < 9999)
		{
			used[i] = 0;
			i++;
		}
		i = 2;
		while (i > 0)
		{
			j = 0;
			while (argv[i][j])
			{
				if (i == 2 && used[(unsigned int) argv[i][j]] == 0)
				{
					used[(unsigned int) argv[i][j]] = 1;
				}
				if (i == 1 && used[(unsigned int) argv[i][j]] == 1)
				{
					write(1, &argv[i][j], 1);
					used[(unsigned int) argv[i][j]] = 2;
				}
				j++;
			}
			i--;
		}
	}
	write(1, "\n", 1);
	return (0);
}
