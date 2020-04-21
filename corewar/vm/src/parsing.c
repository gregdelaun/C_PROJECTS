#include "../includes/corewar.h"

// on ouvre le fichier, vu que l'on nous dis que le Corewar magic
// number se lit sur les 4 premier bytes et que celui que l'on recoit
// dans le fichier header est "uint32_t" on lit avec des "uint8_t" chaque byte
// On stocke dans buffer et l'on convertit en un uint32_t par la suite
// on shift https://stackoverflow.com/questions/20695586/casting-uint8-to-uint32
// On check si on a le meme magic number ou pas

int open_files(int argc, char **argv, t_main *struk, int arg)
{
	int fd;
	size_t	size;
	uint8_t buffer[4];
	uint32_t magic;

	fd = 0;
	fd = open(argv[arg], O_RDONLY);
	size = read(fd, &buffer[0], 1);
	size = read(fd, &buffer[1], 1);
	size = read(fd, &buffer[2], 1);
	size = read(fd, &buffer[3], 1);
	magic = buffer[0] << 24| (buffer[1] << 16) | (buffer[2] << 8) | (buffer[3] << 0);
	if(magic != COREWAR_EXEC_MAGIC)
		problem_occured("Wrong COREWAR_EXEC_MAGIC");
	return(fd);
}

// check les arguemnts et on active dump et ou le visu si nécessaire
// si il y a "-n" on va assigner une certaine valuer dans l'array order player
// Verifier l'orde ainsi de suite et désigner valeur suivante disponible si pas
// de "-n" au prochain .cor
t_main *check_arguments(int argc, char **argv, t_main *struk)
{
	int i;
	int a;

	i = 1;
	a = 0;
	while(i < argc)
	{
		if(!(ft_strcmp(argv[i], "-dump")))
			struk = check_cycles(struk, argv, i);
		if(!(ft_strcmp(argv[i], "-visu")))
				struk->visu = 1;
		if((!(ft_strcmp(argv[i], "-n")) && a < 4))
		{
			if(argv[i + 1] && ft_isdigit((argv[i + 1][0])) && check_if_file(argv, i + 2))
			{
						struk->order_player[a++][0] = ft_atoi(argv[i + 1]);
						if(argv[i + 3])
							i = i + 3;
						else
							break;
			}
		}
		if(check_if_file(argv, i))
		{
					struk->order_player[a][0] = check_previous_player_number(struk);
					a++;
		}
		i++;
	}
	return (struk);
}

// simple ATOI du prochain argument apres le "-dump"

t_main	*check_cycles(t_main *struk, char **argv, int i)
{
	if(argv[i + 1])
			struk->nbr_cycles = ft_atoi(argv[i + 1]);
	return (struk);
}


// regarder si jamais le prochain ordre de joueur sensé être donné est encore dispo
// Si oui l'assigner si non aller voir le prochain

int check_previous_player_number(t_main *struk)
{
	int i;
	int j;

	i = 0;
	j = 1;
	while(i < 4)
	{
		if(struk->order_player[i][0] == j)
		{
				j++;
				i = -1;
		}
		i++;
	}
	return (j);
}


// Simple check pour voir si c'est bien un fichier ".cor"
int check_if_file(char **argv, int i)
{
	int j;

	j = 0;
	while (argv[i][j])
	{
		j++;
	}
	if (argv[i][j - 4] == '.')
	{
		if (argv[i][j - 3] == 'c' && argv[i][j - 2] == 'o' && argv[i][j - 1] == 'r')
			return (1);
		else
			return (0);
	}
	return (0);
	return (0);
}
