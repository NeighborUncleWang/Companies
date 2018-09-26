#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <set>

using namespace std;

struct Entry {
    int id;
    int frequence;
    Entry(int id, int frequence) {
        this->id = id;
        this->frequence = frequence;
    }
};

struct Solution {
    vector<string> split(string& str) {
        vector<string> result;
        stringstream ss(str);
        string temp;
        while (ss >> temp) {
            result.push_back(temp);
        }
        return result;
    }
    void preprocess(string fileName, string query) {
        fstream myFile(fileName);
        string temp;
        vector<Entry> result;
        for (int i = 0; getline(myFile, temp); ++i) {
            vector<string> words = split(temp);
            if (query.find('&') != string::npos) {
                int iter = query.find('&');
                string word1 = query.substr(0, iter - 1);
                string word2 = query.substr(iter + 2);
                int count1 = 0;
                int count2 = 0;
                for (string& word : words) {
                    if (word == word1) {
                        ++count1;
                    } else if (word == word2) {
                        ++count2;
                    }
                }
                if (count1 != 0 && count2 != 0) {
                    result.emplace_back(i, count1 + count2);
                }
            } else if (query.find('|') != string::npos) {
                int iter = query.find('|');
                string word1 = query.substr(0, iter - 1);
                string word2 = query.substr(iter + 2);
                int count1 = 0;
                int count2 = 0;
                for (string& word : words) {
                    if (word == word1) {
                        ++count1;
                    } else if (word == word2) {
                        ++count2;
                    }
                }
                if (count1 != 0 || count2 != 0) {
                    result.emplace_back(i, count1 + count2);
                }
            } else {
                int count = 0;
                for (string& word : words) {
                    if (word == query) {
                        ++count;
                    }
                }
                if (count != 0) {
                    result.emplace_back(i, count);
                }
            }
        }
        sort(result.begin(), result.end(), [](Entry& lhs, Entry& rhs) {
            if (lhs.frequence != rhs.frequence) {
                return lhs.frequence > rhs.frequence;
            } else {
                return lhs.id < rhs.id;
            }
        });
        vector<int> ids;
        for (Entry& entry : result) {
            cout << "id: " << entry.id << " frequence: " << entry.frequence << endl;
        }
    }
};

int main() {
    Solution a;
    string filename = "/Users/lixianshu/ClionProjects/IndeedOnsite/query上机题/input.txt";
    a.preprocess(filename, "python");
    return 0;
}