#include <iostream>
#include <vector>
#include <queue>
using namespace std;
struct Node
{
	Node* par=this;
};
Node* findparent(Node* node)
{
	if (node->par == node) return node;
	return node->par = findparent(node->par);
}
bool join(Node* a, Node* b)
{
	a = findparent(a);
	b = findparent(b);
	if (a != b)
	{
		b->par = a;
		return 1;
	}
	else
		return 0;
}
int main()
{
	int n;
	cin >> n;
	vector<Node*> nodes(26);
	for (auto& node : nodes) node = new Node;
	vector<pair<char, char>> v;
	string s1, s2;
	cin >> s1 >> s2;
	for (int i = 0; i < n; i++)
	{
		char a, b;
		a = s1[i], b = s2[i];
		if (join(nodes[a - 'a'], nodes[b - 'a']))
		{
			v.push_back({ a,b });
		}
	}
	cout << v.size() << endl;
	for (auto& ans : v)
		cout << ans.first << " " << ans.second << endl;
	return 0;

}