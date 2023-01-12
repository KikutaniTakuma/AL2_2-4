#pragma once

#include "Game/Object/Object.h"
#include "Game/Frame/Frame.h"
#include <array>

class Effect : public Object {
private:
	struct Emitter {
		Vector2D rightTop;
		Vector2D leftBottom;
	};

	struct Particle {
		Vector2D pos;
		float spd;
		float size;
		bool flg;
	};

public:
	Effect(Camera* camera);

private:
	Emitter emitter;
	Quad particleBuf;
	std::array<Particle, std::size_t(400)> particle;
	float acceleration;
	Frame frame;
	const int frequency;
	int count;
	Quad quad;

public:
	void Update() override;
	void Draw(Texture& tex) override;
	void Reset() override;
};