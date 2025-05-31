/*
 * 양꼬치 10개 당 음료수 1개 서비스 처리
 */

#include <string>
#include <vector>

using namespace std;

int solution(int n, int k) {
    int answer = 0;
    
    const int price_sheep = 12000;
    const int price_drink = 2000;
    
    // 서비스
    if (n / 10 >= k)
    {
        k = 0;
    }
    else
    {
        k = k - (n / 10);
    }
    
    answer = (n * price_sheep) + (k * price_drink);
    
    return answer;
}