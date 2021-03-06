/*Reference : http://www.careercup.com/question?id=5644609608744960*/
Given a list of integers, e.g.:


{ 2, 6, 7, 9, 1, 0, 1, 2, 3, 6 }
. 
Write an time efficient algorithm to find the longest subset in which the difference between the minimum and maximum numbers is 0 or 1. 
The subset can have a length of 0 and can hold any of the values in the original array (order not matters).

Should be O(n), but I don't have c++11 handy so no hash table

/*Solution from careercup T = O(nlgn) becase of bst map*/
void Longest1Subset(int* pArr, int sz)
{
   std::map<int, int> counts; //should be hash table for O(n)
   for (int i = 0; i < sz; i++)
   {
       counts[pArr[i]]++; 
       counts[pArr[i]-1]++;
       printf("%d,", pArr[i]);
   }
   std::pair<int,int> res(0,0);
   for (std::map<int,int>::iterator i = counts.begin(); i != counts.end(); i++)
      res = res.second > i->second ? res : *i;
   printf(" => (%d to %d): %d\n", res.first, res.first+1, res.second);
}

int main()
{
   int test1[] = {1,5,1,0,2,6,2,1};
   int test2[] = {6,6,5,5,4,4,3,3,2,2,2,1,0,7,7,7,7};
   int test3[] = {0,0,-1,-1,-9,9,-9,9,-9,9,-9,-10,9};
   Longest1Subset(test1, sizeof(test1)/sizeof(*test1));
   Longest1Subset(test2, sizeof(test2)/sizeof(*test2));
   Longest1Subset(test3, sizeof(test3)/sizeof(*test3));
   getch();
}

/*My solution  T=O(n) because of HashMap*/
#include    <iostream>
#include    <algorithm>
#include    <unordered_map>
using namespace std;

void find(int a[],int n,int &s,int &l)
{
    unordered_map<int,int> m;
    for(int i=0;i<n;i++) {
        m[ a[i] ]++;
    }
    int max1 = 0;
    int cur = 0;
    int first;
    for(auto i : m) {
        cur = i.second + m[i.first+1];
        if(cur > max1) {
            s = i.first;
            max1 = cur;
        }
    }
    l = max1;
}
int main()
{
    //int a[] = { 2, 6, 7, 9, 1, 0, 1, 2, 3, 6 };
    //int a[] = {1,5,1,0,2,6,2,1};
    int a[] = {6,6,5,5,4,4,3,3,2,2,2,1,0,7,7,7,7};
    //int a[]=  {0,0,-1,-1,-9,9,-9,9,-9,9,-9,-10,9};
    int n = sizeof(a)/sizeof(a[0]);
    int s,l;
    find(a,n,s,l);
    cout<<"from "<<s<<" to "<<(s+1)<<" : "<<l<<endl;
    cout<<endl;
    return 0;
}
