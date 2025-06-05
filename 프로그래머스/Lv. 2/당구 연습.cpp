/*
 * 입사각과 반사각이 같다면 축 대칭으로 두 선과 동일한 길이의 직선 획득 가능
 * 최소 거리를 알 수 있는 방법은 다른 모든 경우의 수와 비교하는 것
 * 모든 벽에 대한 거리를 구한 뒤 최소 거리 판단
 * 특정 벽을 반드시 사용해야 할 때 원쿠션 각이 안뜨는 경우의 수 고민
 */

#include <string>
#include <vector>

using namespace std;

vector<int> solution(int m, int n, int startX, int startY, vector<vector<int>> balls) {
    vector<int> answer;
    
    for (const vector<int>& ball : balls)
    {
        int ball_x = ball[0];
        int ball_y = ball[1];
        
        int min_dist_sq = -1;
        
        int dist_x;
        int dist_y;
        int dist_sq;
        
        // y=0 아랫벽
        if ((startX == ball_x && startY > ball_y) == false)
        {
            dist_x = startX - ball_x;
            dist_y = startY - (-ball_y);
            dist_sq = dist_x * dist_x + dist_y * dist_y;
            if (min_dist_sq == -1 || dist_sq < min_dist_sq)
            {
                min_dist_sq = dist_sq;
            }
        }
        
        // y=n 윗벽
        if ((startX == ball_x && startY < ball_y) == false)
        {
            dist_x = startX - ball_x;
            dist_y = startY - (n * 2 - ball_y);
            dist_sq = dist_x * dist_x + dist_y * dist_y;
            if (min_dist_sq == -1 || dist_sq < min_dist_sq)
            {
                min_dist_sq = dist_sq;
            }
        }
        
        // x=0 왼벽
        if ((startY == ball_y && startX > ball_x) == false)
        {
            dist_x = startX - (-ball_x);
            dist_y = startY - ball_y;
            dist_sq = dist_x * dist_x + dist_y * dist_y;
            if (min_dist_sq == -1 || dist_sq < min_dist_sq)
            {
                min_dist_sq = dist_sq;
            }
        }
        
        // x=m 오른벽
        if ((startY == ball_y && startX < ball_x) == false)
        {
            dist_x = startX - (m * 2 - ball_x);
            dist_y = startY - ball_y;
            dist_sq = dist_x * dist_x + dist_y * dist_y;
            if (min_dist_sq == -1 || dist_sq < min_dist_sq)
            {
                min_dist_sq = dist_sq;
            }
        }
        
        answer.push_back(min_dist_sq);
    }
    
    return answer;
}