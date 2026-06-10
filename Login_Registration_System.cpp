#include <iostream>
#include <fstream>
#include <string>
using namespace std;

// Function to register a user
void registerUser() {
    string username, password;
    bool exists = false;

    cout << "\nEnter Username: ";
    cin >> username;

    cout << "Enter Password: ";
    cin >> password;

    ifstream infile("users.txt");
    string user, pass;

    while (infile >> user >> pass) {
        if (user == username) {
            exists = true;
            break;
        }
    }
    infile.close();

    if (exists) {
        cout << "Username already exists! Try another.\n";
        return;
    }

    ofstream outfile("users.txt", ios::app);
    outfile << username << " " << password << endl;
    outfile.close();

    cout << "Registration Successful!\n";
}

void loginUser() {
    string username, password;
    bool found = false;

    cout << "\nEnter Username: ";
    cin >> username;

    cout << "Enter Password: ";
    cin >> password;

    ifstream infile("users.txt");
    string user, pass;

    while (infile >> user >> pass) {
        if (user == username && pass == password) {
            found = true;
            break;
        }
    }
    infile.close();

    if (found)
        cout << "Login Successful! Welcome " << username << endl;
    else
        cout << "Invalid Username or Password!\n";
}

int main() {
    int choice;

    do {
        cout << "\n===== LOGIN & REGISTRATION SYSTEM =====\n";
        cout << "1. Register\n";
        cout << "2. Login\n";
        cout << "3. Exit\n";
        cout << "Enter Choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                registerUser();
                break;
            case 2:
                loginUser();
                break;
            case 3:
                cout << "Exiting Program...\n";
                break;
            default:
                cout << "Invalid Choice!\n";
        }
    } while (choice != 3);

    return 0;
}
