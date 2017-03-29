#include <vector>
#include <cmath>
#include <cstdlib>
#include <iostream>

using namespace std;


const int nConst = 100;
int used[nConst];
vector<int> edges[nConst];
int DFSspec = 1;
int Versh = 0;
void dfs(int Num)
{
	used[Num] = DFSspec;
	for (int i = 0; i < (int)edges[Num].size(); i++)
	{
		int to = edges[Num][i];
		if (used[to] == 0)
		{
			dfs(to);
		};
	};
}

int main()
{
	//Чтение и вывод
	freopen("connect.in", "r", stdin);
	freopen("connect.out", "w", stdout); 

	//Блок 1
	bool MainCheck = false, HelpCheck = true, SecCheck;
	int N, M; //N-кол-во вершин; M-кол-во ребер;
	cin >> N >> M;

	//Чтение графа
	for (int i = 0; i < M; i++)
	{
		int l, j; //Вспомогательные переменные
		cin >> l >> j;
		l--;
		j--;
		edges[l].push_back(j);
		edges[j].push_back(l);
	};

	//Поиск Комп.Связ
	while (MainCheck == false)
	{
		dfs(Versh);
		DFSspec++;
		HelpCheck = true;
		//Проверка на выполненость
		for (int i = 0; i < N; i++)
		{
			if (used[i] == 0)
			{
				HelpCheck = false;
			};
		};

		if (HelpCheck == false)
		{
			SecCheck = true;
			for (int i = 0; i<N; i++)
			{
				if (used[i] == 0 && SecCheck == true)
				{
					Versh = i;
					SecCheck = false;
				};
			};
		}
		else
		{
			MainCheck = true;
		};
	};
	DFSspec = DFSspec - 2;
	cout << DFSspec << endl;
	for (int i = 0; i < N; i++)
	{
		cout << used[i] << " ";
	};
}
