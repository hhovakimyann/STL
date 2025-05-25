#include <iostream>
#include <vector>
#include <limits>

#define INF std::numeric_limits<int>::max()


 
void floydWarshall(std::vector<std::vector<int>>& dist, int v) {
    std::vector<std::vector<int>> mat = dist;

    for(int k = 0; k <  v; ++k) {
        for(int i = 0; i < v; ++i) {
            for(int j = 0; j < v; ++j) {
               if(mat[i][k]  < INF && mat[k][j] < INF) {
                    mat[i][j] = std::min(mat[i][j], mat[k][j] + mat[i][k]); 
               }
            }
        }
    }

    for(const auto& row : mat) {
        for(const int x : row) {
            std::cout << x << " ";
        }
        std::cout << std::endl;
    }

}
int main () {
    std::vector<std::vector<int>> dist = {
        {0,3,INF,5},
        {2,0,INF,4},
        {INF,6,0,INF},
        {INF,INF,2,0},
    };

    floydWarshall(dist,4);
}
