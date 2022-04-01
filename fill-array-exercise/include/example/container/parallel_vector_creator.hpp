/// @file
/// @brief Declares the `example::container::ParallelVectorCreator` concrete class.

#ifndef EXAMPLE_CONTAINER_PARALLEL_VECTOR_CREATOR_HPP_
#define EXAMPLE_CONTAINER_PARALLEL_VECTOR_CREATOR_HPP_

// Standard Library
#include <cmath>
#include <thread>

#include <example/container/vector_creator_interface.hpp>
#include <example/math/number_generator_factory_interface.hpp>

namespace example::container {

class ParallelVectorCreator final : public VectorCreatorInterface {
public:
    // TODO(2022-02-23): Consider usage of strong type instead of `std::size_t` for `workerCount`.
    explicit ParallelVectorCreator(
        math::NumberGeneratorFactoryInterface const& numberGeneratorFactory, std::size_t const workerCount)
        : numberGeneratorFactory_ { numberGeneratorFactory }
        , workerCount_ { workerCount }
    {
        // NOOP
    }

    [[nodiscard]] auto create(std::size_t const elementCount) const -> std::vector<std::int32_t> override
    {
        auto result = std::vector<std::int32_t>(elementCount);
        auto const partitionSize = calculatePartitionSize(elementCount);

        auto threads = createThreadHolder();
        // TODO(2022-02-24): Extract threads to separate class.
        addWorkersToThreads(threads, result, partitionSize);
        joinThreads(threads);

        return result;
    }

private:
    [[nodiscard]] auto calculatePartitionSize(std::size_t const elementCount) const -> std::size_t
    {
        // TODO(2022-02-23): Use `narrow_cast` when available or implement it.
        // TODO(2022-02-23): This does not respect all container elements. Use module for the calculation of
        // the remaining element count and assign random numbers to these elements as well.
        return static_cast<std::size_t>(std::floor(elementCount / workerCount_));
    }

    [[nodiscard]] auto createThreadHolder() const -> std::vector<std::thread>
    {
        auto threads = std::vector<std::thread> {};
        threads.reserve(workerCount_);

        return threads;
    }

    // TODO: Needs refactoring!!!
    auto addWorkersToThreads(std::vector<std::thread>& threads, std::vector<std::int32_t>& result,
        std::size_t const partitionSize) const -> void
    {
        auto startIndex = std::size_t { 0 };
        auto endIndex = partitionSize;

        for (auto i = 0U; i < workerCount_; ++i) {
            threads.emplace_back(
                [this, &result](auto const startIndex, auto const endIndex) {
                    auto const numberGenerator = numberGeneratorFactory_.create();

                    for (auto i = startIndex; i < endIndex; ++i) {
                        result[i] = numberGenerator->generate();
                    }
                },
                startIndex, endIndex);
            startIndex += partitionSize;
            endIndex += partitionSize;
        }
    }

    static auto joinThreads(std::vector<std::thread>& threads) -> void
    {
        for (auto& thread : threads) {
            thread.join();
        }
    }

    math::NumberGeneratorFactoryInterface const& numberGeneratorFactory_;
    std::size_t workerCount_;
};

}

#endif // EXAMPLE_CONTAINER_PARALLEL_VECTOR_CREATOR_HPP_
