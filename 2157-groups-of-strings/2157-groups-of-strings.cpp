class Solution {
public:
    vector<int> parent;
    vector<int> group_size;
    int num_groups;
    int max_size;

    int find(int i) {
        if (parent[i] == i)
            return i;
        return parent[i] = find(parent[i]);
    }

    void unite(int i, int j) {
        int root_i = find(i);
        int root_j = find(j);
        if (root_i != root_j) {
            parent[root_i] = root_j;
            group_size[root_j] += group_size[root_i];
            max_size = max(max_size, group_size[root_j]);
            num_groups--;
        }
    }

    vector<int> groupStrings(vector<string>& words) {
        unordered_map<int, int> mask_to_id;
        vector<int> mask_counts;
        int id_counter = 0;

        for (const string& word : words) {
            int mask = 0;
            for (char ch : word) {
                mask |= (1 << (ch - 'a'));
            }
            if (mask_to_id.find(mask) == mask_to_id.end()) {
                mask_to_id[mask] = id_counter++;
                mask_counts.push_back(1);
            } else {
                mask_counts[mask_to_id[mask]]++;
            }
        }

        int n = id_counter;
        parent.resize(n);
        group_size = mask_counts;
        num_groups = n;
        max_size = 0;

        for (int i = 0; i < n; i++) {
            parent[i] = i;
            if (group_size[i] > 0) {
                max_size = max(max_size, group_size[i]);
            }
        }

        unordered_map<int, int> delete_intermediates;

        for (auto const& [mask, id] : mask_to_id) {
            for (int i = 0; i < 26; i++) {
                if ((mask & (1 << i)) != 0) {
                    int del_mask = mask ^ (1 << i);
                    
                    if (mask_to_id.find(del_mask) != mask_to_id.end()) {
                        unite(id, mask_to_id[del_mask]);
                    }

                    if (delete_intermediates.find(del_mask) != delete_intermediates.end()) {
                        unite(id, delete_intermediates[del_mask]);
                    } else {
                        delete_intermediates[del_mask] = id;
                    }
                } 
                else {
                    int add_mask = mask | (1 << i);
                    if (mask_to_id.find(add_mask) != mask_to_id.end()) {
                        unite(id, mask_to_id[add_mask]);
                    }
                }
            }
        }

        return {num_groups, max_size};
    }
};