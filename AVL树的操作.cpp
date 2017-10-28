#include <iostream>
#include <string>

typedef struct AVLTreeNode{
    int Data;
    AVLTreeNode *Left;
    AVLTreeNode *Right;
    int Height;
}nAVLTree ,*pAVLTree;

pAVLTree AVLInsertion( int nodeValue, pAVLTree pAvl );
int GetALVHeight( pAVLTree );
pAVLTree SingleLeftRotation( pAVLTree );
pAVLTree DoubleLeftRotation( pAVLTree );
pAVLTree SingleRightRotation( pAVLTree );
pAVLTree DoubleRightRotation( pAVLTree );
int Max( int hight1, int hight2 );
using namespace std;

int main()
{
    int num;
    int i;
    int value;
    pAVLTree pAvl;
    pAvl = NULL;
    cin >> num;
    for ( i = 0; i < num; i++ )
    {
        cin >> value;
        pAvl = AVLInsertion( value, pAvl);
    }
    cout << pAvl->Data;
}

pAVLTree AVLInsertion( int nodeValue, pAVLTree pAvl )
{
    if ( pAvl == NULL )
    {
        pAvl = ( pAVLTree )malloc( sizeof( nAVLTree ) );
        pAvl->Left = pAvl->Right = NULL;
        pAvl->Data = nodeValue;
        pAvl->Height = 0;
    }
    else if ( nodeValue < pAvl->Data )
    {
        pAvl->Left = AVLInsertion( nodeValue, pAvl->Left );
        if ( GetALVHeight( pAvl->Left ) - GetALVHeight( pAvl->Right ) == 2 )
        {
            if ( nodeValue < pAvl->Left->Data )
            {
                pAvl = SingleLeftRotation( pAvl );
            }
            else
            {
                pAvl = DoubleLeftRotation( pAvl );
            }
        }
    }
    else if ( nodeValue > pAvl->Data )
    {
        pAvl->Right = AVLInsertion( nodeValue, pAvl->Right );
        if ( GetALVHeight( pAvl->Right ) - GetALVHeight( pAvl->Left ) == 2 )
        {
            if ( nodeValue > pAvl->Right->Data )
            {
                pAvl = SingleRightRotation( pAvl );
            }
            else
            {
                pAvl = DoubleRightRotation( pAvl );
            }
        }
    }
    pAvl->Height = Max( GetALVHeight( pAvl->Left ), GetALVHeight( pAvl->Right ) ) + 1;
    return pAvl;
}

pAVLTree SingleLeftRotation( pAVLTree A )
{
    pAVLTree B = A->Left;
    A->Left = B->Right;
    B->Right = A;
    A->Height = Max( GetALVHeight( A->Left ), GetALVHeight( A->Right ) ) + 1;
    B->Height = Max( GetALVHeight( B->Left ), A->Height ) + 1;
    return B;
}

pAVLTree DoubleLeftRotation( pAVLTree A )
{
    A->Left = SingleRightRotation( A->Left );
    return SingleLeftRotation( A );
}

pAVLTree SingleRightRotation( pAVLTree A )
{
    pAVLTree B = A->Right;
    A->Right = B->Left;
    B->Left = A;
    A->Height = Max( GetALVHeight( A->Left ), GetALVHeight( A->Right ) ) + 1;
    B->Height = Max( GetALVHeight( B->Right ), A->Height ) + 1;
    return B;
}

pAVLTree DoubleRightRotation( pAVLTree A )
{
    A->Right = SingleLeftRotation( A->Right );
    return SingleRightRotation( A );
}

int GetALVHeight( pAVLTree pAvl)
{
    if ( pAvl == NULL )
    {
        return 0;
    }
    else
    {
        return pAvl->Height;
    }
}

int Max( int hight1, int hight2 )
{
    return hight1 > hight2 ? hight1 : hight2;
}