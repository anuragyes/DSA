/*
//   TOPOLOGICAL SORT 
 void dfs(int node, vector<pair<int,int>>adj[],stack<int>&st, vector<bool>&visited){
      visited[node] = 1;
          for(int i =0;i<adj[node].size();i++)
          {
          
            if(!visited[adj[node][i]].first){
             dfs(adj[node][i],visited,adj);
            }
          }
           st.push(node);
 }

vector<int> shortestPathInDAG(int n, int m, vector<vector<int>> &edges)
{
   vector<pair<int,int>>adj[N];
    for(int i =0;i<M;i++){
        int u = edges[i][0];
         int v = edges[i][1];
          int weight = edges[i][2];
           adj[u].push_back(make_pair(v,weight));

            // topologicalSort 

            

  stack<int>st;
  vector<bool>visited(N,0);
  dfs(0,adj,st,visited);
  vector<int>distance(N,INT_MAX);
  distance[0]=0;
  while(!st.empty()){
   int node = st.top();
   st.pop();
     for(int i =0;i<adj[node].size();i++){
           int neg = adj[node][i].first;
           int weight = adj[node][i].second;

            distance[node]=min(distance[neg],weight+distance[node])
     }
   }
2
 for(int i =0;i<N;i++){
  if(distance[i]==INT_MAX)
  INT_MAX = -1;
 }
 return distance;


    }
}*/