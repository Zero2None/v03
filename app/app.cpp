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
    	
	results::results(uint32_t kolicina) {
		kolicina_ = kolicina;
		students_=new student[kolicina_];
	}

	results::~results()	{
		delete[] students_;
	}

	void results::add(const student& s) {
		if (brojStudenata_ < kolicina_) {
			students_[brojStudenata_++] = s;
		}
	}

	uint32_t results::has_grade(const int grade) {
		uint32_t count = 0;
		for (uint32_t i = 0; i < brojStudenata_;++i) {
			if (has_grade_check(students_[i], grade)) {
				++count;
			}
		}
		return count;
	}

	uint32_t results::starts_with_letter(const char letter) {
		uint32_t count = 0;
		for (uint32_t j = 0; j < brojStudenata_;++j) {
			if (starts_with_letter_check(students_[j], letter)) {
				++count;
			}
		}
		return count;
	}

    array::array(){}

    array::array(uint32_t size, double value) : size_(size), capacity_(size) {
        data_ = new double[capacity_];
        for (uint32_t k = 0; k < size_; ++k) {
            data_[k] = value;
        }
    }

    array::array(const array& other) : size_(other.size_), capacity_(other.capacity_) {
        data_ = new double[capacity_];
        for (uint32_t l = 0; l < size_; ++l) {
            data_[l] = other.data_[l];
        }
    }

    array::array(array&& other) : data_(other.data_), size_(other.size_), capacity_(other.capacity_) {
        other.data_ = nullptr;
        other.size_ = 0;
        other.capacity_ = 0;
    }

    array::~array() {
        delete[] data_;
    }

    uint32_t array::size() const {
        return size_;
    }

    double array::at(int index) const {
        if (index < 0 || index >= size_) {
            return 0;
        }
        return data_[index];
    }

    void array::push_back(double value) {
        if (size_ == capacity_) {
            if (capacity_ == 0) {
                capacity_ = 1;
            }
            else {
                ++capacity_;
            }

            double* data2_ = new double[capacity_];

            for (uint32_t m = 0; m < size_; ++m) {
                data2_[m] = data_[m];
            }

            delete[] data_;
            data_ = data2_;
        }

        data_[size_] = value;
        ++size_;
    }
}

