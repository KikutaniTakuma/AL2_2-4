#include <Novice.h>
#include <SafeDelete.h>
#include"Game/Resources/Resources.h"
#include "Game/Camera/Camera.h"
#include "Game/Quad/Quad.h"
#include "Game/Easing/Easing.h"
#include "Effect/Effect.h"
#include "Game/Mouse/Mouse.h"
#include "Game/KeyInput/KeyInput.h"

const char kWindowTitle[] = "LC1A_08_キクタニタクマ_タイトル";

// Windowsアプリでのエントリーポイント(main関数)
int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {

	// ライブラリの初期化
	Novice::Initialize(kWindowTitle, 1280, 720);

	Resources tex("Resources", "png");

	Camera* camera = new Camera;

	Effect* effect = new Effect(camera);

	// ウィンドウの×ボタンが押されるまでループ
	while (Novice::ProcessMessage() == 0) {
		// フレームの開始
		Novice::BeginFrame();

		// キー入力を受け取る
		KeyInput::Input();
		Mouse::Input();

		///
		/// ↓更新処理ここから
		///
		effect->Update();

		///
		/// ↑更新処理ここまで
		///

		///
		/// ↓描画処理ここから
		///
		camera->Update();
		Novice::DrawBox(0, 0, 1280, 720, 0.0f, 0xff, kFillModeSolid);
		Novice::DrawLine(0, 360, 1280, 360, WHITE);
		Novice::DrawLine(640, 0, 640, 720,WHITE);
		effect->Draw(tex["circle"]);

		///
		/// ↑描画処理ここまで
		///

		// フレームの終了
		Novice::EndFrame();

		// ESCキーが押されたらループを抜ける
		if (KeyInput::Released(DIK_ESCAPE)) {
			break;
		}
	}

	SafeDelete(camera);
	SafeDelete(effect);

	// ライブラリの終了
	Novice::Finalize();
	return 0;
}
