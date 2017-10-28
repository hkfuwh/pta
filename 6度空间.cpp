#include<iostream>
#include<math.h>
#include<vector>
#include<queue>
#include<algorithm>
#include<cstdlib>
#include<stdio.h>
using namespace std;
typedef vector< vector<int> > vvector;
typedef vector<int>::iterator iter;
int countnum;
int N,M;
bool Visited[10000];
vvector k;

void creat(vvector& k,int n,int m);
int BFS(int i);
void SDX();
int main()
{

    cin>>N>>M;
    creat(k,N,M);
    SDX();
    return 0;
}

void creat(vvector& k,int n,int m)
{
    k.resize(n+1);
    vector<int> tem;
    int p1,p2;;
    for(int i=0;i<m;i++)
    {
        cin>>p1>>p2;
        k[p1].push_back(p2);
        k[p2].push_back(p1);
    }

}

void SDX()
{
    for(int i=1;i<N+1;i++)
    {
        for(int ii=1;ii<N+1;ii++)
            Visited[ii]=false;
        countnum = BFS(i);
        printf("%d: %.2f%%\n",i,100*countnum/float(N));
    }
}

int BFS(int i)
{
    Visited[i] = true;
    int countnum = 1,level = 0,last = i,tail = i;
    queue<int> que;
    que.push(i);
    while(!que.empty())
    {
        i = que.front();
        que.pop();
        for(iter it = k[i].begin();it!=k[i].end();it++)
        {
            if(!Visited[*it])
            {
                Visited[*it] = true;
                que.push(*it);countnum++;
                tail = *it;
            }
        }
        if(last==i)
        {
            level++; last = tail;
        }
        if(level==6)break;
    }
    return countnum;
}
