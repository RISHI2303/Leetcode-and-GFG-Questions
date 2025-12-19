class UnionFind {
private:
    vector<int> parent;
    vector<int> rank;

public:
    UnionFind(int n) {
        parent.resize(n);
        rank.resize(n);
        for (int i = 0; i < n; ++i) {
            parent[i] = i;
        }
    }

    int find(int x) {
        if (parent[x] != x) {
            parent[x] = find(parent[x]);
        }
        return parent[x];
    }

    void unite(int x, int y) {
        int px = find(x);
        int py = find(y);
        if (px != py) {
            if (rank[px] > rank[py]) {
                parent[py] = px;
            } else if (rank[px] < rank[py]) {
                parent[px] = py;
            } else {
                parent[py] = px;
                rank[px] += 1;
            }
        }
    }

    bool connected(int x, int y) {
        return find(x) == find(y);
    }

    void reset(int x) {
        parent[x] = x;
        rank[x] = 0;
    }
};

class Solution {
public:
    vector<int> findAllPeople(int n, vector<vector<int>>& meetings, int firstPerson) {
        sort(meetings.begin(), meetings.end(), [](auto& a, auto& b) {
            return a[2] < b[2];
        });

        map<int, vector<pair<int, int>>> sameTimeMeetings;
        for (auto& meeting : meetings) {
            int x = meeting[0], y = meeting[1], t = meeting[2];
            sameTimeMeetings[t].emplace_back(x, y);
        }
    
        UnionFind graph(n);
        graph.unite(firstPerson, 0);

        for (auto& [t, meetings] : sameTimeMeetings) {
            for (auto& [x, y] : meetings) {
                graph.unite(x, y);
            }
            
            for (auto& [x, y] : meetings) {
                if (!graph.connected(x, 0)) {
                    graph.reset(x);
                    graph.reset(y);
                }
            }
        }
        
        vector<int> ans;
        for (int i = 0; i < n; ++i) {
            if (graph.connected(i, 0)) {
                ans.push_back(i);
            }
        }
        return ans;
    }
};