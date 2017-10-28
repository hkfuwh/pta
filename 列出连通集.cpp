#include<iostream>
#include<vector>
#include<string>
#include<stack>
#include<deque>
#include<stdlib.h>
#include<stdio.h>
#include<algorithm>
#define MaxH -10001
#define MaxSize 10000
using namespace std;
typedef struct binTreeNode *bintree;
typedef int ElementType;
typedef vector<int>::iterator it;
typedef vector< vector<int> > vvector;
struct binTreeNode
{
	bintree lChild;
	bintree rChild;
	ElementType ID;
//	int hight;
};
typedef struct TreeNode *Huffmantree;
struct TreeNode{
    int weight;
    char ch;
    Huffmantree left,right;
};
typedef Huffmantree minTree;
minTree creat(minTree p,int n);
void insert(minTree p,TreeNode& x);
Huffmantree DeleteMin(minTree h);
Huffmantree Huffman(minTree h);

void creatGr(vvector &vv,int NodeNum,int SideNum);
void BSF(vvector &vv,int i);/*广度优先所搜*/
void DSF(vvector &vv,int n);/*深度优先搜寻*/
void dsf(vector<int> &v,vvector &vv);
void listComponents(vvector &vv,int Nodes);
bool checked[10];
int main()
{
    vvector k;
    int N,S;
    cin>>N>>S;
    creatGr(k,N,S);
    listComponents(k,N);
	return 0;
}

void listComponents(vvector &vv,int Nodes)
{
    for(int i=0;i<Nodes;i++)
        checked[i]=false;
    for(int i=0;i<Nodes;i++)
    {
        if(!checked[i])
            DSF(vv,i);
    }
    for(int i=0;i<Nodes;i++)
        checked[i]=false;
    for(int i=0;i<Nodes;i++)
    {
        if(!checked[i])
            BSF(vv,i);
    }
}

void DSF(vvector &vv,int n)
{

    cout<<"{ ";
    dsf(vv[n],vv);
    cout<<"}\n";
}

void dsf(vector<int> &v,vvector &vv)
{
    if(checked[v.front()])
        return;
    checked[v.front()] = true;
    cout<<v.front()<<" ";
    for(it iter=v.begin()+1;iter!=v.end();iter++)
        if(!checked[*iter])
        {

            dsf(vv[*iter],vv);
        }
}

void BSF(vvector &vv,int i)
{
    deque<vector<int> > de;
    vector<int> tem;
    it iter;
    checked[i]=true;
    de.push_back(vv[i]);
    cout<<"{ ";
    while(!de.empty())
    {
        tem = de.front();
        de.pop_front();
        cout<<tem.front()<<" ";
        for(iter = tem.begin()+1;iter!=tem.end();iter++)
        {
            if(!checked[*iter])
            {
                checked[*iter] = true;
                de.push_back(vv[*iter]);
            }
        }
    }
    cout<<"}\n";
}

void creatGr(vvector &vv,int NodeNum,int SideNum)
{
    vv.resize(NodeNum);
    for(int i=0;i<NodeNum;i++)
        vv[i].push_back(i);/*首元素存储该节点信息*/
    int node1,node2;
    for(int i=0;i<SideNum;i++)/*添加边*/
    {
        cin>>node1>>node2;
        vv[node1].push_back(node2);
        vv[node2].push_back(node1);
    }
    for(int i=0;i<NodeNum;i++)
        sort(vv[i].begin()+1,vv[i].end());
}

//ElementType DeleteMin(minTree& h)
//{
//    int Parient,Child;
//    ElementType minItem,temp;
//    if(h.empty())
//        return MaxH;
//    minItem = h[1];/*取出最小元素*/
//    /*利用最小堆中的最后一个元素从根节点开始向上过滤下层结点*/
//    temp = h[h.size()-1];
//    h.pop_back();
//    for(Parient = 1;Parient*2<=h.size();Parient = Child)
//    {
//        Child = Parient*2;
//        if(Child!=h.size()&&h[Child]<h[Child+1])
//            Child++;
//        if(temp >= h[Child]) break;
//        else
//            h[Parient] = h[Child];
//    }
//    h[Parient] = temp;
//    return minItem;
//}
//
//Huffmantree Huffman(minTree& h)
//{
//   int i;
//   Huffmantree t;
//   for(i=2;i<h.size();i++)/*做h.size()-2次合并*/
//   {
//        t = malloc(sizeof(struct TreeNode));
//        t.left = DeleteMin(h);
//        t.right = DeleteMin(h);
//        t.weight = t.left.weight + t.right.weight;/*计算新的权值*/
//   }
//
//
//}
//
//minTree creat(minTree p,int n)
//{
//    char ch;
//    for(int i=0;i<n;i++)
//    {
//        p = malloc(sizeof(struct TreeNode));
//        cin>>p.ch>>p.weight;
//        return p;
//    }
//}
//
//void insert(minTree p,TreeNode& x)
//{
//    minTree::size_type i=p.size();
//    p.push_back(x);
//    for(;p[i/2]>x;i /= 2)
//        p[i] = p[i/2];
//    p[i] = x;
//}
//




