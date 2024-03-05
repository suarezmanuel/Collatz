#include <iostream>
#include <benchmark/benchmark.h>


static void custom_args (benchmark::internal::Benchmark* b) {
    b = b->Arg(8);
}

static void calc_iterative (benchmark::State &s) {
    int num = 1;
    // int out = 0;

    while (s.KeepRunning()) {
        while (num != 1) {
            num = (num % 2 == 0) ? num/2 : 3*num + 1;
            // out ++;
        }
    }
}
BENCHMARK(calc_iterative)->Apply(custom_args)->Unit(benchmark::kMillisecond);


BENCHMARK_MAIN();

