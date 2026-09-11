#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Book {
    int id;
    string title;
    string author;
    bool issued;

public:
    Book(int i, string t, string a) {
        id = i;
        title = t;
        author = a;
        issued = false;
    }

    int getId() {
        return id;
    }

    string getTitle() {
        return title;
    }

    bool isIssued() {
        return issued;
    }

    void issueBook() {
        issued = true;
    }

    void returnBook() {
        issued = false;
    }

    void display() {
        cout << "ID: " << id
             << " | Title: " << title
             << " | Author: " << author
             << " | Status: " << (issued ? "Issued" : "Available")
             << endl;
    }
};

class Member {
    int id;
    string name;
    vector<int> borrowedBooks;

public:
    Member(int i, string n) {
        id = i;
        name = n;
    }

    int getId() {
        return id;
    }

    string getName() {
        return name;
    }

    void borrowBook(int bookId) {
        borrowedBooks.push_back(bookId);
    }

    void returnBook(int bookId) {
        for (auto it = borrowedBooks.begin(); it != borrowedBooks.end(); ++it) {
            if (*it == bookId) {
                borrowedBooks.erase(it);
                break;
            }
        }
    }

    void display() {
        cout << "Member ID: " << id << " | Name: " << name << endl;
        cout << "Borrowed Books: ";

        if (borrowedBooks.empty()) {
            cout << "None";
        } else {
            for (int book : borrowedBooks) {
                cout << book << " ";
            }
        }

        cout << endl;
    }
};

class Library {
    vector<Book> books;
    vector<Member> members;

public:
    void addBook() {
        int id;
        string title, author;

        cout << "Enter Book ID: ";
        cin >> id;
        cin.ignore();

        cout << "Enter Book Title: ";
        getline(cin, title);

        cout << "Enter Author Name: ";
        getline(cin, author);

        books.push_back(Book(id, title, author));
        cout << "Book added successfully.\n";
    }

    void addMember() {
        int id;
        string name;

        cout << "Enter Member ID: ";
        cin >> id;
        cin.ignore();

        cout << "Enter Member Name: ";
        getline(cin, name);

        members.push_back(Member(id, name));
        cout << "Member registered successfully.\n";
    }

    Book* findBook(int id) {
        for (auto& book : books) {
            if (book.getId() == id)
                return &book;
        }
        return nullptr;
    }

    Member* findMember(int id) {
        for (auto& member : members) {
            if (member.getId() == id)
                return &member;
        }
        return nullptr;
    }

    void issueBook() {
        int bookId, memberId;

        cout << "Enter Book ID: ";
        cin >> bookId;

        cout << "Enter Member ID: ";
        cin >> memberId;

        Book* book = findBook(bookId);
        Member* member = findMember(memberId);

        if (!book) {
            cout << "Book not found.\n";
            return;
        }

        if (!member) {
            cout << "Member not found.\n";
            return;
        }

        if (book->isIssued()) {
            cout << "Book is already issued.\n";
            return;
        }

        book->issueBook();
        member->borrowBook(bookId);

        cout << "Book issued successfully.\n";
    }

    void returnBook() {
        int bookId, memberId;

        cout << "Enter Book ID: ";
        cin >> bookId;

        cout << "Enter Member ID: ";
        cin >> memberId;

        Book* book = findBook(bookId);
        Member* member = findMember(memberId);

        if (!book) {
            cout << "Book not found.\n";
            return;
        }

        if (!member) {
            cout << "Member not found.\n";
            return;
        }

        if (!book->isIssued()) {
            cout << "Book is not currently issued.\n";
            return;
        }

        book->returnBook();
        member->returnBook(bookId);

        cout << "Book returned successfully.\n";
    }

    void showBooks() {
        if (books.empty()) {
            cout << "No books available.\n";
            return;
        }

        cout << "\nLibrary Books\n";
        for (auto& book : books)
            book.display();
    }

    void showMembers() {
        if (members.empty()) {
            cout << "No members registered.\n";
            return;
        }

        cout << "\nLibrary Members\n";
        for (auto& member : members)
            member.display();
    }

    void menu() {
        int choice;

        do {
            cout << "\n===== LIBRARY MANAGEMENT SYSTEM =====\n";
            cout << "1. Add Book\n";
            cout << "2. Add Member\n";
            cout << "3. Issue Book\n";
            cout << "4. Return Book\n";
            cout << "5. Show Books\n";
            cout << "6. Show Members\n";
            cout << "7. Exit\n";
            cout << "Enter Choice: ";
            cin >> choice;

            switch (choice) {
                case 1:
                    addBook();
                    break;

                case 2:
                    addMember();
                    break;

                case 3:
                    issueBook();
                    break;

                case 4:
                    returnBook();
                    break;

                case 5:
                    showBooks();
                    break;

                case 6:
                    showMembers();
                    break;

                case 7:
                    cout << "Thank you for using the Library Management System.\n";
                    break;

                default:
                    cout << "Invalid choice.\n";
            }

        } while (choice != 7);
    }
};

int main() {
    Library library;

    library.menu();

    return 0;
}
