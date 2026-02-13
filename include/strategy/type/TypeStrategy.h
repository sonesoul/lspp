#pragma once

class Item;

class TypeStrategy {
public:
	virtual ~TypeStrategy() = default;

	virtual bool applicable(const Item&, const Item&) = 0;
	virtual bool operator()(const Item&, const Item&) = 0;
};