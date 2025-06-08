/*
 * 1 <-> 11011
 * 필요한 시간 복잡도 < O(n) < O(n^2)
 * 필요한 데이터만 찾을 수 있는 방법 찾기
 */

#include <string>
#include <vector>

using namespace std;

long long kan_length[21];
long long kan_one[21];

int count_one(int n, long long l, long long r)
{
    if (n == 0)
    {
        return 1;
    }
    
    long long count = 0;
    long long sub_len = kan_length[n - 1];
    
    for (int i = 0; i < 5; i++)
    {
        long long start = i * sub_len + 1;
        long long end = (i + 1) * sub_len;
        
        if (end < l || start > r)
        {
            continue;
        }
        
        if (i == 2)
        {
            continue;
        }
        
        if (l <= start && end <= r)
        {
            count += kan_one[n - 1];
        }
        else
        {
            long long sub_l = l > start ? l : start;
            long long sub_r = r < end ? r : end;
            
            count += count_one(n - 1, l - start + 1, r - start + 1);
        }
    }
    
    return count;
}

int solution(int n, long long l, long long r) {
    kan_length[0] = 1;
    kan_one[0] = 1;
    for (int i = 1; i <= 20; i++)
    {
        kan_length[i] = kan_length[i - 1] * 5;
        kan_one[i] = kan_one[i - 1] * 4;
    }
    
    return count_one(n, l, r);
}