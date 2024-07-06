//NUMBER GUESSING GAME
#include<iostream>
#include<time.h>
using namespace std;
int main()
{
    srand(time(0));
    int random_no=(rand()%1000)+1;
    cout<<"*****Guess a random number between 1 and 1000*****"<<endl;
    int s=1,e=1000;
    int n;
    while(s<=e)
    {
        cout<<"Guess the number: ";
        cin>>n;
        int mid=n;
        if(mid==random_no)
        {
            cout<<"Number guessed correctly!!! YOU WIN!!!";
            break;
        }
        else if(mid>random_no)
        {
            cout<<"Guess is too high!!"<<endl;
            e=mid-1;
        }
        else
        {
            cout<<"Guess is too low!!"<<endl;
            s=mid+1;
        }
    }
}