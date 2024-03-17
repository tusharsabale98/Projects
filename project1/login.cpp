#include <iostream>
#include <fstream>
using namespace std;

class temp
{
    string searchName, searchPass, searchEmail;
    string userName, Email, password;
    fstream file;

public:
    void login();
    void signUP();
    void forgot();
};

void temp::login()//:: ha scope resolution operator ahe
{
    cout << "------------Login-------------" << endl;
    cout << "Enter your user name :: ";
    cin.ignore(); // to clear the newline character from the buffer
    getline(cin, searchName);
    cout << "Enter your Password :: ";
    getline(cin, searchPass);

    file.open("loginData.txt", ios::in); 
    // file is opened successfully or not
    if (!file.is_open()) {
        cout << "Error opening file!" << endl;
        return;
    }
    while (getline(file, userName, '*')) //getline for better file reading
    {
        getline(file, Email, '*');
        getline(file, password, '\n');
        if (userName == searchName) {
            if (password == searchPass) {
                cout << "\nAccount login successful...!" << endl;
                cout << "Username:: " << userName << endl;
                return; 
            }
            else {
                cout << "Password is Incorrect...!" << endl;
                return; // exit kar jr user unsuccessful login zhal tr
            }
        }
    }
    cout << "User not found...!" << endl;
    file.close();
}

void temp::signUP()
{
    cout << "\nEnter your User Name :: ";
    cin.ignore(); 
    getline(cin, userName);
    cout << "Enter your Email :: ";
    getline(cin, Email);
    cout << "Enter your Password :: ";
    getline(cin, password);

    file.open("loginData.txt", ios::out | ios::app); 
    if (!file.is_open()) {
        cout << "Error opening file!" << endl;
        return;
    }
    file << userName << "*" << Email << "*" << password << endl;
    file.close();
}

void temp::forgot()
{
    cout << "\nEnter your UserName :: ";
    cin.ignore(); //to clear the newline character from the buffer
    getline(cin, searchName);
    cout << "Enter your Email :: ";
    getline(cin, searchEmail);

    file.open("loginData.txt", ios::in); 
    if (!file.is_open()) {
        cout << "Error opening file!" << endl;
        return;
    }
    bool found = false; // Add a flag to track if the user is found
    while (getline(file, userName, '*'))
    {
        getline(file, Email, '*');
        getline(file, password, '\n');
        if (userName == searchName && Email == searchEmail) {
            cout << "\nAccount Found...!" << endl;
            cout << "Your Password:: " << password << endl;
            found = true; // user bhetla tr flag set kare
            break; //jr user bhetla tr loop Break karel 
        }
    }
    if (!found) { // jar user nahi bhetla tr
        cout << "User not found...!" << endl;
    }
    file.close();
}

int main()
{
    temp obj;//class cha object banvla
    char choice;
    do {
        cout << "\n1- Login";
        cout << "\n2- Sign-Up";
        cout << "\n3- Forgot Password";
        cout << "\n4- Exit";
        cout << "\nEnter your choice:: ";
        cin >> choice;

        switch (choice)
        {
        case '1':
            obj.login();
            break;
        case '2':
            obj.signUP();
            break;
        case '3':
            obj.forgot();
            break;
        case '4':
            return 0;
        default:
            cout << "Invalid selection...!" << endl;
        }
    } while (true);

    return 0;
}
