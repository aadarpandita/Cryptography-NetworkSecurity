#include <bits/stdc++.h>
using namespace std;

string encode(string s, int k) {
    k = k%26+26;
    string ans, str;
    stringstream ss(s);

    while(getline(ss, str, ' ')) {
        if(str.empty()) {
            continue;
        }
        
        string temp;
        for(auto i : str) {
            if(i >= 'A' and i <= 'Z') {
                temp += (((i-'A')  + k)%26 + 'A');
            }else{
                temp += (((i-'a')  + k)%26 + 'a');
            }
        }

        ans += temp + ' ';
    }

    return ans.substr(0, ans.length()-1);
}

string decode(string s, int k) {
    k = k%26+26;
    string ans, str;
    stringstream ss(s);
    while(getline(ss, str, ' ')) {
        if(str.empty()) {
            continue;
        }
        
        string temp;
        for(auto i : str) {
            if(i >= 'A' and i <= 'Z') {
                temp += (((i-'A')  - k + 26)%26 + 'A');
            }else {
                temp += (((i-'a')  - k + 26)%26 + 'a');
            }
        }

        ans += temp + ' ';
    }

    return ans.substr(0, ans.length()-1);
}

int main() {
    string s = "impossible";
    int n = 2048*2048*-1;

    cout<<endl<<"String Entered = "<<s<<endl;
    cout<<"Key = "<<n<<endl;
    string e = encode(s, n);
    cout<<endl<<"String Encoded using General Caesar Cipher = "<<e<<endl;
    cout<<"String after decoding = "<<decode(e, n)<<endl<<endl;
    
    return 0;
}
