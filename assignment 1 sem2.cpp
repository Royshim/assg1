  
#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Book {
public:
    Book(int number, string title, string author, string type) : number(number), title(title), author(author), type(type), isBorrowed(false) {}

    int getNumber() const {
        return number;
    }

    string getTitle() const {
        return title;
    }

    string getAuthor() const {
        return author;
    }

    string getType() const {
        return type;
    }

    bool getIsBorrowed() const {
        return isBorrowed;
    }

    void setIsBorrowed(bool borrowed) {
        isBorrowed = borrowed;
    }

private:
    int number;
    string title;
    string author;
    string type;
    bool isBorrowed;
};

class User {
public:
    User(string name, string regNumber) : name(name), regNumber(regNumber) {}

    string getName() const {
        return name;
    }

    string getRegNumber() const {
        return regNumber;
    }

private:
    string name;
    string regNumber;
};

class Library {
public:
    void addBook(const Book& book) {
        books.push_back(book);
    }

    void borrowBook(const Book& book, User& user) {
        for (auto& b : books) {
            if (b.getTitle() == book.getTitle() && b.getAuthor() == book.getAuthor() && !b.getIsBorrowed()) {
                b.setIsBorrowed(true);
                cout << "Book #" << b.getNumber() << " \"" << b.getTitle() << "\" by " << b.getAuthor() << " borrowed by " << user.getName() << " (" << user.getRegNumber() << ")" << endl;
                return;
            }
        }
        cout << "Book not available for borrowing." << endl;
    }

    void returnBook(const Book& book, User& user) {
        for (auto& b : books) {
            if (b.getTitle() == book.getTitle() && b.getAuthor() == book.getAuthor() && b.getIsBorrowed()) {
                b.setIsBorrowed(false);
                cout << "Book #" << b.getNumber() << " \"" << b.getTitle() << "\" by " << b.getAuthor() << " returned by " << user.getName() << " (" << user.getRegNumber() << ")" << endl;
                return;
            }
        }
        cout << "Book not borrowed by user." << endl;
    }

    vector<Book>& getBooks() {
        return books;
    }

    void displayAvailableBooks() {
        cout << "Available Books:" << endl;
        for (const auto& b : books) {
            if (!b.getIsBorrowed()) {
                cout << "Book #" << b.getNumber() << " " << b.getTitle() << " by " << b.getAuthor() << " (" << b.getType() << ")" << endl;
            }
        }
    }

    vector<Book> searchBooksByTitle(const string& title) {
        vector<Book> result;
        for (const auto& b : books) {
            if (b.getTitle() == title) {
                result.push_back(b);
            }
        }
        return result;
    }

private:
    vector<Book> books;
};

int main() {
    Book book1(1, "The Game", "Rollo Tomassi", "Non-Fiction");
    Book book2(2, "Fall of Rome", "Nikola Lee", "Fiction");
    Book book3(3, "The Alchemist", "Paulo Coelho", "Fiction");
    Book book4(4, "Money Managment", "Brandon Carter", "Non-Fiction");
    Book book5(5, "Lazy Wife", "Harper Lee", "Fiction");

    User student1("Alice", "BBIT-O5-0290/2021");
    User student2("Bob", "BSE-O5-0290/2023");

    Library library;

    library.addBook(book1);
    library.addBook(book2);
    library.addBook(book3);
    library.addBook(book4);
    library.addBook(book5);

    library.borrowBook(book3, student1);
    library.borrowBook(book5, student2);

    library.returnBook(book3, student1);
    library.returnBook(book5, student2);

    library.displayAvailableBooks();

    vector<Book> searchResults = library.searchBooksByTitle("The Game");
    if (!searchResults.empty()) {
        cout << "Search results for 'The Game':" << endl;
        for (const auto& result : searchResults) {
            cout << "Book #" << result.getNumber() << " " << result.getTitle() << " by " << result.getAuthor() << " (" << result.getType() << ")" << endl;
        }
    } else {
        cout << "No books found for the search query." << endl;
    }

    return 0;
}
