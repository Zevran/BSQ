#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int		main(int argc, char **argv)
{
	srand(time(0));
	int	x, y, d;

	if (argc < 4)
		cin >> x >> y >> d;
	else
	{
		x = atoi(argv[1]);
		y = atoi(argv[2]);
		d = atoi(argv[3]);
	}
	cout << x << ".ox" << endl;
	for(int i = 0; i < y; i++)
	{
		for(int j = 0; j < x; j++)
		{
			if ((rand() % y ) * 2 < d)
				cout << "o";
			else
				cout << ".";
		}
		cout << endl;
	}
	return (0);
}
