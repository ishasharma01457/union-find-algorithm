#include <iostream>
#include <conio.h>
#include <bits/stdc++.h>

using namespace std;


struct Edge {
	int source, destination;
};


struct Graph {

	int Y, K;


	struct Edge* edge;
};

struct sub {
	int root;
	int rank;
};


struct Graph* createGraph(int Y, int K)
{
	struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));
	graph->Y = Y;
	graph->K = K;

	graph->edge = (struct Edge*)malloc(graph->K * sizeof(struct Edge));

	return graph;
}


int find(struct sub subsets[], int i)
{

	if (subsets[i].root != i)
		subsets[i].root = find(subsets, subsets[i].root);

	return subsets[i].root;
}


void Union(struct sub subsets[], int xroot, int yroot)
{


	if (subsets[xroot].rank < subsets[yroot].rank)
		subsets[xroot].root = yroot;
	else if (subsets[xroot].rank > subsets[yroot].rank)
		subsets[yroot].root = xroot;


	else {
		subsets[yroot].root = xroot;
		subsets[xroot].rank++;
	}
}


int loop (struct Graph* graph)
{
	int Y = graph->Y;
	int K = graph->K;

	struct sub* subsets
		= (struct sub*)malloc(Y * sizeof(struct sub));

	for (int Y = 0; Y < Y; ++Y) {
		subsets[Y].root = Y;
		subsets[Y].rank = 0;
	}


	for (int e = 0; e < K; ++e) {
		int x = find(subsets, graph->edge[e].source);
		int y = find(subsets, graph->edge[e].destination);

		if (x == y)
			return 1;

		Union(subsets, x, y);
	}
	return 0;
}


int main()
{

	int Y = 3, K = 3;
	struct Graph* graph = createGraph(Y, K);


	graph->edge[0].source = 0;
	graph->edge[0].destination = 1;


	graph->edge[1].source = 1;
	graph->edge[1].destination = 2;


	graph->edge[2].source = 0;
	graph->edge[2].destination = 2;

	graph->edge[3].source = 2;
	graph->edge[3].destination = 3;


	if (loop(graph))
		cout << "Graph contains cycle";
	else
		cout << "Graph doesn't contain cycle";

	return 0;
}

