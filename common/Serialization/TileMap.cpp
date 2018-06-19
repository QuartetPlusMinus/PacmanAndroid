//
// Created by views on 18.06.18.
//

#include "TileMap.h"

TileMap::TileMap() : map_(),
                     pacman_(),
                     ghost_() {}

TileMap::~TileMap() = default;

TileMap::TileMap(const TileMap &from) : map_(from.map_),
                                        pacman_(from.pacman_),
                                        ghost_(from.ghost_) {}

void TileMap::serializeToStream(sz::Stream &stream) const {
    stream << map_ << pacman_ << ghost_;
}

void TileMap::parseFromStream(sz::Stream &stream) {
    stream >> map_ >> pacman_ >> ghost_;
}


int TileMap::pacman_size() const {
    return pacman_.size();
}

void TileMap::clear_pacman() {
    pacman_.clear();
}

const Samples::Point &TileMap::pacman(int index) const {
    return pacman_.get(index);
}

Samples::Point *TileMap::mutable_pacman(int index) {
    return pacman_.get_mutable(index);
}

Samples::Point *TileMap::add_pacman() {
    return pacman_.add();
}

sz::Repeated<Samples::Point> *
TileMap::mutable_pacman() {
    return &pacman_;
}

const sz::Repeated<Samples::Point> &
TileMap::pacman() const {
    return pacman_;
}

void TileMap::clear_map() {
    map_.clear();
}

const sz::string &TileMap::map() const {
    return map_;
}

void TileMap::set_map(const sz::string &value) {
    map_ = value;
}

void TileMap::set_map(const char *value) {
    map_ = value;
}

void TileMap::set_map(const char *value, size_t size) {
    map_ = sz::string(value, size);
}

sz::string *TileMap::mutable_map() {
    return &map_;
}

sz::string *TileMap::release_map() {
    auto *result = new sz::string(map_);
    map_.clear();
    return result;
}

int TileMap::ghost_size() const {
    return ghost_.size();
}

void TileMap::clear_ghost() {
    ghost_.clear();
}

const Samples::Point &TileMap::ghost(int index) const {
    return ghost_.get(index);
}

Samples::Point *TileMap::mutable_ghost(int index) {
    return ghost_.get_mutable(index);
}

Samples::Point *TileMap::add_ghost() {
    return ghost_.add();
}

sz::Repeated<Samples::Point> *TileMap::mutable_ghost() {
    return &ghost_;
}

const sz::Repeated<Samples::Point> &TileMap::ghost() const {
    return ghost_;
}

const sz::string TileMap::getStringMap() const {
    return map_;
}