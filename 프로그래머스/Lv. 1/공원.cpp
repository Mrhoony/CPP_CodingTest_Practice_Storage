/*
 * 2차원 공간에서 특정 영역 어떻게 탐색할지 고민
 * 시간복잡도 개선이 필요하다면 이미 탐색한 부분은 다시 탐색하지 않기
 */

#include <string>
#include <vector>

using namespace std;

int solution(vector<int> mats, vector<vector<string>> park) {
    int answer = -1;
    
    const int max_park_row = park.size();
    const int max_park_col = park[0].size();
    
    int max_mat_size = 0;

    for (int row = 0; row < max_park_row; row++)
    {
        for(int col = 0; col < max_park_col; col++)
        {
            if (park[row][col] == "-1")
            {
                bool find_empty_space = true;
                int empty_space_size = 1;
                
                while (find_empty_space == true)
                {
                    if (row + empty_space_size == max_park_row)
                    {
                        find_empty_space = false;
                    }
                    else if (col + empty_space_size == max_park_col)
                    {
                        find_empty_space = false;
                    }
                    else
                    {
                        // 돗자리를 깔 수 있는지 영역 크기 탐색
                        for (int r = 0; r <= empty_space_size; r++)
                        {
                            for (int c = 0; c <= empty_space_size; c++)
                            {
                                if (park[row + r][col + c] != "-1")
                                {
                                    find_empty_space = false;
                                }
                            }
                        }
                    }

                    if (find_empty_space == true)
                    {
                        empty_space_size += 1;
                    }
                    else
                    {
                        max_mat_size = max_mat_size > empty_space_size ? max_mat_size : empty_space_size;
                    }
                }
            }
        }
    }

    while (max_mat_size > 0)
    {
        bool find_max_mat = false;
        
        for (const int& mat : mats)
        {
            if (mat == max_mat_size)
            {
                answer = max_mat_size;
                find_max_mat = true;
            }
        }
        
        if (find_max_mat == true)
        {
            break;
        }
        
        max_mat_size -= 1;
    }
    
    return answer;
}