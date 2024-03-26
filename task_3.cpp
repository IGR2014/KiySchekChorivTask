#include <cstdint>
#include <iostream>


std::int64_t L[61], N, Schek, Choriv, Kyi, rem;

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
    std::cin >> N;
    std::int64_t i = 1L;
    // Замість рядка чисел Якобшталя використовується послідовність Ліхтенберга
    L[1] = 1L;
    L[2] = 2L;
    while (Schek + Choriv + Kyi + 3L * (L[i] + L[i - 1L]) < N) {
        Choriv += 2L * L[i - 1L] - L[i];
        Schek += 2L * L[i - 1L]  - L[i];
        Kyi += 2L * L[i - 1L] - L[i];
        ++i;
        L[i] = L[i - 1L] + 2L * L[i - 2L] + 1L;
    }
    rem = N - 1L - Schek - Choriv - Kyi;
    Score(Kyi, L[i - 1L]);
    Score(Choriv, L[i + 1L]);
    Score(Schek, L[i - 1L]);
    Score(Choriv, L[i]);
    Score(Kyi, L[i + 1L]);
    Score(Schek, L[i + 1L]);
    std::cout << "Schek\tChoriv\tKyi\n";
    std::cout << Schek << '\t' << Choriv << '\t' << Kyi;
}
