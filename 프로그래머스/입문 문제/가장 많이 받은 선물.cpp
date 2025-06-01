/*
 * 입출력 예시의 두 테이블 구현
 */

#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

int solution(vector<string> friends, vector<string> gifts) {
    int answer = 0;
    
    // 테이블 초기화
    unordered_map<string, unordered_map<string, int>> user_gift_datas;
    unordered_map<string, unordered_map<string, int>> user_index_datas;
    
    for (const string& friends_name : friends)
    {
        unordered_map<string, int> gift_data;
        for (const string& name : friends)
        {
            gift_data[name] = 0;
        }
        user_gift_datas[friends_name] = gift_data;
        
        unordered_map<string, int> index_data;
        index_data["give"] = 0;
        index_data["take"] = 0;
        index_data["index"] = 0;
        user_index_datas[friends_name] = index_data;
    }
    
    // 주고받은 선물 데이터 테이블화
    for (string gift : gifts)
    {
        int split_index = gift.find(' ');
        string give_user = gift.substr(0, split_index);
        string take_user = gift.substr(split_index + 1);

        user_gift_datas[give_user][take_user] += 1;
        
        user_index_datas[give_user]["give"] += 1;
        user_index_datas[give_user]["index"] = user_index_datas[give_user]["give"] - user_index_datas[give_user]["take"];
        
        user_index_datas[take_user]["take"] += 1;
        user_index_datas[take_user]["index"] = user_index_datas[take_user]["give"] - user_index_datas[take_user]["take"];
    }
    
    // 주고받은 선물로 계산, 불충분 시 추가로 선물지수 계산
    {
        for (const string& target : friends)
        {
            int get_gift_next_month = 0;
            
            for (const string& source : friends)
            {
                if (target == source)
                {
                    continue;
                }
                
                if (user_gift_datas[target][source] > user_gift_datas[source][target])
                {
                    get_gift_next_month += 1;
                }
                // 선물지수 계산
                else if (user_gift_datas[target][source] == user_gift_datas[source][target])
                {
                    if (user_index_datas[target]["index"] > user_index_datas[source]["index"])
                    {
                        get_gift_next_month += 1;
                    }
                }
            }
            
            answer = answer > get_gift_next_month ? answer : get_gift_next_month;
        }
    }
    
    return answer;
}