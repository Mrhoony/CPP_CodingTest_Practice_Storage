/*
 * 상위 값이 정답인지 증명하기 위해 하위 값을 찾는 과정
 * 깊이 우선 탐색, Depth First Search(DFS)
 * 백트래킹 코드 흐름 읽기
 */

#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);

/*
 * Complete the 'powerSum' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts following parameters:
 *  1. INTEGER X
 *  2. INTEGER N
 */

int powerSumRecursive(int X, int N, int MaxVal)
{
    int answer = 0;
    
    // root^N <= X를 만족하는 가장 큰 양의 정수 찾기
    int root = static_cast<int>(pow(static_cast<double>(X), static_cast<double>(1.0 / N)));
    // 리미트 값 MaxVal과 비교해서 root 조정
    if (root > MaxVal)
    {
        root = MaxVal;
    }
    
    for (int i = 0; i < root; i++)
    {
        int currentNum = root - i;
        int numberSum = static_cast<int>(pow(static_cast<double>(currentNum), static_cast<double>(N)));
        
        if (numberSum == X)
        {
            answer += 1;
            continue;
        }
        else
        {
            if (numberSum > X)
            {
                return answer;                
            }
            else
            {
                // currentNum에 대한 검증이 되었으므로 MaxVal을 currentNum - 1로 제한
                answer += powerSumRecursive(X - numberSum, N, currentNum - 1);
            }
        }
    }
    
    return answer;
}

int powerSum(int X, int N) {
    // X를 구성할 수 있는 가장 큰 제곱근 InitMaxVal 찾기
    // InitMaxVal보다 큰 수를 고려할 필요가 없기 때문
    int InitMaxVal = static_cast<int>(pow(static_cast<double>(X), static_cast<double>(1.0 / N)));
    
    return powerSumRecursive(X, N, InitMaxVal);
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string X_temp;
    getline(cin, X_temp);

    int X = stoi(ltrim(rtrim(X_temp)));

    string N_temp;
    getline(cin, N_temp);

    int N = stoi(ltrim(rtrim(N_temp)));

    int result = powerSum(X, N);

    fout << result << "\n";

    fout.close();

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}
