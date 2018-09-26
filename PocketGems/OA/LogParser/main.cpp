#include <iostream>
#include <fstream>
#include <iomanip>
#include <sstream>
#include <vector>

using namespace std;

class Solution {
public:
    string LogParser(string file_name) {
        ifstream ifs(file_name);
        time_t start, shutdown, connected;
        long long sum = 0, online = 0;
        string line;
        bool is_online = false;
        while (getline(ifs, line)) {
            string time = line.substr(1, 19);
            time_t cur = ParseTime(time);
            string status = line.substr(25);
            if (status == "START") {
                start = cur;
            } else if (status == "CONNECTED") {
                if (!is_online) {
                    is_online = true;
                    connected = cur;
                }
            } else if (status == "DISCONNECTED") {
                if (is_online) {
                    is_online = false;
                    online += difftime(cur, connected);
                }
            } else if (status == "SHUTDOWN") {
                shutdown = cur;
                sum = difftime(cur, start);
            }
        }
        if (is_online) {
            online += difftime(shutdown, connected);
        }
        is_online = false;
        if (sum == 0) return "0%";
        return to_string(int(online * 100.0 / sum)) + "%";
    }
    string parseLines(const std::vector < std::string >& lines) {
        time_t start, shutdown, connected;
        long long sum = 0, online = 0;
        string line;
        bool is_online = false;
        for (auto& line : lines) {
            string time = line.substr(1, 19);
            time_t cur = ParseTime(time);
            string status = line.substr(25);
            if (status == "START") {
                start = cur;
            } else if (status == "CONNECTED") {
                if (!is_online) {
                    is_online = true;
                    connected = cur;
                }
            } else if (status == "DISCONNECTED") {
                if (is_online) {
                    is_online = false;
                    online += difftime(cur, connected);
                }
            } else if (status == "SHUTDOWN") {
                shutdown = cur;
                sum = difftime(cur, start);
            }
        }
        if (is_online) {
            online += difftime(shutdown, connected);
        }
        is_online = false;
        if (sum == 0) return "0%";
        return to_string(int(online * 100.0 / sum)) + "%";
    }
private:
    time_t ParseTime(string& time) {
        struct tm t;
        istringstream ss(time);
        ss.imbue(locale("en_US.utf-8"));
        ss >> get_time(&t, "%d/%m/%Y-%H:%M:%S");
        return timelocal(&t);
    }
};

int main() {
    Solution a;
    cout << a.LogParser("input_3.txt");
    return 0;
}