

/*Given two equally sized 1-D arrays A, B containing N integers each.

A sum combination is made by adding one element from array A and another element of array B.

Return the maximum C valid sum combinations from all the possible sum combinations.
*/

vector<int> Solution::solve(vector<int> &A, vector<int> &B, int C)
{
    // optimal approch

    int N = A.size();
    int M = B.size();

    // Sort both arrays in descending order
    sort(A.rbegin(), A.rend());
    sort(B.rbegin(), B.rend());

    vector<int> ans;
    priority_queue<pair<int, pair<int, int>>> pq; // {sum, {i,j}}
    set<pair<int, int>> visited;

    // Push the largest sum
    pq.push({A[0] + B[0], {0, 0}});
    visited.insert({0, 0});

    while (C-- && !pq.empty())
    {
        auto top = pq.top();
        pq.pop();
        ans.push_back(top.first);
        int i = top.second.first;
        int j = top.second.second;

        // Next pair: (i+1, j)
        if (i + 1 < N && !visited.count({i + 1, j}))
        {
            pq.push({A[i + 1] + B[j], {i + 1, j}});
            visited.insert({i + 1, j});
        }

        // Next pair: (i, j+1)
        if (j + 1 < M && !visited.count({i, j + 1}))
        {
            pq.push({A[i] + B[j + 1], {i, j + 1}});
            visited.insert({i, j + 1});
        }
    }

    return ans;

    // //   brute force approch
    //   vector<int>ans;
    //   priority_queue<int>q;

    //   for(int i=0;i<A.size();i++){

    //       for(int j=0;j<B.size();j++){
    //           int sum = A[i]+B[j];

    //           q.push(sum);
    //           sum =0;
    //       }
    //   }

    //    while(!q.empty() && C--){
    //        ans.push_back(q.top());
    //        q.pop();
    //    }

    //     return ans;
}
