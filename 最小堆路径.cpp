#include<iostream>
#include<vector>
#include<string>
#include<stack>
#include<deque>
#include<stdlib.h>
#include<stdio.h>
#define MaxH -10001
using namespace std;
typedef struct binTreeNode *bintree;
typedef int ElementType;
typedef vector<int>::iterator it;
struct binTreeNode
{
	bintree lChild;
	bintree rChild;
	ElementType ID;
//	int hight;
};
void insert(vector<int> &p,int x);
void creat(vector<int> &p,vector<int>::size_type n);
int main()
{
    int N,M;/*插入元素的个数，输出路径的条数*/
    scanf("%d %d",&N,&M);
    vector<int> mintree;
    creat(mintree,N);
    for(int i=0;i<N;i++)
    {
        int tem;
        cin>>tem;
        insert(mintree,tem);
    }
    for(int i=0;i<M;i++)
    {
        int index;
        cin>>index;
        cout<<mintree[index];
        for(int j=index/2;j!=0;j /= 2)
        {
            cout<<" "<<mintree[j];
        }
        cout<<endl;
    }
	return 0;
}

void creat(vector<int> &p,vector<int>::size_type n)
{
    p.reserve(n);
    p.push_back(MaxH);/*设置岗哨*/
}

void insert(vector<int> &p,int x)
{
    vector<int>::size_type i=p.size();
    p.push_back(0);
    for(;p[i/2]>x;i /= 2)
        p[i]=p[i/2];
    p[i]=x;
}
//
//int getHight(Blvtree t)
//{
//    if(!t)
//        return 0;
//    return t->hight;
//}


