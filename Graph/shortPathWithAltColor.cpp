/*
You are given an integer n, the number of nodes in a directed graph where the nodes are labeled from 0 to n - 1. 
Each edge is red or blue in this graph, and there could be self-edges and parallel edges.

You are given two arrays redEdges and blueEdges where:
redEdges[i] = [ai, bi] indicates that there is a directed red edge from node ai to node bi in the graph, and
blueEdges[j] = [uj, vj] indicates that there is a directed blue edge from node uj to node vj in the graph.
Return an array answer of length n, where each answer[x] is the length of the shortest path from node 0 to node x 
such that the edge colors alternate along the path, or -1 if such a path does not exist.

Input: n = 3, redEdges = [[0,1]], blueEdges = [[2,1]]
Output: [0,1,-1]
*/

/*
Approach: Breadth First Search
Intuition
A breadth-first search is a good algorithm to use if we want to find the shortest path in an unweighted graph. 
The property of BFS is that the first time a node is reached during the traversal, it was reached in the minimum possible steps from the source.
The path used in BFS traversal always has the least number of edges. 

The BFS algorithm does a level-wise iteration of the graph. As a result, it first finds all paths that are one edge away from the source node, 
followed by all paths that are two edges away from the source node, and so on. This allows BFS to find the shortest path in terms of steps 
from the source node to any other node. 
We can use the BFS algorithm here as well, with some modifications.
*/

/*
Algorithm
1. Create an adjacency list adj that contains a list of pairs of integers such that adj[node] contains the neighbors of node in the form (neighbor, color) 
where neighbor is the neighbor of node and color denotes the edge color that connects node and neighbor. We use the number 0 for red and the number 1 for blue.
2. Create a answer array with the value -1 where answer[i] is the answer for the ith node.
3. Create a 2D visit array in which visit[node][color] indicates whether node has yet been visited using an edge of color.
4. Create a queue of triplets. It will save three integers per triplet: 
    a) the current node, 
    b) the steps taken to visit the node, and 
    c) the color of the previous edge used. 
    The node 0 has 0 steps and no specific color of visit, we can use -1 as the color. 
    We also set visit[0][0] and visit[0][1] to true because visiting node 0 again is pointless.
5. While the queue is not empty:
    Remove the first element out of the queue to obtain [node, steps, prevColor].
    Loop through all (neighbor, color) pairs in adj[node]. If a neighbor has not yet been visited with a color edge and color != prevColor, we visit neighbor with the color edge by pushing [neighbor, steps + 1, color] in the queue. If this is neighbor's first visit, i.e., answer[neighbor] == -1, we set answer[neighbor] = steps + 1.
6. Return answer.

*/

vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& redEdges, vector<vector<int>>& blueEdges) {
    vector<vector<pair<int, int>>> adj(n);
    for (auto& redEdge : redEdges) {
        adj[redEdge[0]].push_back({redEdge[1], 0});
    }
    for (auto& blueEdge : blueEdges) {
        adj[blueEdge[0]].push_back(make_pair(blueEdge[1], 1));
    }

    vector<int> answer(n, -1);
    vector<vector<bool>> visit(n, vector<bool>(2));
    queue<vector<int>> q;

    // Start with node 0, with number of steps as 0 and undefined color -1.
    q.push({0, 0, -1});
    visit[0][1] = visit[0][0] = true;
    answer[0] = 0;

    while (!q.empty()) {
        auto element = q.front();
        int node = element[0], steps = element[1], prevColor = element[2];
        q.pop();

        for (auto& [neighbor, color] : adj[node]) {
            if (!visit[neighbor][color] && color != prevColor) {
                visit[neighbor][color] = true;
                q.push({neighbor, 1 + steps, color});
                if (answer[neighbor] == -1) answer[neighbor] = 1 + steps;
            }
        }
    }
    return answer;
}

