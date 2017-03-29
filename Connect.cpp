#include <vector>
#include <cmath>
#include <cstdlib>
#include <iostream>

using namespace std;


const int nConst = 20000;
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
	//Read the graph
	freopen("connect.in", "r", stdin);
	freopen("connect.out", "w", stdout); 


	bool MainCheck = false, HelpCheck = true, SecCheck;
	int N, M;
	cin >> N >> M;

	//Fill in vector
	for (int i = 0; i < M; i++)
	{
		int l, j;
		cin >> l >> j;
		l--;
		j--;
		edges[l].push_back(j);
		edges[j].push_back(l);
	};

	//Search connectivity components
	while (MainCheck == false)
	{
		dfs(Versh);
		DFSspec++;
		HelpCheck = true;
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
	DFSspec--;
	cout << DFSspec << endl;
	for (int i = 0; i < N; i++)
	{
		cout << used[i] << " ";
	};
}
