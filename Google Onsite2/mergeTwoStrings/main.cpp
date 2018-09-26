#include <iostream>
#include <string>
#include <vector>
using namespace std;
long factorial(long n){
    long fact = 1;
    for (long i = 1; i<= n; ++i)
        fact *= i;
    return fact;
}

void DFS(const string &s1, int m, int i,
         const string&s2, int n, int j,
         string path,vector<string> &ret)
{
    if(i==m &&j==n)  {
        ret.push_back(path);
        return;
    }
    if(i < m)  DFS(s1, m, i+1, s2, n, j, path+s1[i], ret);
    if(j < n)  DFS(s1, m, i, s2, n, j+1, path+s2[j], ret);
}

vector<string> combineTowStrings(const string &s1,const string &s2) {
    int m =s1.length(), n = s2.length();
    long count =factorial(m+n)/factorial(n)/factorial(m);
    cout <<"count:" << count << endl;
    vector<string> ret;
    DFS(s1, m, 0, s2,n, 0, "", ret);
    return ret;
}

int main() {
    vector<string> ret = combineTowStrings("AB","CDF");
    cout <<ret.size() << endl;
    for(string &s: ret)  cout << s << endl;
    return 0;


}