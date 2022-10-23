// TC : O(V+E)
// SC : O(V)

#include<bits/stdc++.h>
#define int long long int
using namespace std;

void bfs(int src,vector<vector<int>> &adjList,vector<bool> &vis,vector<int> &bfsTrav){
	queue<int> q;

	q.push(src);

	while(!q.empty()){
		int front_val=q.front();
		q.pop();

		vis[front_val]=true;
		bfsTrav.push_back(front_val);

		for(auto node:adjList[front_val]){
			if(!vis[node]){
				q.push(node);
				vis[node]=true;
			}
		}
	}
}

int32_t main(){
	int n,e;
	//n nodes, e edges

	cin>>n>>e;

	vector<vector<int>> adjList(n,vector<int>());
	//created graph for 0 to n-1 nodes for 1 to n change n to n+1 size.

	for(int i=0;i<e;i++){
		int u,v;
		cin>>u>>v;
		adjList[u].push_back(v);
		adjList[v].push_back(u);      //add this line for undirected graph
	}

	//creating visited array
	vector<bool> vis(n,false);

	vector<int> bfsTrav;

	bfs(1,adjList,vis,bfsTrav);

	cout<<"BFS Traversal order:\n";
	for(auto val:bfsTrav)
		cout<<val<<" ";

	return 0; 
}

