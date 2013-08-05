class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int> > &obstacleGrid) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int rn = obstacleGrid.size();
        if (rn == 0)
            return 0;
        int cn = obstacleGrid[0].size();
        if (cn == 0)
            return 0;
        
        int **map = new int*[rn];
        for (int i = 0; i < rn; i++)
            map[i] = new int[cn];
        
        for (int i = 0; i < rn; i++)    {
            for (int j = 0; j < cn; j++)    {
                map[i][j] = 0;
                if (obstacleGrid[i][j] == 1)
                    continue;
                if (i + j == 0) {
                    map[0][0] = 1;
                }
                if (i > 0)  {
                    map[i][j] += map[i - 1][j];
                }
                if (j > 0)  {
                    map[i][j] += map[i][j - 1];
                }   
            }
        }
            
        int ans = map[rn - 1][cn - 1];
            
        for (int i = 0; i < rn; i++)
            delete map[i];
        delete map;
        
        return ans;
    }
};