#include<iostream>
#include<list>

using namespace std;

class graph
{
private:
	int v;
	list <int> *ptr;
	void dfs_visit(int , bool[]);
public:
	graph(int);
	void addedge(int w, int x);
	void dfs(int);
};

graph::graph(int x)
{
	v = x;
	ptr = new list<int>[v];
}

void graph::addedge(int w, int x)
{
	ptr[w].push_back(x);
}

void graph::dfs_visit(int x, bool visited[])
{
	visited[x] = true;
	cout << "  " << x;

	list <int> ::iterator i;

	for (i = ptr[x].begin();i != ptr[x].end();i++)
	{
		if (!visited[*i])
		{
			dfs_visit(*i, visited);
		}
	}
}

void graph::dfs(int x)
{
	bool *visited = new bool[v];
	for (int i = 0;i < v;i++)
	{
		visited[i] = false;
	}

	dfs_visit(x, visited);

}

void main()
{
	graph g(5);
	g.addedge(0, 1);
	g.addedge(0, 2);
	g.addedge(2, 3);
	g.addedge(1, 3);
	g.addedge(3, 4);
	g.dfs(0);

}