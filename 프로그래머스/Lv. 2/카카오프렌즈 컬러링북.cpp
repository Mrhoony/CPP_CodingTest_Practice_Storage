/*
 * 문제를 풀기 위해 모든 경우의 수를 확인해야하고 인접한 요소간의 관계성을 확인해야함 -> bfs
 */
#include <vector>
#include <queue>

using namespace std;

// 상, 하, 좌, 우
int dr[] = {-1, 1, 0, 0};
int dc[] = {0, 0, -1, 1};

int bfs(const vector<vector<int>> picture, int m, int n, vector<vector<bool>>& visited, int start_r, int start_c, int color)
{
    queue<pair<int, int>> q;
    q.push({start_r, start_c});
    visited[start_r][start_c] = true;
    
    int current_area_size = 1;
    
    while (q.empty() == false)
    {
        pair<int, int> current = q.front();
        q.pop();
        
        int curr_r = current.first;
        int curr_c = current.second;
        
        for (int i = 0; i < 4; i++)
        {
            int next_r = curr_r + dr[i];
            int next_c = curr_c + dc[i];
            
            if (next_r >= 0 && next_r < m && next_c >= 0 && next_c < n)
            {
                if (visited[next_r][next_c] == false && picture[next_r][next_c] == color)
                {
                    visited[next_r][next_c] = true;
                    q.push({next_r, next_c});
                    current_area_size += 1;
                }
            }
        }
    }
    
    return current_area_size;
}

// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
vector<int> solution(int m, int n, vector<vector<int>> picture) {
    int number_of_area = 0;
    int max_size_of_one_area = 0;
    vector<vector<bool>> visited(m, vector<bool>(n, false));
    
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (visited[i][j] == false && picture[i][j] != 0)
            {
                number_of_area += 1;
                int current_color = picture[i][j];
                
                int current_area_size = bfs(picture, m, n, visited, i, j, current_color);
                
                max_size_of_one_area = max_size_of_one_area > current_area_size ? max_size_of_one_area : current_area_size;
            }
        }
    }
    
    vector<int> answer(2);
    answer[0] = number_of_area;
    answer[1] = max_size_of_one_area;
    return answer;
}