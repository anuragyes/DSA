/*class Solution{
public:	
	int matSearch (vector <vector <int>> &matrix, int N, int M, int X)
	{
	     // Check if the matrix is empty
        // check row is present for starting check 
        if (matrix.empty() || matrix[0].empty()) {
            return false;
        }

       
        for (int i = 0; i < N; i++) {
            for (int j = 0; j <M; j++) {
                if (matrix[i][j] == X) {
                    return true; // Found the target
                }
            }
        }

        return false; // Target not found
	}
};*/