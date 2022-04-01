/// @file
/// @brief Declares the `example::random::MersenneTwisterNumberGenerator` concrete class.

#ifndef EXAMPLE_RANDOM_MERSENNE_TWISTER_NUMBER_GENERATOR_HPP_
#define EXAMPLE_RANDOM_MERSENNE_TWISTER_NUMBER_GENERATOR_HPP_

// Standard Library
#include <random>

#include <example/math/closed_interval.hpp>
#include <example/math/number_generator_interface.hpp>

namespace example::random {

class MersenneTwisterNumberGenerator final : public math::NumberGeneratorInterface {
public:
    explicit MersenneTwisterNumberGenerator(math::ClosedInterval const& interval)
        : device_ {}
        , rng_ { device_() }
        , distribution_(interval.lowerBound(), interval.upperBound())
    {
        // NOOP
    }

    [[nodiscard]] auto generate() const -> std::int32_t override { return distribution_(rng_); }

private:
    std::random_device device_;
    // TODO(2022-02-24 ): Add comment why `mutable` is required.
    mutable std::mt19937 rng_;
    std::uniform_int_distribution<std::int32_t> distribution_;
};

}

#endif // EXAMPLE_RANDOM_MERSENNE_TWISTER_NUMBER_GENERATOR_HPP_
