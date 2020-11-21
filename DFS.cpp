#include<bits/stdc++.h>
using namespace std;

template<class T>
class Graph{
    private:
    map< T , list<T> > adjList;
    map< T , bool> visited;
    public:
    Graph(){}
    void addEdge(T s,T d)
    {
        adjList[s].push_back(d);
    }

    void dfs(T node){
        visited[node] = true;
        cout<< node <<"--> ";

        for(T n : adjList[node]){
            if(!visited[n])
                dfs(n);
        }
    }
    void print(){
        for(auto i : adjList){
            cout<<i.first<<"-->";
            for(T node : i.second){
                cout<<node<<"-->";
            }
            cout<<"NULL";
            cout<<endl;
        }
    }
};

int main(){
    Graph<int>g;
    g.addEdge(0,1);
	g.addEdge(1,2);
	g.addEdge(0,4);
	g.addEdge(2,4);
	g.addEdge(2,3);
	g.addEdge(3,4);
	g.addEdge(3,5);	
    cout<<"Printing the adjacency list:\n";
    g.print();
    cout<<endl;
    cout<<"Depth first Search:\n";
	g.dfs(0);

    return 0;
}