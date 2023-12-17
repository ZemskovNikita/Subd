#include "pch.h"
#include <string>
#include "F:\Прога\Vasileva111111\Vasileva111111\Tree.h"


TEST(TestCaseName, TestName) {
  EXPECT_EQ(1, 1);
  EXPECT_TRUE(true);
}


TEST(Test_String, TestPrint_String) {

    Tree<std::string> bst;

    bst.add("Zanildo");
    bst.add("Helder");
    bst.add("Wilson");
    bst.add("Ady");
    bst.add("Adilson");
    bst.add("Patrick");

    EXPECT_EQ(bst.print(), "Adilson Ady Helder Patrick Wilson Zanildo ");
}

TEST(Test_Int, TestPrint_Int) {

    Tree<int> tr;

    tr.add(4);
    tr.add(6);
    tr.add(1);
    tr.add(9);
    tr.add(2);
    tr.add(0);
    tr.add(89);
    tr.add(12);
    tr.add(32);
    tr.add(5);
    tr.add(22);
    tr.add(222);

    EXPECT_EQ(tr.print(), "0 1 2 4 5 6 9 12 22 32 89 222 ");
}

TEST(Test_Int, TestSizeCorrect_Int) {

    Tree<int> tr;

    tr.add(4);
    tr.add(6);

    EXPECT_EQ(tr.get_size(), 2);
}

TEST(Test_String, TestSizeCorrect_String) {

    Tree<std::string> tr;

    tr.add("4");
    tr.add("6");

    EXPECT_EQ(tr.get_size(), 2);
}

TEST(Test_Int, TestAdd_Int) {

    Tree<int> tr;

    tr.add(4);
    tr.add(6);

    EXPECT_TRUE(tr.contain(4));
}

TEST(Test_String, TestAdd_String) {

    Tree<std::string> tr;

    tr.add("4");
    tr.add("6");

    EXPECT_TRUE(tr.contain("4"));
}

TEST(Test_Double, TestAdd_Double) {

    Tree<double> tr;

    tr.add(4.33);
    tr.add(6.343);

    EXPECT_TRUE(tr.contain(6.343));
}

TEST(Test_Double, TestSizeCorrect_Double) {

    Tree<double> tr;

    tr.add(4.33);
    tr.add(6.343);

    EXPECT_EQ(tr.get_size(), 2);
}

TEST(Test_Double, TestPrint_Double) {

    Tree<double> tr;

    tr.add(4.33);
    tr.add(6.343);

    EXPECT_EQ(tr.print(), "4.33 6.343 ");
}

TEST(Test_Int, TestDestroy_Int) {

    Tree<int> tr;

    tr.add(6);
    tr.add(4);
    tr.destroy(4);

    EXPECT_FALSE(tr.contain(4));
}

TEST(Test_Double, TestDestroy_Double) {

    Tree<double> tr;

    tr.add(6.343);
    tr.add(4.4);
    tr.destroy(4.4);

    EXPECT_FALSE(tr.contain(4.4));
}

TEST(Test_String, TestDestroy_String) {

    Tree<std::string> tr;

    tr.add("6.343");
    tr.add("6");
    tr.destroy("6");

    EXPECT_FALSE(tr.contain("6"));
}