#include <vector>
#include <algorithm>

int mochila(const std::vector<int> &p, const std::vector<int> &b, int m, const std::vector<int> &s)
{
	const int n = p.size();
	
	s.assign(n, 0);
	
	std::vector<std::vector<int>> T(n + 1, std::vector<int>(m + 1, 0));
	
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			if (p[i - 1] > j)
				T[i][j] = T[i -1][j];
			else
				T[i][j] = std::max(T[i - 1][j], T[i - 1][j - p[i - 1]] + b[i - 1]);
		}
	}

	//Recupera la solcuion

	int j = m;
	for (int i = n; i >= 1; i--)
		if (T[i][j] != T[i - 1][j])
		{
			s[i - 1] = 1;
			j -= p[i - 1];
		}
	return T[n][m];
}
