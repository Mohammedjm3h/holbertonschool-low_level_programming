# Green Efficiency Analysis

## Measurement Methodology

All measurements were taken on the same environment (GitHub Codespaces) and every program was compiled with the same flags: `gcc -Wall -Werror -Wextra -pedantic -std=gnu89 -Wno-long-long`. The provided source files were not modified, except for adding timing code to `instrumentation_lab.c`.

Time was measured inside the programs with `clock()` from `<time.h>`. Each measurement reads the clock before and after the code being measured, subtracts the two values, and divides the difference by `CLOCKS_PER_SEC` to get seconds. Every program was run three times in a row, and I computed the average of the three runs.

In `instrumentation_lab.c`, I used four `clock()` calls for three phases: one before `build_dataset()`, one between each pair of phases, and one after `reduce_checksum()`. Each boundary is shared by two phases, so no time is missed or counted twice, and `TOTAL` covers all three phases. The results are printed only after the last measurement, so printing is not included in the timings.

## Observed Performance Differences

**Baseline loop (100,000,000 iterations):** 0.106617 s, 0.104772 s and 0.133950 s, with an average of 0.115113 s. The work is identical in every run, yet the third run was about 28% slower than the second. This shows that timing varies even for a deterministic program.

**Algorithm comparison (50,000 elements):**

| Run | Naive | Single-pass |
|---|---|---|
| 1 | 1.384538 s | 0.000079 s |
| 2 | 1.461478 s | 0.000044 s |
| 3 | 1.395485 s | 0.000073 s |
| Average | 1.413834 s | 0.000065 s |

The naive implementation is about 21,600 times slower than the single-pass one. The naive version uses nested loops and re-checks the array from the start for every element. That is about 1.25 billion checks, so its growth is O(n²). The single-pass version checks each element once, which is 50,000 checks and O(n). The results also differ: the naive version returned 625025000 because it counts the same values many times, while the single-pass version returned 25000.

**Instrumentation lab (averages of 3 runs):** TOTAL 0.000519 s, BUILD_DATA 0.000249 s (about 48%), PROCESS 0.000191 s (about 37%) and REDUCE 0.000080 s (about 15%). Building the dataset was the most expensive phase in all three runs, and TOTAL was always greater than or equal to each phase.

## Relation Between Runtime and Energy Consumption

These experiments did not measure power in watts. Runtime is used as a proxy: while a program runs, the CPU stays active and consumes energy, so a longer runtime generally means more energy. In my measurements, the naive algorithm kept the CPU busy for about 1.41 seconds to complete a task that the single-pass algorithm completed in about 0.000065 seconds. If such code ran millions of times on servers, that difference would become a large amount of wasted electricity. The instrumentation results show where to act first: the build phase used almost half of the total time, so it is where an improvement would save the most.

## Limitations of the Experiment

- Energy was not measured directly; runtime is only an approximation of energy use.
- Only three runs were recorded per program, which is a small sample.
- Codespaces is a shared virtual machine, so other activity on the host can affect the timings. This may explain the 0.133950 s outlier in the baseline runs.
- The single-pass and instrumentation timings are in millionths of a second, close to the resolution of `clock()`. Small absolute changes therefore produce large relative changes (0.000044 s to 0.000079 s), so the ~21,600× ratio is approximate.
- `clock()` measures CPU time, not wall-clock time, so waiting time is not included.

## Practical Engineering Takeaway

The choice of algorithm matters far more than small details: replacing an O(n²) approach with an O(n) approach reduced runtime from about 1.4 seconds to a few hundred-thousandths of a second. Engineers should measure before optimizing, repeat measurements and use averages, keep the environment and compiler flags identical, and use instrumentation to find the most expensive phase. Efficient code is faster, cheaper to run, and uses less energy.
