#include <DxLib.h>
#include <stdio.h>
#include <sstream>
#include <cassert>
#include <iomanip>
#include "Geometry.h"
//#include "game.h"
//#include "scene.h"
//#include "Player.h"
//#include "game.h"
//struct Rect 
//{
//	Rect()			//デフォルトコンストラクタ
//	{
//		x = 0;
//		y = 0;
//		sx = 0 ;
//		sy = 0;
//	}
//	Rect(float x, float y , float sx, float sy) {
//		Rect::x = x;
//		Rect::y = y;
//		Rect::sx = sx;
//		Rect::sy = sy;
//	}
//	float x;
//	float y;
//	float sx;
//	float sy;
//	
//};


bool SysInit(void)
{
	SetGraphMode(640, 480, 32);			//最後の引数の60はVisuaでは回せるだけ回す
	ChangeWindowMode(true);				//
	if (DxLib_Init() == -1)				//Dxlibの初期化又
	{
		return false;
	}
	
	return true;

}

Position2 GetMousePoint2()
{
	int mx, my;
	GetMousePoint(&mx, &my);
	return { static_cast<float>(mx), static_cast<float>(my) };
}

float DegreeToRadian(float def)
{
	return def * DX_PI / 180.0f;
}
int WINAPI wWinMain(_In_ HINSTANCE hInstance, _In_opt_ HINSTANCE hPrevInstance, _In_ LPWSTR lpCmdLine, _In_ int nShowCmd)	//緑の波線が消える
{
	SetWindowText(L"2016006_浦山巧");
	if (!SysInit())
	{
		return -1;
	}
	SetDrawScreen(DX_SCREEN_BACK);		//バックバッファに描画
	int groundH = LoadGraph(L"image/ground.png");
	assert(groundH >= 0);
	int bgAssetH = LoadGraph(L"image/Assets.png");
	assert(bgAssetH >= 0);
	constexpr size_t pictrure_num = 5;
	int graphH[pictrure_num] = {};
	for (int i = 0; i < pictrure_num; ++i)
	{

		std::wostringstream oss;
		oss << L"../Aset/Adventurer-1.5/Individual Sprites/adventurer-attack1-";
		oss << std::setw(2);
		oss << std::setfill(L'0');
		oss << i << ".png";

		graphH[i] = LoadGraph(oss.str().c_str());
		assert(graphH[i] != -1);

		//OutputDebugString

			/*wchar_t path[80];
		sprintf_s("../../Aset/Adventurer-1.5/Individual Sprites/adventurer-run-%02d.png", i);
		graphH[i] = LoadGraph(path.str().c_str());
		assert(graphH[i] != 1);*/
	}
	Rect rcA = { {100,100},75,75 };
	//Rect rcA = { 100,300,200,200 };
	
	
	
	constexpr size_t frames_per_pict = 5;
	unsigned int frameNo = 0;
	int frameForAngle = 0;
	bool isReverse = false;
	int lastMouseInput = 0;
	while (ProcessMessage() == 0 && CheckHitKey(KEY_INPUT_ESCAPE) == 0)
	{
		auto currentMouseInput = GetMouseInput();
		if (currentMouseInput &MOUSE_INPUT_LEFT &&
			!lastMouseInput & MOUSE_INPUT_LEFT)
		{
			isReverse = !isReverse;
		}
		lastMouseInput = currentMouseInput;
		ClsDrawScreen();
		constexpr size_t bolck_size = 32;

		const float speed = 4.0f;
		if (CheckHitKey(KEY_INPUT_UP))
		{
			rcA.center.y -= speed;
		}
		if(CheckHitKey(KEY_INPUT_DOWN))
		{
			rcA.center.y += speed;
		}
		if(CheckHitKey(KEY_INPUT_RIGHT))
		{
			rcA.center.x += speed;
		}
		if(CheckHitKey(KEY_INPUT_LEFT))
		{
			rcA.center.x -= speed;
		}
		std::ostringstream oss;
		oss << "x=" << rcA.center.x;
		oss << "y=" << rcA.center.y << "\n";
		OutputDebugStringA(oss.str().c_str());
	
		DrawBox((int)rcA.center.x, (int)rcA.center.y, (int)rcA.center.x + rcA.w, (int)rcA.center.y + rcA.h,0xffffff,true);
		//DrawBox(640, 480, 100, 100, 0xff00ff, true);
		auto mpos = GetMousePoint2();
		auto dir = mpos - rcA.center;
		//基準（０°）が右ベクトルで、マウスの向きを角度で返す
		float angle = atan2(dir.y, dir.x);
		//回転の中心が画像の中心
		//DrawRotaGraph(rcA.center.x, rcA.center.y,4.0f, angle,graphH[],true);
		auto imgIdx = frameNo / frames_per_pict;
		int centerX = 16;
		if (isReverse)
		{
			int w, h;
			GetGraphSize(graphH[imgIdx], &w, &h);
			centerX = w - centerX;
		}
		
		
	
		constexpr size_t block_size = 32;
		auto  count = 720 / 32;
		constexpr int base_y = 240;
		constexpr float sin_amp = 50.0f;
		int x = 0;
		int y = base_y + sin_amp * sin(DegreeToRadian((float)( frameForAngle)));;
		Position2 groundPos(x, y);
		Position2 currentPos(x, y);
		//Vector2 lastDelta90Vec = Vector2::Zero();
		Vector2 lastDelta90Vectors[2] = { Vector2::Zero(), Vector2::Zero() };
		for (int i = 1; i <= count; ++i)
		{
			int nextX = i * block_size;
			int nextY =sin_amp *sin(DegreeToRadian((float)(5.0f* nextX + frameForAngle)));
			
			auto deltaVec = Vector2(block_size,nextY).Normalized() * block_size;
			auto nextPos = currentPos + deltaVec;
			
			auto middleVec0 = deltaVec;
			auto middleVecR = deltaVec.Rotated90();
			
			if (!(lastDelta90Vectors[0] == Vector2::Zero()))
			{
				middleVecR = (middleVecR + lastDelta90Vectors[0]).Normalized() * block_size;
			}
			auto middleVecL = lastDelta90Vectors[0];
			
			if (!(lastDelta90Vectors[1] == Vector2::Zero()))
			{
				middleVecL = (middleVecL + lastDelta90Vectors[1]).Normalized() * block_size;
			}
			lastDelta90Vectors[1] = lastDelta90Vectors[0];
			lastDelta90Vectors[0] = deltaVec.Rotated90();
			
			/*DrawModiGraph(
				x, y,
				nextX, nextY,
				nextX, nextY + block_size,
				x, y + block_size,
				bgAssetH, 5.0f);*/
			auto rithPos = nextPos + deltaVec.Rotated90();
			auto LeftPos = nextPos + deltaVec.Rotated90();

			auto middlePosL = currentPos + middleVecL;
			auto middlePosR = nextPos + middleVecR;
			DrawRectModiGraph(
				currentPos.x, currentPos.y,
				nextPos.x, nextPos.y,
				middlePosR.x, middlePosR.y ,
				middlePosL.x, middlePosL.y,
				48,0,
				16,16,
				bgAssetH, true);
			//DrawLineAA(groundPos.x, groundPos.y, nextPos.x, nextPos.y, 0xffffff, 2.0f);
			/*DrawLineAA(nextX, nextY, nextX, nextY + block_size, 0xffffff, 2.0f);
			DrawLineAA(nextX, nextY + block_size, x, y + block_size, 0xffffff, 2.0f);
			DrawLineAA(x, y, nextX, nextY, 0xffffff, 2.0f);*/

			currentPos = nextPos;
		}
		DrawRotaGraph2(rcA.center.x, rcA.center.y, centerX, 35, 4.0f, angle, graphH[imgIdx], true, isReverse);
		/*int frameNo = 0;
		frameNo = (frameNo + 1)%60;
		DrawGraph(rcA.center.x, rcA.center.y,graphH[frameNo],true);*/
		ScreenFlip();
		frameNo = (frameNo + 1) % (frames_per_pict * pictrure_num);
		frameForAngle = (frameForAngle + 1) % 720;
	}
	/*Vector2 v = { 10,10 };
	auto vv = rcA.center + v;
	test++;*/

	return 0;
}
