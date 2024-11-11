#include "app.h"
#include <algorithm>


namespace vsite::oop::v3
{

	student::student(const std::string& name, int grade)
		: name(name), grade(grade) {}


	bool has_grade_check(const student& s, int grade) {
		return s.grade == grade;
	}

	bool starts_with_letter_check(const student& s, char letter) {
		return std::toupper(s.name[0]) == std::toupper(letter);
	}

	
	results::results(uint32_t kolicina) : students_() {
		students_.reserve(kolicina);
	}

	void results::add(const student& s) {
		students_.push_back(s);
	}

	uint32_t results::has_grade(int grade) const {
		uint32_t count = 0;
		for (const auto& s : students_) {
			if (has_grade_check(s, grade)) {
				++count;
			}
		}
		return count;
	}

	uint32_t results::starts_with_letter(char letter) const {
		uint32_t count = 0;
		for (const auto& s : students_) {
			if (starts_with_letter_check(s, letter)) {
				++count;
			}
		}
		return count;
	}



	array::array() : data_() {}
	array::array(uint32_t size, double value) : data_(size, value) {}
	array::array(const array& other) : data_(other.data_) {}
	array::array(array&& other) : data_(std::move(other.data_)) {
		other.data_.clear();	//ne ostavljamo neodredjeni value u other nego ga ocistimo nakon move
	}

	uint32_t array::size() const {
		return (data_.size());
	}

	double array::at(int index) const {
		if (index < 0 || index >= data_.size())
			return 0.0;
		return data_[index];
	}

	void array::push_back(double value) {
		data_.push_back(value);
	}

}