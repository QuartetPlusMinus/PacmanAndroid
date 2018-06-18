//
// Created by views on 05.06.18.
//

#include "Stream.h"

using namespace Messages::SimpleTypes;

Stream::Stream() : iterator_(data_.begin()) {}

Stream::Stream(string &str) : data_(str.begin(), str.end()), iterator_(data_.begin()) {}

Stream &Stream::operator<<(int8 value) {
    data_.push_back(value);
    return *this;
}

Stream &Stream::operator<<(int16 value) { return write(value); }

Stream &Stream::operator<<(int32 value) { return write(value); }

Stream &Stream::operator<<(int64 value) { return write(value); }

Stream &Stream::operator<<(uint8 value) {
    data_.push_back(value);
    return *this;
}

Stream &Stream::operator<<(uint16 value) { return write(value); }

Stream &Stream::operator<<(uint32 value) { return write(value); }

Stream &Stream::operator<<(uint64 value) { return write(value); }

Stream &Stream::operator<<(float value) { return write(value); }

Stream &Stream::operator<<(const string &value) {
    write((uint32) value.length());
    std::copy(value.begin(), value.end(), std::back_inserter(data_));
    return *this;
}

Stream &Stream::operator>>(int8 &value) {
    value = *iterator_;
    if (iterator_ != data_.end()) {
        iterator_++;
    }
    return *this;
}

Stream &Stream::operator>>(int16 &value) { return read(value); }

Stream &Stream::operator>>(int32 &value) { return read(value); }

Stream &Stream::operator>>(int64 &value) { return read(value); }

Stream &Stream::operator>>(uint8 &value) {
    int8 buff;
    operator>>(buff);
    value = (uint8)buff;
    return *this;
}

Stream &Stream::operator>>(uint16 &value) { return read(value); }

Stream &Stream::operator>>(uint32 &value) { return read(value); }

Stream &Stream::operator>>(uint64 &value) { return read(value); }

Stream &Stream::operator>>(float &value) { return read(value); }

Stream &Stream::operator>>(string &value) {
    uint32 size;
    read(size);
    value = string(iterator_, iterator_+size);
    iterator_ += size;
    return *this;
}

string Stream::str() {
    return string(data_.begin(), data_.end());
}

template<typename T>
Stream &Stream::write(const T &value) {
    auto start = (char*) &value;
    std::copy(start, start + sizeof(T), std::back_inserter(data_));
    return *this;
}

template<typename T>
Stream &Stream::read(T &value) {
    std::copy(iterator_, iterator_+ sizeof(T), (char*) &value);
    iterator_ += sizeof(T);
    return *this;
}