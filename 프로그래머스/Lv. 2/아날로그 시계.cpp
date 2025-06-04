/*
 * 단위를 맞추고 정규화하기
 */

#include <string>
#include <vector>

using namespace std;

int solution(int h1, int m1, int s1, int h2, int m2, int s2) {
    int answer = 0;
    
    int curr_timesecond = s1 + (m1 * 60) + (h1 * 3600);
    const int goal_timesecond = s2 + (m2 * 60) + (h2 * 3600);
    
    double curr_second_pos = s1;
    double curr_minute_pos = s1 + (m1 * 60);
    double curr_hour_pos = s1 + (m1 * 60) + (h1 * 3600);
    
    double prev_second_pos = curr_second_pos;
    double prev_minute_pos = curr_minute_pos;
    double prev_hour_pos = curr_hour_pos;
    
    if (curr_second_pos / 60 == curr_minute_pos / 3600)
    {
        answer += 1;
    }
    else
    {
        if (curr_second_pos / 60 == curr_hour_pos / 43200)
        {
            answer += 1;
        }
    }
    
    while (curr_timesecond < goal_timesecond)
    {
        prev_second_pos = curr_second_pos;
        prev_minute_pos = curr_minute_pos;
        prev_hour_pos = curr_hour_pos;
        
        curr_second_pos += 1;
        curr_minute_pos += 1;
        curr_hour_pos += 1;

        if (prev_second_pos / 60 < prev_minute_pos / 3600 && curr_second_pos / 60 >= curr_minute_pos / 3600)
        {
            answer += 1;
        }
        
        if (prev_second_pos / 60 < prev_hour_pos / 43200 && curr_second_pos / 60 >= curr_hour_pos / 43200)
        {
            if (curr_minute_pos / 3600 != curr_hour_pos / 43200)
            {
                answer += 1;
            }
        }
        
        if (curr_second_pos >= 60)
        {
            curr_second_pos -= 60;
        }
        
        if (curr_minute_pos >= 3600)
        {
            curr_minute_pos -= 3600;
        }
        
        if (curr_hour_pos >= 43200)
        {
            curr_hour_pos -= 43200;
        }
        
        curr_timesecond += 1;
    }
    
    return answer;
}