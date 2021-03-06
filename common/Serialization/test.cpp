//
// Created by views on 02.06.18.
//

#define BOOST_TEST_MAIN
#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MODULE SerialezeNParse

#include <boost/test/unit_test.hpp>
#include <random>

#include "Messages.h"

BOOST_AUTO_TEST_SUITE(SerialezeNParseTest)

    BOOST_AUTO_TEST_CASE(PointSNP) {
        srand((unsigned int) time(nullptr));
        auto x = (sz::uint8) rand();
        auto y = (sz::uint8) rand();

        Samples::Point point1;
        point1.set_x(x);
        point1.set_y(y);

        sz::string buff;
        point1.serializeToString(buff);

        Samples::Point point2;
        point2.parseFromString(buff);

        BOOST_REQUIRE_EQUAL(point2.x(), x);
        BOOST_REQUIRE_EQUAL(point2.y(), y);
    }

    BOOST_AUTO_TEST_CASE(ItemSNP) {
        auto x = (sz::uint8) rand();
        auto y = (sz::uint8) rand();
        auto type = (Samples::ItemType) 0;

        Samples::Item item1;
        item1.mutable_pos()->set_x(x);
        item1.mutable_pos()->set_y(y);
        item1.set_type(type);

        sz::string buff;
        item1.serializeToString(buff);

        Samples::Item item2;
        item2.parseFromString(buff);

        BOOST_REQUIRE_EQUAL(item2.pos().x(), x);
        BOOST_REQUIRE_EQUAL(item2.pos().y(), y);
        BOOST_REQUIRE_EQUAL(item2.type(), type);
    }

    BOOST_AUTO_TEST_CASE(UnitSNP) {
        auto x = (sz::uint8) rand();
        auto y = (sz::uint8) rand();
        auto direction = (Samples::Direction) (rand() % 5);
        auto entrypercent = (float) rand() / RAND_MAX;
        auto status = (Samples::UnitStatus) (rand() % 2);
        auto health = (sz::uint8) (rand() % 4);

        Samples::Unit unit1;
        unit1.mutable_pos()->set_x(x);
        unit1.mutable_pos()->set_y(y);
        unit1.set_direction(direction);
        unit1.set_entrypercent(entrypercent);
        unit1.set_status(status);
        unit1.set_health(health);

        sz::string buff;
        unit1.serializeToString(buff);

        Samples::Unit unit2;
        unit2.parseFromString(buff);

        BOOST_REQUIRE_EQUAL(unit2.pos().x(), x);
        BOOST_REQUIRE_EQUAL(unit2.pos().y(), y);
        BOOST_REQUIRE_EQUAL(unit2.direction(), direction);
        BOOST_REQUIRE_EQUAL(unit2.entrypercent(), entrypercent);
        BOOST_REQUIRE_EQUAL(unit2.status(), status);
        BOOST_REQUIRE_EQUAL(unit2.health(), health);
    }

    BOOST_AUTO_TEST_CASE(UnitInitSNP) {
        auto x = (sz::uint8) rand();
        auto y = (sz::uint8) rand();
        auto direction = (Samples::Direction) (rand() % 5);
        auto entrypercent = (float) rand() / RAND_MAX;
        auto status = (Samples::UnitStatus) (rand() % 2);
        auto health = (sz::uint8) (rand() % 4);
        auto type = (Samples::UnitType) (rand() % 2);
        sz::string name = "Some name";

        Samples::UnitInit unitInit1;
        Samples::Unit *unit1 = unitInit1.mutable_data();
        unit1->mutable_pos()->set_x(x);
        unit1->mutable_pos()->set_y(y);
        unit1->set_direction(direction);
        unit1->set_entrypercent(entrypercent);
        unit1->set_status(status);
        unit1->set_health(health);

        unitInit1.set_type(type);
        unitInit1.set_name(name);

        sz::string buff;
        unitInit1.serializeToString(buff);

        Samples::UnitInit unitInit2;
        unitInit2.parseFromString(buff);

        BOOST_REQUIRE_EQUAL(unitInit2.data().pos().x(), x);
        BOOST_REQUIRE_EQUAL(unitInit2.data().pos().y(), y);
        BOOST_REQUIRE_EQUAL(unitInit2.data().direction(), direction);
        BOOST_REQUIRE_EQUAL(unitInit2.data().entrypercent(), entrypercent);
        BOOST_REQUIRE_EQUAL(unitInit2.data().status(), status);
        BOOST_REQUIRE_EQUAL(unitInit2.data().health(), health);
        BOOST_REQUIRE_EQUAL(unitInit2.type(), type);
        BOOST_REQUIRE_EQUAL(unitInit2.name(), name);
    }

    BOOST_AUTO_TEST_CASE(ConnectMessageSNP) {
        sz::string name = "asdf";

        Messages::ConnectMessage connectMessage1;
        connectMessage1.set_name(name);

        sz::string buff;
        connectMessage1.serializeToString(buff);

        Messages::ConnectMessage connectMessage2;
        connectMessage2.parseFromString(buff);

        BOOST_REQUIRE_EQUAL(connectMessage2.name(), name);
    }

    BOOST_AUTO_TEST_CASE(QueueMessageSNP) {
        Messages::QueueMessage queueMessage1;

        auto position = (sz::uint16)rand();
        queueMessage1.set_position(position);

        sz::string buff;
        queueMessage1.serializeToString(buff);

        Messages::QueueMessage queueMessage2;
        queueMessage2.parseFromString(buff);

        BOOST_REQUIRE_EQUAL(queueMessage2.position(), position);
    }

    BOOST_AUTO_TEST_CASE(StartMessageSNP) {
        auto x = (sz::uint8) rand();
        auto y = (sz::uint8) rand();
        auto direction = (Samples::Direction) (rand() % 5);
        auto entrypercent = (float) rand() / RAND_MAX;
        auto status = (Samples::UnitStatus) (rand() % 2);
        auto health = (sz::uint8) (rand() % 4);
        auto type = (Samples::UnitType) (rand() % 2);

        auto itemX = (sz::uint8) rand();
        auto itemY = (sz::uint8) rand();
        auto itemType = (Samples::ItemType) 0;

        auto id = (sz::uint8)(rand() % 256);
        sz::string map = "#.....#...#.....#..#..#";
        sz::string name = "Some name";

        Messages::StartMessage startMessage1;

        Samples::UnitInit *unitInit = startMessage1.add_unit();
        Samples::Unit *unit = unitInit->mutable_data();
        Samples::Item *item = startMessage1.add_item();

        unit->mutable_pos()->set_x(x);
        unit->mutable_pos()->set_y(y);
        unit->set_direction(direction);
        unit->set_entrypercent(entrypercent);
        unit->set_status(status);
        unit->set_health(health);

        unitInit->set_type(type);
        unitInit->set_name(name);

        item->mutable_pos()->set_x(itemX);
        item->mutable_pos()->set_y(itemY);
        item->set_type(itemType);

        startMessage1.set_id(id);
        startMessage1.set_map(map);

        sz::string buff;
        startMessage1.serializeToString(buff);

        Messages::StartMessage startMessage2;
        startMessage2.parseFromString(buff);

        BOOST_REQUIRE_EQUAL(startMessage2.unit(0).data().pos().x(), x);
        BOOST_REQUIRE_EQUAL(startMessage2.unit(0).data().pos().y(), y);
        BOOST_REQUIRE_EQUAL(startMessage2.unit(0).data().direction(), direction);
        BOOST_REQUIRE_EQUAL(startMessage2.unit(0).data().entrypercent(), entrypercent);
        BOOST_REQUIRE_EQUAL(startMessage2.unit(0).data().status(), status);
        BOOST_REQUIRE_EQUAL(startMessage2.unit(0).data().health(), health);
        BOOST_REQUIRE_EQUAL(startMessage2.unit(0).type(), type);
        BOOST_REQUIRE_EQUAL(startMessage2.unit(0).name(), name);

        BOOST_REQUIRE_EQUAL(startMessage2.item(0).pos().x(), itemX);
        BOOST_REQUIRE_EQUAL(startMessage2.item(0).pos().y(), itemY);
        BOOST_REQUIRE_EQUAL(startMessage2.item(0).type(), itemType);

        BOOST_REQUIRE_EQUAL(startMessage2.id(), id);
        BOOST_REQUIRE_EQUAL(startMessage2.map(), map);
    }

    BOOST_AUTO_TEST_CASE(EventMessageSNP) {
        Messages::EventMessage eventMessage1;

        auto direction = (Samples::Direction)(rand() % 5);
        eventMessage1.set_direction(direction);

        sz::string buff;
        eventMessage1.serializeToString(buff);

        Messages::EventMessage eventMessage2;
        eventMessage2.parseFromString(buff);

        BOOST_REQUIRE_EQUAL(eventMessage2.direction(), direction);
    }

    BOOST_AUTO_TEST_CASE(IterationMessageSNP) {
        auto x = (sz::uint8) rand();
        auto y = (sz::uint8) rand();
        auto direction = (Samples::Direction) (rand() % 5);
        auto entrypercent = (float) rand() / RAND_MAX;
        auto status = (Samples::UnitStatus) (rand() % 2);
        auto health = (sz::uint8) (rand() % 4);

        auto itemX = (sz::uint8) rand();
        auto itemY = (sz::uint8) rand();
        auto itemType = (Samples::ItemType) 0;

        Messages::IterationMessage iterationMessage1;

        Samples::Unit *unit = iterationMessage1.add_unit();
        Samples::Item *item = iterationMessage1.add_item();

        unit->mutable_pos()->set_x(x);
        unit->mutable_pos()->set_y(y);
        unit->set_direction(direction);
        unit->set_entrypercent(entrypercent);
        unit->set_status(status);
        unit->set_health(health);

        item->mutable_pos()->set_x(itemX);
        item->mutable_pos()->set_y(itemY);
        item->set_type(itemType);

        sz::string buff;
        iterationMessage1.serializeToString(buff);

        Messages::IterationMessage iterationMessage2;
        iterationMessage2.parseFromString(buff);

        BOOST_REQUIRE_EQUAL(iterationMessage2.unit(0).pos().x(), x);
        BOOST_REQUIRE_EQUAL(iterationMessage2.unit(0).pos().y(), y);
        BOOST_REQUIRE_EQUAL(iterationMessage2.unit(0).direction(), direction);
        BOOST_REQUIRE_EQUAL(iterationMessage2.unit(0).entrypercent(), entrypercent);
        BOOST_REQUIRE_EQUAL(iterationMessage2.unit(0).status(), status);
        BOOST_REQUIRE_EQUAL(iterationMessage2.unit(0).health(), health);

        BOOST_REQUIRE_EQUAL(iterationMessage2.item(0).pos().x(), itemX);
        BOOST_REQUIRE_EQUAL(iterationMessage2.item(0).pos().y(), itemY);
        BOOST_REQUIRE_EQUAL(iterationMessage2.item(0).type(), itemType);
    }

    BOOST_AUTO_TEST_CASE(EndMessageSNP) {
        auto status = (Samples::GameStatus)(rand() % 2);
        auto points =  (sz::uint16)rand();

        Messages::EndMessage endMessage1;

        endMessage1.set_status(status);
        endMessage1.set_points(points);

        sz::string buff;
        endMessage1.serializeToString(buff);

        Messages::EndMessage endMessage2;
        endMessage2.parseFromString(buff);

        BOOST_REQUIRE_EQUAL(endMessage2.status(), status);
        BOOST_REQUIRE_EQUAL(endMessage2.points(), points);
    }
BOOST_AUTO_TEST_SUITE_END()
