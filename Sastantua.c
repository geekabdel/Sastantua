#include<unistd.h>
void ft_putchar(char c)
{
	write(1,&c,1);
}

int		largeuretage(int i)
{
	if (i == 0)
	return(7);
	
	return(largeuretage(i - 1) + 2 * (1 + (3 + i) + ((i % 2) + (1 / 2))));
}

void	etage(int h, int l, int d)
{
	int i;
	int j;

	i = 0;
	while (i < h)
	{
		j = -d;
		while(j < h - 1 - i)
		{
			ft_putchar(' ');
			j++;
		}
		j+= h + 1 - i;
		ft_putchar('/');
		while (j < l)
		{
			ft_putchar('*');
			j++;
		}
		ft_putchar('\\');
		ft_putchar('\n');
		i++;
	}
}

void	fill_door(int s, int i, int h, int l, int d, int door_size)
{
	int j = s;
	ft_putchar('/');
	while (j < l - (l - s) / 2 - door_size / 2 - 1)
	{
		ft_putchar('*');
		j++;
	}
	while (j < l - (l - s) / 2 + door_size / 2)
	{
		if (door_size > 3 && h - i - 1 == door_size / 2 && j == l - (l - s) / 2 + door_size / 2 - 2) 
			ft_putchar('$');
		else
			ft_putchar('|');
		j++;
	}
	while (j < l)
	{
		ft_putchar('*');
		j++;
	}
	ft_putchar('\\');
	ft_putchar('\n');
}

void 	etage_overdoor(int h, int l, int d, int door_size)
{
	int i;
	int j;

	i = 0;
	while (i < h - door_size)
	{
		j = -d;
		while(j < h - 1 - i)
		{
			ft_putchar(' ');
			j++;
		}
		j+= h + 1 - i;
		ft_putchar('/');
		while (j < l)
		{
			ft_putchar('*');
			j++;
		}
		ft_putchar('\\');
		ft_putchar('\n');
		i++;
	}
}

void	etage_door(int h, int l, int d)
{
	int i;
	int j;

	i = 0;
	while (i < h)
	{
		j = -d;
		while(j < h - 1 - i)
		{
			ft_putchar(' ');
			j++;
		}
		j+= h + 1 - i;
		fill_door(j, i, h, l, d, h);
		i++;
	}
}

void	sastantua(int size)
{
	int		i;
	int		h;
	int		l;
	int		d;
	
	i = -1;
	int door_size = size;
	if(door_size % 2 == 0)
	{
		door_size--;
	}
	while (++i < size)
	{
		d = (largeuretage(size - 1) - largeuretage(i)) / 2;
		h = 3 + i;
		l = largeuretage(i);
		if (i == size - 1)
		{
			etage_overdoor(h, l, d, door_size);
			etage_door(door_size, l, d);
		}
		else
			etage(h, l, d);
	}
}
int main ()
{
	sastantua(5);
}
