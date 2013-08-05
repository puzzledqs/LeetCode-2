class Solution {
public:
    int minPathSum(vector<vector<int> > &grid) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int rn = grid.size();
        if (rn == 0)
            return 0;
        int cn = grid[0].size();
        if (cn == 0)
            return 0;
        
        int **map = new int*[rn];
        for (int i = 0; i < rn; i++)
            map[i] = new int[cn];
        
        for (int i = 0; i < rn; i++)    {
            for (int j = 0; j < cn; j++)    {
                map[i][j] = 1 << 30;
                if (i + j == 0)
                    map[i][j] = grid[0][0];
                else    {
                    if (i > 0)  {
                        map[i][j] = min(map[i][j], map[i - 1][j] + grid[i][j]);
                    }
                    if (j > 0)  {
                        map[i][j] = min(map[i][j], map[i][j - 1] + grid[i][j]);
                    }
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