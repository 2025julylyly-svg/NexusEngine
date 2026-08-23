#include "CheckColl.h"
CheckColl::CheckColl() : CGW(900,900) {}
Set<sf::Shape*> CheckColl::Filter(const Set<sf::Shape*>& shapes, const CheckColl::Shape_Type& target_shape_enum) {
    Set<sf::Shape*> clean;
    if (target_shape_enum == Shape_Type::Shape) {
        return clean;
    }
    for (const auto& shape : shapes) {
        if (target_shape_enum == Shape_Type::Circle && typeid(*shape) == typeid(Circle)) {
            clean.Add(shape);
        } else if (target_shape_enum == Shape_Type::Rectangle && typeid(*shape) == typeid(Rectangle)) {
            clean.Add(shape);
        } else if (target_shape_enum == Shape_Type::Polygon && typeid(*shape) == typeid(Polygon)) {
            clean.Add(shape);
        }
    }
    return clean;
}

Set<sf::Shape*> CheckColl::CircleCircle(sf::Shape* target_shape) {
    const Set<sf::Shape*> CirclesAsideCircle = CheckColl::Filter(CGW.Query(target_shape), Shape_Type::Circle);
    Set<sf::Shape*> ShapeCollide;
    for (auto& SHAPE : CirclesAsideCircle) {
        const float distance_x = std::abs(dynamic_cast<Circle*>(target_shape)->getPosition().x - dynamic_cast<Circle*>(SHAPE)->getPosition().x);
        const float distance_y = std::abs(dynamic_cast<Circle*>(target_shape)->getPosition().y - dynamic_cast<Circle*>(SHAPE)->getPosition().y);
        const float DISTANCE = (distance_x * distance_x) + (distance_y * distance_y);
        const float R1 = dynamic_cast<Circle*>(target_shape)->GetRadius();
        const float R2 = dynamic_cast<Circle*>(SHAPE)->GetRadius();
        if (const float R_SUM = (R1 + R2) * (R1 + R2); DISTANCE <= R_SUM) {
            ShapeCollide.Add( SHAPE );
        }
    }
    return ShapeCollide;
}