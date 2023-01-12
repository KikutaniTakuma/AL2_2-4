#include "Effect/Effect.h"
#include "Game/MyMath/MyMath.h"
#include "Game/Mouse/Mouse.h"
#include "Game/KeyInput/KeyInput.h"

Effect::Effect(Camera* camera) :
	Object(camera),
	acceleration(0.2f),
	emitter({ {-50.0f, -50.0f}, {50.0f, 50.0f} }),
	particle({Vector2D(), 0.0f,0.0f,false}),
	frequency(5),
	count(0),
	particleBuf(Quad())
{
	pos.Set({640.0f,360.0f}, {0.0f,0.0f});
	frame.Restart();
}

void Effect::Update() {
	if (KeyInput::getKeys(DIK_W)) {
		emitter.rightTop.y += 5.0f;
		emitter.leftBottom.y -= 5.0f;
	}
	if (KeyInput::getKeys(DIK_D)) {
		emitter.rightTop.x += 5.0f;
		emitter.leftBottom.x -= 5.0f;
	}
	if (KeyInput::getKeys(DIK_S)) {
		emitter.rightTop.y -= 5.0f;
		if (emitter.rightTop.y <= 0.0f) {
			emitter.rightTop.y = 0.0f;
		}
		emitter.leftBottom.y += 5.0f;
		if (emitter.leftBottom.y >= 0.0f) {
			emitter.leftBottom.y = 0.0f;
		}
	}
	if (KeyInput::getKeys(DIK_A)) {
		emitter.rightTop.x -= 5.0f;
		if (emitter.rightTop.x <= 0.0f) {
			emitter.rightTop.x = 0.0f;
		}
		emitter.leftBottom.x += 5.0f;
		if (emitter.leftBottom.x >= 0.0f) {
			emitter.leftBottom.x = 0.0f;
		}
	}


	pos.worldPos = { static_cast<float>(Mouse::x), static_cast<float>(Mouse::y) };

	for (int i = count; i < count + frequency && count < particle.size()-1; i++) {
		if (!particle[i].flg) {
			particle[i].flg = true;
			particle[i].size = static_cast<float>(MyMath::Random(3, 6));
			particle[i].pos = pos.worldPos;
			particle[i].pos.x += static_cast<float>(MyMath::Random(static_cast<int>(emitter.leftBottom.x), static_cast<int>(emitter.rightTop.x)));
			particle[i].pos.y += static_cast<float>(MyMath::Random(static_cast<int>(emitter.leftBottom.y), static_cast<int>(emitter.rightTop.y)));
		}
	}
	count += frequency;

	MyMath::Clamp(count, static_cast<int>(particle.size()), 0);
	if (count == particle.size()) {
		count = 0;
	}

	for (auto& i : particle) {
		if (i.flg) {
			i.spd += acceleration;
			i.pos.y -= i.spd;
			if (!camera->isDraw(i.pos)) {
				i= { Vector2D(), 0.0f,0.0f,false };
			}
		}
	}
}

void Effect::Draw(Texture& tex) {
	for (auto& i : particle) {
		if (i.flg) {
			particleBuf.Set(i.pos, { i.size,i.size });
			camera->DrawQuad(particleBuf, tex, 0, false);
		}
	}
	quad = Quad();
	quad = { {pos.worldPos.x, emitter.leftBottom.y + pos.worldPos.y}, {emitter.rightTop.x - emitter.leftBottom.x, 1.0f} };
	camera->DrawQuad(quad, tex, 0, false);
	quad = { { emitter.rightTop.x + pos.worldPos.x, pos.worldPos.y}, { 1.0f, emitter.rightTop.y - emitter.leftBottom.y} };
	camera->DrawQuad(quad, tex, 0, false);
	quad = { {pos.worldPos.x,emitter.rightTop.y + pos.worldPos.y}, {emitter.rightTop.x - emitter.leftBottom.x, 1.0f} };
	camera->DrawQuad(quad, tex, 0, false);
	quad = { { emitter.leftBottom.x + pos.worldPos.x , pos.worldPos.y}, { 1.0f, emitter.rightTop.y - emitter.leftBottom.y} };
	camera->DrawQuad(quad, tex, 0, false);
}

void Effect::Reset() {

}