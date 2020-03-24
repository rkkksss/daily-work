int id[21][21];
int dp[1 << 21][21];

class Solution {
public:
    int uniquePathsIII(vector<vector<int>>& grid) {
        
        int w = 0;
        int h = 0;
        h = grid.size();
        w = grid[0].size();
        
        if (h * w > 20) {
            exit(1);
        }
        int num = 0;
        for (int i = 0; i < h; i++) {
            for (int j = 0; j < w; j++) {
                if (grid[i][j] != -1) {
                    id[i][j] = num++; //создаём копию и нумеруем клетки
                }
            }
        }
        int size = num;
        for (int i = 0; i < (1 << size); ++i) {
            for (int j = 0; j < size; j++) {
                dp[i][j] = 0;
            }
            dp[i][20] = 0;
        }
        
        for (int i = 0; i < h; ++i) {
            for (int j = 0; j < w; ++j) {
                if (grid[i][j] == 1) {
                    int start = id[i][j]; //нашли старт
                    dp[1 << start][start] = 1; //dp[если i-ая клетка посещена, то в 
                    //iый бит ставим 1, остальное нолики] = сколько вариантов
                    //посетить [начало]
                    dp[1 << start][20] = 1;
                }
            }
        } 
        
        int dx[] = {-1, 0, 1, 0};
        int dy[] = {0, 1, 0, -1}; //массивы для обхода по х и у
        for (int i = 0; i < (1 << size); ++i) {
            if (dp[i][20] == 0) {
                continue;
            }
            for (int j = 0; j < h; ++j) {
                for (int k = 0; k < w; ++k) {
                    if (grid[j][k] == -1) {
                        continue;
                    }
                    for (int m = 0; m < 4; ++m) {
                        int x = dx[m] + j;
                        int y = dy[m] + k;
                        if (x >= h || x < 0 || y < 0 || y >= w || grid[x][y] == -1) {
                            continue;
                        }
                        int to = id[x][y];
                        int from = id[j][k];
                        if ((i & (1 << to)) == 0) {
                            dp[i | (1 << to)][to] += dp[i][from]; //слева то, куда, 
                            //справа то, откуда
                            dp[i | (1 << to)][20] += dp[i][from];
                        }
                    }
                }
            }
        }
        int allvisit = 0;
        for (int i = 0; i < h; ++i) {
            for (int j = 0; j < w; ++j) {
                if (grid[i][j] != -1) {
                    allvisit |= (1 << id[i][j]); //к всем вершинам != -1 прибавляем i-ый бит
                }
            }
        }
        long long res;
        for (int i = 0; i < h; ++i) {
            for (int j = 0; j < w; ++j) {
                if (grid[i][j] == 2) {
                    int end = id[i][j]; //нашли конец
                    res = dp[allvisit][end]; //считаем 
                }
            }
        }  
        return res;
    }
};
