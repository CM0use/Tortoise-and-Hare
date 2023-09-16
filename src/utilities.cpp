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

# include "../header/utilities.h"

void race(const std::array<std::array<std::uint8_t, MAX>, 2> &animals)
{
    for (const auto &animal: animals) {
        for(const auto &pos: animal)
            std::putchar(pos);
        std::putchar('\n');
    }
}

std::uint8_t currentPos(const std::array<std::uint8_t, MAX> &animal,
                        const char &ICON_ANIMAL)
{
    return std::distance(animal.begin(),
                         std::find(animal.begin(), animal.end(), ICON_ANIMAL));
}

std::int8_t luckyT(const std::uint8_t &random)
{
    return (random >= 1 && random <= 5)? 3:
           (random >= 6 && random <= 8)? 1: -6;
}
std::int8_t luckyH(const std::uint8_t &random)
{
    return (random >= 1 && random <= 3)? 1:
           (random >= 4 && random <= 5)? 0:
           (random >= 6 && random <= 7)? 9:
           (random >= 8 && random <= 9)? -2: -12;
}

void movement(std::array<std::uint8_t, MAX> &animal,
              const std::uint8_t &pos, const std::int8_t &steps,
              const char &ICON_ANIMAL)
{
    if ((pos+steps <= MIN) xor (pos+steps >= MAX-1)) {
        animal[pos] = ICON_FLOOR;
        animal[ (pos+steps >= MAX-1)? MAX-1: MIN ] = ICON_ANIMAL;
    } else {
        animal[pos] = ICON_FLOOR;
        animal[pos+steps] = ICON_ANIMAL;
    }
}
