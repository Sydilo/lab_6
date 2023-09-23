#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

struct Book {
    int registrationNumber;
    std::string author;
    std::string title;
    int year;
    std::string publisher;
    int pageCount;
    int readerCardNumber;
    bool available;
};

// сортування за авторами
bool sortByAuthor(const Book& book1, const Book& book2) {
    return book1.author < book2.author;
}

// сортування за роком видання
bool sortByYear(const Book& book1, const Book& book2) {
    return book1.year < book2.year;
}

int main() {
    std::vector<Book> library;
    int option;

    do {
        std::cout << "\nМеню:" << std::endl;
        std::cout << "1. Додати книгу" << std::endl;
        std::cout << "2. Сортувати за авторами" << std::endl;
        std::cout << "3. Сортувати за роком видання" << std::endl;
        std::cout << "4. Вивести інформацію про всі книги" << std::endl;
        std::cout << "5. Вивести інформацію про книги 2020 року у читачів" << std::endl;
        std::cout << "6. Вийти" << std::endl;
        std::cout << "Виберіть опцію: ";
        std::cin >> option;

        switch (option) {
            case 1: {
                Book book;
                std::cout << "Реєстраційний номер: ";
                std::cin >> book.registrationNumber;
                std::cin.ignore(); // Щоб пропустити перенос рядка після попереднього вводу
                std::cout << "Автор: ";
                std::getline(std::cin, book.author);
                std::cout << "Назва: ";
                std::getline(std::cin, book.title);
                std::cout << "Рік видання: ";
                std::cin >> book.year;
                std::cin.ignore();
                std::cout << "Видавництво: ";
                std::getline(std::cin, book.publisher);
                std::cout << "Кількість сторінок: ";
                std::cin >> book.pageCount;
                std::cout << "Номер читацького квитка останнього читача: ";
                std::cin >> book.readerCardNumber;
                std::cout << "Книга доступна у бібліотеці (1 - так, 0 - ні): ";
                std::cin >> book.available;
                library.push_back(book);
                break;
            }
            case 2: {
                std::sort(library.begin(), library.end(), sortByAuthor);
                std::cout << "Книги відсортовані за авторами." << std::endl;
                break;
            }
            case 3: {
                std::sort(library.begin(), library.end(), sortByYear);
                std::cout << "Книги відсортовані за роком видання." << std::endl;
                break;
            }
            case 4: {
                std::cout << "Інформація про всі книги:" << std::endl;
                for (const Book& book : library) {
                    std::cout << "Реєстраційний номер: " << book.registrationNumber << std::endl;
                    std::cout << "Автор: " << book.author << std::endl;
                    std::cout << "Назва: " << book.title << std::endl;
                    std::cout << "Рік видання: " << book.year << std::endl;
                    std::cout << "Видавництво: " << book.publisher << std::endl;
                    std::cout << "Кількість сторінок: " << book.pageCount << std::endl;
                    std::cout << "Номер читацького квитка останнього читача: " << book.readerCardNumber << std::endl;
                    std::cout << "Доступна у бібліотеці: " << (book.available ? "Так" : "Ні") << std::endl;
                    std::cout << "---------------------------" << std::endl;
                }
                break;
            }
            case 5: {
                std::cout << "Інформація про книги 2020 року видання, які знаходяться у читачів:" << std::endl;
                bool found = false;
                for (const Book& book : library) {
                    if (book.year == 2020 && !book.available) {
                        std::cout << "Реєстраційний номер: " << book.registrationNumber << std::endl;
                        std::cout << "Автор: " << book.author << std::endl;
                        std::cout << "Назва: " << book.title << std::endl;
                        std::cout << "Рік видання: " << book.year << std::endl;
                        std::cout << "Видавництво: " << book.publisher << std::endl;
                        std::cout << "Кількість сторінок: " << book.pageCount << std::endl;
                        std::cout << "Номер читацького квитка останнього читача: " << book.readerCardNumber << std::endl;
                        std::cout << "Доступна у бібліотеці: " << (book.available ? "Так" : "Ні") << std::endl;
                        std::cout << "---------------------------" << std::endl;
                        found = true;
                    }
                }
                if (!found) {
                    std::cout << "Книги 2020 року видання, які знаходяться у читачів, відсутні." << std::endl;
                }
                break;
            }
            case 6: {
                std::cout << "Програму завершено." << std::endl;
                break;
            }
            default: {
                std::cout << "Невірний вибір опції. Спробуйте ще раз." << std::endl;
            }
        }
    } while (option != 6);

    return 0;
}
