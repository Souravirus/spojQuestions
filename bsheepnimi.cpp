#include <bits/stdc++.h>

using namespace std;

vector<int> convexHull(vector<pair<int, int> > &V);
bool isLeftTurn(int a, int b, int c, vector<pair<int, int> > &V);


int main()
{
    int t;
    scanf("%d", &t);
    while(t--)
    {
        int n;
        scanf("%d", &n);
        vector<pair<int, int> > V(n);
        for(int i = 0; i < n; i++)
        {
            int a, b;
            scanf("%d %d", &a, &b);
            V[i].first = a, V[i].second = b;
        }
        sort(V.begin(), V.end());
        vector<int> ans = convexHull(V);
    }
    return 0;
}

vector<int> convexHull(vector<pair<int, int> > &V)
{
    vector<int> upper, lower;
    upper.push_back(0);
    upper.push_back(1);
    int a, b, c;
    for(int i = 2; i < V.size(); i++)
    {
        upper.push_back(i);
        if(upper.size() < 3)
            continue;
        a = upper[upper.size() - 1], b = upper[upper.size() - 2], c = upper[upper.size() - 3];
        while(isLeftTurn(c, b, a, V))
        {
            upper.pop_back();
            upper.pop_back();
            upper.push_back(a);
            if(upper.size() < 3)
                break;
            a = upper[upper.size() - 1], b = upper[upper.size() - 2], c = upper[upper.size() - 3];
        }
    }
    lower.push_back(n - 1);
    lower.push_back(n - 2);
    for(int i = n - 3; i >= 0; i--)
    {
        lower.push_back(i);
        if(lower.size() < 3)
            continue;
        a = lower[lower.size() - 1], b = lower[lower.size() - 2], c = lower[lower.size() - 3];
        while(isLeftTurn(c, b, a, V))
        {
            lower.pop_back();
            lower.pop_back();
            lower.push_back(a);
            if(lower.size() < 3)
                break;
            a = lower[lower.size() - 1], b = lower[lower.size() - 2], c = lower[lower.size() - 3];
        }
    }
    upper.insert(upper.end(), lower.begin(), lower.end());
    return upper;
}

bool isLeftTurn(int a, int b, int c, vector<pair<int, int> > &V)
{

}
