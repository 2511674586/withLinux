/**
 * @file dfs.cc
 * @brief implement depth-first searching
 */
#include <iostream>
#include <stack>

/** 
 * @brief Core function of DFS, depth first search
 * @param adjacent is the adjacent matrix, which should be symmetric
 * @param visit is the vector recording the visiting history across all nodes
 * @param path is the stack maintaining path
 * @return void
 */
void
_dfs (int adjacent[7][7], int visit[7], int cur, std::stack<int> * s)
{
	using namespace std;
	visit[cur] = 1; // set visited bit at cursor
	s->push(cur);
	cout << "cur -> " << cur << endl;
	int if_bound = 0;
	for (unsigned int i = 0; i < 7; i++)
		if_bound += (0 == adjacent[cur][i]) ? 0 : 1;
	if (0 == if_bound) { // boundary reached
		return;
	} else { // not yet, go ahead
		for (unsigned int i = 0; i < 7; i++) {
			// pass nodes that have been visited
			if (visit[i]) continue;
			// pass nodes that cannot be reached
			else if (! adjacent[cur][i]) continue;
			// not visited, go ahead
			else {
				_dfs (adjacent, visit, i, s);
				(void) s->pop();
			}
		}
	}
	return;
}

/**
 * @brief wrapper function of _dfs
 * @param adjacent matrix
 * @param start_from is the point from which you wish to start traversal
 * @return void
 */
void
dfs (int adjacent[7][7], int start_from)
{
	std::cout << "Traversal starting from " << start_from << std::endl;
	std::stack<int> s;
	int visit[7] = {0};
	_dfs (adjacent, visit, start_from, &s);
	return;
}

/**
 * @brief make sure a matrix is symmetric
 * @param matrix
 */
void
make_symmetric (int mat[7][7])
{
	for (int i = 0; i < 7; i++) {
		for (int j = 0; j < 7; j++) {
			if (mat[i][j]) mat[j][i] = 1;
		}
	}
	return;
}

/**
 * @brief test dfs implementation
 */
int
main (void)
{
	int adj[7][7] = {0};
	int visit[7] = {0};
	std::stack<int> s;

	// prepare map
	adj[0][1] = 1;
	adj[0][2] = 1;
	adj[1][3] = 1;
	adj[1][4] = 1;
	adj[2][5] = 1;
	adj[2][6] = 1;
	make_symmetric(adj);

	// test, starting from node 0
	_dfs (adj, visit, 0, &s); 

	// test, we can start from any point actually
	for (int i = 0; i < 7; i++)
		dfs (adj, i);

	return 0;
}
