#include<iostream>
#include<string.h>
using namespace std;

int temp(int key) {
	int i = 1;
	while (i <= 26) {
		if ((key * i) % 26 == 1) {
			return i;
		}
		i++;
	}
	return -1;
}

string enc(string s, int key) {
	string ans;

	for (auto i : s) {
		if (i == ' ') {
			ans += i;
			continue;
		}

		int n = i - 'A';
		// cout << n << " * " << key << endl;
		n = (n * key) % 26;
		// cout << n << endl;
		ans += char(n + 'A');
	}

	return ans.substr(0, ans.size());
}

string dec(string s, int key) {
	string ans;

	int k = temp(key);
	// cout << k << endl;
	for (auto i : s) {
		if (i == ' ') {
			ans += i;
			continue;
		}

		int n = i - 'A';
		n = (n * k) % 26;
		ans += char(n + 'A');
	}

	return ans;
}

int main()
{
	int key;
	string message;
	string encrypted = "";
	cout<<endl<<"Enter the Plaintext : ";	
	getline(cin, message);

	cout<<endl<<"Enter the key value : ";
	cin>>key;
	while(key <= 0 || key % 2 == 0 || key % 13 == 0)
	{
		cout<<"Please enter a valid key value : ";
		cin>>key;
	}

	cout<<endl<<"Cipher Text : "<<enc(message, key)<<endl<<endl; 
	encrypted = enc(message, key);
	cout<<"Original Message : "<<dec(encrypted, key)<<endl<<endl;

	return 0;
}