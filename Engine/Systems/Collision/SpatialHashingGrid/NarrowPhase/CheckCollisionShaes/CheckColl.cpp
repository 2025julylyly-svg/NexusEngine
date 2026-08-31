#include "CheckColl.h"

CheckColl::CheckColl() : CGW( 900, 900 ) {
    assert( false );
}

CheckColl::CheckColl(const int& WIDTH, const int& HEIGHT) : CGW( WIDTH, HEIGHT ) {}

Set<sf::Shape*> CheckColl::Filter(const Set<sf::Shape*>& shapes,
                                  const CheckColl::Shape_Type& target_shape_enum) {
    Set<sf::Shape*> clean;
    if (target_shape_enum == Shape_Type::Shape) {
        return clean;
    }
    if (target_shape_enum == Shape_Type::Circle) {
        for (sf::Shape* shape : shapes) {
            if (typeid( *shape ) == typeid( Circle )) {
                clean.Add( shape );
            }
        }
    } else if (target_shape_enum == Shape_Type::Rectangle) {
        for (sf::Shape* shape : shapes) {
            if (typeid( *shape ) == typeid( Rectangle )) {
                clean.Add( shape );
            }
        }
    } else if (target_shape_enum == Shape_Type::Polygon) {
        for (sf::Shape* shape : shapes) {
            if (typeid( *shape ) == typeid( Polygon )) {
                clean.Add( shape );
            }
        }
    }
    return clean;
}

Set<sf::Shape*> CheckColl::CircleCircle(sf::Shape* target_shape /* circle */) const {
    const Set<sf::Shape*> CirclesAsideCircle = CheckColl::Filter( CGW.Query( target_shape ),
                                                                  Shape_Type::Circle );
    Set<sf::Shape*> ShapeCollide;
    for (auto& SHAPE : CirclesAsideCircle) {
        if (SHAPE == target_shape) {
            continue;
        };
        const float distance_x = std::abs(
            dynamic_cast<Circle*>(target_shape)->getPosition().x - dynamic_cast<Circle*>(SHAPE)->getPosition()
            .x );
        const float distance_y = std::abs(
            dynamic_cast<Circle*>(target_shape)->getPosition().y - dynamic_cast<Circle*>(SHAPE)->getPosition()
            .y );
        const float DISTANCE = (distance_x * distance_x) + (distance_y * distance_y);
        const float R1 = dynamic_cast<Circle*>(target_shape)->getRadius();
        const float R2 = dynamic_cast<Circle*>(SHAPE)->getRadius();
        if (const float R_SUM = (R1 + R2) * (R1 + R2); DISTANCE <= R_SUM) {
            ShapeCollide.Add( SHAPE );
        }
    }
    return ShapeCollide;
}

Set<sf::Shape*> CheckColl::CircleRectangle(sf::Shape* target_shape /* circle */) {
    const Set<sf::Shape*> RectanglesAsideCircle = CheckColl::Filter(
        CGW.Query( target_shape ), Shape_Type::Rectangle );
    Set<sf::Shape*> ShapeCollide;
    for (auto& SHAPE : RectanglesAsideCircle) {}
    return ShapeCollide;
}
