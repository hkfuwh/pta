#include<iostream>
#include<vector>
#include<cstring>
#include<stack>
using namespace std;

vector<int>vecPre, vecInorder,vecPost;

struct Node
{
	Node *lChild;
	Node *rChild;
	int ID;
};

int findRootPos(int istart, int iend, int pstart)
{
	int pos = istart;
	for (int i = istart; i <= iend; ++i)
	{
		if (vecInorder[i] == vecPre[pstart])
			pos = i;
	}
	return pos;
}

void createTree(int pstart,int pend,int istart,int iend,Node *&root)
{
	if (istart > iend || pstart > pend)
		return;
	if (!root)
	{
		root = new Node();
		root->ID = vecPre[pstart];
	}
	int pos = findRootPos(istart,iend,pstart);

	createTree(pstart+1,pstart+pos-istart,istart,pos-1,root->lChild);
	createTree(pend-iend+pos+1,pend,pos+1,iend,root->rChild);
}

void postOrder(Node *root)
{
	if (root)
	{
		postOrder(root->lChild);
		postOrder(root->rChild);
		vecPost.push_back(root->ID);
	}
}

int main()
{
	int N, id;
	char input[5];
	//vector<int>vecorder;//1 for push,0 for pop
	stack<int> s;
	Node *root = NULL;
	scanf("%d", &N);

	for (int i = 0; i < 2 * N; ++i)
	{
		scanf("%s", input);
		//cout << strcmp(input, "Pop") << endl;
		if (strcmp(input, "Pop") == 0)
		{
			int temp = s.top();
			s.pop();
			vecInorder.push_back(temp);
		}
		else
		{
			scanf("%d", &id);
			s.push(id);
			vecPre.push_back(id);
		}
	}
	createTree(0, N - 1, 0, N - 1, root);
	postOrder(root);

	for (int i = 0; i < vecPost.size()-1; ++i)
	{
		printf("%d ",vecPost[i]);
	}
	printf("%d",vecPost[vecPost.size()-1]);
	return 0;
}
