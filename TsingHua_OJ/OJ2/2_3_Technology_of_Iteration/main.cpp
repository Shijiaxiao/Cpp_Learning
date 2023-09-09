//
//  main.cpp
//  Technology of Iteration
//
//  Created by 史家箫 on 2022/4/4.
//

#include <iostream>
#include <vector>
#include <queue>
#include <stack>

using namespace std;

long n;
double *v, *s;                     //分别是速度和新产线的时间
double *ans;                       //每个点的最小时间
long *p, *d;                       //i有p[i]个 precursor nodes
vector <long> pre[100005];         //pre[i][k]为i的第k个前驱
vector <long> aft[100005];         //aft[i][k]为i的第k个后继
vector <double> prew[100005];      //prew[i][k]为需要的pre[i][k]的数量，它可通过f计算pre[i]到i的时间，即边权
queue  <long> q;


//计算生产need件产品的时间,v是速度，s是新建产线的时间
double f(double need, double v, double s) {
    double t = 0;
    // The quantity of production line:
    for (double i = 1; ; i++) {
        // Havn't constructed a production line yet:
        if (s >= need / (i*v))
            return t + need / (i*v);
        // Build a new line and construct at the same time:
        else {
            need -= s * i*v;
            t += s;
        }
    }
}

//注意：本题中所有点均减一
int main() {
    cin >> n;
    v = new double [n];
    s = new double [n];
    ans = new double [n];
    p = new long [n];
    d = new long [n];
    for (int i = 0; i < n; i++)
        ans[i] = 0;
    
    long x;
    double y;
    
    // Speed:
    for (long i = 0; i < n - 1; i++)
        cin >> v[i];
    // Building time:
    for (long i = 0; i < n - 1; i++)
        cin >> s[i];
    
    for (long i = 0; i < n; i++) {
        // Quantity of previous[i]:
        cin >> p[i];
        d[i] = p[i];
        for (int j = 0; j < p[i]; j++) {
            cin >> x >> y;
            // Precursor node
            pre[i].push_back(x - 1);
            // Need of precursor node
            prew[i].push_back(y);
            // Successor node
            aft[(x - 1)].push_back(i);
        }
    }
    
    // Topological Sorting:
    stack <long> sta;

    for (long j = 0; j < n; j++)
        if (p[j] == 0)
            sta.push(j);
    
    while (!sta.empty()) {
        long top = sta.top();
        sta.pop();
        q.push(top);
        // Acquiring the successor node:
        for (int i = 0; i < aft[top].size(); i++) {
            d[aft[top][i]]--;
            if (d[aft[top][i]] == 0)
                sta.push(aft[top][i]);
        }
    }
    
    //cout << (q.size() == n) ;
    
    for (long i = 0; i < n; i++) {
        //先更新更加“独立”的，这样后边就可以参考前边：
        long a = q.front();
        q.pop();
        //访问每个需要的前驱：
        for (long j = 0; j < p[a]; j++)
            ans[a] = max(ans[a], ans[pre[a][j]] + f(prew[a][j], v[pre[a][j]], s[pre[a][j]]));
    }
    
    /*
    for (long i = 0; i < n; i++) {
        for (long j = 0; j < p[i]; j++)
            ans[i] = max(ans[i], ans[pre[i][j]] + f(prew[i][j], v[pre[i][j]], s[pre[i][j]]));
    }
    */
    cout.precision(4);
    for (int i = 0; i < n; i++)
        cout << ans[i] << endl;
    return 0;
}

/*
 5
 2.0 4.0 10.0 3.0
 1.0 6.0 8.0 2.0
 0
 0
 0
 2 2 72.0 3 60.0
 3 1 72.0 2 120.0 4 44.0
 */
