//
// Created by murt on 13.06.18.
//

#ifndef SERVER_CONSTVALUES_H
#define SERVER_CONSTVALUES_H

#include <chrono>

namespace GameMap {
    const unsigned int WIDTH = 15;
    const unsigned int HEIGHT = 24;
}

namespace GameTimer {
    const std::chrono::milliseconds PERIOD{std::chrono::milliseconds(250)};
    const std::chrono::seconds INJURED_TIMER{std::chrono::seconds(2)};
    const std::chrono::seconds DYING_TIMER{std::chrono::seconds(8)};
}

namespace UnitParametrs {
    const float PERCENTS = static_cast<float>(GameTimer::PERIOD.count()) / std::chrono::milliseconds(std::chrono::seconds(1)).count();
}

#endif //SERVER_CONSTVALUES_H
