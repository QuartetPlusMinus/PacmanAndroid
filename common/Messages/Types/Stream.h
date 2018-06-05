//
// Created by views on 05.06.18.
//

#ifndef SERIALIZATION_STREAM_H
#define SERIALIZATION_STREAM_H

#include <sstream>
#include <iostream>

#include "SimpleTypes.h"

namespace Messages {
    namespace SimpleTypes {
        class Stream {
        public:

            Stream();

            explicit Stream(string &str);

            virtual ~Stream() = default;

            Stream &operator<<(int8 value);

            Stream &operator<<(int16 value);

            Stream &operator<<(int32 value);

            Stream &operator<<(int64 value);

            Stream &operator<<(uint8 value);

            Stream &operator<<(uint16 value);

            Stream &operator<<(uint32 value);

            Stream &operator<<(uint64 value);

            Stream &operator<<(float value);

            Stream &operator<<(string &value);

            Stream &operator>>(int8 &value);

            Stream &operator>>(int16 &value);

            Stream &operator>>(int32 &value);

            Stream &operator>>(int64 &value);

            Stream &operator>>(uint8 &value);

            Stream &operator>>(uint16 &value);

            Stream &operator>>(uint32 &value);

            Stream &operator>>(uint64 &value);

            Stream &operator>>(float &value);

            Stream &operator>>(string &value);

            string str();

        private:
            std::stringstream stream_;

            template<typename T>
            Stream &write(const T &value);

            template<typename T>
            Stream &read(T &value);
        };
    }
}

#endif //SERIALIZATION_STREAM_H
