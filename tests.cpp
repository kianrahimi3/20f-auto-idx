//#define CATCH_CONFIG_MAIN
#include "catch.hpp"

#include <cstring>
#include "DSString.h"
#include "DSVector.h"
#include "DSList.h"


TEST_CASE("DSString class", "[string]"){

    DSString s[10];
    s[0] = DSString("testString");
    s[1] = DSString("a test string");
    s[2] = DSString("");
    s[3] = DSString("THIS IS AN UPPERCASE STRING");
    s[4] = DSString("this is an uppercase string");
    s[5] = DSString("\n");
    s[6] = DSString("");
    s[7] = DSString("  split  split  split  ");
    s[8] = DSString("                          ");
    s[9] = DSString("testString");

    SECTION("Equality operators"){
        REQUIRE(s[0] == DSString("testString"));
        REQUIRE(s[0] == s[9]);
        REQUIRE(s[2] == "");
        REQUIRE(s[1] == "a test string");
        REQUIRE(!(s[3] == s[4]));
    }

    SECTION("Assignment operators"){
        DSString str;
        str = "a test string";
        REQUIRE(str == s[1]);
        str = String("testString");
        REQUIRE(str == s[0]);
        str = "";
        REQUIRE(str == s[6]);
        str = String("\n");
        REQUIRE(str == s[5]);
    }

    SECTION("Addition operator"){
        REQUIRE(DSString("testStringtestString") == s[0]+s[9]);
        REQUIRE(s[6] + s[6] == "");
        REQUIRE(s[5] + s[6] == String("\n"));
        REQUIRE(s[0] + s[1] + s[2] == "testStringa test string");
    }

    SECTION("Greater than operator"){
 //       REQUIRE(s[0] > s[1]);
 //       REQUIRE(s[4] > s[3]);
 //       REQUIRE(s[9] > s[6]);
 //       REQUIRE(s[7] > s[6]);
    }

    SECTION("[] Operator"){
        REQUIRE(s[0][1] == 'e');
        REQUIRE(s[4][4] == ' ');
        REQUIRE(s[6][0] == 0);
    }


    SECTION("getLength function"){
        REQUIRE(s[9].getLength() == 10);
        REQUIRE(s[2].getLength() == 0);
        REQUIRE(s[8].getLength() == 26);
        REQUIRE(s[3].getLength() == 27);
    }

//    SECTION("Substring function"){
//        REQUIRE(s[0].substring(0, 5) == "testS");
//        REQUIRE(s[4].substring(0, 4) == "this");
//        REQUIRE(s[4].substring(1, 3) == "his");
 //   }

    SECTION("c_str function"){
        REQUIRE(strcmp(s[0].c_str(), "testString") == 0);
        REQUIRE(strcmp(s[9].c_str(), s[0].c_str()) == 0);
        REQUIRE(strcmp(s[2].c_str(), "") == 0);
    }

}

TEST_CASE("DSVector class", "[vector]") {

    DSVector<int> vector1;
    DSVector<char> vector2;


    SECTION("size function") {

        REQUIRE(vector1.size() == 0);
        REQUIRE(vector2.size() == 0);

        vector1.push_back(1);
        vector1.push_back(2);
        vector1.push_back(3);
        vector1.push_back(4);
        vector1.push_back(5);

        REQUIRE(vector1.size() == 5);

        vector2.push_back('a');
        vector2.push_back('b');
        vector2.push_back('c');

        REQUIRE(vector2.size() == 3);
    }

    SECTION("[]] operator") {

        vector1.push_back(1);
        vector1.push_back(2);
        vector1.push_back(3);
        vector1.push_back(4);
        vector1.push_back(5);

        REQUIRE(vector1[0] == 1);
        REQUIRE(vector1[1] == 2);
        REQUIRE(vector1[2] == 3);
        REQUIRE(vector1[3] == 4);
        REQUIRE(vector1[4] == 5);

        vector2.push_back('a');
        vector2.push_back('b');
        vector2.push_back('c');

        REQUIRE(vector2[0] == 'a');
        REQUIRE(vector2[1] == 'b');
        REQUIRE(vector2[2] == 'c');
    }

    SECTION("Copy Assignment Operator"){

        vector1.push_back(1);
        vector1.push_back(2);
        vector1.push_back(3);
        vector1.push_back(4);
        vector1.push_back(5);

        DSVector<int> vectorTemp;

        vectorTemp.push_back(100);

        vector1 = vectorTemp;

        REQUIRE(vector1[0] == 100);


        vector2.push_back('a');
        vector2.push_back('b');
        vector2.push_back('c');

        DSVector<char> vectorChar;

        vectorChar.push_back('k');

        vector2 = vectorChar;

        REQUIRE(vector2[0] == 'k');
    }


}

TEST_CASE("DSList class", "[LinkedList") {

    DSList<int> DSL;

    DSL.push_back(1);
    DSL.push_back(2);
    DSL.push_back(3);
    DSL.push_back(4);
    DSL.push_back(5);


    SECTION("isEmpty function") {

  //      REQUIRE(DSL.isEmpty() == false);
    }

    ///how to test remove?
    /*
    SECTION("remove function") {
        REQUIRE(DSL.remove(5) == 5);
    }
     */

    SECTION("Equality operator") {
  //      REQUIRE(DSL[4] == 5);
    }
}



