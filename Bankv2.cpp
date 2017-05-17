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
	long long n, x, m, w=0, Sdv=0;
	bool last = false, first = false;
	cin >> n >> x;
	const long long nConst = n;
	vector<long long> nn(0);
	vector<long long> Emj(0);

	for (int i = 0; i < nConst; i++)
	{
		int Q;
		cin >> Q;
		if (Q >= x)
		{
			last = true;
			w++;
		}
		else
		{
			last = false;
		};
		Emj.push_back(w);
		nn.push_back(Q);
	};

	if (nn[0] >= x)
	{
		first = true;
	};

	cin >> m;
	int T, L = 0;

	for (int i = 0; i < m; i++)
	{
		cin >> T;

		if (T == 1)
		{
			cout << "1 p "<<Emj.size()<<endl;
			for (int i = 0; i < Emj.size(); i++)
			{
				cout << Emj[i] << " ";
			};
			cout << endl;

			cin >> L;
			nn.push_back(L);
			Emj.push_back(w);

			cout << "1 p (2)" << endl;
			for (int i = 0; i < Emj.size(); i++)
			{
				cout << Emj[i] << " ";
			};
			cout << endl;

			if (last == true)
			{
				w++;
			};
		};

		if (T == 2)
		{
			cout << "2 p" << endl;
			for (int i = 0; i < Emj.size(); i++)
			{
				cout << Emj[i] << " ";
			}
			cout << endl;

			nn.erase(nn.begin());
			if (first == true)
			{
				w--;
				for (int i = 0; i < Emj.size(); i++)
				{
					if (Emj[i] != 0)
					{
						Emj[i]--;
					};
				}
			};

			cout << "2 p (2)" << endl;
			for (int i = 0; i < Emj.size(); i++)
			{
				cout << Emj[i] << " ";
			};
			cout << endl;
		};

		if (T == 3)
		{
			cout << " 3 p" << endl;
			cin >> L;
			cout << Emj[L] << endl;
		};
	};
}