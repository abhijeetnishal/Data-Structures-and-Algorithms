/*
There is a bi-directional graph with n vertices, where each vertex is labeled from 0 to n - 1 (inclusive). 
The edges in the graph are represented as a 2D integer array edges, where each edges[i] = [ui, vi] denotes a bi-directional edge
between vertex ui and vertex vi. Every vertex pair is connected by at most one edge, and no vertex has an edge to itself.

You want to determine if there is a valid path that exists from vertex source to vertex destination.
Given edges and the integers n, source, and destination, return true if there is a valid path from source to destination, or false otherwise.

Input: n = 3, edges = [[0,1],[1,2],[2,0]], source = 0, destination = 2
Output: true
Explanation: There are two paths from vertex 0 to vertex 2:
- 0 → 1 → 2
- 0 → 2
*/

//TC: O(V+E)  SC:O(V+E)
bool isPathExist(int src, int dest, vector<bool> &vis, vector<vector<int>> &graph){
    if(src==dest)
        return true;
    vis[src]=true;

    for(auto node:graph[src]){
        if(!vis[node]){
            if(isPathExist(node,dest,vis,graph))
                return true;
        }
    }
    return false;
} 

bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
    vector<vector<int>> graph(n,vector<int>());

    for(int i=0;i<edges.size();i++){
        graph[edges[i][0]].push_back(edges[i][1]);
        graph[edges[i][1]].push_back(edges[i][0]);
    }

    vector<bool> vis(n,false);
    return isPathExist(source,destination,vis,graph);
}