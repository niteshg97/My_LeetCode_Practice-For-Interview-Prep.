class Solution {
public:
    int groups, largest;

    int find(int x, unordered_map<int, int>& parent) {
        if (parent[x] == x)
            return x;

        return parent[x] = find(parent[x], parent);
    }

    void unite(int a, int b,
               unordered_map<int, int>& parent,
               unordered_map<int, int>& sz) {

        if (!parent.count(b))
            return;

        int pa = find(a, parent);
        int pb = find(b, parent);

        if (pa == pb)
            return;

        parent[pa] = pb;
        sz[pb] += sz[pa];

        largest = max(largest, sz[pb]);
        groups--;
    }

    vector<int> groupStrings(vector<string>& words) {

        unordered_map<int, int> parent;
        unordered_map<int, int> sz;

        groups = words.size();
        largest = 0;

        // Build DSU nodes (one per unique mask)
        for (string &word : words) {

            int mask = 0;

            for (char c : word)
                mask |= (1 << (c - 'a'));

            parent[mask] = mask;
            sz[mask]++;

            largest = max(largest, sz[mask]);

            // Duplicate mask => same group
            if (sz[mask] > 1)
                groups--;
        }

        // Connect masks
        for (auto &[mask, _] : parent) {

            for (int i = 0; i < 26; i++) {

                // Add / Remove
                unite(mask, mask ^ (1 << i), parent, sz);

                // Replace
                if ((mask >> i) & 1) {

                    for (int j = 0; j < 26; j++) {

                        if (((mask >> j) & 1) == 0) {

                            int newMask = (mask ^ (1 << i)) | (1 << j);

                            unite(mask, newMask, parent, sz);
                        }
                    }
                }
            }
        }

        return {groups, largest};
    }
};