#include <iostream>
#include "List.h"
#include <gtest/gtest.h>
#include <gmock/gmock.h>

using namespace std;

int main(int argc, char* argv[])
{
    cout << "\n~~~~~Char~~~~~";
    List<char> lstChar;

    lstChar.push_back('C');
    lstChar.push_back('a');
    lstChar.push_back('g');
    lstChar.push_back('e');
    lstChar.push_back('m');
    lstChar.push_back('a');

    cout << "\n\nOriginal version:\n";
    cout << lstChar;

    cout << "\n\nNow using the set I add a new field to item #1, #3, #5\n";

    lstChar.set('V', 0);
    lstChar.set('l', 2);
    lstChar.set('r', 4);

    cout << "\nNew version: \n";
    cout << lstChar;

    cout << "\n\n~~~~~Int~~~~~";
    List<int> lstOfInt;

    lstOfInt.push_front(7);
    lstOfInt.push_front(0);
    lstOfInt.push_front(3);
    lstOfInt.push_front(7);

    cout << "\n\nOriginal version: \n";
    cout << lstOfInt << endl;

    cout << "\n\nNow using the set I add a new field to item #4\n";

    lstOfInt.set(2, 3);

    cout << "\nNew version: " << endl;
    cout << lstOfInt << endl;

    lstChar.clear();
    lstOfInt.clear();

    testing::InitGoogleTest(&argc, argv);
    RUN_ALL_TESTS();

    return 0;
}