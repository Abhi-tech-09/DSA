
#include <bits/stdc++.h>
using namespace std;

map<int , list<int>> adjlist;
void addEdge(int s, int d){
    adjlist[s].push_back(d);
}

void dfs(int node){
    map<int,int>visited;
    stack<int>s;
    s.push(node);
    visited[node] =  1;

    while(!s.empty()){
        int t = s.top();
        s.pop();
        cout << t <<" ";

        for(int n : adjlist[t]){
            if(!visited[n]){
                s.push(n);
                visited[n] = 1;
            }
        }
    }

}

int main() {
    addEdge(1,2);
    addEdge(2,4);
    addEdge(1,3);
    dfs(1);
}
