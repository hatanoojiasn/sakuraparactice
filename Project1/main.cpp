#include <windows.h>
int WINAPI WinMain
(
	HINSTANCE hinstance,
	HINSTANCE hPrevInstance,
	LPSTR lpCmdLine,
	int nCmdLine
)
{

	HWND hwnd;//win�n���h��
	WNDCLASS wc;//window�N���X
	//��������E�B���h�E�N���X�̕ϐ���錾���ď���������
	wc.style = CS_HREDRAW && CS_VREDRAW;//�E�B���h�E�N���X�̊�{�N���X�̎w��
	wc.lpfnWndProc = DefWindowProc;//�E�B���h�E�v���\�W����o�^
	wc.cbClsExtra = NULL;
	wc.cbWndExtra = NULL;
	wc.hInstance = hinstance;//�C���X�^���X�n���h����o�^
	wc.hIcon = LoadIcon(NULL, IDI_APPLICATION);//�A���R���̖��O���w�肷��
	wc.hCursor = LoadCursor(NULL,IDC_ARROW);
	wc.hbrBackground = static_cast<HBRUSH>(GetStockObject(WHITE_BRUSH));//�w�i�F�̎w����u���V�̃n���h�����擾����`�Ŏw�肷��
	wc.lpszMenuName = NULL;//�N���X���j���[�̎w��@����͂Ȃ�
	wc.lpszClassName = TEXT("kitty");
	//�����܂łŃE�B���h�E�N���X�̏������I���
//�E�B���h�E�N���X�̃|�C���^��o�^����
	if (!RegisterClass(&wc))return 0;
		//win�n���h��������������
		hwnd = CreateWindow
		(
			TEXT("KITTY"), TEXT("KITTY ON YOUR LAP"),
			WS_OVERLAPPEDWINDOW,
			100, 100, 200, 200, NULL, NULL,
			hinstance, NULL
		);
	//�E�B���h���o��
		ShowWindow(hwnd,SW_SHOW);
		MessageBox(NULL, TEXT(" kitty on your lap")
			, TEXT("kitty"), MB_ICONINFORMATION);
		return 0;

}