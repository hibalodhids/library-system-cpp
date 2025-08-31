#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class Book {
public:
    int id;
    string title, author;
    int year;

    void input() {
        cout << "Enter Book ID: ";
        cin >> id;
        cin.ignore();
        cout << "Enter Title: ";
        getline(cin, title);
        cout << "Enter Author: ";
        getline(cin, author);
        cout << "Enter Year: ";
        cin >> year;
    }

    void display() {
        cout << id << " | " << title << " | " << author << " | " << year << endl;
    }
};

void addBook() {
    Book b;
    b.input();
    ofstream file("library.txt", ios::app);
    file << b.id << "," << b.title << "," << b.author << "," << b.year << endl;
    file.close();
    cout << "Book Added!\n";
}

void viewBooks() {
    ifstream file("library.txt");
    string line;
    cout << "\nAll Books:\n";
    while (getline(file, line)) {
        cout << line << endl;
    }
    file.close();
}

int main() {
    int choice;
    do {
        cout << "\n=== Library Menu ===\n";
        cout << "1. Add Book\n";
        cout << "2. View Books\n";
        cout << "3. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1: addBook(); break;
            case 2: viewBooks(); break;
            case 3: cout << "Exiting...\n"; break;
            default: cout << "Invalid choice!\n";
        }
    } while (choice != 3);

    return 0;
}

