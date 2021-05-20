
#include <stdio.h>
#include <sstream>
#include <iomanip>
#include <DxLib.h>

struct Rect 
{
	Rect()			//デフォルトコンストラクタ
	{
		x = 0;
		y = 0;
		sx = 0 ;
		sy = 0;
	}
	Rect(float x, float y , float sx, float sy) {
		Rect::x = x;
		Rect::y = y;
		Rect::sx = sx;
		Rect::sy = sy;
	}
	float x;
	float y;
	float sx;
	float sy;
	
};

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

int WINAPI wWinMain(_In_ HINSTANCE hInstance, _In_opt_ HINSTANCE hPrevInstance, _In_ LPWSTR lpCmdLine, _In_ int nShowCmd)	//緑の波線が消える
{
	SetWindowText("2016006_浦山巧");
	if (!SysInit())
	{
		return -1;
	}
	Rect rcA = { 100,100,50,50 };
	//Rect rcA = { 100,300,200,200 };
	
	
	while (ProcessMessage() == 0 && CheckHitKey(KEY_INPUT_ESCAPE) == 0)
	{
		
		
		const float speed = 4.0f;
		if (CheckHitKey(KEY_INPUT_UP))
		{
			rcA.y -= speed;
		}
		if(CheckHitKey(KEY_INPUT_DOWN))
		{
			rcA.y += speed;
		}
		if(CheckHitKey(KEY_INPUT_RIGHT))
		{
			rcA.x += speed;
		}
		if(CheckHitKey(KEY_INPUT_LEFT))
		{
			rcA.x -= speed;
		}
		std::ostringstream oss;
		oss << "x=" << rcA.x;
		oss << "y=" << rcA.y << "\n";
		OutputDebugStringA(oss.str().c_str());
		SetDrawScreen(DX_SCREEN_BACK);		//バックバッファに描画
		ClsDrawScreen();
		DrawBox((int)rcA.x, (int)rcA.y, (int)rcA.x + rcA.sx, (int)rcA.y + rcA.sx,0xffffff,true);
		//DrawBox(640, 480, 100, 100, 0xff00ff, true);
		ScreenFlip();
		//for (int i = 0; i < 6; ++i)
		//{

		//	std::wostringstream oss;
		//	oss << "../../Aset/Adventurer-1.5/Individual Sprites/adventurer-run-";
		//	oss << std::setw(2);
		//	oss << std::setfill(L'0');
		//	oss << i << ".png";

		//	graphH[i] = LoadGraph(oss.str, oss.c_str)
		//		assert(graphH[i] != -1)

		//	//OutputDebugString
		//		
		//		wchar_t path[80];
		//		sprintf_s("../../Aset/Adventurer-1.5/Individual Sprites/adventurer-run-%02d.png", i,);
		//		graphH[i] = LoadGraph(path);
		//		assert(graphH[i] != 1);
		//}

		//frame = (frameNo);
		//	DrawRotaGraph(rcA.center.x, rcA.center.y, 4.0f, 0.0f, );
		
	}
	return 0;
}
