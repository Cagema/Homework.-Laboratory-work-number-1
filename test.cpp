#include "pch.h"
#include "gtest/gtest.h"
#include <string>
#include "E:\Study\2 kurs\4 semestr\aistd\Template List 1\Template List 1\List.h"

namespace {
	class ClassDeclaration : public testing::Test {
	public:
		//initialization of object that will be used in test
		List<int> objInt;
		List<double > objDouble;
		List<char> objChar;
		List<std::string> objString;
		ClassDeclaration() {
			objInt;
			objDouble;
			objChar;
			objString;
		}
	};
}

TEST_F(ClassDeclaration, PushBack_onInt1) {
	objInt.push_back(1);
	objInt.push_back(2);
	objInt.push_back(3);

	ASSERT_EQ(3, objInt.getSize());

	ASSERT_EQ(1, objInt.at(0));
}
TEST_F(ClassDeclaration, PushBack_onInt2) {
	objInt.push_back(1);
	objInt.push_back(2);
	objInt.push_back(3);

	ASSERT_EQ(3, objInt.getSize());

	ASSERT_EQ(2, objInt.at(1));
}
TEST_F(ClassDeclaration, PushBack_onInt3) {
	objInt.push_back(1);
	objInt.push_back(2);
	objInt.push_back(3);

	ASSERT_EQ(3, objInt.getSize());

	ASSERT_EQ(3, objInt.at(2));
}

TEST_F(ClassDeclaration, PushFront_onDouble1) {
	objDouble.push_front(1.1);
	objDouble.push_front(2.2);
	objDouble.push_front(3.3);

	ASSERT_EQ(3, objDouble.getSize());

	ASSERT_EQ(3.3, objDouble.at(0));
}
TEST_F(ClassDeclaration, PushFront_onDouble2) {
	objDouble.push_front(1.1);
	objDouble.push_front(2.2);
	objDouble.push_front(3.3);

	ASSERT_EQ(3, objDouble.getSize());

	ASSERT_EQ(2.2, objDouble.at(1));
}
TEST_F(ClassDeclaration, PushFront_onDouble3) {
	objDouble.push_front(1.1);
	objDouble.push_front(2.2);
	objDouble.push_front(3.3);

	ASSERT_EQ(3, objDouble.getSize());

	ASSERT_EQ(1.1, objDouble.at(2));
}

TEST_F(ClassDeclaration, PopBack_onString1) {
	objString.push_back("str1");
	objString.push_back("str2");
	objString.push_back("str3");

	ASSERT_EQ(3, objString.getSize());

	objString.pop_back();
	ASSERT_EQ(2, objString.getSize());

	ASSERT_EQ("str1", objString.at(0));
}
TEST_F(ClassDeclaration, PopBack_onString2) {
	objString.push_back("str1");
	objString.push_back("str2");
	objString.push_back("str3");

	ASSERT_EQ(3, objString.getSize());

	objString.pop_back();
	ASSERT_EQ(2, objString.getSize());

	ASSERT_EQ("str2", objString.at(1));
}

TEST_F(ClassDeclaration, PopFront_onChar1) {
	objChar.push_back('C');
	objChar.push_back('a');
	objChar.push_back('g');

	ASSERT_EQ(3, objChar.getSize());

	objChar.pop_front();
	ASSERT_EQ(2, objChar.getSize());
	
	ASSERT_EQ('a', objChar.at(0));
}
TEST_F(ClassDeclaration, PopFront_onChar2) {
	objChar.push_back('C');
	objChar.push_back('a');
	objChar.push_back('g');

	ASSERT_EQ(3, objChar.getSize());

	objChar.pop_front();
	ASSERT_EQ(2, objChar.getSize());

	ASSERT_EQ('g', objChar.at(1));
}

