Sparse number is an integer if there are no adjacent 1 in it's binary representation. 
Like: 5 -> 101 (no adjacent 1) 
9 -> 1001 (no adjacent 1) 
while 6-> 110 is not sparse number. 
Now you are given an integer find the NEXT BIGGER sparse number.Please mind 'it is next bigger'.

There are 2 possible number types you are going to deal with: 
1. already sparse number 
2. non-sparse number 

Algorithm for solution based on the 2 scenarios: 

1. Check if binary representation of number is Sparse, if it is: 

- Check if bin. number contains a sequence of at least 2 zeros: (i.e "xx1100xx" or "xx11001xx") this will enable for fitting a 1 just right at index of first 0 found and setting to 0 all the right remaining bits (i.e"1010010" to "1010100"). If index of first 2 zeros is 0, just return n+1, i.e"10100" to "10101"). 

-If it doesn't contain a seq. of 2 zeros 
shift N left of 1 and set all remaining bits to 0, 
return 1 << n (n = length of integer). *This is same as returning next higher power of 2. 
i.e"10101", "100000") 

2. If number is not sparse: 

- Check for highest index of a sequence of at least 2 ones (i.e "10011010001" - index 6) then we will see if we can put a 1 at starting index after sequence and set remaining bits to zero on the right side. (i.e: "10011010001" to "10100000000") 
If we find out we created a new seq. of 2 one's on that index (i.e: "10110010001" to "11000000000") then we keep flipping bits to 0 until we get to a point where previous bit is 0 and next is 1 (i.e "101xx") which is sparse, or 0. 


#include    <iostream>
using namespace std;

string convert(string str,int n)
{
    int i;
    for(i=n-1;i>0;i--) {
        if(str[i] == '0' && str[i-1] == '0')
            break;
    }
    if(i == 0)  return ('1'+string(n,'0'));

    str[i] = '1';
    if(i == n-1)    {
        return str;
    }
    str[i++] = '1';
    while(i<n) str[i++] = '0';
    return str;
}
bool isSparse(string str,int n) {
    for(int i=0;i<n-1;i++)
        if(str[i] == '1' && str[i+1] == '1')
            return false;
    return true;
}
string nonSparseConvert(string str,int n){
    int i;
    for(i=n-1;i>0;i--) {
        if(str[i] == '1' && str[i-1] == '1')
            break;
    }
    if(i == 0)  return str;
    i -= 2;
    for(;i>0;i--) {
        if(str[i]=='0' && str[i-1] == '0')
            break;
    }
    if(i == 0)  return ('1'+string(n,'0'));
    return nonSparseConvert( (string(str,0,i) + '1' + string(n-i-1,'0')), n);
}
int main()
{
    string str("100110");
    if(isSparse(str,str.length()))
        cout<< convert(str,str.length())<<endl;
    else
        cout<< nonSparseConvert(str,str.length())<<endl;
    return 0;
}


- If we get 0 then we just need to left shift 1 by the original number's length, example: "110010010" to "1000000000" (512). - Next power of 2. 


/*Another approach - similar question*/
//Ref::http://www.careercup.com/question?id=5186975457869824
/*
Sparse number is an integer if there are no adjacent 1 in it's binary representation. 
Like: 5 -> 101 (no adjacent 1) 
9 -> 1001 (no adjacent 1) 
while 6-> 110 is not sparse number. 
Now you are given an integer find the NEXT BIGGER sparse number.Please mind 'it is next bigger'.



Not sure about sparse number but below code will give no adjacent 1. Can someone check
*/
private static void nextSparse(int x) {
		for (int i = x + 1; i < Integer.MAX_VALUE; i++) {
			if ((i & (i * 2)) == 0) {
				System.out.println(i);
				return;
			}
		}
	}
