/*
 * 캐스팅, 이형 연산 시 결과 타입
 */

#include <string>
#include <vector>

using namespace std;

int solution(int num1, int num2) {
    int answer = 0;
    
    answer = static_cast<float>(num1) / num2 * 1000;
    
    return answer;
}
