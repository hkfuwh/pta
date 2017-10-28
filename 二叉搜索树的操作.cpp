/* #include<iostream>
#include<vector>
#include<deque>
using namespace std;

struct */
typedef struct TNode *Position;
typedef Position BinTree;
struct TNode{
    ElementType Data;
    BinTree Left;
    BinTree Right;
};

BinTree Insert( BinTree BST, ElementType X )
{
    if(!BST)
    {
        BST=(BinTree)malloc(sizeof(struct TNode));
        BST->Data=X;
        BST->Left=BST->Right=NULL;
    }else if(X<BST->Data)
        {
            BST->Left=Insert(BST->Left,X);
        }else if(X>BST->Data)
            {
                BST->Right=Insert(BST->Right,X);
            }
        /*else  x==BST->Data*/
    return BST;
}

BinTree Delete( BinTree BST, ElementType X )
{/*返回结果树的跟指针，若x不存在则 打印Not Found*/
    BinTree tmp;
    if(!BST)
        printf("Not Found\n");
    else if(X<BST->Data)
    {
        BST->Left=Delete(BST->Left,X);
    }else if(X>BST->Data)
        {
            BST->Right=Delete(BST->Right,X);
        }
        /*else 找到了*/
        else
        {
            if(BST->Right&&BST->Left)
            {
                tmp=FindMin(BST->Right);/*找到右子树中最小的元素*/
                BST->Data=tmp->Data;
                BST->Right=Delete(BST->Right,BST->Data);/*删除右子树中的最小元素*/
            }else{
                tmp=BST;
                if(!BST->Left)/*有右孩子或无子*/
                    BST=BST->Right;
                else if(!BST->Right)/*有左孩子*/
                    BST=BST->Left;
                free(tmp);
            }
        }
    return BST;
}

Position Find( BinTree BST, ElementType X )
{
    if(!BST)
        return NULL;
    if(X<BST->Data)
    {
        BST=Find(BST->Left,X);
    }else if(X>BST->Data)
    {
        BST=Find(BST->Right,X);
    }
    /*else 找到了*/
    return BST;
}

Position FindMin( BinTree BST )
{
    if(!BST)
      return NULL;
    while(BST->Left)
    {
        BST=BST->Left;
    }
    return BST;
}

Position FindMax( BinTree BST )
{
    if(!BST)
      return NULL;
    while(BST->Right)
    {
        BST=BST->Right;
    }
    return BST;
}