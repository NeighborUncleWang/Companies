#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class JSON {  // base class for json data type
public:
    JSON() { }

    JSON(string json);  // constructor
    string toString();  // convert json data type to string that can be printed
    virtual string type();  // return type
    vector<string> keys();
    JSON get(string key);
};

class JSONMapping: public JSON {
public:
JSON get(string key); // return value corresponding to the key. 鍥磋鎴戜滑@1point 3 acres
vector<string> keys(); // return all the keys
string type() {return "JSONMapping";}
};

class JSONString: public JSON {
public:
    string value(); // return the string
    string type() {return "JSONString";}
};


class Solution {
public:
    vector<unordered_map<string, string>> ParseJSON(JSON& data, vector<string> columns) {
        vector<unordered_map<string, string>> res;
        unordered_map<string, string> table;
        helper(data, columns, 0, table, res);
        return res;
    }
private:
    void helper(JSON& data, vector<string> columns, int depth, unordered_map<string, string>& table, vector<unordered_map<string, string>>& res) {
        if (data.type() == "JSONMapping") {
            for (string& key : data.keys()) {
                JSON child = data.get(key);
                table[columns[depth]] = key;
                helper(child, columns, depth + 1, table, res);
//                table.erase(columns[depth]);
            }
        } else {
            string value = dynamic_cast<JSONString&>(data).value();
            table[columns[depth]] = value;
            res.push_back(table);
        }
    }
};