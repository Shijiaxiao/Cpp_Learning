//
//  main.cpp
//  Cantor unfold
//
//  Created by 史家箫 on 2022/3/25.
//
 
#include<iostream>

using namespace std;
 


long long stairs (int n) {
    long long result = 1;
    for (int i = 1; i <= n; i++)
        result *= i;
    return result;
}

long long cantor_single(string &str) {
    long long ans = 1;                     //注意，因为 12345 是算作0开始计算的，最后结果要把12345看作是第一个
    int len = int(str.length());
    for (int i = 0; i < len; i++) {
        int tmp = 0;                       //用来计数的
        for( int j = i + 1; j < len; j++)
            if(str[i] > str[j]) tmp++;     //计算str[i]是第几大的数，或者说计算有几个比他小的数
        ans += tmp * stairs(len - i - 1);
    }
    return ans;
}
 
long long cantor(string &str) {
    long long ans = 0;
    int len = int(str.length());
    for (int i = 1; i <= len - 1; i++)
        ans += stairs(i);
    ans += cantor_single(str);
    return ans;
}

int main() {
    string str;
    cin >> str;
    cout << cantor_single(str) << endl;
    cout << cantor(str) << endl;
}

