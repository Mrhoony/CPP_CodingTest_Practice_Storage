/*
 * 일반적인 경우 dp[0] = 1로 정의된다.  // 반드시 그런 것은 아님
 * 이 문제에서는
 * 잔돈 n=8, 사용가능한 화폐 c={8} 이라면 n을 c로 줄 수 있는 방법은 way = dp[n - c]로 표현할 수 있다. dp[8 - 8] = dp[0]이므로 8원을 8화폐로 줄 수 있는 방법은 최소 1가지가 있음을 알 수 있다.
 * 현실적으로 0단위 화폐로 n원을 거슬러 줄 수 있는 방법은 없지만 점화식의 완성을 위해 기저 조건으로 dp[0] = 1을 정의한다. 즉 dp[0]은 n원과 c화폐가 같은 값이라면 n원을 c화폐로 거슬러 줄 수 있는 방법을 의미한다.
 * 배열 dp에 저장된 숫자는 방법의 가짓수를 나타내므로 방법을 찾을 때마다 갱신이 아닌 적재를 해야한다. 따라서 위의 예시의 표현 way = dp[n - c]는 점화식 dp[i] += dp[i - c]로 표현된다.
 */

/*
 * 힌트
 * 동적 프로그래밍(DP)을 사용하여 겹치는 부분 문제 해결:
 * 이 문제는 재귀적으로 해결할 수 있지만, 겹치는 부분 문제를 제거하기 위한 최적화 없이는 모든 테스트 케이스를 통과할 수 없습니다. 동일한 부분 문제를 여러 번 해결하지 않도록 이전에 계산된 해를 저장하고 참조하는 방법을 생각해 보세요.
 * 다음과 같은 퇴화 사례를 고려해 보세요.
 * - 0센트를 잔돈으로 바꿀 수 있는 방법은 몇 가지인가요?
 * - 동전이 없을 때 0센트를 초과하는 금액을 잔돈으로 바꿀 수 있는 방법은 몇 가지인가요?
 * 해의 저장 공간을 정의하는 데 어려움이 있다면, 기본 케이스(n = 0)를 기준으로 생각해 보세요.
 * - 답은 32비트 정수보다 클 수 있습니다.
 * 
 * 원문
 * Hints
 * Solve overlapping subproblems using Dynamic Programming (DP):
 * You can solve this problem recursively but will not pass all the test cases without optimizing to eliminate the overlapping subproblems. Think of a way to store and reference previously computed solutions to avoid solving the same subproblem multiple times. * Consider the degenerate cases:
 * - How many ways can you make change for 0 cents? - How many ways can you make change for > 0 cents if you have no coins? * If you're having trouble defining your solutions store, then think about it in terms of the base case (n = 0). - The answer may be larger than a 32-bit integer.
*/

#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'getWays' function below.
 *
 * The function is expected to return a LONG_INTEGER.
 * The function accepts following parameters:
 *  1. INTEGER n
 *  2. LONG_INTEGER_ARRAY c
 */

long getWays(int n, vector<long> c) {
    vector<long> dp(n + 1, 0);
    dp[0] = 1;

    for (long coin : c)
    {
        for (int i = coin; i <= n; i++)
        {
            dp[i] += dp[i - coin];
        }
    }
    
    return dp[n];
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string first_multiple_input_temp;
    getline(cin, first_multiple_input_temp);

    vector<string> first_multiple_input = split(rtrim(first_multiple_input_temp));

    int n = stoi(first_multiple_input[0]);

    int m = stoi(first_multiple_input[1]);

    string c_temp_temp;
    getline(cin, c_temp_temp);

    vector<string> c_temp = split(rtrim(c_temp_temp));

    vector<long> c(m);

    for (int i = 0; i < m; i++) {
        long c_item = stol(c_temp[i]);

        c[i] = c_item;
    }

    // Print the number of ways of making change for 'n' units using coins having the values given by 'c'

    long ways = getWays(n, c);

    fout << ways << "\n";

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

vector<string> split(const string &str) {
    vector<string> tokens;

    string::size_type start = 0;
    string::size_type end = 0;

    while ((end = str.find(" ", start)) != string::npos) {
        tokens.push_back(str.substr(start, end - start));

        start = end + 1;
    }

    tokens.push_back(str.substr(start));

    return tokens;
}
