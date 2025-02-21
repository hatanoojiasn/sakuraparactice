#include <windows.h>
LRESULT CALLBACK WndProc(HWND hwnd, UINT msg, WPARAM wp, LPARAM lparam)
{
	switch (msg)
	{
		int is_createWindow;
		LPCREATESTRUCT lpcswnd;
	case WM_CREATE://ウィンドウが作成されたときの処理
		lpcswnd = (LPCREATESTRUCT)lparam;//ウィンドウ作成時の構造体を取得する
		is_createWindow = MessageBox(hwnd, TEXT("ウィンドウを作成しますか？"), lpcswnd->lpszName, MB_YESNO | MB_ICONQUESTION);//ウィンドウを作成するかどうかを尋ねる
		if (is_createWindow == IDYES) return 0;//ウィンドウを作成する
		else return -1;//ウィンドウを作成しない
	case WM_CLOSE://ウィンドウが閉じられたときの処理
		return 0;//ウィンドウを閉じないようにする
	case WM_RBUTTONDOWN://右クリックされたときの処理 右クリックしたときにウィンドウを破棄する
		DestroyWindow(hwnd);//ウィンドウを破棄する
		PostQuitMessage(0);//メッセージキューに終了メッセージを送る
		return 0;
	/*case WM_DESTROY:
		MessageBox(hwnd, TEXT("これで終わりだ！！"), TEXT("kitty"), MB_ICONINFORMATION);
		PostQuitMessage(0);//メッセージキューに終了メッセージを送る
		return 0;*/
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
	wc.style = CS_HREDRAW | CS_VREDRAW;//ウィンドウクラスの基本クラスの指定
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
			WS_OVERLAPPEDWINDOW| WS_VISIBLE,
			CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT,//ウィンドウの位置とサイズをデフォルトにする
			NULL, NULL,//親ウィンドウとメニューハンドルを指定しない
			hinstance, NULL
		);
		MSG msg;//メッセージ構造体
	//メッセージループ
		if (hwnd == NULL)return 0;	
		while (	GetMessage(&msg, NULL, 0, 0))//メッセージを取得する受け取るメッセージは制限しない
			DispatchMessage(&msg);//メッセージを処理する
		return msg.wParam;
}