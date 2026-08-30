#include "__shapes_is__.h"

bool ShapeIs::Rotate::RectIsRotated(Rectangle* rectangle) {
    if ((rectangle->getPoint(0).x + rectangle->getSize().x) == rectangle->getPoint(1).x) {
        return false;
    }
    if ((rectangle->getPoint(0).y + rectangle->getSize().y) == rectangle->getPoint(1).y) {
        return false;
    }
    if ((rectangle->getPoint(0).x - rectangle->getSize().x) == rectangle->getPoint(1).x) {
        return false;
    }
    if ((rectangle->getPoint(0).y - rectangle->getSize().y) == rectangle->getPoint(1).y) {
        return false;
    }
    return true;
}
