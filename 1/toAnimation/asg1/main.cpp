/*************************************************************************
	> File Name: game.cpp
	> Author: Maoting Ren
	> Mail: mren@g.clemson.edu
	> Created Time: Sun 07 Feb 2016 04:54:25 AM EST
 ************************************************************************/

#include <iostream>
#include "manager.h"

using namespace std;

int main()
{
    try
    {
        Manager game;
        game.play(); 
    }
    catch(const std::string& msg) { std::cout << msg << std::endl;  } 
    catch(...) { std::cout << "oops" << std::endl;  }
}
