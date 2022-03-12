#ifndef TEXTURE_HOLDER_H
#define TEXTURE_HOLDER_H

#include <map>
#include <memory>

#include <SFML/Graphics.hpp>

//enumerator for textures
namespace Textures
{
    enum ID { Background, Character, Bullet};
}

class TextureHolder
{
private:

    //Variables
    std::map<Textures::ID, std::unique_ptr<sf::Texture>> mTextureMap;
public:

    //Functions
    void                load(Textures::ID, const std::string&);
    sf::Texture&        get(Textures::ID);
    const sf::Texture&  get(Textures::ID id) const;
    
}; 

#endif