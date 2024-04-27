#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <limits> // For clearing input buffer

// Structure to represent a book
struct Book {
    std::string title;
    std::string author;
    int year;
};

// Function to add a book to the library
void addBook(std::vector<Book>& library) {
    Book newBook;
    std::cout << "Enter book title: ";
    std::getline(std::cin >> std::ws, newBook.title); // Read entire line including whitespace
    std::cout << "Enter book author: ";
    std::getline(std::cin >> std::ws, newBook.author); // Read entire line including whitespace
    std::cout << "Enter publication year: ";
    std::cin >> newBook.year;
    library.push_back(newBook);
    std::cout << "Book added successfully!" << std::endl;
}

// Function to remove a book from the library
void removeBook(std::vector<Book>& library, const std::string& title) {
    auto it = std::find_if(library.begin(), library.end(), [&title](const Book& book) {
        return book.title == title;
    });

    if (it != library.end()) {
        library.erase(it);
        std::cout << "Book removed successfully!" << std::endl;
    } else {
        std::cout << "Book not found!" << std::endl;
    }
}

// Function to search for a book in the library
void searchBook(const std::vector<Book>& library, const std::string& title) {
    auto it = std::find_if(library.begin(), library.end(), [&title](const Book& book) {
        return book.title == title;
    });

    if (it != library.end()) {
        std::cout << "Book found:" << std::endl;
        std::cout << "Title: " << it->title << std::endl;
        std::cout << "Author: " << it->author << std::endl;
        std::cout << "Year: " << it->year << std::endl;
    } else {
        std::cout << "Book not found!" << std::endl;
    }
}

int main() {
    std::vector<Book> library;

    while (true) {
        std::cout << "\nMenu:" << std::endl;
        std::cout << "1. Add a book" << std::endl;
        std::cout << "2. Remove a book" << std::endl;
        std::cout << "3. Search for a book" << std::endl;
        std::cout << "4. Quit" << std::endl;

        int choice;
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        // Clear input buffer
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        switch (choice) {
            case 1: {
                addBook(library);
                break;
            }
            case 2: {
                std::string title;
                std::cout << "Enter title of the book to remove: ";
                std::getline(std::cin >> std::ws, title); // Read entire line including whitespace
                removeBook(library, title);
                break;
            }
            case 3: {
                std::string title;
                std::cout << "Enter title of the book to search: ";
                std::getline(std::cin >> std::ws, title); // Read entire line including whitespace
                searchBook(library, title);
                break;
            }
            case 4:
                return 0;
            default:
                std::cout << "Invalid choice. Please try again." << std::endl;
        }
    }

    return 0;
}
