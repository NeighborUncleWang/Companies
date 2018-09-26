#include <iostream>
#include <vector>
#include <unordered_map>
#include <map>
#include <queue>

using namespace std;

void getSumAverage(vector<int>& nums) {
    long long sum = 0;
    int average = 0, count = 0;
    for (int i = 0; i < nums.size(); i += 2) {
        sum += nums[i];
        ++count;
    }
    cout << sum << endl;
    cout << sum * 1.0 / count << endl;
}

pair<int, int> find_sum_and_avg(vector<int> ints)
{
    long long count = 0;
    long long sum = 0;
    for (int i = 0; i < ints.size(); i += 2) {
        sum += ints[i];
        ++count;
    }
    return pair<int, int>(sum, sum / count);
}




vector<int> deleteNElement(vector<int>& nums, int n) {
    map<int, int, greater<int>> treeMap;
    for (int num : nums) {
        ++treeMap[num];
    }
    vector<int> res;
    for (auto& it : treeMap) {
        if (it.second != n) {
            res.insert(res.end(), it.second, it.first);
        }
    }
    return res;
}

int find_two_closest_and_sum(vector < int > int_list, int target_num) {
    sort(int_list.begin(), int_list.end(), [=](int lhs, int rhs) {
        return abs(lhs - target_num) < abs(rhs - target_num);
    });
    return int_list[0] + int_list[1];
}


int twoClosests(vector < int > int_list, int target_num) {
    int first = 0, second = 0;
    int firstDiff = INT_MAX, secondDiff = INT_MAX;
    for (int num : int_list) {
        if (abs(num - target_num) < firstDiff) {
            first = num;
            firstDiff = abs(num - target_num);
        }
    }
    for (int num : int_list) {
        if (abs(num - target_num) < secondDiff && abs(num - target_num) > firstDiff) {
            second = num;
            secondDiff = abs(num - target_num);
        }
    }
    return first + second;
}

int secondMode(vector<int>& the_list) {
    int count = 1, first = the_list[0], second = the_list[0], firstCount = 1, secondCount = 1;
    for (int i = 1; i < the_list.size(); ++i) {
        if (the_list[i] == the_list[i - 1]) {
            ++count;
        } else {
            if (count > firstCount) {
                firstCount = count;
                first = the_list[i - 1];
            } else if (count > secondCount) {
                secondCount = count;
                second = the_list[i - 1];
            }
            count = 1;
        }
    }
    if (count > firstCount) {
        firstCount = count;
        first = the_list.back();
    } else if (count > secondCount) {
        secondCount = count;
        second = the_list.back();
    }
    return second;
}

int get_second_most_freq(vector<int> the_list) {
    unordered_map<int, int> map;
    for (int num : the_list) {
        ++map[num];
    }
    auto comp = [](pair<int ,int> lhs, pair<int, int> rhs) { return lhs.second > rhs.second; };
    priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(comp)> heap(comp);
    for (auto& it : map) {
        heap.push(it);
        if (heap.size() > 2) {
            heap.pop();
        }
    }
    return heap.top().first;
}


bool hasIntersect(pair<int, int> A, pair<int, int> B, pair<int, int> Q, pair<int, int> P, int n) {
    auto Vector = [](pair<int, int> A, pair<int, int> B) { return make_pair(B.first - A.first, B.second - A.second); };
    pair<int, int> AP = Vector(A, P);
    pair<int, int> AQ = Vector(A, Q);
    pair<int, int> BP = Vector(B, P);
    pair<int, int> BQ = Vector(B, Q);
    pair<int, int> PA = Vector(P, A);
    pair<int, int> QA = Vector(Q, A);
    pair<int, int> PB = Vector(P, B);
    pair<int, int> QB = Vector(Q, B);
    auto VectorProduct = [](pair<int, int> A, pair<int, int> B) -> long long
    { return A.first * B.second - A.second * B.first; };
    cout << "VectorProduct(AP, AQ) = " << VectorProduct(AP, AQ) << endl;
    cout << "VectorProduct(BP, BQ) = " << VectorProduct(BP, BQ) << endl;
    cout << "VectorProduct(PA, QA) = " << VectorProduct(PA, QA) << endl;
    cout << "VectorProduct(PB, QB) = " << VectorProduct(PB, QB) << endl;
    return VectorProduct(AP, AQ) * VectorProduct(BP, BQ) <= 0 && VectorProduct(PA, QA) * VectorProduct(PB, QB) <= 0;
}


int main() {
    pair<int, int> A = {1, 2};
    pair<int, int> B = {3, 2};
    pair<int, int> P = {4, 2};
    pair<int, int> Q = {6, 2};
    cout << hasIntersect(A, B, P, Q, 100);
    return 0;
}