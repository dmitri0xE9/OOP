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

	std::cin.get( );
	return 0;
}