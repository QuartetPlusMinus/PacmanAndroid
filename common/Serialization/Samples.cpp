//
// Created by views on 19.06.18.
//

#include "Samples.h"

using namespace Samples;

// -------------------------------------------------------------------

// Point

Point::Point() :
        x_(0),
        y_(0) {}

void Point::serializeToStream(sz::Stream &stream) const{
    stream << x_ << y_;
}

void Point::parseFromStream(sz::Stream &stream) {
    stream >> x_ >> y_;
}

sz::uint8 Point::x() const {
    return x_;
}

void Point::set_x(sz::uint8 value) {
    x_ = value;
}

sz::uint8 Point::y() const {
    return y_;
}

void Point::set_y(sz::uint8 value) {
    y_ = value;
}

// -------------------------------------------------------------------

// Item

Item::Item() :
        type_(),
        pos_(nullptr) {}

Item::~Item() {
    clear_pos();
}

Item::Item(const Item &from) :
        type_(from.type_),
        pos_(nullptr) {
    if (from.pos_) {
        pos_ = new Point(*from.pos_);
    }
}

void Item::serializeToStream(sz::Stream &stream) const {
    stream << (sz::uint8) type_;
    pos_->serializeToStream(stream);
}

void Item::parseFromStream(sz::Stream &stream) {
    sz::uint8 ctype;
    stream >> ctype;
    type_ = (ItemType) ctype;
    mutable_pos()->parseFromStream(stream);
}

ItemType Item::type() const {
    return type_;
}

void Item::set_type(ItemType value) {
    type_ = value;
}

bool Item::has_pos() const {
    return pos_ != nullptr;
}

void Item::clear_pos() {
    pos_ = nullptr;
}

const Point &Item::pos() const {
    return *pos_;
}

Point *Item::release_pos() {
    Point *temp = pos_;
    pos_ = nullptr;
    return temp;
}

Point *Item::mutable_pos() {
    if (pos_ == nullptr) {
        pos_ = new Point;
    }
    return pos_;
}

void Item::set_allocated_pos(Point *pos) {
    pos_ = pos;
}

// -------------------------------------------------------------------

// Unit

Unit::Unit() :
        pos_(nullptr),
        direction_((Direction) 0),
        entrypercent_(0),
        status_((UnitStatus) 0),
        health_(0) {}

Unit::~Unit() {
    clear_pos();
}

Unit::Unit(const Unit &from) :
        pos_(new Point(*from.pos_)),
        direction_(from.direction_),
        entrypercent_(from.entrypercent_),
        status_(from.status_),
        health_(from.health_) {
}

void Unit::serializeToStream(sz::Stream &stream) const {
    pos_->serializeToStream(stream);
    stream << (sz::uint8) direction_;
    stream << entrypercent_;
    stream << (sz::uint8) status_;
    stream << health_;
}

void Unit::parseFromStream(sz::Stream &stream) {
    sz::uint8 ctype;
    mutable_pos()->parseFromStream(stream);
    stream >> ctype;
    direction_ = (Direction) ctype;
    stream >> entrypercent_;
    stream >> ctype;
    status_ = (UnitStatus) ctype;
    stream >> health_;
}

bool Unit::has_pos() const {
    return pos_ != nullptr;
}

void Unit::clear_pos() {
    delete pos_;
}

const Point &Unit::pos() const {
    return *pos_;
}

Point *Unit::release_pos() {
    Point *temp = pos_;
    pos_ = nullptr;
    return temp;
}

Point *Unit::mutable_pos() {
    if (pos_ == nullptr) {
        pos_ = new Point;
    }
    return pos_;
}

void Unit::set_allocated_pos(Point *pos) {
    clear_pos();
    pos_ = pos;
}

Direction Unit::direction() const {
    return direction_;
}

void Unit::set_direction(Direction value) {
    direction_ = value;
}

float Unit::entrypercent() const {
    return entrypercent_;
}

void Unit::set_entrypercent(float value) {
    entrypercent_ = value;
}

UnitStatus Unit::status() const {
    return status_;
}

void Unit::set_status(UnitStatus value) {
    status_ = value;
}

sz::uint8 Unit::health() const {
    return health_;
}

void Unit::set_health(sz::uint8 value) {
    health_ = value;
}

// -------------------------------------------------------------------

// UnitInit

UnitInit::UnitInit() :
        type_((UnitType) 0),
        name_(),
        data_(nullptr) {}

UnitInit::~UnitInit() {
    clear_data();
}

UnitInit::UnitInit(const UnitInit &from) :
        type_(from.type_),
        name_(from.name_),
        data_(new Unit(*from.data_)) {}

void UnitInit::serializeToStream(sz::Stream &stream) const {
    stream << (sz::uint8) type_;
    stream << name_;
    data_->serializeToStream(stream);
}

void UnitInit::parseFromStream(sz::Stream &stream) {
    sz::uint8 ctype;
    stream >> ctype;
    type_ = (UnitType) ctype;
    stream >> name_;
    mutable_data()->parseFromStream(stream);
}

UnitType UnitInit::type() const {
    return type_;
}

void UnitInit::set_type(UnitType value) {
    type_ = value;
}

void UnitInit::clear_name() {
    name_ = sz::string();
}

const sz::string &UnitInit::name() const {
    return name_;
}

void UnitInit::set_name(const sz::string &value) {
    name_ = value;
}

void UnitInit::set_name(const char *value) {
    name_ = value;
}

void UnitInit::set_name(const char *value, size_t size) {
    name_ = sz::string(value, size);
}

sz::string *UnitInit::mutable_name() {
    return &name_;
}

sz::string *UnitInit::release_name() {
    auto *result = new sz::string(name_);
    name_ = sz::string();
    return result;
}

bool UnitInit::has_data() const {
    return data_ != nullptr;
}

void UnitInit::clear_data() {
    delete data_;
    data_ = nullptr;
}

const Unit &UnitInit::data() const {
    return *data_;
}

Unit *UnitInit::release_data() {
    Unit *temp = data_;
    data_ = nullptr;
    return temp;
}

Unit *UnitInit::mutable_data() {
    if (data_ == nullptr) {
        data_ = new Unit;
    }
    return data_;
}

void UnitInit::set_allocated_data(Unit *data) {
    data_ = data;
}