#include <fstream>
#define MAX_N 101
using namespace std;
void inspecteazaTriunghi(
	int a[][MAX_N],
	int L1,
	int C1,
	int L2,
	int C2,
	int p,
	int & patratele,
	int & patrateleAfectate,
	int & patrateleNeafectate);
int main()
{
	ifstream citeste("elicop.in");
	ofstream scrie("elicop.out");
	int m, n;
	citeste >> m >> n;
	int a[m+1][MAX_N], i, j;
	for (i = 1; i <= m; i++)
	{
		for (j = 1; j <= n; j++)
		{
			citeste >> a[i][j];
		}
	}
	int k;
	citeste >> k;
	int N1=0, N2=0, e[k+1];
	for (i = 1; i <= k; i++)
	{
		int L1, L2, C1, C2, p;
		citeste >> L1 >> C1
		        >> L2 >> C2
			>> p;
		int patratele = 0,
		    patrateleAfectate = 0,
		    patrateleNeafectate = 0;
		inspecteazaTriunghi(
			a,
			L1,
			C1,
			L2,
			C2,
			p,
			patratele,
			patrateleAfectate,
			patrateleNeafectate);
		if (patrateleNeafectate == patratele)
		{
			N1++;
		}
		else if (patrateleAfectate > patratele/2)
		{
			e[++N2] = i;
		}
	}
	citeste.close();
	scrie << N1 << endl << N2 << ' ';
	for (i = 1; i <= N2; i++)
	{
		scrie << e[i] << ' ';
	}
	scrie.close();
	return 0;
}
void inspecteazaTriunghi(
	int a[][MAX_N],
	int L1,
	int C1,
	int L2,
	int C2,
	int p,
	int & patratele,
	int & patrateleAfectate,
	int & patrateleNeafectate)
{
	if (L2 < L1)
	{
		swap(L1, L2);
		swap(C1, C2);
	}
	if (p == -1)
	{
		for (int lin = L1; lin <= L2; lin++)
		{
			int col = C1;
			for (int j = 1; j <= lin-L1+1; j++)
			{
				patratele++;
				if (a[lin][col] == 0)
				{
					patrateleAfectate++;
				}
				else
				{
					patrateleNeafectate++;
				}
				col = C1 < C2 ? col+1 : col-1;
			}
		}
	}
	else
	{
		for (int lin = L2; lin >= L1; lin--)
		{
			int col = C2;
			for (int j = 1; j <= L2-lin+1; j++)
			{
				patratele++;
				if (a[lin][col] == 0)
				{
					patrateleAfectate++;
				}
				else
				{
					patrateleNeafectate++;
				}
				col = C2 < C1 ? col+1 : col-1;
			}
		}
	}
}
