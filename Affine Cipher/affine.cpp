#include <iostream>
#include <string.h>

using namespace std;

int i,k,a,b,choice;
string plainText;
    
string encryption(string plainText)
{
		string cipherText = "";
                for(i = 0; i < plainText.length(); i++)
                {
                	if(plainText[i] != ' ' && a > 0)
                        	cipherText += (char) ((((a * (plainText[i] - 'A')) + b) % 26) + 'A');
                        else if(plainText[i] != ' ' && a < 0)
                        	cipherText += (char) ((((a * (plainText[i] - 'A')) + b) % 26 + 26) + 'A');
                	else
                		cipherText += plainText[i];	
                }
                return cipherText;
}

string decryption(string plainText)
{
		string text = "";
            	int a_inverse = 0;	
            	int flag = 0;
                for(k = 0; k < 26; k++)
                {
                    flag = (a * k) % 26;
                    
                    if(flag == 1)
                    {
                        a_inverse = k;
                    }
                }
                for(k = 0; k < plainText.length() ; k++)
                {
                	if(plainText[k] != ' ')
                		text += (char) (((a_inverse * ((plainText[k]+'A' - b)) % 26)) + 'A'); 
		        else
          			text += plainText[k];
                }
}

int main()
{
    cout<<endl<<"Enter the Plaintext : ";
    getline(cin, plainText);
    //cin.ignore();
    cout<<endl;

    cout<<"Enter the value of a & b : ";
    cin>>a>>b;

    while(a == 0 || a % 2 == 0 || a % 13 == 0)
    {
	cout<<endl<<"Inverse not possible.. Please try for different values of a and b"<<endl<<endl;
	cout<<"Enter the value of a & b : ";
	cin>>a>>b;
    }

    while(1)
    {
        cout<<endl<<"1.Encryption\n2.Decryption\n3.Exit\n";
        cout<<endl<<"Enter the choice value : ";
        cin>>choice;
	string cipherText;	
        switch(choice)
        {
            case 1:
            {
            	cipherText = encryption(plainText);
		cout<<endl<<"Ciphertext : "<<cipherText;
                cout<<endl;
                break;
            }
            case 2:
            {
            	string text = decryption(cipherText);
                cout<<endl<<"Plaintext : "<<text;
                cout<<endl;
                break;
            }
            case 3:
                {
                    exit(0);
                    break;
                }
        }
    }
    return 0;
}
