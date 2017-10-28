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
typedef vvector mgraph;
const int Infinite = 65535;

int N,M;
mgraph graph,D,path;

int findmax(int);
void creatgraph();
void floyd();
void buildgraph();
void findAniaml();

int main()
{
    buildgraph();
    findAniaml();
    return 0;
}

void buildgraph()
{
    creatgraph();


}

void creatgraph()
{
    int a,b;
    cin>>N>>M;
    graph.resize(N);
    for(int i=0;i<N;i++)
    {
        graph[i].assign(N,Infinite);
    }

    for(int i=0;i<M;i++)
    {
        cin>>a>>b;
        a--;b--;
        cin>>graph[a][b];
        graph[b][a]=graph[a][b];
    }
}

void findAniaml()
{
    int  maxlength;
    int mi=Infinite,ani=1;
    floyd();
    for(int i=0;i<N;i++)
    {
        maxlength=findmax(i);
        if(maxlength==Infinite)
        {
            cout<<"0\n";
            return;
        }

        if(maxlength<mi)
        {
            mi=maxlength;ani=i+1;
        }
    }

    cout<<ani<<" "<<mi<<endl;

}

int findmax(int i)
{
    int maxleng=0;
    for(int j=0;j<N;j++)
        if(i!=j && D[i][j]>maxleng)
            maxleng=D[i][j];
    return maxleng;
}

void floyd()
{
    D = graph;
    path.resize(N);
    for(int i=0;i<N;i++)
    {
        path[i].assign(N,-1);

    }


    for(int k=0;k<N;k++)
        for(int i=0;i<N;i++)
            for(int j=0;j<N;j++)
                if(D[i][k]+D[k][j]<D[i][j])
                {
                    D[i][j]=D[i][k]+D[k][j];
                    path[i][j] = k;
                }

}
