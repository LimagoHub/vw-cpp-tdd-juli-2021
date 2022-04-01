/// @file
/// @brief Declares the `example::time::StopWatch` concrete class.

#ifndef EXAMPLE_TIME_STOP_WATCH_HPP_
#define EXAMPLE_TIME_STOP_WATCH_HPP_

#include <example/time/stop_watch_interface.hpp>

namespace example::time {

class StopWatch final : public StopWatchInterface {
public:
    auto start() -> void override { startTime_ = std::chrono::high_resolution_clock::now(); }

    auto stop() -> void override { endTime_ = std::chrono::high_resolution_clock::now(); }

    [[nodiscard]] auto elapsedDuration() -> std::chrono::nanoseconds override { return endTime_ - startTime_; }

private:
    std::chrono::steady_clock::time_point startTime_;
    std::chrono::steady_clock::time_point endTime_;
};

}

#endif // EXAMPLE_TIME_STOP_WATCH_HPP_
