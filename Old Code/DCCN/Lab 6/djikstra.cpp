#include<iostream>
using namespace std;
#define max 5

void dijkstra ( int G[max][max], int n, int startnode )
{
	int dist[max], pred[max];
	int visited[max], count, mindist, nextnode, i, j;
	for ( i = 0; i < n; i++ )
		for ( j = 0; j < n; j++ )
			if ( G[i][j] == 0 )
				G[i][j] = 999; //999 represents infinite distance
	for ( i = 0; i < n; i++ )
	{
		dist[i] = G[startnode][i];
		pred[i] = startnode;
		visited[i] = 0;
	}
	dist[startnode] = 0;
	visited[startnode] = 1;
	count = 1;
	while ( count < n - 1 )
	{
		mindist = 999;
		for ( i = 0; i < n; i++ )
			if ( dist[i] < mindist && !visited[i] )
			{
				mindist = dist[i];
				nextnode = i;
			}
		visited[nextnode] = 1;
		for ( i = 0; i < n; i++ )
			if ( !visited[i] )
				if ( mindist + G[nextnode][i] < dist[i] )
				{
					dist[i] = mindist + G[nextnode][i];
					pred[i] = nextnode;
				}
		count++;
	}
	for ( i = 0; i < n; i++ )
		if ( i != startnode )
		{
			cout << "\nDistance of node " << i << " = " << dist[i];
			cout << "\nPath: " << i;
			j = i;
			do
			{
				j = pred[j];
				cout << " <--- " << j;
			}
			while ( j != startnode );
		}
}


int main()
{
	int G[max][max] =
	{
		{0, 1, 0, 3, 10},
		{1, 0, 5, 0, 0},
		{0, 5, 0, 2, 1},
		{3, 0, 2, 0, 6},
		{10, 0, 1, 6, 0}
	};
	int n = 5;
	int u = 0;
	dijkstra ( G, n, u );
	return 0;
}
