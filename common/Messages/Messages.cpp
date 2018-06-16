//
// Created by views on 01.06.18.
//

#include "Messages.h"

using namespace Messages;
using namespace Messages::SimpleTypes;

// -------------------------------------------------------------------

// Message

void Message::serializeToString(string &str) {
    Stream distStream;
    serializeToStream(distStream);
    str = distStream.str();
}

void Message::parseFromString(string &str) {
    Stream srcStream(str);
    parseFromStream(srcStream);
}

// -------------------------------------------------------------------

// Point

Point::Point() :
        x_(0),
        y_(0) {}

void Point::serializeToStream(Stream &stream) const{
    stream << x_ << y_;
}

void Point::parseFromStream(Stream &stream) {
    stream >> x_ >> y_;
}

uint8 Point::x() const {
    return x_;
}

void Point::set_x(uint8 value) {
    x_ = value;
}

uint8 Point::y() const {
    return y_;
}

void Point::set_y(uint8 value) {
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

void Item::serializeToStream(Stream &stream) const {
    stream << (uint8) type_;
    pos_->serializeToStream(stream);
}

void Item::parseFromStream(Stream &stream) {
    uint8 ctype;
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
    std::cout << "KOPIROVANIE" << std::endl;
}

void Unit::serializeToStream(Stream &stream) const {
//    stream << pos_->x();
//    stream << pos_->y();
    pos_->serializeToStream(stream);
    stream << (uint8) direction_;
    stream << entrypercent_;
    stream << (uint8) status_;
    stream << health_;
}

void Unit::parseFromStream(Stream &stream) {
    uint8 ctype;
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

uint8 Unit::health() const {
    return health_;
}

void Unit::set_health(uint8 value) {
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

void UnitInit::serializeToStream(Stream &stream) const {
    stream << (uint8) type_;
    stream << name_;
    data_->serializeToStream(stream);
}

void UnitInit::parseFromStream(Stream &stream) {
    uint8 ctype;
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
    name_ = string();
}

const ::std::string &UnitInit::name() const {
    return name_;
}

void UnitInit::set_name(const ::std::string &value) {
    name_ = value;
}

void UnitInit::set_name(const char *value) {
    name_ = value;
}

void UnitInit::set_name(const char *value, size_t size) {
    name_ = string(value, size);
}

::std::string *UnitInit::mutable_name() {
    return &name_;
}

::std::string *UnitInit::release_name() {
    auto *result = new string(name_);
    name_ = string();
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

// -------------------------------------------------------------------

// ConnectMessage

ConnectMessage::ConnectMessage() :
        name_() {}

ConnectMessage::ConnectMessage(const ConnectMessage &from) :
        name_(from.name_) {}

void ConnectMessage::serializeToStream(Stream &stream) const {
    stream << name_;
}

void ConnectMessage::parseFromStream(Stream &stream) {
    stream >> name_;
}

void ConnectMessage::clear_name() {
    name_.clear();
}

const ::std::string &ConnectMessage::name() const {
    return name_;
}

void ConnectMessage::set_name(const ::std::string &value) {
    name_ = value;
}

void ConnectMessage::set_name(const char *value) {
    name_ = value;
}

void ConnectMessage::set_name(const char *value, size_t size) {
    name_ = string(value, size);
}

::std::string *ConnectMessage::mutable_name() {
    return &name_;
}

::std::string *ConnectMessage::release_name() {
    auto *result = new string(name_);
    name_.clear();
    return result;
}

// -------------------------------------------------------------------

// QueueMessage

QueueMessage::QueueMessage() : position_(0) {}

QueueMessage::~QueueMessage() = default;

QueueMessage::QueueMessage(const QueueMessage &from) : position_(from.position_) {}

void QueueMessage::serializeToStream(Stream &stream) const {
    stream << position_;
}

void QueueMessage::parseFromStream(Stream &stream) {
    stream >> position_;
}

uint16 QueueMessage::position() const {
    return position_;
}

void QueueMessage::set_position(uint16 value) {
    position_ = value;
}

// -------------------------------------------------------------------

// StartMessage

StartMessage::StartMessage() : id_(0),
                               unit_(),
                               map_(),
                               item_() {}

StartMessage::~StartMessage() = default;

StartMessage::StartMessage(const StartMessage &from) : id_(from.id_),
                                                       map_(from.map_),
                                                       unit_(from.unit_),
                                                       item_(from.item_) {}

void StartMessage::serializeToStream(Stream &stream) const {
    stream << id_ << map_ << unit_ << item_;
}

void StartMessage::parseFromStream(Stream &stream) {
    stream >> id_ >> map_ >> unit_ >> item_;
}


uint8 StartMessage::id() const {
    return id_;
}

void StartMessage::set_id(uint8 value) {
    id_ = value;
}

int StartMessage::unit_size() const {
    return unit_.size();
}

void StartMessage::clear_unit() {
    unit_.clear();
}

const UnitInit &StartMessage::unit(int index) const {
    return unit_.get(index);
}

UnitInit *StartMessage::mutable_unit(int index) {
    return unit_.get_mutable(index);
}

UnitInit *StartMessage::add_unit() {
    return unit_.add();
}

Repeated<UnitInit> *
StartMessage::mutable_unit() {
    return &unit_;
}

const Repeated<UnitInit> &
StartMessage::unit() const {
    return unit_;
}

void StartMessage::clear_map() {
    map_.clear();
}

const ::std::string &StartMessage::map() const {
    return map_;
}

void StartMessage::set_map(const ::std::string &value) {
    map_ = value;
}

void StartMessage::set_map(const char *value) {
    map_ = value;
}

void StartMessage::set_map(const char *value, size_t size) {
    map_ = string(value, size);
}

::std::string *StartMessage::mutable_map() {
    return &map_;
}

::std::string *StartMessage::release_map() {
    auto *result = new string(map_);
    map_.clear();
    return result;
}

int StartMessage::item_size() const {
    return item_.size();
}

void StartMessage::clear_item() {
    item_.clear();
}

const Item &StartMessage::item(int index) const {
    return item_.get(index);
}

Item *StartMessage::mutable_item(int index) {
    return item_.get_mutable(index);
}

Item *StartMessage::add_item() {
    return item_.add();
}

Repeated<Item> *StartMessage::mutable_item() {
    return &item_;
}

const Repeated<Item> &StartMessage::item() const {
    return item_;
}

// -------------------------------------------------------------------

// EventMessage

EventMessage::EventMessage() : direction_((Direction) 0) {}

EventMessage::~EventMessage() = default;

EventMessage::EventMessage(const EventMessage &from) : direction_(from.direction_) {}

void EventMessage::serializeToStream(Stream &stream) const {
    stream << (uint8) direction_;
}

void EventMessage::parseFromStream(Stream &stream) {
    uint8 ctype;
    stream >> ctype;
    direction_ = (Direction) ctype;
}

Direction EventMessage::direction() const {
    return direction_;
}

void EventMessage::set_direction(Direction value) {
    direction_ = value;
}

// -------------------------------------------------------------------

// IterationMessage

IterationMessage::IterationMessage() : unit_(), item_() {}

IterationMessage::~IterationMessage() = default;

IterationMessage::IterationMessage(const IterationMessage &from) :
        unit_(from.unit_),
        item_(from.item_) {}

void IterationMessage::serializeToStream(Stream &stream) const {
    stream << unit_ << item_;
}

void IterationMessage::parseFromStream(Stream &stream) {
    stream >> unit_ >> item_;
}

int IterationMessage::unit_size() const {
    return unit_.size();
}

void IterationMessage::clear_unit() {
    unit_.clear();
}

const Unit &IterationMessage::unit(int index) const {
    return unit_.get(index);
}

Unit *IterationMessage::mutable_unit(int index) {
    return unit_.get_mutable(index);
}

Unit *IterationMessage::add_unit() {
    return unit_.add();
}

Repeated<Unit> *
IterationMessage::mutable_unit() {
    return &unit_;
}

const Repeated<Unit> &
IterationMessage::unit() const {
    return unit_;
}

int IterationMessage::item_size() const {
    return item_.size();
}

void IterationMessage::clear_item() {
    item_.clear();
}

const Item &IterationMessage::item(int index) const {
    return item_.get(index);
}

Item *IterationMessage::mutable_item(int index) {
    return item_.get_mutable(index);
}

Item *IterationMessage::add_item() {
    return item_.add();
}

Repeated<Item> *
IterationMessage::mutable_item() {
    return &item_;
}

const Repeated<Item> &
IterationMessage::item() const {
    return item_;
}

// -------------------------------------------------------------------

// EndMessage

EndMessage::EndMessage() :
        status_((GameStatus) 0),
        points_(0) {}

EndMessage::~EndMessage() = default;

EndMessage::EndMessage(const EndMessage &from) :
        status_(from.status_),
        points_(from.status_) {}

void EndMessage::serializeToStream(Stream &stream) const {
    stream<<(uint8)status_<<points_;
}

void EndMessage::parseFromStream(Stream &stream) {
    uint8 ctype;
    stream>>ctype;
    status_= (GameStatus)ctype;
    stream>>points_;
}

GameStatus EndMessage::status() const {
    return status_;
}

void EndMessage::set_status(GameStatus value) {
    status_ = value;
}

uint32 EndMessage::points() const {
    return points_;
}

void EndMessage::set_points(uint16 value) {
    points_ = value;
}