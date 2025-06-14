/*
 * 문제를 보고 재귀로 풀어야 한다고 판단한 부분 -> 문제를 풀기 위해 info를 읽는 방법
 */

#include <string>
#include <vector>
#include <map>
#include <tuple>

using namespace std;

map<tuple<int, int, int>, int> dp;

int perfect_criminal(int item_index, int current_a, int current_b, const vector<vector<int>>& info, int n, int m)
{
    if (item_index == info.size())
    {
        if (current_a < n && current_b < m)
        {
            return current_a;
        }
        else
        {
            return -1;
        }
    }
    
    tuple<int, int, int> current_state = {item_index, current_a, current_b};
    if (dp.find(current_state) != dp.end())
    {
        return dp[current_state];
    }
    
    int min_a = info.size() * 3 + 1;
    
    int next_a_if_a_steal = current_a + info[item_index][0];
    if (next_a_if_a_steal < n)
    {
        int result_if_a_steal = perfect_criminal(item_index + 1, next_a_if_a_steal, current_b, info, n, m);
        min_a = min(min_a, result_if_a_steal);
    }
    
    int next_b_if_b_steal = current_b + info[item_index][1];
    if (next_b_if_b_steal < m)
    {
        int result_if_b_steal = perfect_criminal(item_index + 1, current_a, next_b_if_b_steal, info, n, m);
        min_a = min(min_a, result_if_b_steal);
    }
    
    dp[current_state] = min_a;
    return min_a;
}

int solution(vector<vector<int>> info, int n, int m) {
    dp.clear();
    
    int answer = perfect_criminal(0, 0, 0, info, n, m);
    
    if (answer == info.size() * 3 + 1)
    {
        return -1;
    }
    
    return answer;
}