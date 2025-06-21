

// class Solution
// {
// public:
//     int row[8] = {2, 2, -2, -2, 1, -1, 1, -1};
//     int column[8] = {1, -1, 1, -1, 2, 2, -2, -2};

//     bool valid(int i, int j, int n)
//     {
//         return i >= 0 && j >= 0 && i < n && j < n;
//     }
//     int minStepToReachTarget(vector<int> &KnightPos, vector<int> &TargetPos, int N)
//     {
//         KnightPos[0]--;
//         KnightPos[1]--;

//         TargetPos[0]--;
//         TargetPos[1]--;

//         if (KnightPos[0] == TargetPos[0] && KnightPos[1] == TargetPos[1])
//             return 0;

//         queue<pair<int, int>> q;
//         vector<vector<bool>> chess(N, vector<bool>(N, 0));
//         q.push({KnightPos[0], KnightPos[1]});
//         chess[KnightPos[0]][KnightPos[1]] = 1;
//         int step = 0;
//         while (!q.empty())
//         {
//             int size = q.size();

//             while (size--)
//             {
//                 int i = q.front().first;
//                 int j = q.front().second;
//                 q.pop();

//                 for (int k = 0; k < 8; k++)
//                 {
//                     int new_i = i + row[k];
//                     int new_j = j + column[k];
//                     if (valid(new_i, new_j, N) && !chess[new_i][new_j])
//                     {
//                         chess[new_i][new_j] = 1;
//                         if (new_i == TargetPos[0] && new_j == TargetPos[1])
//                             return step + 1;
//                         q.push({new_i, new_j});
//                     }
//                 }
//             }
//             step++;
//         }

//         return -1;
//     }
// };
