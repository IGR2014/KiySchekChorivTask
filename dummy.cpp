#include <algorithm>
#include <cmath>
#include <cstdint>
#include <iostream>

// Розрахунок балів
void calculateScore(std::int64_t N, std::int64_t &Schek, std::int64_t &Choriv, std::int64_t &Kyi) {
    // Розрахунок балів в заледності від поточного N для Щека
    // Формула T(N) = (N - 2^log2(N)) * 2 + 1;
    // Числовий ряд: https://oeis.org/A006257
    Schek = (N - std::pow(2L, static_cast<std::int64_t>(std::log2(N)))) * 2L + 1L;
    // Розрахунок балів в заледності від поточного N для Хорива
    // Формула T(N) = (4^n + 2) / 3;
    // Числовий ряд: https://oeis.org/A047849
    for (std::int64_t j = 0; j < 64; j++) {
        std::int64_t choriv_n = (std::pow(4L, j) + 2L) / 3L;
        if (N == choriv_n) {
            Choriv = choriv_n;
            break;
        }
    }
    // Розрахунок балів в заледності від поточного N для Кия
    // Формула T(N) = (2^(2 * j + 1) + 1) / 3;
    // Числовий ряд: https://oeis.org/A007583
    for (std::int64_t j = 0; j < 64; j++) {
        std::int64_t kyi_n = (std::pow(2L, (2L * j + 1L)) + 1L) / 3L;
        if (N == kyi_n) {
            Kyi = kyi_n;
            break;
        }
    }
}

int main() {

    std::int64_t N = 100L;

    std::cin >> N;

    std::int64_t Schek = 0L;
    std::int64_t Choriv = 0L;
    std::int64_t Kyi = 0L;

    std::cout << "N\tSchek\tChoriv\tKyi\tTask#1\tTask#2\tTask#3\n";
    for (std::int64_t i = 1L; i <= N; i++) {
        // Розрахунок рахунку князів в залежності від N
        calculateScore(i, Schek, Choriv, Kyi);
        // Вивід рахуків
        std::cout << i << '\t' << Schek << '\t' << Choriv << '\t' << Kyi;
        // Вивід переможців у парі Щек - Кий
        if (Schek == Kyi) {
            std::cout << "\t-";
        } else if (Schek == std::max(Schek, Kyi)) {
            std::cout << "\tS";
        } else if (Kyi == std::max(Schek, Kyi)) {
            std::cout << "\tK";
        }
        // Вивід переможців у парі Хорив - Кий
        if (Choriv == Kyi) {
            std::cout << "\t-";
        } else if (Choriv == std::max(Choriv, Kyi)) {
            std::cout << "\tC";
        } else if (Kyi == std::max(Choriv, Kyi)) {
            std::cout << "\tK";
        }
        // Вивід переможців у тріплеті Щек - Хорив - Кий
        if (Schek == Choriv || Choriv == Kyi || Schek == Kyi) {
            std::cout << "\t-";
        } else if (Schek == std::max({Schek, Choriv, Kyi})) {
            std::cout << "\tS";
        } else if (Choriv == std::max({Schek, Choriv, Kyi})) {
            std::cout << "\tC";
        } else if (Kyi == std::max({Schek, Choriv, Kyi})) {
            std::cout << "\tK";
        }
        // Кінець строки
        std::cout << '\n';
    }
    std::cout << std::endl;

}
