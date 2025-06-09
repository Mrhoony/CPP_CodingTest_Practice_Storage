/*
 * 규칙 찾기
 * result[0] = 1;  // 문제의 설명만으로는 납득되지 않는 부분
 */

#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    if (n % 2 != 0)
    {
        return 0;
    }
    
    const int mod_num = 1000000007;
    vector<long long> result(n + 1, 0);
    result[0] = 1;
    result[2] = 3;
    
    for (int i = 4; i <= n; i += 2)
    {
        result[i] = (result[i - 2] * 3) % mod_num;
        
        for (int j = i - 4; j >= 0; j -= 2)
        {
            result[i] = (result[i] + result[j] * 2) % mod_num; 
        }
    }
    
    return result[n];
}