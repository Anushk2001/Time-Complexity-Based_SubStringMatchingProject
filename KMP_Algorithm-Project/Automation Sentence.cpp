/*
Author               Anushk Gautam
Starting Date        5 November 2019
*/
#include<vector>
#include<iostream>
#include<algorithm>                
#include<string.h>                 
#include<bits/stdc++.h>            
#include<cstring>                  
#include<map>                     
#include<cmath>                  
#include<set>
using namespace std;
#define ll long long int
ll i,j;
void LPS(string pat ,ll lps[],ll M)
{   ll i=1,len=0;
//cout<<pat<<" ";
    lps[0]=0;
	while(i<M)
	{
		if(pat[i]==pat[len])
		{
			lps[i]=len+1;
			len++;
			i++;
		}
		else
		{
			if(len!=0)
			len=lps[len-1];
			else
			{
			lps[i]=0;
			i++;
			}
		}
	}
	return ;
}
ll KMP(string pat,string txt,ll lps[],ll N,ll M)
{
//cout<<pat<<txt<<" ";
//cout<<N<<" "<<M<<" ";

		ll i=0;
		ll j=0;
		while(i<N-M+1)
		{
			if(pat[j]==txt[i])
			{
				i++;
				j++;
//				cout<<"p";
			}
			else
			{
				if(j!=0)
				j=lps[j-1];
				else
				i++;
			}
			if(j==M)
			{
//				cout<<i<<"   "<<j;
//				cout<<endl;	
				return 1;
			}
		}
		return 0;
}

int main(){
ios_base::sync_with_stdio(0);
cin.tie(0);	
{
	string S,s;
cout<<"Please Input \"Text\" String\n";
cin>>S;
cout<<"Please Input \"Part\" String\n";
cin>>s;
ll n;
ll M=s.length();
ll N=S.length();
ll lps[M];
for(ll i=0;i<M;i++)
lps[i]=0;
LPS(s,lps,M);
cout<<"Click 1 for LPS Array of \"Part\"String ";
cin>>n;
if(n==1)
for(ll i=0;i<M;i++)
{
	cout<<lps[i]<<" ";
}
cout<<endl;
i=0,j=0;
if(KMP(s,S,lps,N,M)==1)
{
	cout<<"Yes Sentence Found\n";
	cout<<"Press 1 to Get the First Index\n";
	cin>>n;
	if(n==1)
	cout<<i-j+1<<"th Letter";
	else
	return 0;
}
else 
{
	cout<<"Sorry \"Part\" String is not a Substring of \"Text\" String";
}

   }


return 0;
}


