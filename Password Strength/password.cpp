#include<bits/stdc++.h>
using namespace std;

int main()
{
  char choice;
  do{
    bool hasUpper = false;
    bool hasLower = false;
    bool hasDigit = false;
    bool hasSpecial = false;

    string password;
    cout<<"Please enter your password : ";
    cin>>password;
    
    for(int i = 0; i < password.length(); i++)
    {
      if(islower(password[i]))
        hasLower = true;
      
      if(isupper(password[i]))
        hasUpper = true;
      
      if(isdigit(password[i]))
        hasDigit = true;
      
      if(!isalpha(password[i]) && !isdigit(password[i]))
        hasSpecial = true;  
    }
    
    if(hasLower && hasUpper && hasDigit && hasSpecial && password.length() >= 10)
      cout<<"You have a Strong Password"<<endl;
    else if(hasLower && hasUpper && hasDigit && password.length() >= 6 || hasSpecial && hasUpper && hasDigit && password.length() >= 6 || hasLower && hasSpecial && hasDigit && password.length() >= 6 || hasLower && hasUpper && hasSpecial && password.length() >= 8)
      cout<<"You have a Moderate password"<<endl;
    else
      cout<<"You have a Weak password"<<endl;
    
    cout<<endl<<"Would you like to check the strength of another password? Y/N : ";
    cin>>choice;
    cout<<endl;
    }while(choice == 'y' || choice == 'Y');

  return 0;
}
