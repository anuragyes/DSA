// Median in a row-wise sorted Matrxi
/*class Solution{   
public:
    int median(vector<vector<int>> &matrix, int R, int C){
           vector<int> ans;

    // Flatten the matrix into a 1D vector
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            ans.push_back(matrix[i][j]);
        }
    }  

    // Sort the vector
   sort(ans.begin(), ans.end());

    // Calculate the median
    int size = ans.size();
    if (size % 2 == 1) 
        // Odd size, return the middle element
        return ans[size / 2];
    else 
        // Even size, return the average of the two middle elements
        return (ans[size / 2 - 1] + ans[size / 2]) / 2;
    
    }
};*/