#include <iostream>
#include <vector>

using namespace std;

int QuickSelect(vector<int> a, int k)
{
	int x = a.back();
	
	vector<int> L;
	vector<int> E;
	vector<int> G;
	
	for(int i = 0; i < a.size(); i++)
	{
		if(a[i] < x)
		{
			L.push_back(a[i]);
		}
		else if(a[i] == x)
		{
			E.push_back(a[i]);
		}
		else
		{
			G.push_back(a[i]);
		}
	} // -1,5,6	7	8,9
	int elem = 0;
	if(k <= L.size())
	{
		elem = QuickSelect(L, k);
	}
	else if(k <= L.size() + E.size())
	{
		elem = x;
	}
	else
	{
		elem = QuickSelect(G, k-L.size()-E.size());
	}
	
	return elem;
}
int main()
{
	vector<int> v {-1,8,9,5,6,7};
	
	cout << QuickSelect(v,2) << endl;
	
	return EXIT_SUCCESS;
}
