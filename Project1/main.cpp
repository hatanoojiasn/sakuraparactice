#include <windows.h>
LRESULT CALLBACK WndProc(HWND hwnd, UINT msg, WPARAM wp, LPARAM lparam)
{
	switch (msg)
	{
		MessageBox(hwnd, TEXT("これで終わりだ！！"), TEXT("kitty"), MB_ICONINFORMATION);
		exit(0);
	}
	return DefWindowProc(hwnd, msg, wp, lparam);
}
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
	wc.lpfnWndProc = WndProc;//ウィンドウプロ―ジャを登録
	wc.cbClsExtra = NULL;
	wc.cbWndExtra = NULL;
	wc.hInstance = hinstance;//インスタンスハンドルを登録
	wc.hIcon = LoadIcon(NULL, IDI_APPLICATION);//アイコンの名前を指定する
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
			WS_CAPTION| WS_VISIBLE,
			100, 100, 200, 200, NULL, NULL,
			hinstance, NULL
		);
		MSG msg;//メッセージ構造体
	//メッセージループ
		if (hwnd == NULL)return 0;	
		while (TRUE)
		{
			GetMessage(&msg, NULL, 0, 0);//メッセージを取得する受け取るメッセージは制限しない
			if (msg.message == WM_LBUTTONUP) break; //左ボタンが押されたら終了
			DispatchMessage(&msg);//メッセージを処理する
		}
		return 0;

}