#include <iostream>

#include "../include/Constants.h"
#include "../include/KeyPad.h"

KeyPad::KeyPad(bool isNumericPad) {
    if(isNumericPad) {
        pad = Constants::NUMERIC_PAD;
        currentPosition = Constants::NUMERIC_PAD_START_POSITION;
    } else {
        pad = Constants::DIRECTIONAL_PAD;
        currentPosition = Constants::DIRECTIONAL_PAD_START_POSITION;
    }
    safePadCoords();
}

KeyPad::~KeyPad() {}

void KeyPad::safePadCoords() {
    for(size_t i = 0; i < pad.size(); i++) {
        for(size_t j = 0; j < pad[i].size(); j++) {
            if(pad[i][j] != '_') {
                padCoords[pad[i][j]] = intPair({i,j});
            }
        }
    }
}

std::string KeyPad::moveTo(char button) {
    if(padCoords.find(button) == padCoords.end()) {
        return "";
    }

    const intPair buttonCoords = padCoords[button];
    std::string instructions;

    if(pad.size() > 2) {    // Directional
        if(currentPosition.first == pad.size() - 1) {
            vertical(buttonCoords, instructions);
            horizontal(buttonCoords, instructions);
        } else {
            horizontal(buttonCoords, instructions);
            vertical(buttonCoords, instructions);
        }
    } else {                // Numeric
        if(currentPosition.second == 0) {
            horizontal(buttonCoords, instructions);
            vertical(buttonCoords, instructions);
        } else {
            vertical(buttonCoords, instructions);
            horizontal(buttonCoords, instructions);
        }
    }

    instructions += 'A';
    return instructions;
}

void KeyPad::vertical(intPair buttonCoords, std::string& instructions) {
    while (currentPosition.first != buttonCoords.first) {
        Direction direction = (currentPosition.first < buttonCoords.first) ? DOWN : UP;
        if (canMove(direction)) {
            currentPosition = moveCoords(currentPosition, direction);
            instructions += (direction == DOWN) ? 'v' : '^';
        } else {
            break;
        }
    }
}

void KeyPad::horizontal(intPair buttonCoords, std::string& instructions) {
    while (currentPosition.second != buttonCoords.second) {
        Direction direction = (currentPosition.second < buttonCoords.second) ? RIGHT : LEFT;
        if (canMove(direction)) {
            currentPosition = moveCoords(currentPosition, direction);
            instructions += (direction == RIGHT) ? '>' : '<';
        } else {
            break;
        }
    }
}

intPair KeyPad::moveCoords(intPair coords, Direction d) {
    switch (d) {
        case UP: return intPair(coords.first - 1, coords.second);
        case RIGHT: return intPair(coords.first, coords.second + 1);
        case DOWN: return intPair(coords.first + 1, coords.second);
        case LEFT: return intPair(coords.first, coords.second - 1);
    }
    return coords;
}

bool KeyPad::canMove(Direction dir) {
    intPair nextCoords = moveCoords(currentPosition, dir);
    return !outOfPad(nextCoords);
}

bool KeyPad::outOfPad(intPair pos) {
    return (pos.first < 0 || pos.first >= static_cast<int>(pad.size()) || 
            pos.second < 0 || pos.second >= static_cast<int>(pad[0].size()) ||
            pad[pos.first][pos.second] == '_');

}

void KeyPad::resetCurrentPosition() {
    currentPosition = padCoords['A'];
}

void KeyPad::printCodes() {
    
}