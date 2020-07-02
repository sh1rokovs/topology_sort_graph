#include <iostream>
#include <vector>

using namespace std;

using Graph = vector<vector<int>>;

void DFS(const Graph& graph,
    const int vertice,
    vector<bool>& used,
    vector<int>& result)
{
    used[vertice] = true;
    for (size_t idx = 0; idx < graph[vertice].size(); ++idx) {
        const int adjacent_vertice = graph[vertice][idx];
        if (!used[adjacent_vertice]) {
            DFS(graph, adjacent_vertice, used, result);
        }
    }
    result.push_back(vertice);
}

void Solve(const Graph& graph,
    const int from,
    vector<int>& result)
{
    vector<bool> used(graph.size(), false);
    DFS(graph, from, used, result);
}

int main() {
    int vertices, edges;
    cin >> vertices >> edges;

    Graph graph(vertices + 1);

    for (int edge = 0; edge < edges; ++edge) {
        int from, to;
        cin >> from >> to;
        graph[from].push_back(to);
    }

    int reset_vertice;
    cin >> reset_vertice;

    vector<int> result;

    Solve(graph, reset_vertice, result);

    for (vector<int>::const_reverse_iterator it = result.rbegin();
        it != result.rend();
        ++it)
    {
        cout << *it << " ";
    }
    cout << endl;

    return 0;
}