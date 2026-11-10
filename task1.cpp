// ============================================================================
// Компільовано під: GCC 15.2 (флаг стандарту: -std=c++23)
// Програмний проєкт 5. Варіант 1. Величко Максим, К-24.
// Дослідження асинхронних обчислень та мінімізації потоків (<future>).
// ============================================================================

#include "task1.h"

using namespace std;

void slow(const string& name)
{
    this_thread::sleep_for(chrono::seconds(7));
    osyncstream(cout) << name << '\n';
}

void quick(const string& name)
{
    this_thread::sleep_for(chrono::seconds(1));
    osyncstream(cout) << name << '\n';
}

void work()
{
    const auto start_time = chrono::high_resolution_clock::now();

    try
    {
        auto future_bg = async(launch::async, []() {
            quick("A1");
            quick("C1");
            quick("C2");
            quick("D2");
        });

        slow("A2");

        slow("B");

        future_bg.get();

        quick("D1");
    }
    catch (const exception& e)
    {
        osyncstream(cerr) << format("[Помилка під час виконання work()]: {}\n", e.what());
        throw;
    }

    const auto end_time = chrono::high_resolution_clock::now();
    const auto duration = chrono::duration_cast<chrono::seconds>(end_time - start_time).count();

    osyncstream(cout) << format("Час виконання: {} секунд\n", duration);
    osyncstream(cout) << "Work is done!\n";
}

void run_task1()
{
    osyncstream(cout) << string(75, '=') << '\n';
    osyncstream(cout) << "  АСИНХРОННІ ОБЧИСЛЕННЯ ТА МІНІМІЗАЦІЯ ПОТОКІВ (<future>) — ВАРІАНТ 1\n";
    osyncstream(cout) << string(75, '=') << "\n\n";

    work();
}