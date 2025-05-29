/*
 * +- 연산
 */

#include <string>
#include <vector>

using namespace std;

int solution(int age) {
    int answer = 0;
    
    const int base_year = 2022;
    const int korean_age = 1;
    
    answer = base_year - age + korean_age;
    
    return answer;
}
