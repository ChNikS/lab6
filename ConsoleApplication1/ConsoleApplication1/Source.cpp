/** @file Source.cpp */
#include <iostream>
using namespace std;

int main()
{
	

	int N; /*! Vvod kolichestva uzlov v grafe */
	cout << "Vvedite kolichestvo uzlov v grafe >> "; cin >> N;
	/// Massiv so stoimost'ju reber v grafe 
	int **cost = new int*[N];
	for (int i = 0; i < N; i++)
	{
		cost[i] = new int[N];
	}
	/// Massiv, v kotorom poseshhennye rebra
	int *visited = new int[N];
	/// Massiv, v kotorom vershiny, obrazujushhie min. ostovnoe derevo
	int *way = new int[N];
	int way_id = 0;

	cout << "Vvedite rasstojanie mezhdu uzlami:" << endl; /*! Vvod rasstojanija mezhdu uzlami */
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (i == j)
			{
				cost[i][j] = 0;
			}

			if (i < j)
			{
				cout << "Rasstojanie mezhdu uzlom " << i + 1 << " i " << j + 1;
				cin >> cost[i][j];
				cost[j][i] = cost[i][j];
			}
		}
	}
	/// Vyvod matricy sezhnosti
	cout << "\nMatrica smezhnosti: \n" << endl;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cout << cost[i][j] << "\t ";
			if (cost[i][j] == 0)
			{
				cost[i][j] = INT_MAX;
			}
		}
		cout << endl << endl;
	}

	visited[0] = 1;
	for (int i = 1; i < N; i++)
	{
		visited[i] = 0;
	}
	/// algoritm Prima 
	int a, b, u, v, ix = 1, min, mincost = 0;
	cout << "Pary vershin, kotorye svjazyvaet minimal'noe ostovnoe derevo: ";
	while (ix < N)
	{
		min = INT_MAX;
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
			{
				if (cost[i][j] < min)
				{
					if (visited[i] != 0)
					{
						min = cost[i][j];
						a = u = i;
						b = v = j;
					}
				}
			}
		}

		if (visited[a] == 0 || visited[b] == 0)
		{
			way[way_id] = b;
			way_id++;
			cout << endl << ix++ << ") " << "Stoimost' rebra mezhdu " << a + 1 << " i " << b + 1 << " = " << min;
			mincost += min;
			visited[b] = 1;
		}

		cost[a][b] = cost[b][a] = INT_MAX;
	}

	cout << "\n\nMinimal'noe ostovnoe derevo: "; /*! Vyvod min. ostovnogo dereva */
	cout << 1 << " --> ";
	for (int i = 0; i < N - 1; i++)
	{
		cout << way[i] + 1;
		if (i < N - 2) cout << " --> ";
	}

	cout << "\nMinimal'naja stoimost' ostovnogo dereva: " << mincost; /*! Vyvod min. stoimosti ostovnogo dereva*/
	cout << endl;

	system("pause");
	return 0;
}