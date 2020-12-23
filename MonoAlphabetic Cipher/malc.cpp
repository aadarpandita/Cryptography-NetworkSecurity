#include<bits/stdc++.h>

using namespace std;

string encrypt(string s, unordered_map<char, char> &mp) 
{
	string ans;
	for (auto i : s) 
	{
		if (mp.count(i)) {
			ans += mp[i];
		} 
		else {
			ans += i;
		}
	}
	return ans;
}

string decrypt(string s, unordered_map<char, char> &mp) 
{
	string ans;
	for (auto i : s) 
	{
		if (mp.count(i)) {
			ans += mp[i];
		} 
		else {
			ans += i;
		}
	}
	return ans;
}

int main() 
{

unordered_map<char, char> encode = {{'A', 'Q'}, {'B', 'W'}, {'C', 'E'}, {'D', 'R'},
{'E', 'T'}, {'F', 'Y'}, {'G', 'U'}, {'H', 'I'},
{'I', 'O'}, {'J', 'P'}, {'K', 'A'}, {'L', 'S'},
{'M', 'D'}, {'N', 'F'}, {'O', 'G'}, {'P', 'H'},
{'Q', 'J'}, {'R', 'K'}, {'S', 'L'}, {'T', 'Z'},
{'U', 'X'}, {'V', 'C'}, {'W', 'V'}, {'X', 'B'},
{'Y', 'N'}, {'Z', 'M'}
};

unordered_map<char, char> decode = {{'Q', 'A'}, {'W', 'B'}, {'E', 'C'}, {'R', 'D'},
{'T', 'E'}, {'Y', 'F'}, {'U', 'G'}, {'I', 'H'},
{'O', 'I'}, {'P', 'J'}, {'A', 'K'}, {'S', 'L'},
{'D', 'M'}, {'F', 'N'}, {'G', 'O'}, {'H', 'P'},
{'J', 'Q'}, {'K', 'R'}, {'L', 'S'}, {'Z', 'T'},
{'X', 'U'}, {'C', 'V'}, {'V', 'W'}, {'B', 'X'},
{'N', 'Y'}, {'M', 'Z'},
};

	cout << endl <<"Mapped Alphabets : " <<endl;
	for (auto i : encode) 
	{
		cout << i.first << " : " << i.second << ", ";
	}
	cout << endl <<endl;
	
	string s;
	
	cout << "Enter Plaintext : " ;
	cin >> s;

	string e = encrypt(s, encode);
	string d = decrypt(e, decode);

	cout << "Encoded Text : " << e << endl;
	cout << "Decoded Text : " << d << endl;

	return 0;
}