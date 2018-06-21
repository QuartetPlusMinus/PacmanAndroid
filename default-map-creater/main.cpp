//
// Created by views on 19.06.18.
//

#include <iostream>
#include <fstream>

#include "../common/Serialization/TileMap.h"

int main() {
    // new TileMap
    TileMap tileMap;

    // add PACMAN to TileMap
    Samples::Point* pacman_pos = tileMap.add_pacman();
    pacman_pos->set_x(1);
    pacman_pos->set_y(1);

    pacman_pos = tileMap.add_pacman();
    pacman_pos->set_x(13);
    pacman_pos->set_y(1);

    // add GHOSTS to TileMap
    sz::uint8 ghost_postions[] = {
            1, 22,
            5, 22,
            8, 22,
            13, 22,
            7, 22,
    };

    // add map data to TileMap as string
    tileMap.set_map("==============="   // 1
                    "=     =       ="   // 2
                    "= === = ===== ="   // 3
                    "= =       = = ="   // 4
                    "=   =====     ="   // 5
                    "= =       = = ="   // 6
                    "= = == == = = ="   // 7
                    "= =       = = ="   // 8
                    "=   == ==     ="   // 9
                    "= = == == = = ="   // 10
                    "= =       = = ="   // 11
                    "= = == == = = ="   // 12
                    "= = == == = = ="   // 13
                    "= =       = = ="   // 14
                    "= = ===== = = ="   // 15
                    "=             ="   // 16
                    "= = ===== = = ="   // 17
                    "= =       = = ="   // 18
                    "= == === ==== ="   // 19
                    "=        ==   ="   // 20
                    "= === ==    = ="   // 21
                    "= === == ==== ="   // 22
                    "=     =       ="   // 23
                    "==============="  // 24
    );

    for (int i = 0; i < sizeof(ghost_postions); i+=2) {
        Samples::Point* ghost_pos = tileMap.add_ghost();
        ghost_pos->set_x(ghost_postions[i]);
        ghost_pos->set_y(ghost_postions[i+1]);
    }

    std::ofstream out("default-map.map", std::ios::binary);

    // serialize TileMap
    std::string tileMapString;
    tileMap.serializeToString(tileMapString);

    // write to file
    out << tileMapString;
    out.close();

    return 0;
}