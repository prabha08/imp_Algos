/*
BOTTOM

We will use the following (standard) definitions from graph theory. Let V be a non-empty and finite set, its elements being called vertices (or nodes). Let E be a subset of the Cartesian product V×V, its elements being called edges. Then G=(V,E) is called a directed graph.

Let n be a positive integer, and let p=(e1,…,en) be a sequence of length n of edges ei∈E such that ei=(vi,vi+1)for a sequence of vertices (v1,…,vn+1). Then p is called a path from vertex v1 to vertex vn+1 in G and we say that vn+1 is reachable from v1, writing (v1→vn+1).

Here are some new definitions. A node v in a graph G=(V,E) is called a sink, if for every node w in G that is reachable from v, v is also reachable from w. The bottom of a graph is the subset of all nodes that are sinks, i.e., bottom(G)={v∈V∣∀w∈V:(v→w)⇒(w→v)}. You have to calculate the bottom of certain graphs.
Input Specification
The input contains several test cases, each of which corresponds to a directed graph G. Each test case starts with an integer number v, denoting the number of vertices of G=(V,E) where the vertices will be identified by the integer numbers in the set V={1,…,v}. You may assume that 1≤v≤5000. That is followed by a non-negative integer e and, thereafter, e pairs of vertex identifiers v1,w1,…,ve,we with the meaning that (vi,wi)∈E. There are no edges other than specified by these pairs. The last test case is followed by a zero.
Output Specification
For each test case output the bottom of the specified graph on a single line. To this end, print the numbers of all nodes that are sinks in sorted order separated by a single space character. If the bottom is empty, print an empty line.
Sample Input
3 3
1 3 2 3 3 1
2 1
1 2
0
Sample Output
1 3
2

*/

#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> adjList, adjListT;
vector<unordered_set<int>> components;
bool * visited;
stack<int> finishVertex;
int v, e; 

void dfs(int st){
   	 visited[st] = true;
    
    for(auto& a: adjList[st]) {
        if(visited[a]) continue;
        dfs(a);
    }
    finishVertex.push(st);
}

void dfs2(int st){
     visited[st] = true;
    components[components.size()-1].insert(st);
    for(auto& a: adjListT[st]) {
        if(visited[a]) continue;
        dfs2(a);
    }
}

void printBotton() {
    vector<int> ans;
    for(auto& a: components) {
        bool bot = true;
        for(auto& b: a) {
            for(auto& e: adjList[b]) {
                if(a.find(e) == a.end()) {
                    bot = false;
                    break;
                }
            }
            if(bot == false) break;
        }
       
        if(bot) {
        for(auto& b: a) {
            ans.push_back(b+1);
        }
        }
    }
    sort(ans.begin(), ans.end());
    for(int i=0; i<ans.size(); ++i) cout<<ans[i]<<" ";
}

void getSCC()
{
	//kosaraju's 
    for(int i=0; i<v; ++i) {
        visited[i] = false;
    }
    for(int i=0; i<v; ++i) {
    	if(visited[i]) continue; //cout<<i;
        dfs(i);
    }
    for(int i=0; i<v; ++i) {
        visited[i] = false;
    }
   
    while(!finishVertex.empty()) {
        int i = finishVertex.top(); //cout<<i;
        finishVertex.pop();
        components.push_back(unordered_set<int>());
    	if(visited[i]) continue;
    	dfs2(i);
    }
}

int main()
{ 
    while(1) {
        cin>>v;
        if(v==0) {
            break;
        }
        cin>>e;
        for(int i=0; i<v; ++i) {
            adjList.push_back(vector<int>());
            adjListT.push_back(vector<int>());
        }
        while(e--) {
            int x, y; cin>>x>>y;
            adjList[x-1].push_back(y-1);    
            adjListT[y-1].push_back(x-1);            
        }
        
        visited = new bool[v];
        getSCC();
        printBotton();
        adjList.clear();
        adjListT.clear();
        components.clear();
        cout<<endl;
    }
	return 0;
}
