/*
input:
4 4
0 1
0 2
1 3
2 3

output:
2 
path-> 0 1 3
path-> 0 2 3
*/

//TC : O(V+E)
//SC : O(V)

#include<bits/stdc++.h>
#define int long long int
using namespace std;

void dfs(int src,int dest,vector<vector<int>> &adjList,vector<int> &curPath,vector<vector<int>> &allPath){
	curPath.push_back(src);

	if(src==dest){
		allPath.push_back(curPath);
		return;
	}

	for(auto node:adjList[src]){
		dfs(node,dest,adjList,curPath,allPath);
		curPath.pop_back();
	}
}

int32_t main(){
	int n,e;
	cin>>n>>e;

	vector<vector<int>> adjList(n,vector<int>());
	for(int i=0;i<e;i++){
		int u,v;
		cin>>u>>v;
		adjList[u].push_back(v);
		//adjList[v].push_back(u);
	}

	vector<int> curPath;
	vector<vector<int>> allPath;

	dfs(0,n-1,adjList,curPath,allPath);

	for(int i=0;i<allPath.size();i++){
		for(int j=0;j<allPath[i].size();j++){
			cout<<allPath[i][j]<<" ";
		}
		cout<<"\n";
	}

	return 0; 
}

