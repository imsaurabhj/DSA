#include <bits/stdc++.h>
using namespace std;
// To find if the permutation of given substring is present in given main string
//i.e anagram of given substring
bool iscountsame(int a[],int b[])
{
    for(int i=0;i<256;i++){
        if(a[i]!=b[i])
            return false;
    }
    return true;
}

bool ispattern(string txt, string pat)
{
    int c_pat[256]={0};
    int c_txt[256]={0};
    for(int i=0;i<pat.size();i++)
    {
        c_pat[pat[i]]++;
        c_txt[txt[i]]++;
    }
    int i=0,j=pat.size()-1;
    if(iscountsame(c_pat,c_txt))
        return true;
    else{
        while(j<txt.size()-1)
        {
            c_txt[txt[i++]]--;
            c_txt[txt[++j]]++;
            if(iscountsame(c_txt,c_pat))
                return true;
        }
        return false;
    }
}
int main() {
	string s1="saurabh";
	string s2="ras";
	ispattern(s1,s2) ? cout<<"yes" : cout<<"No";
	return 0;
}
