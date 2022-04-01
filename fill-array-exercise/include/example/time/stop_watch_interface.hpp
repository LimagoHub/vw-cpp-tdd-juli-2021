/// @file
/// @brief Declares the `example::time::StopWatchInterface` *Interface Class*.

#ifndef EXAMPLE_TIME_STOP_WATCH_INTERFACE_HPP_
#define EXAMPLE_TIME_STOP_WATCH_INTERFACE_HPP_

// Standard Library
#include <chrono>

namespace example::time {

// NOLINTNEXTLINE(cppcoreguidelines-special-member-functions)
class StopWatchInterface {
public:
    /// Finalizes an instance of the `StopWatchInterface` class.
    virtual ~StopWatchInterface() = default;

    /// Starts this stop watch.
    virtual auto start() -> void = 0;

    /// Stops this stop watch.
    virtual auto stop() -> void = 0;

    /// Returns the elapsed duration.
    ///
    /// @return the elapsed time duration between the last call to `start()` and `stop()`
    [[nodiscard]] virtual auto elapsedDuration() -> std::chrono::nanoseconds = 0;
};

}

#endif // EXAMPLE_TIME_STOP_WATCH_INTERFACE_HPP_
