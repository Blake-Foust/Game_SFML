#include "TextureHolder.hpp"

//Place Texture for easy look up
void TextureHolder::load(Textures::ID id, const std::string& filename)
{
    std::unique_ptr<sf::Texture> texture(new sf::Texture());
    texture->loadFromFile(filename);

    this->mTextureMap.insert(std::make_pair(id, std::move(texture)));
};

sf::Texture& TextureHolder::get(Textures::ID id)
{
    auto found = this->mTextureMap.find(id);
    return *found->second;
};

const sf::Texture& TextureHolder::get(Textures::ID id) const
{
    auto found = this->mTextureMap.find(id);
    return *found->second;
};
