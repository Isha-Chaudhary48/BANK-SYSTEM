#include <iostream>
#include <string>
#include <map>
using namespace std;
struct user;

typedef struct PunjabNationalBank
{
    int acc = 0;
    int amount = 0;
    bool depositMoney(user &u);

    bool withdrawMoney(user &u);

} pnb;
struct user
{
    string name;
    int userMoney = 1000;
    int MoneyWantToDoW;
    pnb account;
    bool creditMoney()
    {
        if (userMoney < MoneyWantToDoW)
        {
            cout << "**you don't have enough money in your pocket**" << endl;
            return false;
        }
        else if (account.depositMoney(*this))
        {
            userMoney = userMoney - MoneyWantToDoW;
            cout << "Money left of User : " << userMoney << endl;

            return true;
        }
    }
    bool debitMoney()
    {

        if (account.amount < MoneyWantToDoW)
        {
            cout << "**your Bank account doesn't hold enough money** " << endl;
            return false;
        }

        else
        {
            userMoney = userMoney + MoneyWantToDoW;
            account.withdrawMoney(*this);
            cout << "after debit u have :" << userMoney << endl;
            return true;
        }
    }
};
bool PunjabNationalBank::depositMoney(user &u)
{
    if (u.userMoney < u.MoneyWantToDoW)
    {
        return false;
    }
    else
    {
        amount = amount + u.MoneyWantToDoW;
        return true;
    }
}
bool PunjabNationalBank::withdrawMoney(user &u)
{

    if (amount < u.MoneyWantToDoW)
    {

        return false;
    }
    else
    {
        amount = amount - u.MoneyWantToDoW;
        return true;
    }
}
int main()
{
    map<int, user> userDatabase;

    pnb a;

    int choice, userID;
    string userName;

    while (true)
    {
        cout << " ********* WELCOME TO PUNJAB NATIONAL BANK ********" << endl;

        cout << "1.  To Create an account " << endl;
        cout << "2.  To Deposite Money " << endl;
        cout << "3.  To Withdraw Money " << endl;
        cout << "4.  To Check Bank Balance " << endl;
        cout << "5.  To Exit " << endl;
        cout << "Enter your choice" << endl;
        cin >> choice;

        switch (choice)
        {

        case 1:
            userID = userDatabase.size() + 1;

            cout << "enter your name" << endl;
            cin >> userName;
            userDatabase[userID] = {userName};
            userDatabase[userID].account.acc = userID;

            a.acc++;
            cout << "Account is created successfully" << endl;
            cout << "user ID:" << userID << endl;
            cout << "Account NO:" << 123456700000 + userDatabase[userID].account.acc << endl;

            break;

        case 2:
            cout << "Enter your userID" << endl;
            cin >> userID;
            if (userDatabase.find(userID) != userDatabase.end())
            {
                cout << "----enter money you want to deposite----" << endl;
                cin >> userDatabase[userID].MoneyWantToDoW;
                userDatabase[userID].creditMoney();
            }
            else
            {
                cout << "User ID not Found" << endl;
            }

            break;

        case 3:
            cout << "Enter UserID" << endl;
            cin >> userID;
            if (userDatabase.find(userID) != userDatabase.end())
            {
                cout << "----enter money you want to withdraw-----" << endl;
                cin >> userDatabase[userID].MoneyWantToDoW;
                userDatabase[userID].debitMoney();
            }
            else
            {
                cout << "User ID not found " << endl;
            }

            break;

        case 4:
            cout << "Enter UserID" << endl;
            cin >> userID;
            if (userDatabase.find(userID) != userDatabase.end())

            {

                cout << "total amount in your bank account : " << userDatabase[userID].account.amount << endl;
            }
            else
            {
                cout << "user ID not found " << endl;
            }

            break;

        case 5:
            return false;

            break;

        default:
            break;
        }
    }
}