/*
 * % 연산 후 나머지 0의 의미
 */

#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> num_list) {
    vector<int> answer;
    
    int even = 0;
    int odd = 0;
    
    for (const int& num : num_list)
    {
        if (num % 2 == 0)
        {
            even++;
        }
        else
        {
            odd++;
        }
    }
    
    answer.push_back(even);
    answer.push_back(odd);
    
    return answer;
}