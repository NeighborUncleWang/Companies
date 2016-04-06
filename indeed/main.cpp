#include <iostream>
#include <vector>
#include <sstream>
#include <algorithm>
#include <fstream>

using namespace std;

struct Entry {
    int id;
    int frequency;

    Entry(int id, int frequency) {
        this->id = id;
        this->frequency = frequency;
    }
};

vector<string> split(string &line) {
    stringstream ss(line);
    vector<string> result;
    string temp;
    while (ss >> temp) {
        result.push_back(temp);
    }
    return result;
}

void onlieTest() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int totalLines = 0;
    string fileName = "/Users/lixianshu/ClionProjects/Indeed/input001.txt";
    fstream myFile(fileName);
    myFile >> totalLines;
//    cin >> totalLines;
    vector<vector<string>> lines;
    string line;
    getline(myFile, line);
    for (int i = 0; i < totalLines; ++i) {
        getline(myFile, line);
//        cin >> line;
        vector<string> words = split(line);
        lines.push_back(move(words));
    }
    int totalQueries = 0;
    myFile >> totalQueries;
//    cin >> totalQueries;
    vector<string> queries;
    string query;
    getline(myFile, query);
    for (int i = 0; i < totalQueries; ++i) {
        getline(myFile, query);
//        cin >> query;
        queries.push_back(move(query));
    }
    vector<Entry> result;
    auto lambda = [](Entry &lhs, Entry &rhs) {
        if (lhs.frequency != rhs.frequency) {
            return lhs.frequency > rhs.frequency;
        } else {
            return lhs.id < rhs.id;
        }
    };
    for (int i = 0; i < totalQueries; ++i) {
        string query = queries[i];
        if (query.find('&') != string::npos) {
            int iter = query.find('&');
            string word1 = query.substr(0, iter - 1);
            string word2 = query.substr(iter + 2);
            for (int j = 0; j < totalLines; ++j) {
                int count1 = 0;
                int count2 = 0;
                for (string &word : lines[j]) {
                    if (word == word1) {
                        ++count1;
                    } else if (word == word2) {
                        ++count2;
                    }
                }
                if (count1 > 0 && count2 > 0) {
                    result.emplace_back(j + 1, count1 + count2);
                }
            }
            sort(result.begin(), result.end(), lambda);
            for (Entry &entry : result) {
                cout << entry.id << " ";
            }
            if (!result.empty()) {
                cout << endl;
            }
        } else if (query.find('|') != string::npos) {
            int iter = query.find('|');
            string word1 = query.substr(0, iter - 1);
            string word2 = query.substr(iter + 2);
            for (int j = 0; j < totalLines; ++j) {
                int count1 = 0;
                int count2 = 0;
                for (string &word : lines[j]) {
                    if (word == word1) {
                        ++count1;
                    } else if (word == word2) {
                        ++count2;
                    }
                }
                if (count1 > 0 || count2 > 0) {
                    result.emplace_back(j + 1, count1 + count2);
                }
            }
            sort(result.begin(), result.end(), lambda);
            for (Entry &entry : result) {
                cout << entry.id << " ";
            }
            if (!result.empty()) {
                cout << endl;
            }
        } else {
            for (int j = 0; j < totalLines; ++j) {
                int count = 0;
                for (string &word : lines[j]) {
                    if (word == query) {
                        ++count;
                    }
                }
                if (count > 0) {
                    result.emplace_back(j + 1, count);
                }
            }
            sort(result.begin(), result.end(), lambda);
            for (Entry &entry : result) {
                cout << entry.id << " ";
            }
            if (!result.empty()) {
                cout << endl;
            }
        }
        result.clear();
    }
}

//int main() {
//    onlieTest();
//    return 0;
//}



void readFromCin() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int totalLines = 0;
    string fileName = "/Users/lixianshu/ClionProjects/Indeed/input001.txt";
    fstream myFile(fileName);
//    myFile >> totalLines;
    cin >> totalLines;
    vector<vector<string>> lines;
    string line;
//    getline(myFile, line);
    getline(cin, line);
    for (int i = 0; i < totalLines; ++i) {
//        getline(myFile, line);
        getline(cin, line);
        vector<string> words = split(line);
        lines.push_back(move(words));
    }
    int totalQueries = 0;
    myFile >> totalQueries;
//    cin >> totalQueries;
    vector<string> queries;
    string query;
//    getline(myFile, query);
    getline(cin, query);
    for (int i = 0; i < totalQueries; ++i) {
//        getline(myFile, query);
        getline(cin, query);
        queries.push_back(move(query));
    }
    vector<Entry> result;
    auto lambda = [](Entry &lhs, Entry &rhs) {
        if (lhs.frequency != rhs.frequency) {
            return lhs.frequency > rhs.frequency;
        } else {
            return lhs.id < rhs.id;
        }
    };
    for (int i = 0; i < totalQueries; ++i) {
        string query = queries[i];
        if (query.find('&') != string::npos) {
            int iter = query.find('&');
            string word1 = query.substr(0, iter - 1);
            string word2 = query.substr(iter + 2);
            for (int j = 0; j < totalLines; ++j) {
                int count1 = 0;
                int count2 = 0;
                for (string &word : lines[j]) {
                    if (word == word1) {
                        ++count1;
                    } else if (word == word2) {
                        ++count2;
                    }
                }
                if (count1 > 0 && count2 > 0) {
                    result.emplace_back(j + 1, count1 + count2);
                }
            }
            sort(result.begin(), result.end(), lambda);
            for (Entry &entry : result) {
                cout << entry.id << " ";
            }
            if (!result.empty()) {
                cout << endl;
            }
        } else if (query.find('|') != string::npos) {
            int iter = query.find('|');
            string word1 = query.substr(0, iter - 1);
            string word2 = query.substr(iter + 2);
            for (int j = 0; j < totalLines; ++j) {
                int count1 = 0;
                int count2 = 0;
                for (string &word : lines[j]) {
                    if (word == word1) {
                        ++count1;
                    } else if (word == word2) {
                        ++count2;
                    }
                }
                if (count1 > 0 || count2 > 0) {
                    result.emplace_back(j + 1, count1 + count2);
                }
            }
            sort(result.begin(), result.end(), lambda);
            for (Entry &entry : result) {
                cout << entry.id << " ";
            }
            if (!result.empty()) {
                cout << endl;
            }
        } else {
            for (int j = 0; j < totalLines; ++j) {
                int count = 0;
                for (string &word : lines[j]) {
                    if (word == query) {
                        ++count;
                    }
                }
                if (count > 0) {
                    result.emplace_back(j + 1, count);
                }
            }
            sort(result.begin(), result.end(), lambda);
            for (Entry &entry : result) {
                cout << entry.id << " ";
            }
            if (!result.empty()) {
                cout << endl;
            }
        }
        result.clear();
    }
}

int main() {

    return 0;
}