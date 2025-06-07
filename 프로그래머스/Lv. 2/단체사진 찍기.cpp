/*
 * 모든 케이스 생성 -> 오답 소거 = 시간 초과
 */

#include <string>
#include <vector>
#include <cmath>
#include <map>

using namespace std;

vector<char> g_friends = {'A', 'C', 'F', 'J', 'M', 'N', 'R', 'T'};
vector<string> g_conditions_data;
int g_valid_permutation_count;

void generate_permutations_and_check(int depth, string current_permutation, vector<bool>& used)
{
    if (depth == g_friends.size())
    {
        map<char, int> friend_pos_map;
        for(int i = 0; i < current_permutation.length(); i++)
        {
            friend_pos_map[current_permutation[i]] = i;
        }
        
        bool is_current_permutation_valid = true;
    
        for (const string& condition_str : g_conditions_data)
        {
            char p1_char = condition_str[0];
            char p2_char = condition_str[2];
            char op = condition_str[3];
            int val = condition_str[4] - '0';

            int pos1 = friend_pos_map[p1_char];
            int pos2 = friend_pos_map[p2_char];

            int distance = abs(pos1 - pos2) - 1;
            bool condition_met = false;

            if (op == '=')
            {
                condition_met = (distance == val);
            }
            else if (op == '<')
            {
                condition_met = (distance < val);
            }
            else if (op == '>')
            {
                condition_met = (distance > val);
            }

            if (condition_met == false)
            {
                is_current_permutation_valid = false;
                break;
            }
        }
        
        if (is_current_permutation_valid == true)
        {
            g_valid_permutation_count += 1;
        }
        
        return;
    }
    
    for (int i = 0; i <g_friends.size(); i++)
    {
        if (used[i] == true)
        {
            continue;
        }
        
        used[i] = true;
        generate_permutations_and_check(depth + 1, current_permutation + g_friends[i], used);
        used[i] = false;
    }
}

// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
int solution(int n, vector<string> data) {
    g_valid_permutation_count = 0;
    g_conditions_data = data;
    
    vector<bool> used(g_friends.size(), false);
    
    generate_permutations_and_check(0, "", used);
    
    return g_valid_permutation_count;
}