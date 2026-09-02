#include "CheckColl.h"

Vector<VecPos> CheckColl::Point::GetClosestPointsOnSidesOfSqToCircle(
    const sf::Shape* rectangle, const Circle* circle) {
    Vector<VecPos> points;
    for (std::size_t point = 0; point < rectangle->getPointCount(); ++point) {
        const sf::Vector2f StartLinePoint = rectangle->getTransform().
                                                       transformPoint( rectangle->getPoint( point ) );

        const sf::Vector2f EndLinePoint = rectangle->getTransform().transformPoint(
            rectangle->getPoint( (point + 1) % rectangle->getPointCount() ) );

        // distance in start line point and end line point
        sf::Vector2f DA = EndLinePoint - StartLinePoint;
        // distance in center on circle and start line point
        sf::Vector2f DP = circle->getPosition() - StartLinePoint;
        float PositionOnSide = DP.dot( DA ) / DA.dot( DA );
        PositionOnSide = std::clamp( PositionOnSide, 0.0f, 1.0f );
        sf::Vector2f Closest = StartLinePoint + DA * PositionOnSide;
        points.Append( { Closest.x, Closest.y } );
    }
    return points;
}


VecPos CheckColl::Point::GetClosestPointOnSqToCircle(
    const Vector<VecPos>& points,
    const Circle* target_circle) {
    sf::Vector2f closestPoint = { points[0].get_x(), points[0].get_y() };

    float closestDistance =
        (closestPoint - target_circle->getPosition()).lengthSquared();

    for (std::size_t point = 1; point < points.Size(); ++point) {
        const float currentDistance =
            (sf::Vector2f { points[point].get_x(), points[point].get_y() } - target_circle->getPosition()).
            lengthSquared();

        if (currentDistance < closestDistance) {
            closestDistance = currentDistance;
            closestPoint = { points[point].get_x(), points[point].get_y() };
        }
    }

    return { closestPoint.x, closestPoint.y };
}

void CheckColl::set(sf::Shape* shape) {
    CGW.AddShape( shape );
}

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

Set<sf::Shape*> CheckColl::CircleRectangle(sf::Shape* target_shape /* circle */) const {
    const Set<sf::Shape*> RectanglesAsideCircle = CheckColl::Filter(
        CGW.Query( target_shape ), Shape_Type::Rectangle );

    Set<sf::Shape*> ShapeCollide;
    for (sf::Shape* SHAPE : RectanglesAsideCircle) {
        const Rectangle* rect = dynamic_cast<Rectangle*>(SHAPE);
        if ((target_shape->getPosition().x > rect->getPosition().x)
            && (target_shape->getPosition().x < (rect->getPosition().x + rect->getSize().x))
            && (target_shape->getPosition().y > rect->getPosition().y)
            && (target_shape->getPosition().y < (rect->getPosition().y + rect->getSize().y))) {
            ShapeCollide.Add( SHAPE );
            continue;
        }

        VecPos ClosestPoint = CheckColl::Point::GetClosestPointOnSqToCircle(
            CheckColl::Point::GetClosestPointsOnSidesOfSqToCircle(
                rect, dynamic_cast<Circle*>(target_shape) ), dynamic_cast<Circle*>(target_shape) );

        const VecPos& Differance = {
            ClosestPoint.get_x() - target_shape->getPosition().x,
            ClosestPoint.get_y() - target_shape->getPosition().y };

        const float& Distance = Differance.get_x() * Differance.get_x() + Differance.get_y() * Differance.
            get_y();
        if (const float& RadiusOfCircle = dynamic_cast<Circle*>(target_shape)->getRadius();
            Distance <= RadiusOfCircle * RadiusOfCircle) {
            ShapeCollide.Add( SHAPE );
        }
    }
    return ShapeCollide;
}

Set<sf::Shape*> CheckColl::CirclePolygon(sf::Shape* target_shape) const {
    const Set<sf::Shape*> PolygonsAsideCircle = CheckColl::Filter(
        CGW.Query( target_shape ), Shape_Type::Polygon );
    Set<sf::Shape*> ShapeCollide;
    for (sf::Shape* SHAPE : PolygonsAsideCircle) {
        VecPos ClosestPoint = CheckColl::Point::GetClosestPointOnSqToCircle(
            CheckColl::Point::GetClosestPointsOnSidesOfSqToCircle(
                SHAPE, dynamic_cast<Circle*>(target_shape) ), dynamic_cast<Circle*>(target_shape) );
        const VecPos& Differance = {
            ClosestPoint.get_x() - target_shape->getPosition().x,
            ClosestPoint.get_y() - target_shape->getPosition().y };
        const float& Distance = Differance.get_x() * Differance.get_x() +
            Differance.get_y() * Differance.get_y();
        if (const float& RadiusOfCircle = dynamic_cast<Circle*>(target_shape)->getRadius(); Distance <=
            RadiusOfCircle * RadiusOfCircle) {
            ShapeCollide.Add( SHAPE );
        }
    }
    return ShapeCollide;
}
