#include<iostream>
#include<cstring>
using namespace std;

void encode(string message, int key)
{
	int message_length = message.length();

	
	char message_char[message_length];
	strcpy(message_char, message.c_str());
	
	char matrix[key][message_length];
	
	for(int i=0; i< key; i++)
	{
		for(int j=0; j< message_length; j++)
		{
			matrix[i][j]='*';
		}
	}
	
	int row = 0, count = -1;
	for(int i = 0; i < message_length; ++i)
	{
        matrix[row][i] = message_char[i];
 
        if(row == 0 || row == key-1)
		{
            count= count * (-1);
		}
 
        row = row + count;
    }

	cout<<"Cipher Text : ";

	for(int i=0; i< key; i++)
	{
		for(int j=0; j< message_length; j++)
		{
			if(matrix[i][j] != '*')
			{
				cout<<matrix[i][j];
			}
		}
	}
	cout<<endl;
}

void decode(string message, int key)
{
	int message_length = message.length();
	
	char message_char[message_length];
	strcpy(message_char, message.c_str());

	char matrix[key][message_length];
	
	for(int i=0; i< key; i++)
	{
		for(int j=0; j< message_length; j++)
		{
			matrix[i][j]='*';
		}
	}
	
	for(int i = 0,row = 0, k = -1; i < message_length; ++i)
	{
        matrix[row][i] = '#';
 
        if(row == 0 || row == key-1)
		{
			k= k * (-1);
		}
        row = row + k;
    }
 
	int m=0;
    for(int i = 0; i < key; ++i)
	{
        for(int j = 0; j < message_length; ++j)
		{
            if(matrix[i][j] == '#')
			{
                matrix[i][j] = message_char[m++];
			}
		}
 
	}

	cout<<"Original Message after Decoding : ";
	for(int i = 0,row = 0,k=-1; i < message_length; ++i)
	{
        cout<<matrix[row][i];
 
        if(row == 0 || row == key-1)
            k= k * (-1);
 
        row = row + k;
    }
    cout<<endl;
}

int main()
{
	int key = 0;
	bool keySmallTwo = true;
	string message;
	int choose_num;
	bool num_true = true;
	
	cout<<"Enter the Plain Text : ";
	getline(cin, message);
	cout<<endl;
	
	cout<<"Enter the rails value : ";
	while(keySmallTwo)
	{
		cin>>key;
		if(key<2)
		{
			cout<<"Rails value must be at least 2 : "<<endl;
			cout<<"Enter the rails value : ";
		}
		else
		{
			keySmallTwo = false;
		}
	}
	
	cout<<"1. Encode or 2. Decode : ";
	while(num_true)
	{
		cin>>choose_num;
		if(choose_num < 1 || choose_num > 2)
		{
			cout<<"1. or 2."<<endl;
			cout<<"1. Encode or 2. Decode : ";
		}
		else
		{
			num_true = false;
		}
	}
	
	if(choose_num == 1)
		encode(message, key);
	else
		decode(message, key);
	
	return 0;
}