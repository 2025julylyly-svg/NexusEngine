#include "__shapes_is__.h"

int ShapeIs::Rotate::RectIsRotated(Rectangle* rectangle) {
    if ((rectangle->getPoint(0).x + rectangle->getSize().x) == rectangle->getPoint(1).x) {
        return 0;
    }
    if ((rectangle->getPoint(0).y + rectangle->getSize().y) == rectangle->getPoint(1).y) {
        return 1;
    }
    if ((rectangle->getPoint(0).x - rectangle->getSize().x) == rectangle->getPoint(1).x) {
        return 2;
    }
    if ((rectangle->getPoint(0).y - rectangle->getSize().y) == rectangle->getPoint(1).y) {
        return 3;
    }
    return -1;
}
