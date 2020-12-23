#include <iostream>
#include <utility>

using namespace std;

class Playfair
{
    private:
        string plaintext, key;
        int keysquare[5][5];
        char iorj;
    public:
        Playfair(string plaintext, string key)
        {
            this->plaintext = plaintext;
            if(plaintext.length() % 2 != 0)
                this->plaintext += 'z';
            this->key = key;
            
            if(charPresent('i'))
                this->iorj = 'i';
            else if (charPresent('j'))
                this->iorj = 'j';
            else
                this->iorj = 'i';
        }
    
        void display()
        {
            cout << "\nUpdated plaintext: " << this->plaintext << endl;
        }
        bool charPresent(char c)
        {
            // checks if char c is present in key
            if(this->key.find(c) != -1)
                return true;
            return false;
        }
        void generateKeySquare()
        {
            for (int i = 0; i < 26; i ++)
            {
                if(this->charPresent(char(i + 97)) || i == 8)
                    continue;
                
                else if(i == 9)
                    this->key += iorj;
                
                else
                    this->key += char(i+97);
            }
            
            // Converting string to matrix
            for(int i = 0; i < 5; i ++)
            {
                for(int j = 0; j < 5; j ++)
                {
                    keysquare[i][j] = this->key[i*5 + j];
                }
            }
        }
    
        void displayKeyMatrix()
        {
            cout << "\nKey matrix :\n";
            for(int i = 0; i < 5; i ++)
            {
                for(int j = 0; j < 5; j ++)
                {
                    cout << char(keysquare[i][j]) << " ";
                }
                cout << endl;
            }
            cout << endl;
        }
    
        string encrypt()
        {
            // Encrypts plaintext using key matrix
            
            int index1, index2;
            pair <int, int> pair1, pair2;
            
            for(int i = 0; i < plaintext.length(); i += 2)
            {
                index1 = int(key.find(plaintext[i]));
                pair1.first = index1 / 5;
                pair1.second = index1 % 5;
                index2 = int(key.find(plaintext[i+1]));
                pair2.first = index2 / 5;
                pair2.second = index2 % 5;
                
                if(pair1.second == pair2.second)
                {
                    // Case 1 : Same column
                    plaintext[i] = keysquare[(pair1.first + 1) % 5][pair1.second];
                    plaintext[i+1] = keysquare[(pair2.first + 1) % 5][pair2.second];
                }
                else if(pair1.first == pair2.first)
                {
                    // Case 2 : Same row
                    plaintext[i] = keysquare[pair1.first][(pair1.second + 1) % 5];
                    plaintext[i+1] = keysquare[pair2.first][(pair2.second + 1) % 5];
                }
                else
                {
                    // Case 3 : Other
                    plaintext[i] = keysquare[pair1.first][pair2.second];
                    plaintext[i+1] = keysquare[pair2.first][pair1.second];
                }
            }
            return plaintext;
        }
    
        string decrypt()
        {
            // Decrypts cipher text using key matrix
            
            int index1, index2;
            pair <int, int> pair1, pair2;
            
            for(int i = 0; i < plaintext.length(); i += 2)
            {
                index1 = int(key.find(plaintext[i]));
                pair1.first = index1 / 5;
                pair1.second = index1 % 5;
                index2 = int(key.find(plaintext[i+1]));
                pair2.first = index2 / 5;
                pair2.second = index2 % 5;
                
                if(pair1.second == pair2.second)
                {
                    // Case 1 : Same column
                    plaintext[i] = keysquare[(pair1.first + 4) % 5][pair1.second];
                    plaintext[i+1] = keysquare[(pair2.first + 4) % 5][pair2.second];
                }
                else if(pair1.first == pair2.first)
                {
                    // Case 2 : Same row
                    plaintext[i] = keysquare[pair1.first][(pair1.second + 4) % 5];
                    plaintext[i+1] = keysquare[pair2.first][(pair2.second + 4) % 5];
                }
                else
                {
                    // Case 3 : Other
                    plaintext[i] = keysquare[pair1.first][pair2.second];
                    plaintext[i+1] = keysquare[pair2.first][pair1.second];
                }
            }
            return plaintext;
        }
};

int main(int argc, const char * argv[]) {

    string plaintext, key;
    cout << "Enter plaintext: ";
    cin >> plaintext;
    cout << "Enter key: ";
    cin >> key;
    
    Playfair p(plaintext,key);
    p.display();
    p.generateKeySquare();
    p.displayKeyMatrix();
    cout << "After Encryption : Cipher Text = " + p.encrypt() << "\n\n";
    cout << "After Decryption : Plaintext Text = " + p.decrypt() << "\n\n";
    return 0;
}