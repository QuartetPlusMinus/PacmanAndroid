//
// Created by views on 18.06.18.
//

#ifndef COMMON_SERIALIZABLE_TILE_MAP_H
#define COMMON_SERIALIZABLE_TILE_MAP_H

#include "Serialization/Serialization.h"
#include "Samples.h"

class TileMap : public sz::Serializable {
public:
    TileMap();

    ~TileMap() override;

    TileMap(const TileMap &from);

    void serializeToStream(sz::Stream &stream) const override;

    void parseFromStream(sz::Stream &stream) override;

    void clear_map();

    const sz::string &map() const;

    void set_map(const sz::string &value);

    void set_map(const char *value);

    void set_map(const char *value, size_t size);

    sz::string *mutable_map();

    sz::string *release_map();

    int pacman_size() const;

    void clear_pacman();

    const Samples::Point &pacman(int index) const;

    Samples::Point *mutable_pacman(int index);

    Samples::Point *add_pacman();

    sz::Repeated<Samples::Point> *mutable_pacman();

    const sz::Repeated<Samples::Point> &pacman() const;

    int ghost_size() const;

    void clear_ghost();

    const Samples::Point &ghost(int index) const;

    Samples::Point *mutable_ghost(int index);

    Samples::Point *add_ghost();

    sz::Repeated<Samples::Point> *mutable_ghost();

    const sz::Repeated<Samples::Point> &ghost() const;

private:
    sz::string map_;
    sz::Repeated<Samples::Point> pacman_;
    sz::Repeated<Samples::Point> ghost_;

};

#endif //COMMON_SERIALIZABLE_TILE_MAP_H
