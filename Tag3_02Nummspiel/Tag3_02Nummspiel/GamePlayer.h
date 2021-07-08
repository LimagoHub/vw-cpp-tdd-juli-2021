#pragma once
#include <string>
template<class SCENE, class TURN>
class GamePlayer
{
public:
	virtual std::string get_name() const = 0;
	virtual TURN do_turn(const SCENE & scene) const = 0;
};

