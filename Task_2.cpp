//SIMPLE CALCULATOR
#include<iostream>
using namespace std;
int main()
{
    int num1,num2,ch;
    double result;
    char ch1;
    do
    {
        cout<<"Enter first number: ";
        cin>>num1;
        cout<<"Enter second number: ";
        cin>>num2;
        cout<<"Press the number to perform the following operations:- \n 1.Addition \n 2.Subtraction \n 3.Multiplication \n 4.Division \n 5.Exit \n";
        cout<<"Enter your choice(1/2/3/4/5): ";
        cin>>ch;
        switch(ch)
        {
            case 1: 
                result=num1+num2;
                cout<<"The sum is: "<<result<<"\n\n";
                cout<<"Do you wish to continue(y/n): ";
                cin>>ch1;
                if(ch1=='y')
                break;
                else
                {
                    ch=5;
                    break;
                }
                

            case 2:
                result=num1-num2;
                cout<<"The difference is: "<<result<<"\n\n";
                cout<<"Do you wish to continue(y/n): ";
                cin>>ch1;
                if(ch1=='y')
                break;
                else
                {
                    ch=5;
                    break;
                }

            case 3:
                result=num1*num2;
                cout<<"The product is: "<<result<<"\n\n";
                cout<<"Do you wish to continue(y/n): ";
                cin>>ch1;
                if(ch1=='y')
                break;
                else
                {
                    ch=5;
                    break;
                }

            case 4:
                
                result=double(num1)/double(num2);
                cout<<"The division is: "<<result<<"\n\n";
                cout<<"Do you wish to continue(y/n): ";
                cin>>ch1;
                if(ch1=='y')
                break;
                else
                {
                    ch=5;
                    break;
                }
            
            case 5:
                cout<<"Thanks for visiting!!!";
                break;
            
            default:
                cout<<"INVALID CHOICE!!";
        }

    }while(ch!=5);
}