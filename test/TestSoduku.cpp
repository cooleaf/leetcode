//
// Created by Xiaoguang Zhao on 2020/6/27.
//
#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include "NumberSolution.h"
#include <vector>
using std::vector;
class TestSolveSoduku : public ::testing::Test
{
protected:
    ns::Solution solution;
    vector<vector<char>> board {
            {'1','2','3','4','5','6','7','8','9'},
            {'4','5','6','7','8','9','1','2','3'},
            {'7','8','9','1','2','3','4','5','6'},
            {'2','3','1','5','6','4','8','9','7'},
            {'5','6','4','8','9','7','2','3','1'},
            {'8','9','7','2','3','1','5','6','4'},
            {'3','1','2','6','4','5','9','7','8'},
            {'6','4','5','9','7','8','3','1','2'},
            {'9','7','8','3','1','2','6','4','5'}
    };
};

TEST_F(TestSolveSoduku, try_to_fill_last_number_found)
{
    vector<vector<char>> testBoard(board);
    testBoard[8][8] = '*';

    auto output = solution.backTrackSoduku(testBoard, 8, 7);
    EXPECT_EQ(output, true);
    EXPECT_THAT(testBoard, ::testing::Eq(board));
}
TEST_F(TestSolveSoduku, try_to_fill_multi_cells)
{
    vector<vector<char>> testBoard(board);
    testBoard[8][8] = '*';
    testBoard[2][5] = '*';
    testBoard[7][5] = '*';
    testBoard[5][3] = '*';


    auto output = solution.backTrackSoduku(testBoard, 0, 0);
    EXPECT_EQ(output, true);
    EXPECT_THAT(testBoard, ::testing::Eq(board));
}
TEST_F(TestSolveSoduku, try_to_fill_full_cells)
{
    vector<vector<char>> testBoard = vector<vector<char>> (9, vector<char>(9, '*'));


    auto output = solution.backTrackSoduku(testBoard, 0, 0);
    EXPECT_EQ(output, true);
    //EXPECT_THAT(testBoard, ::testing::Eq(board));
}

TEST_F(TestSolveSoduku, try_to_find_next_empty_number)
{
    board[8][8] = '*';
    int x = 8;
    int y = 1;
    auto output = solution.foundNextEmptyElement(board, x, y);
    EXPECT_EQ(output, true);
    EXPECT_EQ(x, 8);
    EXPECT_EQ(y, 8);
}
TEST_F(TestSolveSoduku, should_return_false_when_find_next_empty_element)
{
    board[6][8] = '*';
    int x = 8;
    int y = 1;
    auto output = solution.foundNextEmptyElement(board, x, y);
    EXPECT_EQ(output, false);
    EXPECT_EQ(x, 8);
    EXPECT_EQ(y, 1);
}

TEST_F(TestSolveSoduku, found_next_empty_element_in_next_line)
{
    board[6][4] = '*';
    int x = 5;
    int y = 7;
    auto output = solution.foundNextEmptyElement(board, x, y);
    EXPECT_EQ(output, true);
    EXPECT_EQ(x, 6);
    EXPECT_EQ(y, 4);
}

TEST_F(TestSolveSoduku, try_to_solve_a_board)
{
    vector<vector<char>> testBoard(board);
    testBoard[8][8] = '*';
    testBoard[2][5] = '*';
    testBoard[7][5] = '*';
    testBoard[5][3] = '*';


    solution.solveSudoku(testBoard);
    //EXPECT_EQ(output, true);
    EXPECT_THAT(testBoard, ::testing::Eq(board));
}