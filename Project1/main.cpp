#include <windows.h>
int WINAPI WinMain
(
	HINSTANCE hinstance,
	HINSTANCE hPrevInstance,
	LPSTR lpCmdLine,
	int nCmdLine
)
{

	HWND hwnd;//winハンドル
	WNDCLASS wc;//windowクラス
	//ここからウィンドウクラスの変数を宣言して初期化する
	wc.style = CS_HREDRAW && CS_VREDRAW;//ウィンドウクラスの基本クラスの指定
	wc.lpfnWndProc = DefWindowProc;//ウィンドウプロ―ジャを登録
	wc.cbClsExtra = NULL;
	wc.cbWndExtra = NULL;
	wc.hInstance = hinstance;//インスタンスハンドルを登録
	wc.hIcon = LoadIcon(NULL, IDI_APPLICATION);//アンコンの名前を指定する
	wc.hCursor = LoadCursor(NULL,IDC_ARROW);
	wc.hbrBackground = static_cast<HBRUSH>(GetStockObject(WHITE_BRUSH));//背景色の指定をブラシのハンドルを取得する形で指定する
	wc.lpszMenuName = NULL;//クラスメニューの指定　今回はなし
	wc.lpszClassName = TEXT("kitty");
	//ここまででウィンドウクラスの初期化終わり
//ウィンドウクラスのポインタを登録する
	if (!RegisterClass(&wc))return 0;
		//winハンドルを初期化する
		hwnd = CreateWindow
		(
			TEXT("KITTY"), TEXT("KITTY ON YOUR LAP"),
			WS_OVERLAPPEDWINDOW,
			100, 100, 200, 200, NULL, NULL,
			hinstance, NULL
		);
	//ウィンドを出す
		ShowWindow(hwnd,SW_SHOW);
		MessageBox(NULL, TEXT(" kitty on your lap")
			, TEXT("kitty"), MB_ICONINFORMATION);
		return 0;

}