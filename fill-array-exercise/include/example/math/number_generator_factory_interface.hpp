/// @file
/// @brief Declares the `example::math::NumberGeneratorFactoryInterface` *Interface Class*.

#ifndef EXAMPLE_MATH_NUMBER_GENERATOR_FACTORY_INTERFACE_HPP_
#define EXAMPLE_MATH_NUMBER_GENERATOR_FACTORY_INTERFACE_HPP_

// Standard Library
#include <memory>

#include <example/math/number_generator_interface.hpp>

namespace example::math {

/// This *Interface Class* uses the *Factory Method* creation design pattern.
// NOLINTNEXTLINE(cppcoreguidelines-special-member-functions)
class NumberGeneratorFactoryInterface {
public:
    /// Finalizes an instance of the `NumberGeneratorFactoryInterface` class.
    virtual ~NumberGeneratorFactoryInterface() = default;

    [[nodiscard]] virtual auto create() const -> std::unique_ptr<NumberGeneratorInterface> = 0;
};

}

#endif // EXAMPLE_MATH_NUMBER_GENERATOR_FACTORY_INTERFACE_HPP_
