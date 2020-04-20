#include <iostream>
using namespace std;
//creating LPS array in cubic time complexity

int main() {
	string s="abbabb";
	int n=s.size(),temp=0;
	int lps[n]={0};
	for(int i=0;i<n;i++)
	{
	    for(int j=1;j<=i;j++)
	    {   int sos,sop;
	        if(s[j]==s[0])
	        {
	             sos=j,sop=0; temp=0;
	            while(s[sos]==s[sop] && sos<=i)
	            {
	                temp++; sos++; sop++;
	            }
	        }
	            if(sos==i+1)
	              { lps[i]=temp; break;}
	    }
	}
	for(int i=0;i<n;i++)
	    cout<<lps[i]<<" ";
	return 0;
}
