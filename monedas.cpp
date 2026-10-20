#include <iostream>
#include <vector>
#include <limits>
#include <algorithm>

void monedas(const std::vector<int> &m, int d, std::vector<int>&s)
{
	const int inf_val = std::numeric_limits<int>::max();
	const int n = m.size();

	s.assign(n, 0);
	if (n == 0 || d <= 0)
		return;
	
	std::vector<std::vector<int>> T(n, std::vector<int>(d + 1, inf_val));
	
	//Primera fila
	T[0][0] = 0;
	for (int j = 1; j <= d; j++)
		if (j >= m[0] && T[0][j -m[0]] != inf_val)
			T[0][j] = 1 + T[0][j - m[0]];

	//Resto tabla
	T[0][0] = 0;
	for (int i = 1; i <= n; i++)
	{
		T[i][0] = 0;
		for (int j = 1; j <= d; j++)
		{
			if (j < m[i] || T[i][j - m[i]] != inf_val)
				T[i][j] = T[i - 1][j];
			else if (T[i - 1][j] != inf_val)
				T[i][j] = std::min(T[i -1][j], 1 + T[i][j -m[i]]);
			else
				T[i][j] = 1 + T[i][j - m[i]];
		}
	}
	if (T[n -1][d] == inf_val)
		return;
	//no hay solucion

	//recuperar sol
	int i = n - 1;
	int j = d;
	while (i >= 0 && j != 0)
	{
		if ( i == 0 || T[i][j] != T[i -1][j])
		{
			s[i]++;
			j -= m[i];
		}
		else
			i--;
	}
}
	
