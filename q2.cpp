// // Write a function to find the shortest path from a source vertex to all 
// other vertices in a graph using Dijkstra's algorithm.
// // Sample Test Case
// // Input: graph = {0: {1: 4, 2: 1},
//  1: {3: 1}, 
//  2: {1: 2, 3: 5}, 
//  3: {}}, 
//  source = 0 Output: {0: 0, 1: 3, 2: 1, 3: 4}


#include <iostream>
#include <vector>
#include <queue>
#include<unordered_map>
#include<climits>
using namespace std;

typedef pair<int, int>pii;

unordered_map<int, int>dijikstra(unordered_map<int, unordered_map<int, int>>&graph, int source){
priority_queue<pii,
vector<pii>, greater<pii>>pq;

unordered_map<int, int>dist;
for(const auto &node : graph){
    dist[node.first] = INT_MAX;
}
pq.push(make_pair(0,source));
dist[source] = 0;

while (!pq.empty()){
int u = pq.top().second;
pq.pop();

    for(const auto &neighbor : graph[u]){
        int v = neighbor.first;
        int weight = neighbor.second;

        if(dist[v]>dist[u]+weight){
            pq.push(make_pair(dist[v],v));
        }
    }
    return dist;
}



}

int main(){
          unordered_map<int, unordered_map<int, int>> graph ={
            {0, {{1,4},{2,1}}},
            {1, {{3,1}}},
            {2, {{1,2},{3,5}}},
            {3, {}}

          };
          int source = 0;

          unordered_map<int, int>distance = dijikstra(graph, source);
          cout<<"Vertex Distance from source "<<endl;
          for(const auto &dist:distance){
            cout << dist.first<<"\t\t"<<dist.second <<endl;
            
          }


          
    return 0;
}