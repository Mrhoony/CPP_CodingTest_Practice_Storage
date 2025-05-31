/*
 * 컨테이너의 마지막 요소를 가리키는 인덱스 찾기
 */

#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> num_list) {
    vector<int> answer;
    
    for (int i = num_list.size() - 1; i >= 0; i--)
    {
        answer.push_back(num_list[i]);
    }
    
    return answer;
    
    /*
    // 이렇게 해도 될거 같은데 안된다.
    vector<int> answer;
    answer.reserve(num_list.size());
    
    for(int i = 0; i < num_list.size(); i++)
    {
        answer[answer.capacity() - 1 - i] = num_list[i];
    }
    
    return answer;
    */
}