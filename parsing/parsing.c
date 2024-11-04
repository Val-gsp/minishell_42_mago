#include "../include/minishell.h"

void	parsing(t_data *data)
{
    /*faire une boucle qui renvoie une chaine contenu entre deux pipes ou toutes la chaine
    s il y en a pas
    initialiser un noeud avec cette chaine
    split_and_clean ce noeud, cad:
    {
        retirer les quotes et ajouter les VA;
        gerer les redirections;

    }
    le refaire tant qu il y a des noeuds*/
    //syntax_parsing(data); // ici je verifie si toutes les quotes sont fermes et il y a bien des 
                       //commandes apres chaque pipe
	pre_parsing(data);
	create_nodes(data);
	split_and_clean(data);
	print_nodes (data);// faire une fonction debug qui affiche le contenu de chaque noeud;*/
}



void	pre_parsing(t_data *data)
{
		if(quotes_syntax(data))
		{
			free(data->line);
			printf("Quotes are not close");
			exit();
		}
		if(pipe_syntax(data))
		{
			free(data->line);
			printf("Need cmd after pipe");
			exit();
		}
}

int	quote_chr(char *str, int i)
{
	char	quote;
	
	quote = str[i];
	i++;
	while (str[i] && str[i] != quote)
	{
		i++;
	}
	if (str[i])
		return (i);
	else
		return (-42);
}


int	quotes_syntax(char *data)
{
	int	i;
	int add_index;
	
	i = 0;
	while (data[i])
	{
		if (data[i] == '\'' || data[i] == '"')
		{
			add_index = quote_chr(data, i);
			if (add_index == -42)
				return (1);
			i = add_index;
		}
		i++;
	}
	return (0);
}

int	pipe_syntax(t_data *data)
{
	char	*line;
	int	i;
	
	i = -1;
	line = data->input;
	while (line[++i])
	{
		if (data[i] == '\'' || data[i] == '"')
			i = quote_chr(data, i);
		if (line [i] && line[i] = '|')
		{
			while (line[i] && line[i] == ' ')
				i++;
			if (line[i] == '\0')
				return(1);
		}
	}
	return (0);
}







