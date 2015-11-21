#include<iostream>
#include<list>
#include<queue>
using namespace std;

class Graph{
    int V;
    list<int> *adj;
    public:
    Graph(int n){
        V=n;
        adj = new list<int>[n];
    }
    void addEdge(int u, int v){
        adj[u].push_back(v);
    }
    void BFS(int s){
        bool *isVisited = new bool[V];
        for(int i=0;i<V;i++)
            isVisited[i] = false;
        
        queue<int> q;
        q.push(s);
        isVisited[s] = true;
        
        while(!q.empty()){
            s = q.front();
            cout<<s<<" ";
            q.pop();
            
            for(list<int>::iterator ii = adj[s].begin(); ii != adj[s].end(); ii++){
                if(!isVisited[*ii]){
                    isVisited[*ii] = true;
                    q.push(*ii);
                }
            }
        }
    }
};

int main(){
    Graph g(4);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(2, 0);
    g.addEdge(2, 3);
    g.addEdge(3, 3);
    
    g.BFS(2);

    return 0;
}
