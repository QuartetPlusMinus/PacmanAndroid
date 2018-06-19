//
// Created by views on 19.06.18.
//

#ifndef SERIALIZATION_SAMPLES_H
#define SERIALIZATION_SAMPLES_H

#include "Serialization/Serialization.h"

namespace Samples {
    class Point : public sz::Serializable {
    public:
        Point();

        void serializeToStream(sz::Stream &stream) const override;

        void parseFromStream(sz::Stream &stream) override;

        sz::uint8 x() const;

        void set_x(sz::uint8 value);

        sz::uint8 y() const;

        void set_y(sz::uint8 value);

    private:
        sz::uint8 x_;
        sz::uint8 y_;
    };

    enum ItemType {
        COIN = 0,
    };

    class Item : public sz::Serializable {
    public:
        Item();

        ~Item() override;

        Item(const Item &from);

        void serializeToStream(sz::Stream &stream) const override;

        void parseFromStream(sz::Stream &stream) override;

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

    class Unit : public sz::Serializable {
    public:
        Unit();

        ~Unit() override;

        Unit(const Unit &from);

        Unit &operator=(const Unit &from) {
            set_allocated_pos(new Point(*from.pos_));
            direction_ = from.direction_;
            entrypercent_ = from.entrypercent_;
            status_ = from.status_;
            health_ = from.health_;
            return *this;
        }

        void serializeToStream(sz::Stream &stream) const override;

        void parseFromStream(sz::Stream &stream) override;

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

        sz::uint8 health() const;

        void set_health(sz::uint8 value);

    private:
        Point *pos_;
        Direction direction_;
        float entrypercent_;
        UnitStatus status_;
        sz::uint8 health_;
    };

    class UnitInit : public sz::Serializable {
    public:
        UnitInit();

        ~UnitInit() override;

        UnitInit(const UnitInit &from);

        void serializeToStream(sz::Stream &stream) const override;

        void parseFromStream(sz::Stream &stream) override;

        void clear_name();

        const sz::string &name() const;

        void set_name(const sz::string &value);

        void set_name(const char *value);

        void set_name(const char *value, size_t size);

        sz::string *mutable_name();

        sz::string *release_name();

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
        sz::string name_;
        Unit *data_;
    };
}

#endif //SERIALIZATION_SAMPLES_H
