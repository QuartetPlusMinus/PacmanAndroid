//
// Created by views on 01.06.18.
//

#include "Messages.h"

using namespace Messages;

// -------------------------------------------------------------------

// ConnectMessage

ConnectMessage::ConnectMessage() :
        name_() {}

ConnectMessage::ConnectMessage(const ConnectMessage &from) :
        name_(from.name_) {}

void ConnectMessage::serializeToStream(sz::Stream &stream) const {
    stream << name_;
}

void ConnectMessage::parseFromStream(sz::Stream &stream) {
    stream >> name_;
}

void ConnectMessage::clear_name() {
    name_.clear();
}

const sz::string &ConnectMessage::name() const {
    return name_;
}

void ConnectMessage::set_name(const sz::string &value) {
    name_ = value;
}

void ConnectMessage::set_name(const char *value) {
    name_ = value;
}

void ConnectMessage::set_name(const char *value, size_t size) {
    name_ = sz::string(value, size);
}

sz::string *ConnectMessage::mutable_name() {
    return &name_;
}

sz::string *ConnectMessage::release_name() {
    auto *result = new sz::string(name_);
    name_.clear();
    return result;
}

// -------------------------------------------------------------------

// QueueMessage

QueueMessage::QueueMessage() : position_(0) {}

QueueMessage::~QueueMessage() = default;

QueueMessage::QueueMessage(const QueueMessage &from) : position_(from.position_) {}

void QueueMessage::serializeToStream(sz::Stream &stream) const {
    stream << position_;
}

void QueueMessage::parseFromStream(sz::Stream &stream) {
    stream >> position_;
}

sz::uint16 QueueMessage::position() const {
    return position_;
}

void QueueMessage::set_position(sz::uint16 value) {
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

void StartMessage::serializeToStream(sz::Stream &stream) const {
    stream << id_ << map_ << unit_ << item_;
}

void StartMessage::parseFromStream(sz::Stream &stream) {
    stream >> id_ >> map_ >> unit_ >> item_;
}


sz::uint8 StartMessage::id() const {
    return id_;
}

void StartMessage::set_id(sz::uint8 value) {
    id_ = value;
}

int StartMessage::unit_size() const {
    return unit_.size();
}

void StartMessage::clear_unit() {
    unit_.clear();
}

const Samples::UnitInit &StartMessage::unit(int index) const {
    return unit_.get(index);
}

Samples::UnitInit *StartMessage::mutable_unit(int index) {
    return unit_.get_mutable(index);
}

Samples::UnitInit *StartMessage::add_unit() {
    return unit_.add();
}

sz::Repeated<Samples::UnitInit> *
StartMessage::mutable_unit() {
    return &unit_;
}

const sz::Repeated<Samples::UnitInit> &
StartMessage::unit() const {
    return unit_;
}

void StartMessage::clear_map() {
    map_.clear();
}

const sz::string &StartMessage::map() const {
    return map_;
}

void StartMessage::set_map(const sz::string &value) {
    map_ = value;
}

void StartMessage::set_map(const char *value) {
    map_ = value;
}

void StartMessage::set_map(const char *value, size_t size) {
    map_ = sz::string(value, size);
}

sz::string *StartMessage::mutable_map() {
    return &map_;
}

sz::string *StartMessage::release_map() {
    auto *result = new sz::string(map_);
    map_.clear();
    return result;
}

int StartMessage::item_size() const {
    return item_.size();
}

void StartMessage::clear_item() {
    item_.clear();
}

const Samples::Item &StartMessage::item(int index) const {
    return item_.get(index);
}

Samples::Item *StartMessage::mutable_item(int index) {
    return item_.get_mutable(index);
}

Samples::Item *StartMessage::add_item() {
    return item_.add();
}

sz::Repeated<Samples::Item> *StartMessage::mutable_item() {
    return &item_;
}

const sz::Repeated<Samples::Item> &StartMessage::item() const {
    return item_;
}

// -------------------------------------------------------------------

// EventMessage

EventMessage::EventMessage() : direction_((Samples::Direction) 0) {}

EventMessage::~EventMessage() = default;

EventMessage::EventMessage(const EventMessage &from) : direction_(from.direction_) {}

void EventMessage::serializeToStream(sz::Stream &stream) const {
    stream << (sz::uint8) direction_;
}

void EventMessage::parseFromStream(sz::Stream &stream) {
    sz::uint8 ctype;
    stream >> ctype;
    direction_ = (Samples::Direction) ctype;
}

Samples::Direction EventMessage::direction() const {
    return direction_;
}

void EventMessage::set_direction(Samples::Direction value) {
    direction_ = value;
}

// -------------------------------------------------------------------

// IterationMessage

IterationMessage::IterationMessage() : unit_(), item_() {}

IterationMessage::~IterationMessage() = default;

IterationMessage::IterationMessage(const IterationMessage &from) :
        unit_(from.unit_),
        item_(from.item_) {}

void IterationMessage::serializeToStream(sz::Stream &stream) const {
    stream << unit_ << item_;
}

void IterationMessage::parseFromStream(sz::Stream &stream) {
    stream >> unit_ >> item_;
}

int IterationMessage::unit_size() const {
    return unit_.size();
}

void IterationMessage::clear_unit() {
    unit_.clear();
}

const Samples::Unit &IterationMessage::unit(int index) const {
    return unit_.get(index);
}

Samples::Unit *IterationMessage::mutable_unit(int index) {
    return unit_.get_mutable(index);
}

Samples::Unit *IterationMessage::add_unit() {
    return unit_.add();
}

sz::Repeated<Samples::Unit> *
IterationMessage::mutable_unit() {
    return &unit_;
}

const sz::Repeated<Samples::Unit> &
IterationMessage::unit() const {
    return unit_;
}

int IterationMessage::item_size() const {
    return item_.size();
}

void IterationMessage::clear_item() {
    item_.clear();
}

const Samples::Item &IterationMessage::item(int index) const {
    return item_.get(index);
}

Samples::Item *IterationMessage::mutable_item(int index) {
    return item_.get_mutable(index);
}

Samples::Item *IterationMessage::add_item() {
    return item_.add();
}

sz::Repeated<Samples::Item> *
IterationMessage::mutable_item() {
    return &item_;
}

const sz::Repeated<Samples::Item> &
IterationMessage::item() const {
    return item_;
}

// -------------------------------------------------------------------

// EndMessage

EndMessage::EndMessage() :
        status_((Samples::GameStatus) 0),
        points_(0) {}

EndMessage::~EndMessage() = default;

EndMessage::EndMessage(const EndMessage &from) :
        status_(from.status_),
        points_(from.status_) {}

void EndMessage::serializeToStream(sz::Stream &stream) const {
    stream<<(sz::uint8)status_<<points_;
}

void EndMessage::parseFromStream(sz::Stream &stream) {
    sz::uint8 ctype;
    stream>>ctype;
    status_= (Samples::GameStatus)ctype;
    stream>>points_;
}

Samples::GameStatus EndMessage::status() const {
    return status_;
}

void EndMessage::set_status(Samples::GameStatus value) {
    status_ = value;
}

sz::uint16 EndMessage::points() const {
    return points_;
}

void EndMessage::set_points(sz::uint16 value) {
    points_ = value;
}