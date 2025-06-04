/*
 * attacks의 시간 흐름 이용하기
 */

#include <string>
#include <vector>

using namespace std;

int solution(vector<int> bandage, int health, vector<vector<int>> attacks) {
    int answer = -1;
    
    int curr_health = health;
    int curr_time = 0;
    int curr_healtime = 0;
    
    for (const vector<int>& attack : attacks)
    {
        for (int t = curr_time + 1; t <= attack[0]; t++)
        {
            if (t == 0)
            {
                continue;
            }
            
            if (t == attack[0])
            {
                curr_health -= attack[1];
                if (curr_health <= 0)
                {
                    return answer;
                }
                
                curr_healtime = 0;
            }
            else
            {
                curr_healtime += 1;
                if (curr_healtime >= bandage[0])
                {
                    curr_health += bandage[2];
                    curr_healtime = 0;
                }
                
                curr_health += bandage[1];
                curr_health = curr_health < health ? curr_health : health;
            }
            
            curr_time += 1;
        }
    }
    
    answer = curr_health;
    return answer;
}