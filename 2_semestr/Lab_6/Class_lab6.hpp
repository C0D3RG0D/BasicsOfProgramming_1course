#pragma once
#include <iostream>


namespace my_class {

	template<typename T>
	class Vector;

	template<>
	class Vector<bool> {
    private:
        uint8_t* data_;
        size_t capacity_;
        size_t size_;

        void resize(size_t newCapacity) {
            uint8_t* newData = new uint8_t[((newCapacity + 7) / 8)];
            if (data_) {
                std::copy(data_, data_ + ((newCapacity + 7) / 8), newData);
                delete[] data_;
            }

            data_ = newData;
            capacity_ = newCapacity;
        }

    public:

        Vector() : data_(nullptr), capacity_(0), size_(0) {}

        ~Vector() {
            delete[] data_;
        }

        void push_back(bool value) {
            if (size_ == capacity_) {
                size_t newCapacity = capacity_ == 0 ? 1 : capacity_ * 2;
                resize(newCapacity);
            }

            size_t byteIndex = size_ / 8;
            size_t bitIndex = size_ % 8;

            if (value)
                data_[byteIndex] |= (1 << bitIndex);
            else
                data_[byteIndex] &= ~(1 << bitIndex);

            ++size_;
        }

        Vector& operator=(Vector& other) = delete;


        bool operator[](size_t index) const {
         if (index >= size_)
          throw std::out_of_range("Index out of range!");

         size_t byteIndex = index / 8;
         size_t bitIndex = index % 8;

         return (data_[byteIndex] >> bitIndex) & 1;
        }

        void set(size_t index, bool value) {
            if (index >= size_) {
                throw std::out_of_range("Index out of range!");
            }
            if (value) {
                data_[index / 8] |= 1 << (index % 8);
            }
            else {
                data_[index / 8] &= ~(1 << (index % 8));
            }
        }


        size_t size() const {
            return size_;
        }

        void insert(size_t index, bool value) {
            if (index > size_)
                throw std::out_of_range("Index out of range!");

            if (index == size_) {
                push_back(value);
                return;
            }

            size_t byteIndex = index / 8;
            size_t bitIndex = index % 8;

            if (value)
                data_[byteIndex] |= (1 << bitIndex);
            else
                data_[byteIndex] &= ~(1 << bitIndex);

            for (size_t i = size_; i > index; i--) {
                std::swap(data_[i / 8], data_[(i - 1) / 8]);
            }
            size_++;

        }

        void erase(size_t index) {
            if (index > size_)
                throw std::out_of_range("Index out of range!");

            size_t byteIndex = index / 8;
            size_t bitIndex = index % 8;

            data_[byteIndex] &= ~(1 << bitIndex);

            for (size_t i = index + 1; i < size_; i++) {
                std::swap(data_[i / 8], data_[(i - 1) / 8]);
            }

            size_--;
        }
	};
}