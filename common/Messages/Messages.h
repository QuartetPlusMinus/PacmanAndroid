//
// Created by views on 01.06.18.
//

#ifndef SERIALIZATION_PROTOCOL_H
#define SERIALIZATION_PROTOCOL_H

#include <string>

#include "Types.h"

namespace Messages {

    using namespace SimpleTypes;

    class Message {
    public:
        virtual ~Message() = default;

        void serializeToString(string &str) {
            Stream distStream;
            serializeToStream(distStream);
            str = distStream.str();
        }

        virtual void serializeToStream(Stream &stream)=0;

        void parseFromString(string &str) {
            Stream srcStream(str);
            parseFromStream(srcStream);
        }

        virtual void parseFromStream(Stream &stream)=0;
    };

    class Point : public Message {
    public:
        Point();

        Point(const Point &from);

        void serializeToStream(Stream &stream) override;

        void parseFromStream(Stream &stream) override;

        uint8 x() const;

        void set_x(uint8 value);

        uint8 y() const;

        void set_y(uint8 value);

    private:
        uint8 x_;
        uint8 y_;
    };

    enum ItemType {
        COIN = 0,
    };

    class Item : public Message {
    public:
        Item();

        ~Item() override;

        Item(const Item &from);

        void serializeToStream(Stream &stream) override;

        void parseFromStream(Stream &stream) override;

        bool has_pos() const;

        void clear_pos();

        const Point &pos() const;

        Point *release_pos();

        Point *mutable_pos();

        void set_allocated_pos(Point *pos);

        ItemType type() const;

        void set_type(ItemType value);

    private:
        ItemType type_;
        Point *pos_;
    };

    enum Direction {
        NONE = 0,
        RIGHT = 1,
        DOWN = 2,
        LEFT = 3,
        UP = 4,
    };

    enum UnitType {
        PACMAN = 0,
        GHOST = 1,
        //BOSS = 2; ?)
    };

    enum UnitStatus {
        KILLED = 0,
        ALIVE = 1,
        DYING = 2,
    };

    enum GameStatus {
        WIN = 0,
        LOSE = 1,
    };

    class Unit : public Message {
    public:
        Unit();

        ~Unit() override;

        Unit(const Unit &from);

        void serializeToStream(Stream &stream) override;

        void parseFromStream(Stream &stream) override;

        bool has_pos() const;

        void clear_pos();

        const Point &pos() const;

        Point *release_pos();

        Point *mutable_pos();

        void set_allocated_pos(Point *pos);

        Direction direction() const;

        void set_direction(Direction value);

        float entrypercent() const;

        void set_entrypercent(float value);

        UnitStatus status() const;

        void set_status(UnitStatus value);

        uint8 health() const;

        void set_health(uint8 value);

    private:
        Point *pos_;
        Direction direction_;
        float entrypercent_;
        UnitStatus status_;
        uint8 health_;
    };

    class UnitInit : public Message {
    public:
        UnitInit();

        ~UnitInit() override;

        UnitInit(const UnitInit &from);

        void serializeToStream(Stream &stream) override;

        void parseFromStream(Stream &stream) override;

        void clear_name();

        const ::std::string &name() const;

        void set_name(const ::std::string &value);

        void set_name(const char *value);

        void set_name(const char *value, size_t size);

        ::std::string *mutable_name();

        ::std::string *release_name();

        bool has_data() const;

        void clear_data();

        const Unit &data() const;

        Unit *release_data();

        Unit *mutable_data();

        void set_allocated_data(Unit *data);

        UnitType type() const;

        void set_type(UnitType value);

    private:
        UnitType type_;
        string name_;
        Unit *data_;
    };

    class ConnectMessage : public Message {
    public:

        ConnectMessage();

        ConnectMessage(const ConnectMessage &from);

        void serializeToStream(Stream &stream) override;

        void parseFromStream(Stream &stream) override;

        void clear_name();

        const ::std::string &name() const;

        void set_name(const ::std::string &value);

        void set_name(const char *value);

        void set_name(const char *value, size_t size);

        ::std::string *mutable_name();

        ::std::string *release_name();

    private:
        string name_;
    };

    class QueueMessage : public Message {
    public:
        QueueMessage();

        ~QueueMessage() override;

        QueueMessage(const QueueMessage &from);

        void serializeToStream(Stream &stream) override;

        void parseFromStream(Stream &stream) override;

        uint16 position() const;

        void set_position(uint16 value);

    private:
        uint16 position_;
    };

    class StartMessage : public Message {
    public:
        StartMessage();

        ~StartMessage() override;

        StartMessage(const StartMessage &from);

        void serializeToStream(Stream &stream) override;

        void parseFromStream(Stream &stream) override;

        uint8 id() const;

        void set_id(uint8 value);

        int unit_size() const;

        void clear_unit();

        const UnitInit &unit(int index) const;

        UnitInit *mutable_unit(int index);

        UnitInit *add_unit();

        Repeated<UnitInit> *mutable_unit();

        const Repeated<UnitInit> &unit() const;

        void clear_map();

        const ::std::string &map() const;

        void set_map(const ::std::string &value);

        void set_map(const char *value);

        void set_map(const char *value, size_t size);

        ::std::string *mutable_map();

        ::std::string *release_map();

        int item_size() const;

        void clear_item();

        const Item &item(int index) const;

        Item *mutable_item(int index);

        Item *add_item();

        Repeated<Item> *mutable_item();

        const Repeated<Item> &item() const;

    private:
        uint8 id_; // index in room
        string map_; // game map. Not string, bytes array
        Repeated<UnitInit> unit_; // unit init data
        Repeated<Item> item_; // game item init data
    };

    class EventMessage : public Message {
    public:
        EventMessage();

        virtual ~EventMessage() override;

        EventMessage(const EventMessage &from);

        void serializeToStream(Stream &stream) override;

        void parseFromStream(Stream &stream) override;

        Direction direction() const;

        void set_direction(Direction value);

    private:
        Direction direction_;
    };

    class IterationMessage : public Message {
    public:
        IterationMessage();

        ~IterationMessage() override;

        IterationMessage(const IterationMessage &from);

        void serializeToStream(Stream &stream) override;

        void parseFromStream(Stream &stream) override;

        int unit_size() const;

        void clear_unit();

        const Unit &unit(int index) const;

        Unit *mutable_unit(int index);

        Unit *add_unit();

        Repeated<Unit> *mutable_unit();

        const Repeated<Unit> &unit() const;

        int item_size() const;

        void clear_item();

        const Item &item(int index) const;

        Item *mutable_item(int index);

        Item *add_item();

        Repeated<Item> *
        mutable_item();

        const Repeated<Item> &item() const;

    private:
        Repeated<Unit> unit_;
        Repeated<Item> item_;
    };

    class EndMessage : public Message {
    public:
        EndMessage();

        ~EndMessage() override ;

        EndMessage(const EndMessage &from);

        void serializeToStream(Stream &stream) override;

        void parseFromStream(Stream &stream) override;

        GameStatus status() const;

        void set_status(GameStatus value);

        uint32 points() const;
        
        void set_points(uint16 value);
        
    private:
        GameStatus status_;
        uint16 points_;
    };
}


#endif //SERIALIZATION_PROTOCOL_H
