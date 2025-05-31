/*
 * string 인덱스 접근
 */

#include <string>
#include <vector>

using namespace std;

int solution(string str1, string str2) {
    if (str2.empty() == true)
    {
        return 1;
    }
    
    if (str1.length() < str2.length())
    {
        return 2;
    }
    
    for (size_t i = 0; i <= str1.length() - str2.length(); i++)
    {
        bool bisInclude = true;
        for (size_t j = 0; j < str2.length(); j++)
        {
            if (str1[i + j] != str2[j])
            {
                bisInclude = false;
                break;
            }
        }
        
        if (bisInclude == true)
        {
            return 1;
        }
    }
    
    return 2;
    
    /*
    // 이렇게 풀 수 있지만 원하는 답이 아닌 것 같다.
    int answer = 0;
    
    if (str1.find(str2) != string::npos)
    {
        answer = 1;
    }
    else
    {
        answer = 2;
    }
    
    return answer;
    */
}