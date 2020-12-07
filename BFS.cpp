
#include <bits/stdc++.h>
using namespace std;
//With BFS we can find shortest path in unweighted graph
map<int , list<int>> adjlist;
void addEdge(int s, int d){
    adjlist[s].push_back(d);
}

void bfs(int node){
    map<int,int>visited;
    visited[node] = 1;
    queue<int>q;
    q.push(node);

    while(!q.empty()){
        int node = q.front();
        cout<<node<<" ";
        q.pop();

        for(int n : adjlist[node]){
            if(!visited[n]){
                q.push(n);
                visited[n] = 1;
            }
        }
    }

}

int main() {
    addEdge(0,1);
	addEdge(1,2);
	addEdge(0,4);
	addEdge(2,4);
	addEdge(2,3);
	addEdge(3,5);
	addEdge(3,4);
    bfs(0);
}
