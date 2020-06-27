#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include "NumberSolution.h"
#include "Random.h"

class TestRandom : public ns::Random 
{
public:
    MOCK_METHOD(int, Rand,(), (const, override));
};

TEST(MockSample, TestRandom)
{
    TestRandom tr;
    EXPECT_CALL(tr, Rand()).Times(::testing::AtLeast(4))
        .WillOnce(::testing::Return(1))
        .WillOnce(::testing::Return(2))
        .WillOnce(::testing::Return(3))
        .WillOnce(::testing::Return(4))
        .WillRepeatedly(::testing::Return(5));
    
    ns::Game24 game(&tr);
    EXPECT_THAT(game.GenerateNumbers(), ::testing::StrEq("1234"));
}

TEST(MockSample, TestRandomWithRedundantNumber)
{
    TestRandom tr;
    
}

class TestPowSolution : public ::testing::Test
{
public:
    void SetUp()
    {

    }
    void TearDown()
    {

    }
protected:
    ns::Solution solution;

};

TEST_F(TestPowSolution, when_give_positive_number)
{
    double x = 10.0;
    int n = 5;

    double output = solution.myPow(x, n);
    EXPECT_DOUBLE_EQ(100000.00, output);
}

TEST_F(TestPowSolution, when_n_is_0)
{
    double x = 10.0;
    int n = 0;

    double output = solution.myPow(x, n);
    EXPECT_DOUBLE_EQ(1.00, output);
}
TEST_F(TestPowSolution, when_n_is_0_and_x_is_smallnumber)
{
    double x = 0.44528;
    int n = 0;

    double output = solution.myPow(x, n);
    EXPECT_DOUBLE_EQ(1.00, output);
}


TEST_F(TestPowSolution, when_n_is_negtive)
{
    double x = 10;
    int n = -5;

    double output = solution.myPow(x, n);
    double expect = double{1.0/100000};
    EXPECT_DOUBLE_EQ(expect, output);
}

TEST_F(TestPowSolution, when_x_is_0_but_n_is_postive)
{
    double x = 0;
    int n = 5;
    double output = solution.myPow(x, n);
    double expect = double{0};
    EXPECT_DOUBLE_EQ(expect, output);
}

TEST_F(TestPowSolution, when_x_is_0_but_n_is_negtive)
{
    double x = 0;
    int n = -5;
    double output = solution.myPow(x, n);
    double expect = double{0};
    EXPECT_DOUBLE_EQ(expect, output);
}
TEST_F(TestPowSolution, when_but_n_is_negtive_1)
{
    double x = 8.95371;
    int n = -1;
    double output = solution.myPow(x, n);
    double expect = double{0.11168554710840535};
    EXPECT_DOUBLE_EQ(expect, output);
}

TEST_F(TestPowSolution, when_n_is_1)
{
    double x = 8.95371;
    int n = 1;
    double output = solution.myPow(x, n);
    double expect = double{ 8.95371};
    EXPECT_DOUBLE_EQ(expect, output);
}

TEST_F(TestPowSolution, when_but_n_is_maxint)
{
    double x = 1;
    int n = INT_MAX;
    double output = solution.myPow(x, n);
    double expect = double{ 1};
    EXPECT_DOUBLE_EQ(expect, output);
}
TEST_F(TestPowSolution, when_n_is_minint)
{
    double x = 1;
    int n = INT_MIN;
    double output = solution.myPow(x, n);
    double expect = double{ 1};
    EXPECT_DOUBLE_EQ(expect, output);
}