/*
 * std::find() 사용
 * k번 이상 신고된 유저 찾기
 * 해당 유저를 신고한 유저 찾기
 */

#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

vector<int> solution(vector<string> id_list, vector<string> report, int k) {
    vector<int> answer;
    
    unordered_map<string, int> report_count;
    unordered_map<string, vector<string>> reporter_list;
    unordered_map<string, int> mail_list;
    
    // 저장공간 할당 및 초기화
    for (const string& id : id_list)
    {
        report_count[id] = 0;
        mail_list[id] = 0;
        
        vector<string> data;
        reporter_list[id] = data;
    }
    
    // 신고내역 테이블화
    for (const string& data : report)
    {
        int blank_index = data.find(' ');
        const string reporter = data.substr(0, blank_index);
        const string target = data.substr(blank_index + 1);
        
        if (find(reporter_list[target].begin(), reporter_list[target].end(), reporter) == reporter_list[target].end())
        {
            report_count[target] += 1;
            reporter_list[target].push_back(reporter);
        }
    }
    
    // 메일 카운트 정리
    for (const string& id : id_list)
    {
        if (report_count[id] >= k)
        {
            for (const string& mail : reporter_list[id])
            {
                mail_list[mail] += 1;
            }
        }
    }
    
    for (const string& id : id_list)
    {
        answer.push_back(mail_list[id]);
    }
    
    return answer;
}