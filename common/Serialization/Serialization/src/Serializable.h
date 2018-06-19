//
// Created by views on 19.06.18.
//

#ifndef SERIALIZATION_ISERIALIZABLE_H
#define SERIALIZATION_ISERIALIZABLE_H

#include "SimpleTypes.h"
#include "Repeated.h"
#include "Stream.h"

namespace Serialization {

    class Serializable {
    public:
        virtual ~Serializable() = default;

        void serializeToString(string &str) const;

        virtual void serializeToStream(Stream &stream) const =0;

        void parseFromString(string &str);

        virtual void parseFromStream(Stream &stream)=0;
    };

}

#endif //SERIALIZATION_ISERIALIZABLE_H
