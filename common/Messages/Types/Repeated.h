//
// Created by views on 05.06.18.
//

#include "SimpleTypes.h"
#include "Stream.h"

#ifndef MESSAGES_REPEATED_H
#define MESSAGES_REPEATED_H

#define REPEATED_MIN_CAPACITY 8

namespace Messages {
    namespace SimpleTypes {

        template<class T>
        class Repeated {
        public:
            Repeated() : capacity_(REPEATED_MIN_CAPACITY),
                         size_(0),
                         data_(new T *[REPEATED_MIN_CAPACITY]) {}

            Repeated(const Repeated<T> &from) : capacity_(from.capacity_),
                                                size_(from.size_),
                                                data_(new T *[from.capacity_]) {
                for (int i = 0; i < size_; i++) {
                    data_[i] = new T(*from.data_[i]); // ?
                }
            }

            ~Repeated() {
                clear();
                delete[] data_;
            }

            friend Stream &operator<<(Stream &stream, const Repeated<T> &value) {
                stream << (uint32) value.size_;
                for (int i = 0; i < value.size_; i++) {
                    value.data_[i]->serializeToStream(stream);
                }
                return stream;
            }

            friend Stream &operator>>(Stream &stream, Repeated<T> &value) {
                value.clear();

                auto some = stream.str();
                uint32 size;
                stream >> size;
                value.size_ = (unsigned int) size;
                value.capacity_ = (unsigned int) size;
                value.data_ = new T *[size];

                for (int i = 0; i < value.size_; i++) {
                    value.data_[i] = new T();
                    value.data_[i]->parseFromStream(stream);
                }
                return stream;
            }

            int capacity() const {
                return capacity_;
            }

            int size() const {
                return size_;
            }

            void clear() {
                for (int i = 0; i < size_; i++) {
                    delete data_[i];
                }
                size_ = 0;
            }

            const T &get(int index) const {
                return *data_[index];
            }

            T *get_mutable(int index) const {
                return data_[index];
            }

            T *add() {
                if (capacity_ == size_) {
                    resize();
                }
                auto item = new T();
                data_[size_++] = item;
                return item;
            }

            void resize() {
                capacity_ *= 2;
                auto newData = new T *[capacity_];
                std::copy(data_, data_ + size_, newData);
                delete[] data_;
                data_ = newData;
            }

        private:
            unsigned int capacity_;
            unsigned int size_;
            T **data_;
        };
    }
}
#endif //MESSAGES_REPEATED_H
