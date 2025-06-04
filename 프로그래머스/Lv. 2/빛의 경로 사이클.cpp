/*
 * 방향을 숫자로 표현
 * 모든 경우의 수에 대한 진행상황 기록
 */

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

// 0, 1, 2, 3
// 북, 동, 남, 서
int dir_y[] = {-1, 0, 1, 0};
int dir_x[] = {0, 1, 0, -1};

bool is_visit[500][500][4];

int max_row = 0;
int max_col = 0;

int find_cycle_length(int start_y, int start_x, int start_dir, const vector<string>& grid)
{
    int curr_y = start_y;
    int curr_x = start_x;
    int curr_dir = start_dir;
    int length = 0;
    
    while (is_visit[curr_y][curr_x][curr_dir] == false)
    {
        is_visit[curr_y][curr_x][curr_dir] = true;
        length += 1;
        
        int next_y = (curr_y + dir_y[curr_dir] + max_row) % max_row;
        int next_x = (curr_x + dir_x[curr_dir] + max_col) % max_col;
        
        char node_behavior = grid[next_y][next_x];
        int next_dir = curr_dir;
        
        if (node_behavior == 'L')
        {
            next_dir = (curr_dir + 3) % 4;
        }
        else if (node_behavior == 'R')
        {
            next_dir = (curr_dir + 1) % 4;
        }
        
        curr_y = next_y;
        curr_x = next_x;
        curr_dir = next_dir;
    }
    
    return length;
}

vector<int> solution(vector<string> grid) {
    vector<int> answer;
    
    max_row = grid.size();
    max_col = grid[0].length();
    
    for (int y = 0; y < max_row; y++)
    {
        for (int x = 0; x < max_col; x++)
        {
            for (int dir = 0; dir < 4; dir++)
            {
                if (is_visit[y][x][dir] == false)
                {
                    int cycle_length = find_cycle_length(y, x, dir, grid);
                    answer.push_back(cycle_length);
                }
            }
        }
    }
    
    sort(answer.begin(), answer.end());
    return answer;
}
