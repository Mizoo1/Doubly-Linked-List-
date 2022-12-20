/**
 * @file main.cpp
 * @author Muaaz Bdear
 * Matrikel-Nr.: 5194038
 * Assignment 2
 * @brief
 * @version 0.1
 * @date 2022-12-20
 * @copyright Copyright (c) 2022
 */
#include <iostream>
#include "list.h"


int main()
{
    util::list<int> my_int_list;

    std::cout << "\ntesting exception handling for all cases.... \n";
    try { my_int_list.pop_back(); } catch (util::ListError &e)
    {
        std::cout << e.getMsg() << std::endl;
    }
    try { my_int_list.pop_front(); } catch (util::ListError &e)
    {
        std::cout << e.getMsg() << std::endl;
    }
    try { my_int_list.front(); } catch (util::ListError &e)
    {
        std::cout << e.getMsg() << std::endl;
    }
    try { my_int_list.back(); } catch (util::ListError &e)
    {
        std::cout << e.getMsg() << std::endl;
    }

    std::cout << "\ntesting size(), push_front(), pop_front(), front() and back().... \n";
    std::cout << my_int_list.size() << my_int_list << std::endl;
    my_int_list.push_front(1);
    std::cout << my_int_list.size() << my_int_list << " front: " << my_int_list.front() << " ,back: "
              << my_int_list.back() << std::endl;
    my_int_list.push_front(2);
    std::cout << my_int_list.size() << my_int_list << " front: " << my_int_list.front() << " ,back: "
              << my_int_list.back() << std::endl;
    my_int_list.push_front(3);
    std::cout << my_int_list.size() << my_int_list << " front: " << my_int_list.front() << " ,back: "
              << my_int_list.back() << std::endl;
    my_int_list.push_front(4);
    std::cout << my_int_list.size() << my_int_list << " front: " << my_int_list.front() << " ,back: "
              << my_int_list.back() << std::endl;
    my_int_list.pop_front();
    std::cout << my_int_list.size() << my_int_list << " front: " << my_int_list.front() << " ,back: "
              << my_int_list.back() << std::endl;
    my_int_list.pop_front();
    std::cout << my_int_list.size() << my_int_list << " front: " << my_int_list.front() << " ,back: "
              << my_int_list.back() << std::endl;
    my_int_list.pop_front();
    std::cout << my_int_list.size() << my_int_list << " front: " << my_int_list.front() << " ,back: "
              << my_int_list.back() << std::endl;
    my_int_list.pop_front();
    std::cout << my_int_list.size() << my_int_list << std::endl;

    std::cout << "\ntesting size(), push_back(), pop_back(), front() and back().... \n";
    std::cout << my_int_list.size() << my_int_list << std::endl;
    my_int_list.push_back(1);
    std::cout << my_int_list.size() << my_int_list << " front: " << my_int_list.front() << " ,back: "
              << my_int_list.back() << std::endl;
    my_int_list.push_back(2);
    std::cout << my_int_list.size() << my_int_list << " front: " << my_int_list.front() << " ,back: "
              << my_int_list.back() << std::endl;
    my_int_list.push_back(3);
    std::cout << my_int_list.size() << my_int_list << " front: " << my_int_list.front() << " ,back: "
              << my_int_list.back() << std::endl;
    my_int_list.push_back(4);
    std::cout << my_int_list.size() << my_int_list << " front: " << my_int_list.front() << " ,back: "
              << my_int_list.back() << std::endl;
    my_int_list.pop_back();
    std::cout << my_int_list.size() << my_int_list << " front: " << my_int_list.front() << " ,back: "
              << my_int_list.back() << std::endl;
    my_int_list.pop_back();
    std::cout << my_int_list.size() << my_int_list << " front: " << my_int_list.front() << " ,back: "
              << my_int_list.back() << std::endl;
    my_int_list.pop_back();
    std::cout << my_int_list.size() << my_int_list << " front: " << my_int_list.front() << " ,back: "
              << my_int_list.back() << std::endl;
    my_int_list.pop_back();
    std::cout << my_int_list.size() << my_int_list << std::endl;


    //iterator...
    std::cout << "\ntesting iterator task.... \n";
    class car {
        const char *color;
        int hp;
    public:
        car(const char *color, int hp) : color(color), hp(hp) {}

        const char *getColor() const
        {
            return color;
        }

        int getHp() const
        {
            return hp;
        }
    };
    util::list<car> my_cars_list;
    my_cars_list.push_back(car("yellow", 690));
    my_cars_list.push_back(car("black", 500));
    my_cars_list.push_back(car("brown", 370));
    my_cars_list.push_back(car("blue", 470));

    util::list<car>::iterator itB = my_cars_list.begin();
    util::list<car>::iterator itE = my_cars_list.end();
    while (itB != itE) {
        std::cout << "\t" << (*itB).getColor() << "\t" << itB->getHp() << std::endl;
        ++itB;
    }

    std::cout << "\ntesting insert method.... \n";

    my_cars_list.insert(my_cars_list.begin(), car("navy blue", 650));
    my_cars_list.insert(my_cars_list.begin(), car("cyan", 650));

    my_cars_list.insert(my_cars_list.end(), car("red", 690));
    my_cars_list.insert(my_cars_list.end(), car("purple", 620));


    itB = my_cars_list.begin();
    while (itB != itE)
    {
        std::cout << "\t" << (*itB).getColor() << "\t" << itB->getHp() << std::endl;
        ++itB;
    }

    std::cout << "\ntesting erase method.... \n";

    try
    {
        my_cars_list.erase(my_cars_list.end());
    }
    catch (util::ListError &e)
    {
        std::cout << e.getMsg() << std::endl;
    }

    my_cars_list.erase(my_cars_list.begin());
    itB = my_cars_list.begin();
    while (itB != itE) {
        std::cout << "\t" << (*itB).getColor() << "\t" << itB->getHp() << std::endl;
        ++itB;
    }
    std::cout << "\ntesting erase method on an empty list.... \n";

    try
    {
        (new util::list<car>)->erase(my_cars_list.begin());
    }
    catch (util::ListError &e)
    {
        std::cout << e.getMsg() << std::endl;
    }
    return 0;
}
