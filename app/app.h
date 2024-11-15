#pragma once
#include <string>
#include <cctype>

namespace vsite::oop::v3
{	
		struct student
		{
			std::string name;
			int grade;

			student(const std::string& name = "pero", int grade = 2);
		};
				
		class results
		{
		public:
			
			results(uint32_t kolicina);
			~results();

			void add(const student& s);
			uint32_t has_grade(const int grade);
			uint32_t starts_with_letter(const char letter);

		private:
			student* students_=nullptr;
			uint32_t kolicina_=0;
			uint32_t brojStudenata_=0;

		};
	

	class array
	{
	public:
		array();
		~array();

		array(uint32_t size, double value);
		array(const array& other);
		array(array&& other);


		uint32_t size() const;
		double at(int index) const;
		void push_back(double value);

	private:
		double* data_=nullptr;
		uint32_t size_=0;
		
	};

}