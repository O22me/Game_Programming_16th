#include <iostream>
#include <string>

using namespace std;

namespace Value
{
	class Library
	{
	private:
		Book BookShelf[100];
		Book EmptyBook;
	public:
		Book GetBook(int n) { return BookShelf[n]; }
		Book SetBook(Book book, int idx) { return BookShelf[idx] = book; }

		Book BorrowBook(int n)
		{
			Book cBook = BookShelf[n];
			BookShelf[n] = EmptyBook;
			return cBook;
		}
	};

	class Book
	{
	public:
		int Number;	//책 번호
		string Title;	//책 제목
	};

	class Borrower
	{
		Book borrowBook[100];
	public:
		void BorrowBook(Book cBook, int idx)
		{
			borrowBook[idx] = cBook;
		}
	};

	void SimulationLibraryMain()
	{
		//도서관은 생기면 책이 존재한다.
		Library cLibrary;
		Borrower cBorrower;
		//도서관에서 책을 꺼내와서 대출자가 빌려간다.
		cBorrower.BorrowBook(cLibrary.BorrowBook(0), 0);
	}

	class Student
	{
		string name;
		int phone_number;
	public:
		Student(string name, int number)
		{
			this->name = name;
			this->phone_number = number;
		}
	};

	class Lap //연구소
	{
		string strNAme;
		Student cChief;
		Student cManager;
	public:
		Lap() :cChief(string("kcs"), 101), cManager(string("kcs"), 101)
		{

		}
		void SetChief(Student student)
		{
			cChief = student;
		}
		void SetManager(Student student)
		{
			cManager = student;
		}
	};

	void SimulationLabMain()
	{
		//연구소가 생기면 임명하지않아도 책임자와 관리자가 모두 있다.
		Lap cLaboratory;
	}
}

namespace Reference
{
	class Library
	{
	public:
		Book* BookShlef[100];

		Book* GetBook(int n) { return BookShlef[n]; }
		Book* SetBook(Book* book, int idx) { return BookShlef[idx] = book; }

		Book* BorrowBook(int n)
		{
			Book* pBook = BookShlef[n];
			BookShlef[n] = NULL;
			return pBook;
		}
	};

	class Book
	{
	public:
		int Number;
		string Title;
	};

	class Borrower
	{
		Book* borrowBook[100];
	public:
		void BorrowBook(Book* pBook, int idx)
		{
			borrowBook[idx] = pBook;
		}
	};

	void SimulationLibraryMain()
	{
		Library cLibrary;
		Borrower cBorrower;
		Book LibraryBooks[100];

		//도서관에서 책을 구매함.
		for (int i = 0; i < 100; i++)
			cLibrary.SetBook(&LibraryBooks[i], i);
		//도서관에서 책을 꺼내와서
		Book* pBorrowBook = cLibrary.BorrowBook(0);
		//대출자에게 빌려준다.
		cBorrower.BorrowBook(pBorrowBook, 0);
	}

	class Student
	{
		string name;
		int phone_number;
	};

	class Lap
	{
		string strNAme;
		Student* cChief = NULL;
		Student* cManager = NULL;
	public:
		void SetChief(Student* student)
		{
			cChief = student;
		}
		void SetManager(Student* student)
		{
			cManager = student;
		}
	};

	void SimulationLibraryMain()
	{
		//연구소가 생기면 책임자와 관리자의 자리는 비어있다.
		Lap cLaboratory;
		Student cKCS;
		//연구소에 책임자와 관리자를 철수로 임명한다.
		cLaboratory.SetChief(&cKCS);
		cLaboratory.SetManager(&cKCS);
	}
}