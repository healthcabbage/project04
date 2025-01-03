#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Book
{
public:
	string title;
	string author;

	Book(const string& title, const string& author)
		: title(title), author(author) {}
};

class BookManager
{
private:
	vector<Book> books;
public:
	void addBook(const string& title, const string& author) {
		books.push_back(Book(title, author));
		cout << "책이 추가되었습니다: " << title << " by " << author << endl;
	}

	void displayAllBooks() const
	{
		if (books.empty())
		{
			cout << "현재 등록된 책이 없습니다." << endl;
			return;
		}

		cout << "현재 도서 목록: " << endl;
		for (size_t i = 0; i < books.size(); i++)
		{
			cout << "- " << books[i].title << "by " << books[i].author << endl;
		}
	}

	void searchByTitle(string title)
	{

        if (books.empty())
        {
            cout << "현재 보관된 책이 없습니다!" << endl;
        }

        for (int i = 0; i < books.size(); i++)
        {
            if (books[i].title == title)
            {
                cout << title << "책은 존재 합니다." << endl;
            }
            else
            {
                cout << title << "책은 존재 하지 않습니다." << endl;
            }
        }
	}

	void searchByAuthor(string author)
	{
        if (books.empty())
        {
            cout << "현재 보관된 책이 없습니다!" << endl;
        }

        for (int i = 0; i < books.size(); i++)
        {
            if (books[i].author == author)
            {
                cout << author << "작가의 책은 존재 합니다." << endl;
            }
            else
            {
                cout << author << "작가의 책은 존재 하지 않습니다." << endl;
            }
        }
	}
};



int main()
{
	BookManager manager;

    while (true) {
        cout << "\n도서관 관리 프로그램" << endl;
        cout << "1. 책 추가" << endl;
        cout << "2. 모든 책 출력" << endl;
        cout << "3. 책 이름 검색" << endl;
        cout << "4. 작가 이름 검색" << endl;
        cout << "5. 종료" << endl;
        cout << "선택: ";

        int choice;
        cin >> choice;

        if (choice == 1) 
        {
            string title, author;
            cout << "책 제목: ";
            cin.ignore();
            getline(cin, title); 
            cout << "책 저자: ";
            getline(cin, author);
            manager.addBook(title, author);
        } 
        else if (choice == 2) 
        {
            manager.displayAllBooks();
        } 
        else if (choice == 3) 
        {
            string title;
            cout << "찾으실 책 제목은? ";
            cin.ignore();
            cin >> title;
            manager.searchByTitle(title);
        } 
        else if (choice == 4)
        {
            string author;
            cout << "찾으실 책의 작가 이름은? ";
            cin.ignore();
            cin >> author;
            manager.searchByAuthor(author);
        }
        else if (choice == 5)
        {
            cout << "프로그램을 종료합니다." << endl;
            break;
        }
        else {
            cout << "잘못된 입력입니다. 다시 시도하세요." << endl;
        }
    }

    return 0;
}
