#include <iostream>
#include <fstream>
#include <string>
using namespace std;

void registerUser() {
    string username, password;
    cout << "Enter username: ";
    cin >> username;
    cout << "Enter password: ";
    cin >> password;
    
    ofstream file(username + ".txt");
    file << username << endl << password;
    file.close();
    
    cout << "Registration successful!" << endl;
}

bool loginUser() {
    string username, password, storedUser, storedPass;
    cout << "Enter username: ";
    cin >> username;
    cout << "Enter password: ";
    cin >> password;
    
    ifstream file(username + ".txt");
    if (!file) {
        cout << "User not found!" << endl;
        return false;
    }
    
    getline(file, storedUser);
    getline(file, storedPass);
    file.close();
    
    if (storedUser == username && storedPass == password) {
        cout << "Login successful!" << endl;
        return true;
    } else {
        cout << "Incorrect username or password!" << endl;
        return false;
    }
}

int main() {
    int choice;
    cout << "1. Register\n2. Login\nChoose an option: ";
    cin >> choice;
    
    if (choice == 1) {
        registerUser();
    } else if (choice == 2) {
        loginUser();
    } else {
        cout << "Invalid option!" << endl;
    }
    
    return 0;
}
