/**
 * @file ChronoBenchmark.hpp
 * @brief simple benchmark class utilizing RAII
 * @version 1.0
 * @date 2022-02-11
 */

#ifndef ChronoBenchmark_HPP
#define ChronoBenchmark_HPP

#include <chrono>
#include <iostream>

class Timer
{
    public:
        Timer()
        {
            timerStartPoint = std::chrono::high_resolution_clock::now();
        }
        ~Timer()
        {
            Stop();
        }

    // RAII technique
    void Stop()
    {
        auto timerEndPoint = std::chrono::high_resolution_clock::now();

        auto startMuS = std::chrono::time_point_cast<std::chrono::microseconds>(timerStartPoint).time_since_epoch().count();
        auto endMuS = std::chrono::time_point_cast<std::chrono::microseconds>(timerEndPoint).time_since_epoch().count();

        auto totalDurationMuS = endMuS - startMuS;

        // convert micro to milli
        double totalDurationMilli = totalDurationMuS * 0.001;

        std::cout << totalDurationMilli << "milli\n";
    }

    private:
        std::chrono::time_point<std::chrono::high_resolution_clock> timerStartPoint;
};

#endif // !ChronoBenchmark_HPP