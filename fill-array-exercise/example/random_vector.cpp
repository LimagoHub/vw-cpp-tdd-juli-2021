/// @file
/// @example random_vector.cpp

// Standard Library
#include <exception>
#include <iostream>
#include <thread>

#include <example/container/parallel_vector_creator.hpp>
#include <example/math/closed_interval.hpp>
#include <example/random/mersenne_twister_number_generator.hpp>
#include <example/random/mersenne_twister_number_generator_factory.hpp>
#include <example/time/stop_watch.hpp>

namespace example::app {

class Settings final {
public:
    explicit Settings(
        math::ClosedInterval numberInterval, std::size_t const elementCount, std::size_t const maxWorkerCount)
        : numberInterval_ { numberInterval }
        , elementCount_ { elementCount }
        , maxWorkerCount_ { maxWorkerCount }
    {
    }

    [[nodiscard]] auto numberInterval() const -> math::ClosedInterval const& { return numberInterval_; }

    [[nodiscard]] auto elementCount() const -> std::size_t { return elementCount_; }

    [[nodiscard]] auto maxWorkerCount() const -> std::size_t { return maxWorkerCount_; }

private:
    math::ClosedInterval numberInterval_;
    std::size_t elementCount_;
    std::size_t maxWorkerCount_;
};

class Client final {
public:
    explicit Client(Settings settings, math::NumberGeneratorFactoryInterface const& numberGenerator,
        time::StopWatchInterface& stopWatch)
        : settings_ { settings }
        , numberGeneratorFactory_ { numberGenerator }
        , stopWatch_ { stopWatch }

    {
        // NOOP
    }

    auto run() const -> void
    {
        // TODO(2022-02-24 ): Remove hard dependency.
        std::cout << "Maximum Worker Count: " << settings_.maxWorkerCount() << '\n';

        for (auto currentWorker = 1U; currentWorker <= settings_.maxWorkerCount(); ++currentWorker) {
            createVectorAndTimeMeasureAndDebugPrint(currentWorker);
        }
    }

private:
    // TODO(2022-02-24 ): Find better name.
    auto createVectorAndTimeMeasureAndDebugPrint(std::size_t const currentWorker) const -> void
    {
        // TODO(2022-02-24 ): Adding a factory would allow to inject this too.
        auto const creator = container::ParallelVectorCreator { numberGeneratorFactory_, currentWorker };

        stopWatch_.start();
        auto const container = creator.create(settings_.elementCount());
        stopWatch_.stop();

        debugPrintTimeMeasure(currentWorker);
        debugPrint(container);
    }

    auto debugPrintTimeMeasure(std::size_t const currentWorker) const -> void
    {
        // TODO(2022-02-24 ): Remove hard dependency.
        std::cout << "Duration for creation of vector with " << settings_.elementCount() << " elements with "
                  << currentWorker << " workers: " << stopWatch_.elapsedDuration().count() << " ns\n\n";
    }

    static auto debugPrint(std::vector<std::int32_t> const& container) -> void
    {
        // TODO(2022-02-24 ): Remove hard dependency
        for (auto const& element : container) {
            std::cout << element << ',';
        }

        std::cout << "\n\n\n";
    }

    Settings settings_;
    math::NumberGeneratorFactoryInterface const& numberGeneratorFactory_;
    time::StopWatchInterface& stopWatch_;
};

}

// Bootstrap
// TODO: Refactor to class `Application`.
auto run() -> int
{
    auto const resultNumberInterval = example::math::ClosedInterval { 1, 1000 };
    auto constexpr resultElementCount = 100U;
    auto const maxWorkerCount = std::thread::hardware_concurrency() + 1;
    auto const settings = example::app::Settings { resultNumberInterval, resultElementCount, maxWorkerCount };

    auto const numberGeneratorFactory = example::random::MersenneTwisterNumberGeneratorFactory { resultNumberInterval };
    // TODO(2022-02-23 ): Consider usage of a function decorator.
    // https://gist.github.com/lizhongz/21e77864aa9d5f66e842
    auto stopWatch = example::time::StopWatch {};

    // TODO: Add `ClientBuilder`.
    example::app::Client { settings, numberGeneratorFactory, stopWatch }.run();

    return EXIT_SUCCESS;
}

auto main() -> int
{
    try {
        return run();
    } catch (std::exception const& ex) {
        std::cerr << "Exception: " << ex.what() << '\n';
    } catch (...) {
        std::cerr << "Unexpected Exception\n";
    }
}
