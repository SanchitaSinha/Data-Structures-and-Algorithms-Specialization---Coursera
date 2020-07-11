#include <iostream>
#include <vector>
#include <cstdio>

using std::cin;
using std::vector;
using std::ios;

struct GSM_network_problem_to_SAT {
    static constexpr auto K = 3;

    struct edge {
        int from;
        int to;
    };

    GSM_network_problem_to_SAT(int n, int m)
        : numVertices(n)
        , edges(m)
    {
    }

    void print_SAT_formula() const noexcept
    {
        const int C = K * edges.size() + numVertices;
        const int V = numVertices * K;

        printf("%d %d\n", C, V);

        for (int j = 0, cnt = 1; j < numVertices; ++j, cnt += K) {
            printf("%d %d %d 0\n", cnt, cnt + 1, cnt + 2);
        }

        for (const edge& e : edges) {
            printf("%d %d 0\n", -((e.from - 1) * K + 1), -((e.to - 1) * K + 1));
            printf("%d %d 0\n", -((e.from - 1) * K + 2), -((e.to - 1) * K + 2));
            printf("%d %d 0\n", -((e.from - 1) * K + 3), -((e.to - 1) * K + 3));
        }
    }

    int numVertices;
    vector<edge> edges;
};

int main()
{
    ios::sync_with_stdio(false);

    int n, m;
    cin >> n >> m;

    GSM_network_problem_to_SAT converter(n, m);

    for (int i = 0; i < m; ++i) {
        cin >> converter.edges[i].from >> converter.edges[i].to;
    }

    converter.print_SAT_formula();

    return 0;
}