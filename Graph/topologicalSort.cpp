/*
Topological sorting for Directed Acyclic Graph (DAG) is a linear ordering of vertices such that for every directed edge u v, 
vertex u comes before v in the ordering.
Note: Topological Sorting for a graph is not possible if the graph is not a DAG.

Use Kahn's Algorithm and add node to toposort array while performing bfs to get the sorted order if cycle is not present.
*/
vector<int> topoSort(vector<vector<int>> &edges, int v){
    vector<vector<int>> graph;
    for(int i=0; i<edges.size(); i++){
        graph[edges[i][0]].push_back(edges[i][1]);
    }

    vector<int> indegree(n,0);
    for(int i=0; i<n; i++){
        for(int j=0; j<graph[i].size(); j++){
            indegree[graph[i][j]]++;
        }
    }

    int ans=0;
    queue<int> q;
    for(int i=0; i<n; i++){
        if(indegree[i]==0){
            q.push(i);
            ans++;
        }
    }

    unordered_set<int> vis;
    vector<int> topoSortArr;
    while(!q.empty()){
        int fr=q.front();
        q.pop();

        topoSortArr.push_back(fr);

        if(vis.find(fr)!=vis.end())
            continue;
        vis.insert(fr);

        for(auto neigh:graph[fr]){
            indegree[neigh]--;
            if(indegree[neigh]==0){
                ans++;
                q.push(neigh);
            }
        }
    }

    if(ans==n)
        return topoSortArr;
    //else cycle is present
}