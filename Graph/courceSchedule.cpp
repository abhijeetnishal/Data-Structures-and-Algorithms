/*
Cource Schedule - 1:
There are a total of numCourses courses you have to take, labeled from 0 to numCourses - 1. You are given an array prerequisites where 
prerequisites[i] = [ai, bi] indicates that you must take course bi first if you want to take course ai.

For example, the pair [0, 1], indicates that to take course 0 you have to first take course 1.
Return true if you can finish all courses. Otherwise, return false.

*/
//using Kahn's algorithm
bool isCycle(int n, vector<vector<int>> &graph){
        vector<int> indeg(n, 0);
        for(int i=0; i<n; i++){
        for(int j=0; j<graph[i].size(); j++){
            indeg[graph[i][j]]++;
        }
        }

        int ans=0;
        queue<int> q;
        for(int i=0; i<n; i++){
            if(indeg[i]==0){
                ans++;
                q.push(i);
            }
        }

    unordered_set<int> vis;
    while(!q.empty()){
        int fr=q.front();
        q.pop();

        if(vis.find(fr)!=vis.end())
            continue;
        vis.insert(fr);

        for(auto neigh:graph[fr]){
            indeg[neigh]--;
            if(indeg[neigh]==0){
                ans++;
                q.push(neigh);
            }
        }
    }

    if(n==ans)
        return false;
    else
        return true;
}

bool canFinish(int numCourses, vector<vector<int>> &prerequisites) {
    vector<vector<int>> graph(numCourses);

    for(int i=0; i<prerequisites.size(); i++){
        graph[prerequisites[i][0]].push_back(prerequisites[i][1]);
    }

    if(isCycle(numCourses, graph))
        return false;
    else
        return true;
}



/*
Cource Schedule - 2:
There are a total of numCourses courses you have to take, labeled from 0 to numCourses - 1. You are given an array prerequisites where 
prerequisites[i] = [ai, bi] indicates that you must take course bi first if you want to take course ai.

For example, the pair [0, 1], indicates that to take course 0 you have to first take course 1.
Return the ordering of courses you should take to finish all courses. If there are many valid answers, return any of them. 
If it is impossible to finish all courses, return an empty array.

Input: numCourses = 4, prerequisites = [[1,0],[2,0],[3,1],[3,2]]
Output: [0,2,1,3]
Explanation: There are a total of 4 courses to take. To take course 3 you should have finished both courses 1 and 2. 
Both courses 1 and 2 should be taken after you finished course 0.
So one correct course order is [0,1,2,3]. Another correct ordering is [0,2,1,3].
*/

bool isCycle(int n, vector<vector<int>> &graph, vector<int> &topoSort){
    vector<int> indeg(n, 0);
    for(int i=0; i<n; i++){
        for(int j=0; j<graph[i].size(); j++){
            indeg[graph[i][j]]++;
        }
    }

    int ans=0;
    queue<int> q;
    for(int i=0; i<n; i++){
        if(indeg[i]==0){
            ans++;
            q.push(i);
        }
    }

    unordered_set<int> vis;
    while(!q.empty()){
        int fr=q.front();
        q.pop();

        topoSort.push_back(fr);

        if(vis.find(fr)!=vis.end())
            continue;
        vis.insert(fr);

        for(auto neigh:graph[fr]){
            indeg[neigh]--;
            if(indeg[neigh]==0){
                ans++;
                q.push(neigh);
            }
        }
    }
    if(ans==n)
        return false;
    else
        return true;
}

vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
    if(numCourses==1)
        return {0};
    
    vector<int> topoSort;

    vector<vector<int>> graph(numCourses);
    for(int i=0; i<prerequisites.size(); i++){
        graph[prerequisites[i][1]].push_back(prerequisites[i][0]);
    }

    if(isCycle(numCourses, graph, topoSort))
        return {};
    else
        return topoSort;
}