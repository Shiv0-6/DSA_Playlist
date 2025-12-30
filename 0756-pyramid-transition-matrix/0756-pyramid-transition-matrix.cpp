
class Solution {
public:
    unordered_map<int, int> trans; // (A,B) -> bitmask of possible tops
    unordered_set<string> bad;

    bool dfs(const string& row) {
        if (row.size() == 1) return true;
        if (bad.count(row)) return false;

        string next(row.size() - 1, ' ');
        bool ok = build(row, 0, next);

        if (!ok) bad.insert(row);
        return ok;
    }

    bool build(const string& row, int idx, string& next) {
        if (idx == row.size() - 1)
            return dfs(next);

        int key = (row[idx] - 'A') * 26 + (row[idx + 1] - 'A');
        if (!trans.count(key)) return false;

        int mask = trans[key];
        while (mask) {
            int bit = mask & -mask;
            mask -= bit;
            next[idx] = 'A' + __builtin_ctz(bit);
            if (build(row, idx + 1, next)) return true;
        }
        return false;
    }

    bool pyramidTransition(string bottom, vector<string>& allowed) {
        for (auto& s : allowed) {
            int key = (s[0] - 'A') * 26 + (s[1] - 'A');
            trans[key] |= (1 << (s[2] - 'A'));
        }
        return dfs(bottom);
    }
};
