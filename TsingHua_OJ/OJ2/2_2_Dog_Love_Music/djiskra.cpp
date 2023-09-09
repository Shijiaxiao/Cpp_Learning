//
//  main.cpp
//  Djisktra_all
//
//  Created by 史家箫 on 2022/4/3.
//

#include <iostream>
#include <cstring>
#include <set>
#include <vector>

using namespace std;

const int INF = 20000;

// This problem have 2^14 = 16384 nodes(status) in all:
char x[14];
int vis[16384] = { 0 };
int ways = 0;
vector <int> previous;
vector <vector <int>> all_previous;
// int previous[10][16384] = { 0 };

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
    // serial number of this node：
    int serial;
    // distance是这个节点对键盘此时的不饱和度：
    int distance;
    // Recording all previous nodes:
    vector <int> previous;
    int possibilities;
    // Ranking function:
    bool operator<(const Node & temp) const {
        if (distance == temp.distance) {
            if (serial == 0) return false;
            else if (temp.serial == 0) return true;
            else return serial < temp.serial;
        }
        else return distance < temp.distance;
    }
} nod;
Node nodes[16384];

set <Node> q;

// Dijkstra:
void dj(int x) {
    q.insert(nodes[x]);
    // Havn't reach the terminal status(0):
    while (!vis[0]) {
        int current = q.begin()->serial;
        // Haven't visit the shortest one:
        // Is this if a must? Yes! One node might be enqueue and dequeue in different times!
        if (!vis[current]) {
            vis[current] = 1;
            if (current == 0)
                break;
            // Acquiring the next node:
            for (int i = 0; i < 14; i++) {
                // The next serial number:
                int next = (current) ^ (1 << i);
                int d_temp = f(next); // g is the simplified version of f.
                // Update the shortest distance:
                if (nodes[next].distance > nodes[current].distance + d_temp) {
                    // Ready to npdate:
                    // Already in queue, throw it!
                    if ((q.find(nodes[next]) != q.end()) || (q.end()->serial == next)) // Already in queue, fuck it!
                        q.erase(nodes[next]);
                    nodes[next].distance = nodes[current].distance + d_temp;
                    // Discard thr former previous nodes:
                    if (nodes[next].previous.size())
                        nodes[next].previous.clear();
                    nodes[next].previous.push_back(current);
                    nodes[next].possibilities = int(nodes[next].previous.size());
                    // in queue:
                    q.insert(nodes[next]);
                }
                else if (nodes[next].distance == nodes[current].distance + d_temp) {
                    q.erase(nodes[next]);
                    nodes[next].previous.push_back(current);
                    nodes[next].possibilities = int(nodes[next].previous.size());
                    q.insert(nodes[next]);
                }
            }
        }
        // Top serial won't change!
        q.erase(nodes[current]);
    }
}

void store_data(int x, int start) {
    
    if (x == start) {
        cout << "Asshole!\n";
        all_previous.push_back(previous);
        return;
    }
    
    for (int i = 0; i < nodes[x].possibilities; i++) {
        previous.push_back(nodes[x].previous[i]);
        store_data(nodes[x].previous[i], start);
        previous.pop_back();
    }
        
    
}

int main() {
    // Initialize distance to every node:
    for (int i = 0; i < 16384; i++) {
        nodes[i].serial = i;
        nodes[i].distance = INF;
    }
        
    
    cin >> x;
    // Set start point, view as 2 binary->10 binary:
    int start = e(x);
    // Set the start distance to 0:
    nodes[start].distance = 0;
    dj(start);
    int end = 0;
    
    store_data(end, start);

    for (int i = 0; i < all_previous.size(); i++) {
        for (int j = int(all_previous[i].size() - 1); j >= 0; j--) {
            
            int answer;
            if (j == 0) answer = all_previous[i][j] ^ end;
            else        answer = all_previous[i][j] ^ all_previous[i][j - 1];
            
            if      (answer == 8192) cout << "G2 ";
            else if (answer == 4096) cout << "A3 ";
            else if (answer == 2048) cout << "B3 ";
            else if (answer == 1024) cout << "C3 ";
            else if (answer == 512)  cout << "D3 ";
            else if (answer == 256)  cout << "E3 ";
            else if (answer == 128)  cout << "F3 ";
            else if (answer == 64)   cout << "G3 ";
            else if (answer == 32)   cout << "A4 ";
            else if (answer == 16)   cout << "B4 ";
            else if (answer == 8)    cout << "C4 ";
            else if (answer == 4)    cout << "D4 ";
            else if (answer == 2)    cout << "E4 ";
            else if (answer == 1)    cout << "F4 ";
        }
        cout << endl << nodes[end].distance << endl;
    }
    return 0;
}

/*
 11111111111111
 F3 C4 G2 E4 B3 D4 A3 A4 B4 D3 G3 F4 E3 C3
 00000000000111
 */
