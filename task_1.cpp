#include <cstdint>
#include <iostream>


std::int64_t L[61], N = 10L, Schek, Kyi, rem;

void Score (std::int64_t &X, std::int64_t Y) {
    if (rem > Y) {
        X += Y;
        rem -= Y;
    } else {
        X += rem;
        rem = 0L;
    }
}

int main() {
    //std::cin >> N;
    std::int64_t i = 1L;
    // Замість рядка чисел Якобшталя використовується послідовність Ліхтенберга
    L[1] = 1L;
    L[2] = 2L;
    while (Schek + Kyi + 3L * (L[i] + L[i - 1L]) < N) {
        Schek += 2L * L[i - 1L] - L[i] - 3L;
        Kyi += 2L * L[i - 1L] - L[i] - 1L;
        ++i;
        L[i] = L[i - 1L] + 2L * L[i - 2L] + 1L;
    }
    rem = N - 1L - Schek - Kyi;
    Score(Kyi, L[i + 1L]);
    Score(Schek, L[i]);
    Score(Kyi, L[i]);
    Score(Schek, L[i]);
    Score(Kyi, L[i + 1L]);
    Score(Schek, L[i + 1L]);
    std::cout << "Schek\tKyi\n";
    std::cout << Schek << '\t' << Kyi;
}
