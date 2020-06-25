#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include "NumberSolution.h"
#include "Random.h"

class TestRandom : public ns::Random 
{
public:
    MOCK_METHOD(int, Rand,(), (const, override));
};
TEST(NSTest, should_return_simple_add_result)
{
    int input_a = 2, input_b = 3;
    
    int output = ns::Add(input_a, input_b);

    EXPECT_EQ(output, 5);
}

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