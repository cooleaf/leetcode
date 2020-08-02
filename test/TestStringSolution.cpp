//
// Created by Xiaoguang Zhao on 7/4/20.
//

#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include "StringSolution.h"
#include <vector>
#include <unordered_set>
#include <functional>

using namespace std;

class TestStringSolution : public ::testing::Test
{
protected:
    StringSolution ss;
};

TEST_F(TestStringSolution, should_return_0_when_give_string_less_than_2)
{
    auto output = ss.longestValidParentheses("(");

    EXPECT_THAT(output, ::testing::Eq(0));
}



using StringSolutionPtr = StringSolution*;

struct MyHash
{
    size_t operator()(const StringSolutionPtr& p) const
    {
        return reinterpret_cast<long long>(p) % 10;
    }
};

struct MyEqual
{
    bool operator() (const StringSolutionPtr& lhs, const StringSolutionPtr& rhs) const
    {
        return lhs == rhs;
    }
};

template <class hash, class equalto>
class KeylessMap{
public:
    typedef unordered_set<StringSolutionPtr, hash, equalto> MySet;
    void Insert(StringSolutionPtr ssp) {
        mySet.insert(ssp);
    }
private:
    MySet mySet;

};


TEST(TestUnorderedSet, test)
{
    KeylessMap<MyHash, MyEqual> myMap;
    StringSolutionPtr ssp = new StringSolution;
    myMap.Insert(ssp);

}

//假装是个hash函数

int fakeHash(int k)
{
    return k;
}

size_t xhash(int p)
{
    return p % 10;
}

class KeyLessMap2
{
public:
    void Init(int(*h)(int ))
    {
        _hash = h;
    }
private:
    int (*_hash)(int a);

    unordered_set<StringSolutionPtr, std::function<xhash>> ssp;
};


