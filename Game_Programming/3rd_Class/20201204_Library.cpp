#include <iostream>
#include <string>

using namespace std;

namespace Value
{
	class Library
	{
		Book BookShlef[100];
		Book EmptyBook;
	public:
		Book GetBook(int n) { return BookShlef[n]; }
		Book SetBook(Book book, int idx) { return BookShlef[idx] = book; }

		Book BorrowBook(int n)
		{
			Book cBook = BookShlef[n];
			BookShlef[n] = EmptyBook;
			return cBook;
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
		Book borrowBook[100];
	public:
		void BorrowBook(Book cBook, int idx)
		{
			borrowBook[idx] = cBook;
		}
	};

	void SimulationLibraryMain()
	{
		//�������� ����� å�� �����Ѵ�.
		Library cLibrary;
		Borrower cBorrower;
		//���������� å�� �����ͼ� �����ڰ� ��������.
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

	class Lap
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
		//�����Ұ� ����� �Ӹ������ʾƵ� å���ڿ� �����ڰ� ��� �ִ�.
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

		//���������� å�� ������.
		for (int i = 0; i < 100; i++)
			cLibrary.SetBook(&LibraryBooks[i], i);
		//���������� å�� �����ͼ�
		Book* pBorrowBook = cLibrary.BorrowBook(0);
		//�����ڿ��� �����ش�.
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
		//�����Ұ� ����� å���ڿ� �������� �ڸ��� ����ִ�.
		Lap cLaboratory;
		Student cKCS;
		//�����ҿ� å���ڿ� �����ڸ� ö���� �Ӹ��Ѵ�.
		cLaboratory.SetChief(&cKCS);
		cLaboratory.SetManager(&cKCS);
	}
}