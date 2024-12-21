#ifndef SCENEOBJECT_H
#define SCENEOBJECT_H
#include <SFML/Graphics.hpp>

struct coords {
    int x;
    int y;
};

class sceneObject
{
    // Sprite
    sf::Sprite aSprite;
    sf::Texture *texturePointer;
    // Location
    coords coordinates;
public:
    sceneObject();
    void draw();
};

#endif // SCENEOBJECT_H
