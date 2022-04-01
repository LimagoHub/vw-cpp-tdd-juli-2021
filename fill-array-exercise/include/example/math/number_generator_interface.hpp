/// @file
/// @brief Declares the `example::math::NumberGeneratorInterface` *Interface Class*.

#ifndef EXAMPLE_MATH_NUMBER_GENERATOR_INTERFACE_HPP_
#define EXAMPLE_MATH_NUMBER_GENERATOR_INTERFACE_HPP_

// Standard Library
#include <cstdint>

namespace example::math {

/// This *Interface Class* uses the *Strategy* behavioral design pattern.
// NOLINTNEXTLINE(cppcoreguidelines-special-member-functions)
class NumberGeneratorInterface {
public:
    /// Finalizes an instance of the `NumberGeneratorInterface` class.
    virtual ~NumberGeneratorInterface() = default;

    [[nodiscard]] virtual auto generate() const -> std::int32_t = 0;
};

}

#endif // EXAMPLE_MATH_NUMBER_GENERATOR_INTERFACE_HPP_
