//
// Created by views on 01.06.18.
//

#ifndef COMMON_SERIALIZABLE_MESSAGES_H
#define COMMON_SERIALIZABLE_MESSAGES_H

#include "Serialization/Serialization.h"
#include "Samples.h"

namespace Messages {

    class ConnectMessage : public sz::Serializable {
    public:

        ConnectMessage();

        ConnectMessage(const ConnectMessage &from);

        void serializeToStream(sz::Stream &stream) const override;

        void parseFromStream(sz::Stream &stream) override;

        void clear_name();

        const sz::string &name() const;

        void set_name(const sz::string &value);

        void set_name(const char *value);

        void set_name(const char *value, size_t size);

        sz::string *mutable_name();

        sz::string *release_name();

    private:
        sz::string name_;
    };

    class QueueMessage : public sz::Serializable {
    public:
        QueueMessage();

        ~QueueMessage() override;

        QueueMessage(const QueueMessage &from);

        void serializeToStream(sz::Stream &stream) const override;

        void parseFromStream(sz::Stream &stream) override;

        sz::uint16 position() const;

        void set_position(sz::uint16 value);

    private:
        sz::uint16 position_;
    };

    class StartMessage : public sz::Serializable {
    public:
        StartMessage();

        ~StartMessage() override;

        StartMessage(const StartMessage &from);

        void serializeToStream(sz::Stream &stream) const override;

        void parseFromStream(sz::Stream &stream) override;

        sz::uint8 id() const;

        void set_id(sz::uint8 value);

        int unit_size() const;

        void clear_unit();

        const Samples::UnitInit &unit(int index) const;

        Samples::UnitInit *mutable_unit(int index);

        Samples::UnitInit *add_unit();

        sz::Repeated<Samples::UnitInit> *mutable_unit();

        const sz::Repeated<Samples::UnitInit> &unit() const;

        void clear_map();

        const sz::string &map() const;

        void set_map(const sz::string &value);

        void set_map(const char *value);

        void set_map(const char *value, size_t size);

        sz::string *mutable_map();

        sz::string *release_map();

        int item_size() const;

        void clear_item();

        const Samples::Item &item(int index) const;

        Samples::Item *mutable_item(int index);

        Samples::Item *add_item();

        sz::Repeated<Samples::Item> *mutable_item();

        const sz::Repeated<Samples::Item> &item() const;

    private:
        sz::uint8 id_; // index in room
        sz::string map_; // game map. Not sz::string, bytes array
        sz::Repeated<Samples::UnitInit> unit_; // unit init data
        sz::Repeated<Samples::Item> item_; // game item init data
    };

    class EventMessage : public sz::Serializable {
    public:
        EventMessage();

        virtual ~EventMessage() override;

        EventMessage(const EventMessage &from);

        void serializeToStream(sz::Stream &stream) const override;

        void parseFromStream(sz::Stream &stream) override;

        Samples::Direction direction() const;

        void set_direction(Samples::Direction value);

    private:
        Samples::Direction direction_;
    };

    class IterationMessage : public sz::Serializable {
    public:
        IterationMessage();

        ~IterationMessage() override;

        IterationMessage(const IterationMessage &from);

        void serializeToStream(sz::Stream &stream) const override;

        void parseFromStream(sz::Stream &stream) override;

        int unit_size() const;

        void clear_unit();

        const Samples::Unit &unit(int index) const;

        Samples::Unit *mutable_unit(int index);

        Samples::Unit *add_unit();

        sz::Repeated<Samples::Unit> *mutable_unit();

        const sz::Repeated<Samples::Unit> &unit() const;

        int item_size() const;

        void clear_item();

        const Samples::Item &item(int index) const;

        Samples::Item *mutable_item(int index);

        Samples::Item *add_item();

        sz::Repeated<Samples::Item> *
        mutable_item();

        const sz::Repeated<Samples::Item> &item() const;

    private:
        sz::Repeated<Samples::Unit> unit_;
        sz::Repeated<Samples::Item> item_;
    };

    class EndMessage : public sz::Serializable {
    public:
        EndMessage();

        ~EndMessage() override;

        EndMessage(const EndMessage &from);

        void serializeToStream(sz::Stream &stream) const override;

        void parseFromStream(sz::Stream &stream) override;

        Samples::GameStatus status() const;

        void set_status(Samples::GameStatus value);

        sz::uint16 points() const;

        void set_points(sz::uint16 value);

    private:
        Samples::GameStatus status_;
        sz::uint16 points_;
    };
}

#endif //COMMON_SERIALIZABLE_MESSAGES_H
