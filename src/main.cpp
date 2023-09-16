/**
 ** This file is part of Tortoise-and-Hare project.
 ** Copyright 2023 CM0use dilanuzcs@gmail.com
 ** URL: https://github.com/CM0use/Tortoise-and-Hare
 **
 ** This program is free software: you can redistribute it and/or modify
 ** it under the terms of the GNU General Public License as published by
 ** the Free Software Foundation, either version 3 of the License, or
 ** (at your option) any later version.
 **
 ** This program is distributed in the hope that it will be useful,
 ** but WITHOUT ANY WARRANTY; without even the implied warranty of
 ** MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 ** GNU General Public License for more details.
 **
 ** You should have received a copy of the GNU General Public License
 ** along with this program.  If not, see <http://www.gnu.org/licenses/>.
 **/

# include <iostream>
# include <random>

# include "../header/utilities.h"

int main()
{
    using namespace std::chrono_literals;
    std::string repeat;
    do {
        std::array<std::array<std::uint8_t, MAX>, 2> animals;
        std::uint8_t posT{MIN}, posH{MIN};
        std::int8_t stepT{0}, stepH;
        std::random_device rd{};
        std::mt19937 engine{rd()};
        std::uniform_int_distribution<std::uint8_t> dist{1, 10};

        animals[TURTLE].fill(ICON_FLOOR);
        animals[TURTLE][MIN] = ICON_TURTLE;

        animals[HARE].fill(ICON_FLOOR);
        animals[HARE][MIN] = ICON_HARE;

        std::puts("\nPRESS ENTER TO START THE RACE");
        race(animals);
        std::getchar();

        CLEAN_SCREEN;
        std::puts("BANG !!!!!\nAND THE'RE OF !!!!!");
        race(animals);
        std::this_thread::sleep_for(TIME+0.5s);

        while ((posT != MAX-1) && (posH != MAX-1)) {
            CLEAN_SCREEN;
            std::puts("\n");
            race(animals);
            std::this_thread::sleep_for(TIME);

            posT = { currentPos(animals[TURTLE], ICON_TURTLE) };
            posH = { currentPos(animals[HARE], ICON_HARE) };
            if (stepT && (posT == posH)) {
                std::puts("Hare: OUCH!!!");
                std::this_thread::sleep_for(TIME+0.5s);
            }
            stepT = { luckyT(dist(engine)) };
            stepH = { luckyH(dist(engine)) };
            movement(animals[TURTLE], posT, stepT, ICON_TURTLE);
            movement(animals[HARE], posH, stepH, ICON_HARE);
        }
        if (posT > posH) std::puts("TURTLE WINS!!! YAY!!!");
        else if (posT < posH) std::puts("Hare wins. That's too bad.");
        else std::puts("It's a tie.");

        std::puts("Do you want to play again? [Y/y/S/s/n/N]");
        std::getline(std::cin, repeat);
        CLEAN_SCREEN;
    } while (std::tolower(repeat[0]) == 'y' || std::tolower(repeat[0]) == 's');

    return EXIT_SUCCESS;
}
