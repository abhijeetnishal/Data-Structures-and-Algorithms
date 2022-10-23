// TC : O(V+E)
// SC : O(V)

#include<bits/stdc++.h>
#define int long long int
using namespace std;

void dfs(int src,vector<vector<int>> &adjList,vector<bool> &vis,vector<int> &dfsTrav){
	vis[src]=true;
	
	dfsTrav.push_back(src);

	for(auto node:adjList[src]){
		if(!vis[node]){
			dfs(node,adjList,vis,dfsTrav);
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
		adjList[v].push_back(u);       //add this line for undirected graph
	}

	//creating visited array
	vector<bool> vis(n,false);

	vector<int> dfsTrav;

	dfs(0,adjList,vis,dfsTrav);

	cout<<"DFS Traversal order:\n";
	for(auto val:dfsTrav)
		cout<<val<<" ";

	return 0; 
}