TEST_F(ClassDeclaration, Insert_onDoub_NormArg1) {
	objDouble.push_back(1.1);
	objDouble.push_back(2.2);

	ASSERT_EQ(2, objDouble.getSize());

	objDouble.insert(3.3, 1);

	ASSERT_EQ(3, objDouble.getSize());

	ASSERT_EQ(1.1, objDouble.at(0));
}
TEST_F(ClassDeclaration, Insert_onDoub_NormArg2) {
	objDouble.push_back(1.1);
	objDouble.push_back(2.2);

	ASSERT_EQ(2, objDouble.getSize());

	objDouble.insert(3.3, 1);

	ASSERT_EQ(3, objDouble.getSize());

	ASSERT_EQ(3.3, objDouble.at(1));
}
TEST_F(ClassDeclaration, Insert_onDoub_NormArg3) {
	objDouble.push_back(1.1);
	objDouble.push_back(2.2);

	ASSERT_EQ(2, objDouble.getSize());

	objDouble.insert(3.3, 1);

	ASSERT_EQ(3, objDouble.getSize());

	ASSERT_EQ(2.2, objDouble.at(2));
}

TEST_F(ClassDeclaration, Insert_onInt_BiggerSize) { //bigger than size
	try {
		objInt.push_back(1);
		objInt.push_back(2);
		objInt.push_back(3);
		objInt.insert(18, 10);
	}
	catch (std::exception& ex) {
		EXPECT_STREQ("Index is larger than size of list", ex.what());
	}
}

TEST_F(ClassDeclaration, At_onInt_BiggerSize) { //bigger than Size
	try {
		objInt.push_back(1);
		objInt.push_back(2);
		objInt.push_back(3);
		objInt.at(10);
	}
	catch (std::exception& ex) {
		EXPECT_STREQ("Index is larger than size of list", ex.what());
	}
}


TEST_F(ClassDeclaration, At_onString_NormArg) {
	objString.push_back("Str1");
	objString.push_back("Str2");

	objString.at(0);

	ASSERT_EQ("Str1", objString.at(0));
}

TEST_F(ClassDeclaration, Remove_onChar_BiggerThanSizeArg) { // bigger than size
	try {
		objChar.push_back('C');
		objChar.push_back('a');
		objChar.push_back('g');
		objChar.remove(10);
	}
	catch (std::exception& ex) {
		EXPECT_STREQ("Index is larger than size of list", ex.what());
	}
}

TEST_F(ClassDeclaration, Remove_onChar_NormArg1) {
	objChar.push_back('C');
	objChar.push_back('a');
	objChar.push_back('g');

	ASSERT_EQ(3, objChar.getSize());
	objChar.remove(1);

	ASSERT_EQ(2, objChar.getSize());

	ASSERT_EQ('C', objChar.at(0));
}
TEST_F(ClassDeclaration, Remove_onChar_NormArg2) {
	objChar.push_back('C');
	objChar.push_back('a');
	objChar.push_back('g');

	ASSERT_EQ(3, objChar.getSize());
	objChar.remove(1);

	ASSERT_EQ(2, objChar.getSize());

	ASSERT_EQ('g', objChar.at(1));
}

TEST_F(ClassDeclaration, Clear_onInt){
    objInt.push_back(1);
	objInt.push_back(2);
	objInt.push_back(3);

	objInt.clear();

    ASSERT_EQ(1, objInt.isEmpty());
}

TEST_F(ClassDeclaration, Set_onDoub_BiggerThanSizeArg){
    try {
		objDouble.push_back(1.1);
		objDouble.push_back(2.2);
		objDouble.push_back(3.3);
		objDouble.set(1.1, 10);
    }
    catch (std::exception& ex) {
        EXPECT_STREQ("Index is larger than size of list", ex.what());
    }
}

TEST_F(ClassDeclaration, Set_onDoub_NormArg){
	objDouble.push_back(1.1);
	objDouble.push_back(2.2);
	objDouble.push_back(3.3);
	objDouble.set(4.4, 1);

    ASSERT_EQ(3, objDouble.getSize());

    ASSERT_EQ(1.1, objDouble.at(0));
    ASSERT_EQ(4.4, objDouble.at(1));
    ASSERT_EQ(3.3, objDouble.at(2));
}

TEST_F(ClassDeclaration, GetSize_onInt){
    ASSERT_EQ(0, objInt.getSize());

	objInt.push_back(1);
	objInt.push_back(2);
	objInt.push_back(3);

    ASSERT_EQ(3, objInt.getSize());
}

TEST_F(ClassDeclaration, IsEmpty_onInt){
    ASSERT_EQ(1, objInt.isEmpty());

	objInt.push_back(1);
	objInt.push_back(2);
	objInt.push_back(3);

    ASSERT_EQ(0, objInt.isEmpty());
}