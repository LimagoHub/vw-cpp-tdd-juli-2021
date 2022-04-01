/// @file
/// @brief Declares the `example::container::VectorCreatorInterface` *Interface Class*.

#ifndef EXAMPLE_CONTAINER_VECTOR_CREATOR_INTERFACE_HPP_
#define EXAMPLE_CONTAINER_VECTOR_CREATOR_INTERFACE_HPP_

// Standard Library
#include <cstddef>
#include <cstdint>
#include <vector>

namespace example::container {

// Problematische Änderungen an Schnittstellen ("Signatur einer Klasse").
//
// 1. Namespace
// 2. Name der Klasse
// 3. Methoden Namen
// 4. Parameterlisten
// 5. Rückgabetypen
// 6. Verhalten im Fehlerfall (Error Code, Exceptions, ...)
// 7. Fachlichkeit

/// This *Interface Class* uses the *Strategy* behavioral design pattern.
// NOLINTNEXTLINE(cppcoreguidelines-special-member-functions)
class VectorCreatorInterface {
public:
    virtual ~VectorCreatorInterface() = default;

    // TODO(2022-02-23 ): Consider usage of strong type instead of `std::size_t` for `elementCount`.
    [[nodiscard]] virtual auto create(std::size_t elementCount) const -> std::vector<std::int32_t> = 0;
};

}

#endif // EXAMPLE_CONTAINER_VECTOR_CREATOR_INTERFACE_HPP_
