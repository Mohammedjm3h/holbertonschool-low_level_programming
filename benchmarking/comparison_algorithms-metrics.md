# Algorithmic Efficiency Comparison

Program: `comparison_algorithms.c` (unmodified)
Compiled with: `gcc -Wall -Werror -Wextra -pedantic -std=gnu89 -Wno-long-long comparison_algorithms.c -o comparison_algorithms`
Environment: same machine (GitHub Codespaces) for all runs.

## Raw output

### Run 1
```
Naive algorithm result: 625025000
Naive algorithm time: 1.384538 seconds
Single-pass algorithm result: 25000
Single-pass algorithm time: 0.000079 seconds
```

### Run 2
```
Naive algorithm result: 625025000
Naive algorithm time: 1.461478 seconds
Single-pass algorithm result: 25000
Single-pass algorithm time: 0.000044 seconds
```

### Run 3
```
Naive algorithm result: 625025000
Naive algorithm time: 1.395485 seconds
Single-pass algorithm result: 25000
Single-pass algorithm time: 0.000073 seconds
```

## Execution times

| Run | Naive (A) | Single-pass (B) |
|---|---|---|
| 1 | 1.384538 s | 0.000079 s |
| 2 | 1.461478 s | 0.000044 s |
| 3 | 1.395485 s | 0.000073 s |
| **Average** | **1.413834 s** | **0.000065 s** |

- Average A = (1.384538 + 1.461478 + 1.395485) / 3 = 4.241501 / 3 = 1.413834 s
- Average B = (0.000079 + 0.000044 + 0.000073) / 3 = 0.000196 / 3 = 0.000065 s

## Relative difference

1.413834 / 0.0000653 ≈ 21,640

**Implementation A (naive) is ~21,600 times slower than implementation B (single-pass).**

## Observations

- The naive algorithm uses two nested loops: for each `i`, it re-checks every element from `0` to `i`. That is about 50,000 × 50,000 / 2 ≈ 1.25 billion checks, so its complexity is O(n²).
- The single-pass algorithm checks each element exactly once: 50,000 checks, so its complexity is O(n).
- The two results are different (625025000 vs 25000). The naive version counts the same even numbers many times, so it does a lot of extra work and does not even return the real number of even values. The single-pass result (25000) is the correct count.
- Times were close but not identical between runs (timing variability). The naive time varied between 1.38 s and 1.46 s.
- The single-pass time is extremely small (millionths of a second), so it is close to the resolution of `clock()` and its relative variation is large (0.000044 s to 0.000079 s). The ratio of ~21,600 is therefore approximate; the important point is the difference in the amount of work.
- A longer runtime means the CPU stays active longer, which generally means more energy use. Choosing the O(n) algorithm instead of the O(n²) one is a simple way to write more energy-efficient code.
