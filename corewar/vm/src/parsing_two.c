#include "../includes/corewar.h"

// Dans le pdf ou ous dit que"Next 2048 bytes represent champions comment.
// It is same as champion name excepting max size COMMENT_LENGTH.
// On read le commentaire et on le stocke dans la structure du joueur actuel
// Check si il y a bien NULL Bytes apres le commentaire comme dit dans le pdf
// Le reste du fichier .cor est le code du joueur, on le lit grace a la taille que l'on
// a récupérer précedement.

t_main *some_other_parsing(int fd, t_main *struk, int num_play)
{
	uint8_t buf[4];
	char buffer[COMMENT_LENGTH];
	uint8_t *buff;
	size_t size;
	int i;

	i = 0;
	if (!(buff = malloc(struk->player[num_play].code_length)))
		problem_occured("malloc failed");
	size = read(fd, &buffer, COMMENT_LENGTH);
	while (i < 4)
		size = read(fd, &buf[i++], 1);
	i = 0;
	if (check_if_zero(buf))
		problem_occured("No NULL-bytes after comment");
	size = read(fd, buff, struk->player[num_play].code_length);
	struk->player[num_play].code = buff;
	i = 0;
	struk->player[num_play].comment = buffer;
	return (struk);
}

// Focntion en cas d'erreur

void problem_occured(char *problem)
{
	printf("%s\n", problem);
	exit(0);
}

// verifier si ce sont bien tous des NULL BYTES

int check_if_zero(uint8_t *buf)
{
	int i;

	i = 0;
	while (i < 4)
	{
		if (buf[i] != 0)
			return (1);
		i++;
	}
	return (0);
}

// Dans le pdf "Next 128 bytes are champion's name. 128
// is the value of constant PROG_NAME_LENGTH from op.h file."
// On lit du coup les 128 bytes avec read en char.
// Mets dans la structure dans l'actuel joueur (voir num_play actuel)
// Ensuite on nous dit que "Next four bytes are NULL-bytes. Their goal is to be present at this
// place and to be NULL. If they are not, file is invalid."
// On check ça, si faux alors on appelle problem occured
// Ensuite on nous dit "Next four bytes represent the size of
// champion's executable code (only executable part of champion)."
// On fait pareil que pour le COREWAR_EXEC_MAGIC et on chope la taille du Champion et on la stocke

t_main *some_parsing_checks(int fd, t_main *struk, int num_play)
{
	char buffer[PROG_NAME_LENGTH];
	size_t size;
	uint8_t buf[4];
	uint32_t magic;
	int i;

	i = 0;
	size = read(fd, &buffer, PROG_NAME_LENGTH);
	struk->player[num_play].name = ft_strcpy(ft_strnew(PROG_NAME_LENGTH), buffer);
	while (i < 4)
		size = read(fd, &buf[i++], 1);
	if (check_if_zero(buf))
		problem_occured("No NULL-bytes after file name");
	i = 0;
	while (i < 4)
		size = read(fd, &buf[i++], 1);
	magic = buf[0] << 24 | (buf[1] << 16) | (buf[2] << 8) | (buf[3] << 0);
	if (magic > CHAMP_MAX_SIZE /* || magic < 0*/)
		problem_occured("Champ size too big");
	struk->player[num_play].code_length = magic;
	return (struk);
}
