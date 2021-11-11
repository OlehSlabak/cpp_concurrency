#include <iostream>
#include <future>
#include <exception>
#include <stdexcept>

int test()
{
    std::promise<int> pr;
    auto fut = pr.get_future();

    {
      //  auto fut2 = pr.get_future();
        std::promise<int> pr2(std::move(pr));
    }   // Error: "broken promise"

    return fut.get();
}

int main()
{
    try
    {
        return test();
    }
    catch (std::future_error const & e)
    {
        std::cout << "Future error: " << e.what() << " / " << e.code() << std::endl;
    }
    catch (std::exception const & e)
    {
        std::cout << "Standard exception: " << e.what() << std::endl;
    }
    catch (...)
    {
        std::cout << "Unknown exception." << std::endl;
    }
}



