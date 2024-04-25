#include <iostream>
#include <list>
#include <vector>

using namespace std;

class Hashtable {
private:
    vector<list<pair<int, int>>> closed_table;
    vector<pair<int, int>> open_table;
    
    int table_size;
    string addressing_type;
    int hash_function(int key) {
        return key % table_size;
    }
    int linear_probing(int key, int i) {
        return (hash_function(key) + i) % table_size;
    }
    int quadratic_probing(int key, int i) {
        return (hash_function(key) + i * i) % table_size;
    }
    int double_hashing(int key, int i) {
        int h2 = 7 - (key % 7);
        return (hash_function(key) + i * h2) % table_size;
    }

public:

    Hashtable(int size, string type) : table_size(size), addressing_type(type) {
        closed_table.resize(table_size);
        open_table.resize(table_size, {0, -1});
    }

    void insert(int key, int value) {
        int index = hash_function(key);
        if (addressing_type == "closed") {
            closed_table[index].push_back({key, value});
        }
        else {
            int i = 0;
            int probe_index;
            if (addressing_type == "linear") {
                do {
                    probe_index = linear_probing(key, i++);
                } while (open_table[probe_index].second != -1 && open_table[probe_index].first != key);
            } else if (addressing_type == "quadratic") {
                do {
                    probe_index = quadratic_probing(key, i++);
                } while (open_table[probe_index].second != -1 && open_table[probe_index].first != key);
            } else {
                do {
                    probe_index = double_hashing(key, i++);
                } while (open_table[probe_index].second != -1 && open_table[probe_index].first != key);
            }
            open_table[probe_index] = {key, value};
        }
    }

    void remove(int key) {
        int index = hash_function(key);
        if (addressing_type == "closed") {
            auto &list = closed_table[index];
            for (auto it = list.begin(); it != list.end(); ++it) {
                if (it->first == key) {
                    list.erase(it);
                    return;
                }
            }
        } 
        else {
            int i = 0;
            int probe_index;
            if (addressing_type == "linear") {
                do {
                    probe_index = linear_probing(key, i++);
                } while (open_table[probe_index].second != -1 && open_table[probe_index].first != key);
            } else if (addressing_type == "quadratic") {
                do {
                    probe_index = quadratic_probing(key, i++);
                } while (open_table[probe_index].second != -1 && open_table[probe_index].first != key);
            } else {
                do {
                    probe_index = double_hashing(key, i++);
                } while (open_table[probe_index].second != -1 && open_table[probe_index].first != key);
            }
            open_table[probe_index] = {0, -1};
        }
    }

    int search(int key) {
        int index = hash_function(key);
        if (addressing_type == "closed") {
            for (const auto &kv : closed_table[index]) {
                if (kv.first == key) {
                    return kv.second;
                }
            }
        } 
        else {
            int i = 0;
            int probe_index;
            if (addressing_type == "linear") {
                do {
                    probe_index = linear_probing(key, i++);
                } while (open_table[probe_index].second != -1 && open_table[probe_index].first != key);
            } else if (addressing_type == "quadratic") {
                do {
                    probe_index = quadratic_probing(key, i++);
                } while (open_table[probe_index].second != -1 && open_table[probe_index].first != key);
            } else {
                do {
                    probe_index = double_hashing(key, i++);
                } while (open_table[probe_index].second != -1 && open_table[probe_index].first != key);
            }
            if (open_table[probe_index].first == key) {
                return open_table[probe_index].second;
            }
        }
        return -1;
    }
};

// Example usage
int main() {
    Hashtable hashtable_closed(10, "closed");
    hashtable_closed.insert(5, 10);
    hashtable_closed.insert(15, 20);
    hashtable_closed.remove(15);
    cout << hashtable_closed.search(5) << endl; 
    cout << hashtable_closed.search(15) << endl; 

    Hashtable hashtable_open_linear(10, "linear");
    hashtable_open_linear.insert(5, 10);
    hashtable_open_linear.insert(15, 20);
    hashtable_open_linear.remove(15);
    cout << hashtable_open_linear.search(5) << endl;
    cout << hashtable_open_linear.search(15) << endl; 
    return 0;
}
