#include "../../includes/termcaps/termcaps.h"
#include "../../includes/minishell.h"

int					count_line(char *line, int lenght)
{
	int i;

	i = 0;
	while (i < lenght)
	{
		if (line[i] == ' ')
		{
			if (i == lenght)
				return (0);
			else
				return (1);
		}
		i++;
	}
	return (0);
}

int					putwithtab(char *line, int space)
{
	int 			erg;
	int				lght;

	lght = ft_strlen(line);
	erg = space - lght;
	ft_putstr(line);
	while (erg-- != 0)
		ft_putchar(' ');
	return (space - lght + ft_strlen(line));
}

void 				list_files(t_window *win, t_llist *dline, int tabulation)
{
	int				count;
	int				lenght_line;

	count = 2;
	lenght_line = 0;
	tputs(tgetstr("sc", 0), 1, ft_puts);
	ft_putchar('\n');
	while (dline)
	{
		if (lenght_line >= win->column - 20)
		{
			ft_putchar('\n');
			lenght_line = 0;
			count++;
		}
		lenght_line += putwithtab(dline->content, tabulation);
		dline = dline->next;
	}
	tputs(tgetstr("rc", 0), 1, ft_puts);
	tputs(tgoto(tgetstr("cm", 0),win->pos[0] + 1, win->pos[1] - count), 1, ft_puts);
}

void 				path_found(t_window *win, t_llist *e, char *line)
{
	t_llist			*dline;
	char			*save;
	int				tabulation;

	dline = NULL;
	tabulation = 0;
	dline = created_path(&tabulation, e);
	list_files(win, dline, tabulation);
}

int					ft_search(t_window *win, t_llist *e, char *line)
{
	if (win->lineshell == 0)
	{
		ft_putchar('\t');
		return (0);
	}
	if (count_line(line, win->lineshell) > 0)
	{
		if (line[win->lineshell - 1] == ' ')
			path_found(win, e, line);
		else if (ft_isalnum(line[win->lineshell - 1]) == 1)
			path_found(win, e, line);
	}
	return (TAB);
}
