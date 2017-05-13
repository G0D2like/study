#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
#include <cstdlib>

using namespace std;

int main()
{
	freopen("longqueue.in", "r", stdin);
	freopen("longqueue.out", "w", stdout);
	long long n, x, m;
	cin >> n >> x;
	const long long nConst = n;
	vector<long long> nn(0);

	for (int i = 0; i < nConst; i++)
	{
		int Q;
		cin >> Q;
		nn.push_back(Q);
	};

	cin >> m;
	int T, L, A = 0;
	
	for (int i = 0; i < m; i++)
	{
		cin >> T;

		if (T == 1)
		{
			cin >> L;
			nn.push_back(L);
		};

		if (T == 2)
		{
			nn.erase(nn.begin());
		};

		if (T == 3)
		{
			cin >> L;
			for (int j = 0; j<L; j++)
			{
				if (nn[j] >= x)
				{

					A++;
				};
			}
			cout << A << endl;
			A = 0;
		};
	};
}