/// @file
/// @brief Declares the `example::math::ClosedInterval` concrete class.

#ifndef EXAMPLE_MATH_CLOSED_INTERVAL_HPP_
#define EXAMPLE_MATH_CLOSED_INTERVAL_HPP_

// Standard Library
#include <cstdint>

namespace example::math {

class ClosedInterval final {
public:
    explicit ClosedInterval(std::int32_t const lowerBound, std::int32_t const upperBound)
        : lowerBound_ { lowerBound }
        , upperBound_ { upperBound }
    {
        // NOOP
    }

    [[nodiscard]] auto lowerBound() const -> std::int32_t { return lowerBound_; }

    [[nodiscard]] auto upperBound() const -> std::int32_t { return upperBound_; }

private:
    std::int32_t lowerBound_;
    std::int32_t upperBound_;
};

}

#endif // EXAMPLE_MATH_CLOSED_INTERVAL_HPP_
