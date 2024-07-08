#include <iostream>
#include <string>
using namespace std;

const int MAX_BOOKS = 100;
const int MAX_BORROWERS = 100;

struct Book {
    int id;
    string title;
    string author;
    string ISBN;
    bool isAvailable;
};

struct Borrower {
    int id;
    string name;
    int borrowedBookId;
};

Book books[MAX_BOOKS];
Borrower borrowers[MAX_BORROWERS];
int bookCount = 0;
int borrowerCount = 0;

void addBook() {
    if (bookCount < MAX_BOOKS) {
        cout << "Enter Book ID: ";
        cin >> books[bookCount].id;
        cout << "Enter Book Title: ";
        cin.ignore();
        getline(cin, books[bookCount].title);
        cout << "Enter Book Author: ";
        getline(cin, books[bookCount].author);
        cout << "Enter Book ISBN: ";
        getline(cin, books[bookCount].ISBN);
        books[bookCount].isAvailable = true;
        bookCount++;
    } else {
        cout << "Book database is full!" << endl;
    }
}

void searchBook() {
    string query;
    cout << "Enter title, author, or ISBN to search: ";
    cin.ignore();
    getline(cin, query);
    for (int i = 0; i < bookCount; i++) {
        if (books[i].title == query || books[i].author == query || books[i].ISBN == query) {
            cout << "Book ID: " << books[i].id << ", Title: " << books[i].title << ", Author: " << books[i].author << ", ISBN: " << books[i].ISBN << ", Available: " << (books[i].isAvailable ? "Yes" : "No") << endl;
        }
    }
}

void checkoutBook() {
    int bookId, borrowerId;
    cout << "Enter Book ID to checkout: ";
    cin >> bookId;
    cout << "Enter Borrower ID: ";
    cin >> borrowerId;

    for (int i = 0; i < bookCount; i++) {
        if (books[i].id == bookId && books[i].isAvailable) {
            for (int j = 0; j < borrowerCount; j++) {
                if (borrowers[j].id == borrowerId) {
                    books[i].isAvailable = false;
                    borrowers[j].borrowedBookId = bookId;
                    cout << "Book checked out successfully!" << endl;
                    return;
                }
            }
            cout << "Borrower not found!" << endl;
            return;
        }
    }
    cout << "Book not available!" << endl;
}

void returnBook() {
    int bookId;
    cout << "Enter Book ID to return: ";
    cin >> bookId;

    for (int i = 0; i < bookCount; i++) {
        if (books[i].id == bookId && !books[i].isAvailable) {
            books[i].isAvailable = true;
            for (int j = 0; j < borrowerCount; j++) {
                if (borrowers[j].borrowedBookId == bookId) {
                    borrowers[j].borrowedBookId = -1;
                    cout << "Book returned successfully!" << endl;
                    return;
                }
            }
        }
    }
    cout << "Book ID not found!" << endl;
}

void addBorrower() {
    if (borrowerCount < MAX_BORROWERS) {
        cout << "Enter Borrower ID: ";
        cin >> borrowers[borrowerCount].id;
        cout << "Enter Borrower Name: ";
        cin.ignore();
        getline(cin, borrowers[borrowerCount].name);
        borrowers[borrowerCount].borrowedBookId = -1;
        borrowerCount++;
    } else {
        cout << "Borrower database is full!" << endl;
    }
}

void displayMenu() {
    cout << "Library Management System" << endl;
    cout << "1. Add Book" << endl;
    cout << "2. Search Book" << endl;
    cout << "3. Checkout Book" << endl;
    cout << "4. Return Book" << endl;
    cout << "5. Add Borrower" << endl;
    cout << "6. Exit" << endl;
    cout << "Enter your choice: ";
}

int main() {
    int choice;
    do {
        displayMenu();
        cin >> choice;
        switch (choice) {
            case 1:
                addBook();
                break;
            case 2:
                searchBook();
                break;
            case 3:
                checkoutBook();
                break;
            case 4:
                returnBook();
                break;
            case 5:
                addBorrower();
                break;
            case 6:
                cout << "Exiting..." << endl;
                break;
            default:
                cout << "Invalid choice!" << endl;
        }
    } while (choice != 6);
    return 0;
}
