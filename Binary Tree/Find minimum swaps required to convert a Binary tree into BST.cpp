#include<bits/stdc++.h>
using namespace std;
 
// Inorder Traversal of Binary Tree
void inorder(int a[], std::vector<int> &v,
                        int n, int index)
{
    // if index is greater or equal to vector size
    if(index >= n)
        return;
    inorder(a, v, n, 2 * index + 1);
     
    // push elements in vector
    v.push_back(a[index]);
    inorder(a, v, n, 2 * index + 2);
}
 
// Function to find minimum swaps to sort an array
int minSwaps(std::vector<int> &v)
{
    std::vector<pair<int,int> > t(v.size());
    int ans = 0;
    for(int i = 0; i < v.size(); i++)
        t[i].first = v[i], t[i].second = i;
     
    sort(t.begin(), t.end());
    for(int i = 0; i < t.size(); i++)
    {
        // second element is equal to i
        if(i == t[i].second)
            continue;
        else
        {
            // swapping of elements
            swap(t[i].first, t[t[i].second].first);
            swap(t[i].second, t[t[i].second].second);
        }
         
        // Second is not equal to i
        if(i != t[i].second)
            --i;
        ans++;
    }
    return ans;
}
 
// Driver code
int main()
{
    int a[] = { 5, 6, 7, 8, 9, 10, 11 };
    int n = sizeof(a) / sizeof(a[0]);
    std::vector<int> v;
    inorder(a, v, n, 0);
    cout << minSwaps(v) << endl;
}
 