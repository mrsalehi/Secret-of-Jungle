#include "VioletCell.h"


using namespace std;

void VioletCell::printColor() {
    cout << "(Violet)";
}

string VioletCell::getColor() {
    return "Violet";
}

void VioletCell::setIsFilled(bool isFilled) {

    this->isFilled = isFilled;


}

bool VioletCell::getIsFilled() {

    return isFilled;

}

VioletCell::VioletCell() {
    isFilled = false;
}

