
/*

class Solution {
public:
	bool isPossible(int N,int P, vector<pair<int, int> >& prerequisites) {
	       //  make adjancy list
     //  make adjancy list
          vector<int>adj[N];
              //  find indegree
              vector<int>indegree(N,0);
           for(int i=0;i<P;i++)
           {
             adj[prerequisites[i].second].push_back(prerequisites[i].first);
            indegree[prerequisites[i].first]++;
           }
            // kahn's algo
             queue<int>q;
               for(int i=0;i<N;i++)
               
                //  indegree == 0 qush into the queue
                 if(indegree[i]==0) q.push(i);
                 int cnt = 0 ;
                  while(!q.empty())
                  {
                     int node = q.front();
                      q.pop();
                      cnt++;

                    //    look at the neg
                     for(int j = 0; j<adj[node].size();j++)
                     {
                            //  queue ke front mai hai usko decrease krdo 
                        indegree[adj[node][j]]--; 
                   
                         if(indegree[adj[node][j]]==0) q.push(adj[node][j]);
                     }
                  
                   }

  return  cnt==N;



	}
};
*/