#include "CheckColl.h"

#include <cmath>

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

Vector<VecPos> CheckColl::Extract::ExtractPointFromShape(const sf::Shape* shape) {
    Vector<VecPos> DataExtracted;
    for (std::size_t point = 0; point < shape->getPointCount(); ++point) {
        DataExtracted.Append( { shape->getPoint( point ).x, shape->getPoint( point ).y } );
    }
    return DataExtracted;
}

VecPos CheckColl::Extract::ExtractVector2fToVecPos(const sf::Vector2f& VECTOR2F) {
    return VecPos { VECTOR2F.x, VECTOR2F.y };
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

float CheckColl::SAT::DotProduct(const VecPos& FirstPoint, const VecPos& SecondPoint) {
    return FirstPoint.get_x() * SecondPoint.get_x() + FirstPoint.get_y() * SecondPoint.get_y();
}

bool CheckColl::Point::PointIsInShape(const VecPos& target_point, const sf::Shape* target_shape) {
    bool is_inside = false;
    const Vector<VecPos>& PointsOfShape = CheckColl::Extract::ExtractPointFromShape( target_shape );
    const std::size_t& point_count = PointsOfShape.Size();
    for (std::size_t current_point_index = 0; current_point_index < point_count; ++current_point_index) {
        const std::size_t Previous_Index = (current_point_index != 0) ? current_point_index - 1 :
                                               point_count - 1;
        const VecPos& CurrentShapePoint = PointsOfShape[current_point_index];
        const VecPos& PreviousShapePoint = PointsOfShape[Previous_Index];
        const bool LineIsOutOfRange = (CurrentShapePoint.get_y() > target_point.get_y()) !=
            (PreviousShapePoint.get_y() > target_point.get_y());
        if (!LineIsOutOfRange) {
            continue;
        }
        const float intersection_x =
            PreviousShapePoint.get_x() +
            (CurrentShapePoint.get_x() - PreviousShapePoint.get_x()) *
            (target_point.get_y() - PreviousShapePoint.get_y()) /
            (CurrentShapePoint.get_y() - PreviousShapePoint.get_y());
        if (target_point.get_x() > intersection_x) {
            is_inside = !is_inside;
        }
    }
    return is_inside;
}

VecPos CheckColl::SAT::Normalize(const VecPos& point) {
    VecPos NormalizedPoint = { point.get_x(), point.get_y() };
    const float length = std::sqrt(
        NormalizedPoint.get_x() * NormalizedPoint.get_x() + NormalizedPoint.get_y() * NormalizedPoint.
        get_y() );
    NormalizedPoint.Set_XY( NormalizedPoint.get_x() / length, NormalizedPoint.get_y() / length );
    return NormalizedPoint;
}

VecPos CheckColl::SAT::GetNormalLine(const VecPos& FirstPoint, const VecPos& SecondPoint) {
    VecPos edge = FirstPoint - SecondPoint;
    edge = {edge.get_x(), -edge.get_y()};
    return Normalize( edge );
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
        if (CheckColl::Point::PointIsInShape(
            { target_shape->getPosition().x, target_shape->getPosition().y }, SHAPE )) {
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
        if (CheckColl::Point::PointIsInShape(
            { target_shape->getPosition().x, target_shape->getPosition().y }, SHAPE )) {
            ShapeCollide.Add( SHAPE );
            continue;
        }
        VecPos ClosestPoint = CheckColl::Point::GetClosestPointOnSqToCircle(
            CheckColl::Point::GetClosestPointsOnSidesOfSqToCircle(
                SHAPE, dynamic_cast<Circle*>(target_shape) ), dynamic_cast<Circle*>(target_shape) );
        const VecPos& Differance = {
            ClosestPoint.get_x() - target_shape->getPosition().x,
            ClosestPoint.get_y() - target_shape->getPosition().y };
        const float& Distance = Differance.get_x() * Differance.get_x() +
            Differance.get_y() * Differance.get_y();
        if (const float& RadiusOfCircle = dynamic_cast<Circle*>(target_shape)->getRadius();
            (Distance <= RadiusOfCircle * RadiusOfCircle)) {
            ShapeCollide.Add( SHAPE );
        }
    }
    return ShapeCollide;
}

Set<sf::Shape*> CheckColl::RectanglePolygon(sf::Shape* target_shape) const {
    const Set<sf::Shape*> PolygonAsideRectangle = CheckColl::Filter(
        CGW.Query( target_shape ), Shape_Type::Polygon );
    Set<sf::Shape*> ShapeCollide;
    for (sf::Shape* SHAPE : PolygonAsideRectangle) {}
    return ShapeCollide;
}
