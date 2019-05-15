#include<iostream>
#include<list>
using namespace std;

class Graph
{
    int V;
    list<int> *adjList;
public:
    Graph(int v)
    {
        V=v;
        adjList=new list<int>[v];
    }

    void addEdge(int u, int v, bool directed=true)
    {
        adjList[u].push_back(v);

        if(directed)
        {
            adjList[v].push_back(u);
        }
    }

    void printAdjList()
    {
        for(int i=0;i<V;++i)
        {
            cout<<i<<"-->";
            int j=0;
            for(auto a=adjList[i].begin();a!=adjList[i].end();++a)
            {
                j++;
                if(j!=(adjList[i].size())) cout<<adjList[i].back()<<",";
                else cout<<adjList[i].back();
            }
            cout<<endl;
        }
    }


};

int main()
{
    Graph g(4);
    g.addEdge(0,1);
    g.addEdge(0,2);
    g.addEdge(1,3);
    g.addEdge(3,2);
    g.addEdge(3,0);

    g.printAdjList();

}
