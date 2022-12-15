#include "View.h"

void View::setPosition(const float _X, const float _Y)
{
    m_position = Vec2f(_X, _Y);
}

void View::setSize(const float _X, const float _Y)
{
    m_size = Vec2f(_X, _Y);
}

void View::setScale(const float _X, const float _Y)
{
    m_scale = Vec2f(_X, _Y);
}

Vec2f View::getScale() const
{
    return m_scale;
}

Vec2f View::getPosition() const
{
    return m_position;
}

Vec2f View::getSize() const
{
    return m_size;
}

void View::move(const float _X, const float _Y)
{
    m_position += Vec2f(_X, _Y);
}

void View::scale(const float _X, const float _Y)
{
    m_scale += Vec2f(_X, _Y);
}
