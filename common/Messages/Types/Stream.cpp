//
// Created by views on 05.06.18.
//

#include "Stream.h"

using namespace Messages::SimpleTypes;

Stream::Stream() : stream_() {}

 Stream::Stream(string &str) : stream_(str) {}

Stream &Stream::operator<<(int8 value) {
    stream_ << value;
    return *this;
}

Stream &Stream::operator<<(int16 value) { return write(value); }

Stream &Stream::operator<<(int32 value) { return write(value); }

Stream &Stream::operator<<(int64 value) { return write(value); }

Stream &Stream::operator<<(uint8 value) {
    stream_ << value;
    return *this;
}

Stream &Stream::operator<<(uint16 value) { return write(value); }

Stream &Stream::operator<<(uint32 value) { return write(value); }

Stream &Stream::operator<<(uint64 value) { return write(value); }

Stream &Stream::operator<<(float value) { return write(value); }

Stream &Stream::operator<<(const string &value) {
    write((uint32) value.length());
    stream_ << value;
    return *this;
}

Stream &Stream::operator>>(int8 &value) {
    stream_ >> value;
    return *this;
}

Stream &Stream::operator>>(int16 &value) { return read(value); }

Stream &Stream::operator>>(int32 &value) { return read(value); }

Stream &Stream::operator>>(int64 &value) { return read(value); }

Stream &Stream::operator>>(uint8 &value) {
    stream_ >> value;
    return *this;
}

Stream &Stream::operator>>(uint16 &value) { return read(value); }

Stream &Stream::operator>>(uint32 &value) { return read(value); }

Stream &Stream::operator>>(uint64 &value) { return read(value); }

Stream &Stream::operator>>(float &value) { return read(value); }

Stream &Stream::operator>>(string &value) {
    uint32 size;
    read(size);
    value.resize(size);
    stream_.read(&value[0], size);
    return *this;
}

string Stream::str() {
    return stream_.str();
}

template<typename T>
Stream &Stream::write(const T &value) {
    stream_.write((char *) &value, sizeof(T));
    return *this;
}

template<typename T>
Stream &Stream::read(T &value) {
    stream_.read((char *) &value, sizeof(T));
    return *this;
}