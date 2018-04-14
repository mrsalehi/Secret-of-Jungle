#include "OrangeCell.h"


void OrangeCell::printColor() {
    cout << "(Orange)";
}

string OrangeCell::getColor() {
    return "Orange";
}

char OrangeCell::getTreasureName() {
    return treasure_name;
}

void OrangeCell::setTreasureName(char treasure_name) {
    this->treasure_name = treasure_name;
}

void OrangeCell::setIsFilled(bool isFilled) {

    this->isFilled = isFilled;

}

bool OrangeCell::getIsFilled() {

    return isFilled;
}

OrangeCell::OrangeCell() {

    this->isFilled = false;
}
