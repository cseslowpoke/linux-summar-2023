#include <chrono>
#include <iostream>
#include <iomanip>

static inline uintptr_t align_up1(uintptr_t sz, size_t alignment)
{
    uintptr_t mask = alignment - 1;
    if ((alignment & mask) == 0) {  /* power of two? */
        return ((sz - 1) | mask) + 1;      
    }
    return (((sz + mask) / alignment) * alignment);
}

static inline uintptr_t align_up2(uintptr_t sz, size_t alignment)
{
    uintptr_t mask = alignment - 1;
    if ((alignment & mask) == 0) {  /* power of two? */
        return (sz + mask) & ~mask;      
    }
    return (((sz + mask) / alignment) * alignment);
}

int main() {
  /* degisn a timer to test the performance of align_up1 and align_up2
  */

  /* test align_up1 */
  long long times[7] = {1000, 10000, 100000, 1000000, 10000000, 100000000,
                         1000000000};
  for (int i = 0; i < 7; i++) {
    auto start = std::chrono::high_resolution_clock::now();
    for (int j = 0; j < times[i]; j++) {
      align_up1(100, 16);
    }
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> diff = end - start;
    std::cout << std::fixed << i << ' ' << diff.count() << " \n";
  }
  
std::cout << '\n';
    for (int i = 0; i < 7; i++) {
    auto start = std::chrono::high_resolution_clock::now();
    for (int j = 0; j < times[i]; j++) {
        align_up2(100, 16);
    }
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> diff = end - start;
    std::cout << std::fixed << i << ' ' << diff.count() << " \n";
    }
}