#include <iostream>       
#include <functional>     
#include <thread>        
#include <future>       
#include <stdexcept>

bool Time_Out(std::chrono::steady_clock::time_point time_point,
                                                               uint seconds)
{
    if (std::chrono::steady_clock::now() <= time_point + std::chrono::seconds(seconds))
        return false;
    return true;
}


int main()
{

}