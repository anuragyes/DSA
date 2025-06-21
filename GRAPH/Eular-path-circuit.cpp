/*class Solution {
public:

 void  dfs(int node , vector<int>adj[],vector<bool>&visited){
      visited[node]= 1;
      
       for(int i =0;i<adj[node].size();i++){
            if(!visited[adj[node][i]]){
                dfs(adj[node][i],adj,visited);
            }
       }
 }
	int isEulerCircuit(int V, vector<int>adj[]){
	   //   when  the deg is not an even 
	    int odd = 0;
	   // find degree of every node 
	    vector<int>deg(V);
	     for(int i =0;i<V;i++){
	          deg[i] = adj[i].size();
	           if(deg[i]%2!=0)
	           odd++;
	     }
	     
	   //   case when not eular not curcite or when deg is odd present
	    if(odd!=2 && odd!=0) return 0;
	    
	   //   dfs function
	    vector<bool>visited(V,0);
	     for(int i =0;i<V;i++){
	          if(deg[i]){
	               dfs(i,adj,visited);
	               // if there are many components are present 
	                break;
	          }
	     }
	     
	   //   after visitng all node but still  few nodes are not visited  
	   //  means not a Eulerian Path not be Eulerian circuit
	     for(int i =0;i<V;i++){
	         if(deg[i]&&!visited[i])
	             return 0;
	         
	     }
	   //  if  Eulerian Path
	    if(odd==0) return 2;
	    
	   // if  Eulerian circuit 
	   else 
	    return 1;
	     
	      
	}
};
*/

//  prof
// Eular Circuit
//  case 1; every and each node should be component of single graph 
//  case2 : every and each node have even degree 
//  case 3; if odd degree is present return not a eular circuit


//   Eular path 
priority_queue<pair<int,int>>,vector<pair<int,<pair<int,int>>>, greater<pair<int,int>>q;