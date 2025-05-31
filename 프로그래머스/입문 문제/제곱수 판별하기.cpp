/*
 * 같은 정수 x의 ^2가 n인지 확인
 */

#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    int answer = 0;
    
    for (int i = 1; i * i <= n; i++)
    {
        if (i * i == n)
        {
            return 1;
        }
    }
    
    return 2;
}