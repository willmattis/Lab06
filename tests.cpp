#include "Tree.h"
#include "Node.h"
#include <vector>
#include <memory>
#include <gtest/gtest.h>

using namespace std;

TEST(Tree, Insert1)
{
    Tree<int>tree3;

    std::shared_ptr<Node<int>> n2 = std::make_shared<Node<int>>(1);

    //tree3.Insert(n2,1);
    //tree3.Insert(n2,7);
    //tree3.Insert(n2,2);
    tree3.Insert(1);
    tree3.Insert(2);
    tree3.Insert(5);

    int size = tree3.Size();

    ASSERT_EQ(size, 3);
}

TEST(Tree, Insert2){
    Tree<int>tree3;
    tree3.Insert(1);
    tree3.Insert(2);
    tree3.Insert(-1);
    tree3.Insert(5);

    int size = tree3.Size();

    ASSERT_EQ(size, 4);
}

TEST(Tree, Find1){
    Tree<int>tree3;
    tree3.Insert(1);
    tree3.Insert(2);
    tree3.Insert(3);

    ASSERT_NE(tree3.Find(1), nullptr);
}
TEST(Tree, Find2){
    Tree<int>tree3;
    tree3.Insert(1);
    tree3.Insert(7);
    tree3.Insert(3);
    tree3.Insert(-16);

    ASSERT_EQ(tree3.Find(69), nullptr);
}

TEST(Tree, Size1){
    Tree<int>tree3;

    tree3.Insert(1);
    tree3.Insert(2);

    ASSERT_EQ(tree3.Size(), 2);
}
TEST(Tree, Size2){
    Tree<int>tree3;

    tree3.Insert(69);
    tree3.Insert(-420);
    tree3.Insert(69420);

    ASSERT_EQ(tree3.Size(), 3);
}

TEST(Tree, Clear1){

    Tree<int>tree3;
    tree3.Insert(5);
    tree3.Insert(4);
    tree3.Insert(0);

    tree3.Clear();

    ASSERT_EQ(tree3.Size(), 0);

}
TEST(Tree, Clear2){

    Tree<int>tree3;
    tree3.Insert(9);
    tree3.Insert(4);
    tree3.Clear();
    tree3.Insert(0);

    ASSERT_EQ(tree3.Size(), 1);

}

TEST(Tree, GetAllAscending1){
    Tree<int>tree3;
    tree3.Insert(5);
    tree3.Insert(6);
    tree3.Insert(3);

    vector<int> values = {3, 5, 6};

    ASSERT_EQ(tree3.GetAllAsc(), values);
}
TEST(Tree, GetAllAscending2){
    Tree<int>tree3;
    tree3.Insert(9);
    tree3.Insert(12);
    tree3.Insert(6969);
    tree3.Clear();
    tree3.Insert(5);
    tree3.Insert(3000);
    tree3.Insert(-1);
    tree3.Insert(2);

    vector<int> values = {-1, 2, 5, 3000};

    ASSERT_EQ(tree3.GetAllAsc(), values);
}









int main(int argc, char **argv) 
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
