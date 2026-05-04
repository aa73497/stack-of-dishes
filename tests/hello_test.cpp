#include <catch2/catch_test_macros.hpp>
#include <catch2/benchmark/catch_benchmark.hpp>
#include <catch2/benchmark/catch_constructor.hpp>
#include <catch2/generators/catch_generators_range.hpp>

#include "../src/hello.hpp"

TEST_CASE( "initial empty stack" ) {
    DishStack Stack;
    REQUIRE(Stack.size()==0);
}
TEST_CASE("Push adds to stack") {
    DishStack Stack;
    Dish dish("test");
    Stack.push(dish);
    REQUIRE(Stack.size()==1);
}
TEST_CASE("Peek checks top dish w/o removing") {
    DishStack Stack;
    Dish dish("test");
    Stack.push(dish);
    Dish dish2("test2");
    Stack.push(dish2);
    REQUIRE(Stack.size()==2);
    REQUIRE(Stack.peek().get_description()=="test2");
    REQUIRE(Stack.size()==2);
}
TEST_CASE("Push when full") {
    DishStack Stack;
    Dish dish1("test");
    Stack.push(dish1);
    Dish dish2("test");
    Stack.push(dish2);
    Dish dish3("test");
    Stack.push(dish3);
    Dish dish4("test");
    Stack.push(dish4);
    Dish dish5("test");
    Stack.push(dish5);
    Dish dish6("test");
    Stack.push(dish6);
    Dish dish7("test");
    Stack.push(dish7);
    Dish dish8("test");
    Stack.push(dish8);
    Dish dish9("test");
    Stack.push(dish9);
    Dish dish10("top");
Stack.push(dish10);
    Dish dish11("extra");
    REQUIRE(Stack.size()==10);
    Stack.push(dish11);
    REQUIRE(Stack.size()==10);
    REQUIRE(Stack.peek().get_description()=="top");
}
TEST_CASE("Pop removes top dish") {
    DishStack Stack;
    Dish dish("test");
    Stack.push(dish);
    Dish dish2("test2");
    Stack.push(dish2);
    Dish dish3("test3");
    Stack.push(dish3);
    REQUIRE(Stack.size()==3);
    REQUIRE(Stack.pop().get_description()=="test3");
    REQUIRE(Stack.size()==2);
}
