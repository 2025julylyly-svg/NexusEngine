#include "Polygon.h"
Polygon::Polygon() = default;

Polygon::Polygon(const std::size_t& point_count) {
    CVX.setPointCount(point_count);
}

Polygon::Polygon(const std::size_t& point_count, const float& speed) {
    CVX.setPointCount( point_count );
    Speed = speed;
}
void Polygon::SetSpeed(const float& speed) {
    Speed = speed;
}
void Polygon::MoveUp() {
}
