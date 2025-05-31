/*
 * string 요소 직접 비교
 */

#include <string>
#include <vector>

using namespace std;

string solution(string my_string, string letter) {
    string answer = "";
    
    for (const char& my_letter : my_string)
    {
        if (my_letter == letter[0])
        {
            continue;
        }
        else
        {
            answer += my_letter;
        }
    }
    
    return answer;
}