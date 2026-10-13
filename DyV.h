#include <iostream>
#include <vector>

template <typename T>

int busquedaBinaria(const T& X, const std::vector<T>&V, int ini, int fin){
	if (ini > fin)
		return -1;
	int medio = ini + (fin - ini) / 2;
	
	if(V[medio] == X)
		return medio;
	else if (V[medio] > X)
		return busquedaBinaria(X, V, ini, medio -1);
	else
		return busquedaBinaria(X, V, medio +1, fin);
}

template <typename T>

void quickSort(std::vector<T>&V, int ini, int fin){
	if (ini < fin){
		int pivot = partition(V, ini, fin);
		quickSort(V, ini, pivot -1);
		quickSort(V, pivot +1, ini);
	}
}

int partition(std::vector<T>&V, int ini, int fin)
{
	 	T x = V[fin
		int i = ini;
	
		for (int j = ini; j <= fin - 1; j++)
		{
			if (V[j] <= x)
			{
				std::swap(V[i], V[j]);
				i = i + 1;
			}
		}
		std::swap(V[i], V[j]);
		return i;
}		
