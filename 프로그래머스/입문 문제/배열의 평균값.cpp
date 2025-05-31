/*
 * vector::size()
 */

#include <string>
#include <vector>

using namespace std;

double solution(vector<int> numbers) {
    double answer = 0;
    
    double sum = 0;
    for (const int& number : numbers)
    {
        sum += number;
    }
    
    answer = sum / numbers.size();
    
    return answer;
}