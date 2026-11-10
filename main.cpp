// ============================================================================
// Компільовано під: GCC 15.2 (флаг стандарту: -std=c++23)
// Програмний проєкт 5. Варіант 1. Величко Максим, К-24.
// Дослідження асинхронних обчислень та мінімізації потоків (<future>).
// ============================================================================

#include "task1.h"

#include <iostream>
#include <format>
#include <exception>
#include <cstdlib>

int main()
{
    try
    {
        run_task1();
        return EXIT_SUCCESS;
    }
    catch (const std::exception &e)
    {
        std::cerr << std::format("Критична помилка: {}\n", e.what());
        return EXIT_FAILURE;
    }
    catch (...)
    {
        std::cerr << "Невідома фатальна помилка\n";
        return EXIT_FAILURE;
    }
}