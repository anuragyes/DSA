

/*

class Solution
{
    public:
    //Function to return the sorted array.
    vector <int> nearlySorted(int arr[], int num, int K){


        //  optimal approch
        vector<int> ans;
        priority_queue<int,vector<int>,greater<int>> pq;

        int i = 0;
        while(i < num){
            while(pq.size() > K){
                ans.push_back(pq.top());
                pq.pop();
            }
            pq.push(arr[i]);
            i++;
        }

        while(!pq.empty()){
            ans.push_back(pq.top());
            pq.pop();
        }

        return ans;
        /*
         brute force approch
     priority_queue <int, vector<int>, greater<int>> pq;
      vector<int>ans;
      for(int i=0;i<num;i++){
          pq.push(arr[i]);
      }

       while(!pq.empty()){
           ans.push_back(pq.top());
           pq.pop();

       }
        return ans;
        */
//     }
// };
// */
// */