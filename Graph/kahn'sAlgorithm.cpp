/*
Used to find cycle using BFS.(previous graph coloring concept for finding cycle using DFS)
APPROACH:
1. Calculate the indegree of every vertex and create a variable ans=0 and queue<int> q.
2. Find the vertex with indegree 0 and push that vertex into queue and increament ans by 1.
3. Now apply bfs on that vertex whose indegree is 0.
4. If indegree of current vertex is then push into queue and increment ans by 1.
5. Finally if number of vertex is not equal to ans then cycle is present else no cycle.

*/
bool isCycle(int n, vector<vector<int>> &graph){
    vector<int> indeg(n,0);

    for(int i=0; i<graph.size(); i++){
        for(auto node:graph[i]){
            indeg[node]++;
        }
    }

    int ans=0;
    queue<int> q;

    for(int i=0; i<n; i++){
        if(indeg[i]==0){
            q.push(i);
            ans++;
        }
    }

    unordered_set<int> vis;
    while(!q.empty()){
        int curVertex=q.front();
        q.pop();

        if(vis.find(curVertex)!=vis.end())
            continue;
        vis.insert(curVertex);

        for(auto neigh:graph[curVertex]){
            indegree[neigh]--;

            if(indeg[neigh]==0){
                q.push(neigh);
                ans++;
            }
        }
    }

    if(ans==n)
        return false;
    else
        return true;
}