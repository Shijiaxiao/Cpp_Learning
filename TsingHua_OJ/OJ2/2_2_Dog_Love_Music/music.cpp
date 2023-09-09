//
//  main.cpp
//  Music
//
//  Created by 史家箫 on 2022/4/2.
//

// View this problem a shortest path one!

#include <iostream>
#include <cstring>
#include <queue>

using namespace std;

const int INF = 20000;

// This problem have 2^14 = 16384 nodes(status) in all:
char x[14];
int d[16384];
int vis[16384] = { 0 };
int previous[16384] = { 0 };

//计算不和谐度的函数（两位）default x > y:
int g(int y, int x) {
    if ((x - y) == 2)
        return 3;
    else if (((x - y) == 9) || ((x - y) == 7) || (x - 7 > 0 && x - y == 5) || (x + 7 < 15 && x - y == 5))
        return 4;
    else if ((x - y) == 4)
        return 5;
    else if (((x - y) == 11) || ((x - 7 > 0) && (x - y == 3)) || ((x + 7 < 15) && (x - y == 3)))
        return 6;
    else if ((x - y) == 6)
        return 7;
    else if (((x - y) == 13) || ((x - 7 > 0) && (x - y == 1)) || ((x + 7 < 15) && (x - y == 1)))
        return 8;
    else
        return 1000;
}

//计算不和谐度的函数（多位）y已经被又二进制 转换为整型：
int f(int y) {
    int ans = 0;
    vector <int> tmp;
    //钢琴的哪些按键被按下：
    for (int i = 0; i <= 13; i++)
        if ((y & (1 << i)))
            tmp.push_back(i);
    
    if (tmp.size() <= 1)
        return 0;
    
    for (int i = 0; i <= tmp.size() - 1; i++)
        for (int j = i + 1; j <= tmp.size() - 1; j++)
                ans ^= g(tmp[i], tmp[j]);
    
    return ans;
}

//计算二进制，方便存答案
int e(char x[14]) {
    int k = 0, m = 1;
    for (int i = 13; i >= 0; i--) {
        k += (x[i] - '0') * m;
        m = m * 2;
    }
    return k;
}

struct Node {
    // serial是这个节点的编号：
    int serial;
    // length是这个节点对键盘此时的不饱和度：
    int length;
    bool operator<(const Node &b) const { return length > b.length; }
} nod;

priority_queue <Node> q;

//用迪杰斯特拉算最短路径，部分思路借鉴于CSDN：
void dj(int x) {
    q.push({ x,d[x] });
    // Havn't reach the terminal status(0):
    while (!vis[0]) {
        // Haven't visit the shortest one:
        if (!vis[q.top().serial]) {
            vis[q.top().serial] = 1;
            //int k = f(q.top().serial); // g is the simplified version of f.
            
            // Acquiring the next node:
            for (int i = 0; i < 14; i++) {
                // The next serial number:
                int next = (q.top().serial) ^ (1 << i);
                int k = f(next); // g is the simplified version of f.
                // Update the shortest distance:
                if (d[next] > d[q.top().serial] + k) {
                    d[next] = d[q.top().serial] + k;
                    previous[next] = q.top().serial;
                    nod.serial = next;
                    nod.length = d[next];
                    q.push(nod);
                }
            }
        }
        q.pop();
    }
}

int main() {
    // Initialize distance to every node:
    for (int i = 0; i < 16384; i++)
        d[i] = INF;
    
    cin >> x;
    // Set start point, view as 2 binary->10 binary:
    int start = e(x);
    // Set the start distance to 0:
    d[start] = 0;
    dj(start);
    int end = 0;
    int path[1000] = { 0 };
    int k = 0;
    
    while (previous[end] != start) {
        path[++k] = previous[end];
        end = previous[end];
    }
    path[++k] = start;
    
    int answer[1000] = { 0 };
    
    for (int i = k; i >= 1; i--)
    {
        answer[i] = path[i] ^ path[i - 1];
        if      (answer[i] == 8192) cout << "G2 ";
        else if (answer[i] == 4096) cout << "A3 ";
        else if (answer[i] == 2048) cout << "B3 ";
        else if (answer[i] == 1024) cout << "C3 ";
        else if (answer[i] == 512)  cout << "D3 ";
        else if (answer[i] == 256)  cout << "E3 ";
        else if (answer[i] == 128)  cout << "F3 ";
        else if (answer[i] == 64)   cout << "G3 ";
        else if (answer[i] == 32)   cout << "A4 ";
        else if (answer[i] == 16)   cout << "B4 ";
        else if (answer[i] == 8)    cout << "C4 ";
        else if (answer[i] == 4)    cout << "D4 ";
        else if (answer[i] == 2)    cout << "E4 ";
        else if (answer[i] == 1)    cout << "F4 ";
    }
    cout << endl << d[0] << endl;
}

/*
 11111111111111
 F3 C4 G2 E4 B3 D4 A3 A4 B4 D3 G3 F4 E3 C3
 11
 */
