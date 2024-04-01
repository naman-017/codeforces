#include <bits/stdc++.h>
using namespace std;
#define ll long long

void binary(int n, int end){
	
	for(int j=0; j<=end; j++){
		string s="";
    	for(int i=n-1; i>=0; --i){
    		int x=((j>>i) & 1);
        	s+=to_string(x);
    	}
    	bool check=false;
    	for(int i=0; i<n-1; i++){
    		if(s[i]=='1' && s[i+1]=='1'){
    			check=true;
    			break;
    		}
    	}
    	if(check==false)
    		cout << s << endl;
	}
}

int binaryToDecimal(int n) 
{ 
    int num = n; 
    int dec_value = 0; 
    int base = 1; 
    int temp = num; 
    while (temp) { 
        int last_digit = temp % 10; 
        temp = temp / 10; 
        dec_value += last_digit * base; 
        base = base * 2; 
    }
    return dec_value; 
}


int main()
{
	int n;
	cin >> n;
	string str = "";
	for(int i=0; i<n; i++){
		str+='1';
	}
	int end = binaryToDecimal(stoi(str));
	binary(n, end);
}
