/*
Detect cycle is present or not in a directed graph.

Approach: (i am using coloring concept)
1. choose 3 colors-> 0, 1, 2.
   0-> unprocessed
   1-> processing
   2-> processed
2. Initially all nodes color is 0 i.e. all nodes are unprocessed.
3. whenever we visit node first time, change the color to 1 i.e. processing node.
4. whenever we backtrack:
    if we find color to be 1 then return true as cycle is present because we already traversing the 
    processing node and again we visit means loop.
    else change color to 2 means processed and return false.

*/

//TC: O(V+E) SC:O(V)
bool isCycle( vector<vector<int>>& adj, vector<int> &vis, int src){
        vis[src]=1;

        for(auto node:adj[src]){
        if(vis[node]==1)
            return true;
            
        if(vis[node]!=2){
            if(isCycle(adj, vis, node))
                return true;
            }
        }

        vis[src]=2;
        return false;
}