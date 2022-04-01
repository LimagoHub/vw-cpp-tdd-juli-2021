/// @file
/// @brief Declares the `example::random::MersenneTwisterNumberGeneratorFactory` concrete class.

#ifndef EXAMPLE_RANDOM_MERSENNE_TWISTER_NUMBER_GENERATOR_FACTORY_HPP_
#define EXAMPLE_RANDOM_MERSENNE_TWISTER_NUMBER_GENERATOR_FACTORY_HPP_

// Standard Library
#include <memory>

#include <example/math/closed_interval.hpp>
#include <example/math/number_generator_factory_interface.hpp>
#include <example/random/mersenne_twister_number_generator.hpp>

namespace example::random {

class MersenneTwisterNumberGeneratorFactory final : public math::NumberGeneratorFactoryInterface {
public:
    explicit MersenneTwisterNumberGeneratorFactory(math::ClosedInterval interval)
        : interval_ { interval }
    {
        // NOOP
    }

    [[nodiscard]] auto create() const -> std::unique_ptr<math::NumberGeneratorInterface> override
    {
        return std::make_unique<MersenneTwisterNumberGenerator>(interval_);
    }

private:
    math::ClosedInterval interval_;
};
}

#endif // EXAMPLE_RANDOM_MERSENNE_TWISTER_NUMBER_GENERATOR_FACTORY_HPP_
