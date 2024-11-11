#pragma once
#include <string>
#include <vector>
#include <cctype>

namespace vsite::oop::v3
{	
		struct student
		{
			std::string name;
			int grade;

			student(const std::string& name = "pero", int grade = 2);
		};

		static bool has_grade_check(const student& s, int grade);
		static bool starts_with_letter_check(const student& s, char letter);

		class results
		{
		public:
			
			results(uint32_t kolicina);
			void add(const student& s);
			uint32_t has_grade(int grade) const;
			uint32_t starts_with_letter(char letter) const;

		private:
			std::vector<student> students_;

		};
	

	class array
	{
	public:
		array();
		array(uint32_t size, double value);
		array(const array& other);
		array(array&& other);
		uint32_t size() const;
		double at(int index) const;
		void push_back(double value);

	private:
		std::vector<double> data_;
	};

}