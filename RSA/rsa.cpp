#include<iostream>
#include<math.h>
 
using namespace std;
 
//finding greatest common divisor
int gcd(int num1, int num2)
{
    int temp;
    while(1)
    {
        temp = num1 % num2;
        if(temp == 0)
            return num2;
        num1 = num2;
        num2 = temp;
    }
}
 
int main()
{
    double prime1;
    double prime2;
    cout<<"Enter two Prime Numbers : ";
    cin>>prime1>>prime2;
    double num = prime1*prime2;
    double count;
    double phi = (prime1-1)*(prime2-1);
 
    //public key
    double encr;
    cout<<"Enter the value of e in Public Key(n,e) : ";
    cin>>encr;
 
    //for checking whether co-prime satisfies encr>1
    while(encr < phi){
        count = gcd(encr, phi);
        if(count == 1)
            break;
        else
            encr++;
        }
 
    //private key
    double decr;

    //decr*encr = 1 + constant*phi
    double d = 1/encr;
    decr = fmod(d, phi);

    double message;
    cout<<"Enter the value of Message : ";
    cin>>message;
    
    double cipher = pow(message, encr);
    double originalMessage = pow(cipher, decr);
    cipher = fmod(cipher, num);
    originalMessage = fmod(originalMessage, num);
 
    cout<<endl<<"Message : "<<message;
    cout<<endl<<"First Prime : "<<prime1;
    cout<<endl<<"Second Prime : "<<prime2;
    cout<<endl<<"Num = (First Prime)*(Second Prime) : "<<num;
    cout<<endl<<"Phi = (First Prime -1)*(Second Prime -1) : "<<phi;
    cout<<endl<<"e in Public Key(n,e) : "<<encr;
    cout<<endl<<"d in Private Key(n,d) : "<<decr;
    cout<<endl<<"After Encryption : "<<cipher;
    cout<<endl<<"Original Message After Decryption : "<<originalMessage<<endl<<endl;
 
    return 0;
}
