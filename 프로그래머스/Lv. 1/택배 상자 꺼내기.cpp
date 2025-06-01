/*
 * 좌/우측 적재 규칙 찾기
 */

#include <string>
#include <vector>

using namespace std;

int solution(int n, int w, int num) {
    int answer = 0;

    int floor = 1;
    int target_floor_position = num;
    
    while(target_floor_position - w > 0)
    {
        target_floor_position -= w;
        floor += 1;
    }
    
    // 타겟 위치가 짝수층인 경우
    if (floor % 2 == 0)
    {
        target_floor_position = w - target_floor_position + 1;
    }
    
    int right_stack = (w - target_floor_position) + (w - target_floor_position + 1);
    int left_stack = (w - (w - target_floor_position) - 1) + target_floor_position;
        
    int current_position = num;
        
    while (current_position < n)
    {
        if (floor % 2 == 0)
        {
            current_position += left_stack;
        }
        else
        {
            current_position += right_stack;
        }
        
        floor += 1;
        
        if (current_position <= n)
        {
            answer += 1;
        }
    }
    
    answer += 1;
    
    return answer;
}