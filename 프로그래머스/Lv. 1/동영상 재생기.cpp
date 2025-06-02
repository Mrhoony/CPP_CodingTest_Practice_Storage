/*
 * 시간 정리 부분에 유의
 * 조건1: 초가 0 미만이거나 60 이상인 경우
 * 조건2: pos_mm == video_len_mm 이면서 video_len_ss 초과인 경우
 */

#include <string>
#include <vector>

using namespace std;

string solution(string video_len, string pos, string op_start, string op_end, vector<string> commands) {
    string answer = "";
    
    int video_len_mm = stoi(video_len.substr(0, video_len.find(':')));
    int video_len_ss = stoi(video_len.substr(video_len.find(':') + 1));
    int pos_mm = stoi(pos.substr(0, pos.find(':')));
    int pos_ss = stoi(pos.substr(pos.find(':') + 1));
    int op_start_mm = stoi(op_start.substr(0, op_start.find(':')));
    int op_start_ss = stoi(op_start.substr(op_start.find(':') + 1));
    int op_end_mm = stoi(op_end.substr(0, op_end.find(':')));
    int op_end_ss = stoi(op_end.substr(op_end.find(':') + 1));
    
    // 오프닝 건너뛰기
    if (pos_mm > op_start_mm || (pos_mm == op_start_mm && pos_ss >= op_start_ss))
    {
        if (pos_mm < op_end_mm || (pos_mm == op_end_mm && pos_ss <= op_end_ss))
        {
            pos_mm = op_end_mm;
            pos_ss = op_end_ss;
        }
    }
    
    // 명령 처리
    for (const string& command : commands)
    {
        if (command == "prev")
        {
            pos_ss -= 10;
        }
        else if (command == "next")
        {
            pos_ss += 10;
        }
        
        // 시간 정리
        if (pos_mm == video_len_mm)
        {
            if (pos_ss > video_len_ss)
            {
                pos_ss = video_len_ss;
            }
        }
        
        if (pos_ss < 0)
        {
            if (pos_mm == 0)
            {
                pos_ss = 0;
            }
            else
            {
                pos_mm -= 1;
                pos_ss += 60;
            }
        }
        else if (pos_ss > 59)
        {
            if (pos_mm == video_len_mm)
            {
                pos_ss = video_len_ss;
            }
            else
            {
                pos_mm += 1;
                pos_ss -= 60;

                if (pos_mm == video_len_mm)
                {
                    if (pos_ss > video_len_ss)
                    {
                        pos_ss = video_len_ss;
                    }
                } 
            }
        }
    
        // 오프닝 건너뛰기
        if (pos_mm > op_start_mm || (pos_mm == op_start_mm && pos_ss >= op_start_ss))
        {
            if (pos_mm < op_end_mm || (pos_mm == op_end_mm && pos_ss <= op_end_ss))
            {
                pos_mm = op_end_mm;
                pos_ss = op_end_ss;
            }
        }
    }

    // 10 미만인 경우 자릿수 0으로 표현
    string str_mm;
    string str_ss;
    {
        if (pos_mm < 10)
        {
            str_mm = "0";
        }
        str_mm += to_string(pos_mm);

        if (pos_ss < 10)
        {
            str_ss = "0";
        }
        str_ss += to_string(pos_ss);
    }
    
    answer = str_mm + ":" + str_ss;
    
    return answer;
}