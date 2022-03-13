#ifndef RESOURCEHOLDER_H
#define RESOURCEHOLDER_H

#include <map>
#include <memory>

#include <SFML/Graphics.hpp>


template<typename Resource, typename Identifier>
class ResourceHolder
{
private:
	std::map<Identifier, std::unique_ptr<Resource>> mResourceMap;
public:
	void 		load(Identifier id, const std::string& filename);
	Resource& 	get(Identifier id);
	const Resource&  get(Identifier id) const;

};

#include "ResourceHolder.inl";

#endif