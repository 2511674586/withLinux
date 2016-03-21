/** 
 * @file bfs.cc
 * @brief breadth-first search
 */
#include <iostream>
#include <queue>

/**
 * @brief Core function of BFS, breadth-First search
 * @param adjacent matrix
 * @param visit vector
 * @param cur is the current cursor location
 * @param q is the queue used to maintain dfs within recursion
 */
void
_bfs (int adjacent[7][7], int visit[7], int cur, std::queue<int> * q)
{
	using namespace std;
	visit[cur] = 1;
	cout << "cur -> " << cur << endl;
	// refresh queue
	for (int i = 0; i < 7; i++) {
		if (adjacent[cur][i]) { // filter 1, reachable
			if (! visit[i]) { // filter 2, not visited
				q->push(i);
			}
		}
	}
	if (0 == q->size()) { // boundary
		return;
	} else { // go ahead
		int next = q->front();
		q->pop();
		_bfs (adjacent, visit, next, q);
	}
	return;
}

/**
 * @brief wrapper function of the core bfs
 * @param adjacent matrix
 * @param start_from is the starting point of traversal
 */
void
bfs (int adjacent[7][7], int start_from)
{
	std::cout << "Traversal starting from " << start_from << std::endl;
	std::queue<int> q;
	int visit[7] = {0};
	_bfs (adjacent, visit, start_from, &q);
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
 * @brief test bfs implementation
 */
int
main (void)
{
	int adj[7][7] = {0};
	int visit[7] = {0};
	std::queue<int> q;

	// prepare map
	adj[0][1] = 1;
	adj[0][2] = 1;
	adj[1][3] = 1;
	adj[1][4] = 1;
	adj[2][5] = 1;
	adj[2][6] = 1;
	make_symmetric(adj);

	// test, starting from node 0
	_bfs (adj, visit, 0, &q); 

	// test, we can start from any point actually
	for (int i = 0; i < 7; i++)
		bfs (adj, i);

	return 0;
}
