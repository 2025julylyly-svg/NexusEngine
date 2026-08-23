#include "CheckColl.h"

Set<sf::Shape*> CheckColl::Cleaning(const Set<sf::Shape*>& shapes, const CheckColl::Shape_Type& target_shape_enum) {
    Set<sf::Shape*> clean;
    if (target_shape_enum == Shape_Type::Shape) {
        return clean;
    }
    for (const auto& shape : shapes) {
        if (target_shape_enum == Shape_Type::Circle && typeid( *shape ) == typeid( Circle )) {
            clean.Add( shape );
        } else if (target_shape_enum == Shape_Type::Rectangle && typeid( *shape ) == typeid( Rectangle )) {
            clean.Add( shape );
        } else if (target_shape_enum == Shape_Type::Polygon && typeid( *shape ) == typeid( Polygon )) {
            clean.Add( shape );
        }
    }
    return clean;
}

Set<sf::Shape*> CheckColl::CircleCircle(const sf::Shape* target_shape) {
    const Set<sf::Shape*> CirclesAsideCircle = CheckColl::Cleaning( CGW.Query( target_shape ), Shape_Type::Circle );
    Set<sf::Shape*> ShapeCollide;
    for (auto& SHAPE : CirclesAsideCircle) {}
    return ShapeCollide;
}
