#define _USE_MATH_DEFINES
#include <cmath>
#include <iostream>
#include <iomanip>

int Lab1()
{
    setlocale(LC_ALL, "RUS");
    double R, S;
    std::cout << "Ââåäèòå ðàäèóñ\n";
    std::cin >> R;

    if (R > 0 and R < 100) {
        S = R * R * M_PI;
        std::cout << std::setprecision(9) << "Ïëîùàäü êðóãà ðàâíà: " << S;
    }
    else {
        std::cout << "Ðàäèóñ äîëæåí íàõîäèòüñÿ â äèàïîçîíå îò 1 äî 100!!! (0 < R < 100)";
        return 1;
    }

    return 0;

}