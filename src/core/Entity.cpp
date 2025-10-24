#include "Entity.h"

Entity::Entity(std::unique_ptr<ITransform> t)
	: transform(std::move(t)) {
	
}

ITransform& Entity::getTransform() {
	return *transform;
}

const ITransform& Entity::getTransform() const {
	return *transform;
}

void Entity::setCollider(std::unique_ptr<Collider> c) {
	collider = std::move(c);
}

Collider* Entity::getCollider() const {
	return collider.get();
}

bool Entity::isAnchored() const {
	return Anchor;
}

void Entity::setAnchored(bool state) {
	Anchor = state;
}

bool Entity::isCollidable() const {
	return canCollide;
}

void Entity::setCollidable(bool state) {
	canCollide = state;
}