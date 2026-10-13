#include <iostream>
#include <vector>


int busquedaBinaria(const T& X, const std::vector<T>&V, int ini, int fin)
{
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
