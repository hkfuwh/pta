#include<iostream>
#include<vector>
#include<cstring>
#include<stack>
#include<stdlib.h>
using namespace std;
typedef struct treeNode *bintree;
typedef int Element;
typedef vector<int>::iterator it;
struct treeNode
{
	bintree lChild;
	bintree rChild;
	Element ID;
};

bintree creaTree(vector<Element>& T);
bintree insertNode(bintree t,Element x);
bool iscom(bintree t1,bintree t2);

int main()
{
    vector<Element> baseV,textV;
    bintree base,text;
    int n,m;
    cin>>n;//表示元素个数*/
    while(n!=0)
    {
        cin>>m;/*测试次数*/
        Element temp;
        for(int i=0;i<n;i++)/*创建基准搜索树*/
        {
            cin>>temp;
            baseV.push_back(temp);
        }
        base=creaTree(baseV);
        /*测试样例*/
        for(int j=0;j<m;j++)
        {
           for(int i=0;i<n;i++)
            {
                cin>>temp;
                textV.push_back(temp);
            }
            text=creaTree(textV);
            if(iscom(base,text))
                cout<<"Yes\n";
            else
                cout<<"No\n";
            textV.clear();/*清空text*/
        }
        baseV.clear();/*清空base*/
        cin>>n;//下一次输入
    }
    return 0;
}
bintree insertNode(bintree t,Element x)
{
    if(!t)
    {
        t=(bintree)malloc(sizeof(struct treeNode));
        t->ID=x;
        t->rChild=t->lChild=NULL;
    }

    else if(x<t->ID){
        t->lChild=insertNode(t->lChild,x);
        }else if(x>t->ID)
            t->rChild=insertNode(t->rChild,x);
        /*else x 已经存在，略过*/
    return t;
}

bintree creaTree(vector<Element>& T)
{
    bintree t=NULL;
    if(T.empty())
      return t;
    for(it i=T.begin();i!=T.end();i++)
    {
        t=insertNode(t,*i);
    }

    return t;
}

bool iscom(bintree t1,bintree t2)
{
    if(t1==NULL&&t2==NULL)/*both empty*/
        return true;
    if((t1==NULL&&t2!=NULL)||(t1!=NULL&&t2==NULL))/*only one is empty*/
        return false;
    if(t1->ID!=t2->ID)/*根节点不相同*/
        return false;
    /*根节点相同*/
    /*左子树为空的情况*/
//    if(t1->lChild==NULL&&t2->rChild==NULL)
//        return(iscom(t1->rChild,t2->rChild));
    /*左子树不空*/
    return(iscom(t1->lChild,t2->lChild)&&iscom(t1->rChild,t2->rChild));
}
