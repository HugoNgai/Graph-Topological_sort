#include<iostream>
#include<list>
#include<queue>
using namespace std;

class Graph
{
	int vex;    									//the numbers of vertex
	list<int> *adj;									//the linklist array
	queue<int> q;									//the queue using to store the vertex with 0 indegree
	int *indegree;									//use to count the indegree

public:
	Graph(int vex);										
	~Graph();
	void addEdge(int v,int w);
	bool Topological_sort();
};

Graph::Graph(int vex)
{
	this->vex=vex;
	adj=new list<int>[vex];
	indegree=new int[vex];
	for (int i=0;i<vex;i++)
		indegree[i]=0;
}

Graph::~Graph()
{
	delete [] adj;
	delete [] indegree;
}

void Graph::addEdge(int v,int w)
{
	adj[v].push_back(w);
	++indegree[w];
}

bool Graph::Topological_sort()
{
	for (int i=0;i<vex;i++)							//all of the vertex with 0 indegree enqueue
		if (indegree[i]==0)
			q.push(i);

	int count=0;

	while (!q.empty())
	{	
		++count;
		int v = q.front();
		q.pop();
		if (count==vex)
			cout<<v;
		else
			cout<<v<<"->";
		
		list<int>::iterator beg = adj[v].begin();
		for ( ;beg!=adj[v].end();beg++)
			if (!(--indegree[*beg]))
				q.push(*beg);
	}

	if (count<vex)
		return false;
	else 
		return true;
}

int main(void)
{
	Graph g(6);
	g.addEdge(5,2);
	g.addEdge(5,0);
	g.addEdge(4,0);
	g.addEdge(4,1);
	g.addEdge(2,3);
	g.addEdge(3,1);

	g.Topological_sort();
	return 0;
}
