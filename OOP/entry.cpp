#include <Windows.h>
#include <iostream>
#include <vector>

class c_student
{
private:
	std::string student_name;
	std::string student_last_name;
	int student_age;
	int student_average_score;

public:
	c_student( std::string student_name, std::string student_last_name, int student_age, int student_average_score )
	{
		this->student_name = student_name;
		this->student_last_name = student_last_name;
		this->student_age = student_age;
		this->student_average_score = student_average_score;
	}

	void get( ) const
	{
		std::cout <<  student_name << ", " << student_last_name << ", " << student_age << ", " << student_average_score << "\n";
	}
};

class c_group
{
private:
	std::vector<c_student> students_;
public:
	void add_student_in_group( c_student& _student )
	{
		students_.push_back( _student );
	}

	void get_student( ) const
	{
		for( int i = 0; i < students_.size( ); i++ )
		{
			auto st = students_[ i ];
			st.get( );
		}
	}
};

class c_book
{
private:
	std::string book_name_;
	std::string book_author_;
	int release_book_date_{};

public:

	c_book(const std::string& book_name, const std::string& book_author, const int release_book_date )
	{
		this->book_name_ = book_name;
		this->book_author_ = book_author;
		this->release_book_date_ = release_book_date;
	}

	[[nodiscard]] std::string get_book_name( ) const
	{
		return this->book_name_;
	}

	std::string get_book_author( ) const
	{
		return this->book_author_;
	}

	int get_release_book_date( ) const
	{
		return this->release_book_date_;
	}

	void get_all( ) const
	{
		std::cout << "[ ALL BOOKS ] " << book_name_ << ", " << book_author_ << ", " << release_book_date_ << "\n";
	}
};

class c_library
{
private:
	std::vector<c_book> books_;

public:

	void find_book_by_name(const std::string& book_name ) const
	{
		for( int i = 0; i < books_.size(); i++ )
		{
			auto book = books_[ i ];

			if( strcmp( book.get_book_name( ).c_str( ), book_name.c_str( ) ) == 0 )
			{
				std::cout << "[ FIND BOOK BY NAME ] Book by name found: " << book.get_book_name( ).c_str( ) << "\n";
			}
		}
	}

	void find_book_by_author( const std::string& book_author ) const
	{
		for(int i = 0; i < books_.size(); i++ )
		{
			auto book = books_[ i ];
			if( strcmp( book.get_book_author( ).c_str( ), book_author.c_str( ) ) == 0 )
			{
				std::cout << "[ FIND BOOK BY AUTHOR ] Book by author found: " << book.get_book_name( ).c_str( ) << "\n";
			}
		}
	}

	bool IsStored( const c_book& book ) const
	{
		for( int i = 0; i < books_.size(); i++ )
		{
			auto books = books_[ i ];
			if( strcmp( books.get_book_name( ).c_str( ), book.get_book_name( ).c_str( ) ) == 0 )
				return true;
		}

		return false;
	}

	void add_book(const c_book& book )
	{
		if( IsStored( book ) )
		{
			std::cout << "[ ADD BOOK ] book already in library\n";
			return;
		}

		books_.push_back( book );
	}

	void get_books( ) const
	{
		for( const auto& books : books_ )
		{
			books.get_all( );
		}
	}
};

int main( )
{
	c_student Dmitrii("Dmitrii", "Solovev", 21, 75);
	c_student Maxim("Maxim", "Ivanov", 18, 99);
	c_student Petya("Petya", "Sidorov", 23, 13);

	c_group current_group;
	current_group.add_student_in_group( Dmitrii );
	current_group.add_student_in_group( Maxim );
	current_group.add_student_in_group( Petya );

	current_group.get_student( );

	c_book book1( "The Death of Mrs. Westaway", "Ruth Ware", 2019 );
	c_book book2( "The Silent Patient", "Alex Michaelides", 2019 );
	c_book book3( "The C++ Programming Language", "Bjarne Stroustrup", 1985 );
	c_book book4( "The C++ Programming Language", "Bjarne Stroustrup", 1985 );
	c_library library;

	library.add_book( book1 );
	library.add_book( book2 );
	library.add_book( book3 );
	library.add_book( book4 );

	library.get_books( );

	library.find_book_by_name( "The Silent Patient" );
	library.find_book_by_author( "Bjarne Stroustrup" );

	std::cin.get( );
	return 0;
}