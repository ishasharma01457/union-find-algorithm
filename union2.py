from collections import defaultdict


class Graph:

	def __init__(self, vertx):
		self.vertx = vertx
		self.edges = defaultdict(list)

	
	def edge(self, u, v):
		self.edges[u].append(v)


class Sub:
	def __init__(self, rank, root):
		self.root = root
		self.rank = rank




def find(subset, node):
	if subset[node].root != node:
		subset[node].root = find(subset, subset[node].root)
	return subset[node].root




def union(subset, u, v):

	 
	if subset[u].rank > subset[v].rank:
		subset[v].root = u
	elif subset[v].rank > subset[u].rank:
		subset[u].root = v

	
	else:
		subset[v].root = u
		subset[u].rank += 1




def loop(graph):

	
	subset = []

	for u in range(graph.vertx):
		subset.append(Sub(u, 0))

	
	for u in graph.edges:
		u_rep = find(subset, u)

		for v in graph.edges[u]:
			v_rep = find(subset, v)

			if u_rep == v_rep:
				return True
			else:
				union(subset, u_rep, v_rep)



g = Graph(3)


g.edge(0, 1)


g.edge(1, 2)


g.edge(0, 2)

g.edge(1, 0)

if loop(g):
	print('Graph contains cycle')
else:
	print('Graph does not contain cycle')
