#include <iostream>
#include <cstdint>

std::int64_t J[61], N, Kyi, Choriv, rem;

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
    J[1] = 1L; J[2] = 1L;
    while (Kyi + Choriv + 3L * (J[i] + J[i + 1]) < N) {
        Choriv += 2L * J[i] + J[i + 1L];
        Kyi += J[i] + 2L * J[i + 1L];
        i += 2L;
        J[i] = J[i - 1L] + 2L * J[i - 2L];
        J[i + 1L] = J[i] + 2L * J[i - 1L];
    }
    rem = N - 1L - Choriv - Kyi;
    // Код майже такий самий як у прикладі, але оця послідовність інша.
    // Прохід разбитий на блоки по 6 елементів (у текстовці завдання).
    // У прикладі шістки були з повторюванням елементів ряду Якобшталя:
    // [3, 5, 3, 3, 5, 5] та [11, 21, 11, 11, 21, 21].
    // В задачі з Києм та Хоривом ж шістки послідовні:
    // [3, 5, 11, 21, 43, 86]
    // Саме тому тут індекс "i" просто інкрементується
    Score(Kyi, J[i]);
    Score(Choriv, J[i + 1L]);
    Score(Kyi, J[i + 1L]);
    Score(Choriv, J[i + 1L]);
    Score(Kyi, J[i + 1L]);
    Score(Choriv, J[i + 1L]);
    std::cout << "Kyi\tChoriv\n";
    std::cout << Kyi << '\t' << Choriv;
}
