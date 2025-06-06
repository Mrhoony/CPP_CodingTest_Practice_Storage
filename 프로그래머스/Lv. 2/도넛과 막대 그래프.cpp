/*
 * 시작 노드의 out_count = 존재하는 그래프의 총 갯수
 * 각 그래프의 고유 특징으로 판별
 */

#include <string>
#include <vector>
#include <set>
#include <map>

using namespace std;

vector<int> solution(vector<vector<int>> edges) {
    vector<int> answer;
    
    set<int> all_nodes;
    map<int, int> in_count;
    map<int, int> out_count;
    
    for (const vector<int>& edge : edges)
    {
        int from = edge[0];
        int to = edge[1];
        out_count[from] += 1;
        in_count[to] += 1;
        all_nodes.insert(from);
        all_nodes.insert(to);
    }
    
    int start_node = -1;
    int donut_count = 0;
    int stick_count = 0;
    int eight_count = 0;
    
    // 시작노드 탐색
    for (int node : all_nodes)
    {
        if (in_count[node] == 0 && out_count[node] > 1)
        {
            start_node = node;
            break;
        }
    }
    
    int start_node_out_count = out_count[start_node];
    
    // 시작노드의 간선 제거
    for (const vector<int>& edge : edges)
    {
        if (edge[0] == start_node)
        {
            in_count[edge[1]] -= 1;
            out_count[edge[0]] -= 1;
        }
    }
    
    for (int node : all_nodes)
    {
        if (node == start_node)
        {
            continue;
        }
        
        if (out_count[node] == 0)
        {
            stick_count++;
        }
        else if (in_count[node] == 2 && out_count[node] == 2)
        {
            eight_count++;
        }
    }
    
    donut_count = start_node_out_count - stick_count - eight_count;
    
    answer.push_back(start_node);
    answer.push_back(donut_count);
    answer.push_back(stick_count);
    answer.push_back(eight_count);
    
    return answer;
}