#include<iostream>
#include<math.h>
#include<vector>
#include<algorithm>
using namespace std;
const int N=110;
const double iland_radius=7.5;
const int squre=100;

typedef struct point
{
    double x,y;
}position;

position P[N];
bool Visited[N];
int n;
double d;

void save007();
bool DFS(int v);
bool FirstJump(int v);
bool Jump(int v1,int v2);
bool IsSave(int v);

int main()
{
    cin>>n>>d;
    for(int i=0;i<n;i++)
    {
        Visited[i]=false;
        cin>>P[i].x>>P[i].y;
    }
    save007();
    return 0;
}

void save007()
{
    bool isSafe = false;
    for(int i=0;i<n;i++)
    {
        if(!Visited[i] && FirstJump(i))
        {
            isSafe = DFS(i);
            if(isSafe)
                break;
        }
    }
    if(isSafe) cout<<"Yes\n";
    else cout<<"No\n";
}

bool FirstJump(int v)
{
    return sqrt(P[v].x*P[v].x + P[v].y*P[v].y) <= d + iland_radius;
}

bool DFS(int v)
{
    Visited[v] = true;
    bool answer = false;
    if(IsSave(v))
        return true;
    for(int i=0;i<n;i++)
    {
        if(!Visited[i] && Jump(i,v))
        {
            answer = DFS(i);
            if(answer)
                break;
        }
    }
    return answer;
}

bool IsSave(int v)
{
    return (abs(P[v].x)>=50 - d || abs(P[v].y)>= 50 - d);
}

bool Jump(int v1,int v2)
{
    return sqrt((P[v1].x - P[v2].x)*(P[v1].x - P[v2].x)
                + (P[v1].y - P[v2].y)*(P[v1].y - P[v2].y)) <= d;
}
