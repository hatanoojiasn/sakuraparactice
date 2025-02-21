#include <windows.h>
LRESULT CALLBACK WndProc(HWND hwnd, UINT msg, WPARAM wp, LPARAM lparam)
{
	switch (msg)
	{
		int is_createWindow;
		LPCREATESTRUCT lpcswnd;
	case WM_CREATE://�E�B���h�E���쐬���ꂽ�Ƃ��̏���
		lpcswnd = (LPCREATESTRUCT)lparam;//�E�B���h�E�쐬���̍\���̂��擾����
		is_createWindow = MessageBox(hwnd, TEXT("�E�B���h�E���쐬���܂����H"), lpcswnd->lpszName, MB_YESNO | MB_ICONQUESTION);//�E�B���h�E���쐬���邩�ǂ�����q�˂�
		if (is_createWindow == IDYES) return 0;//�E�B���h�E���쐬����
		else return -1;//�E�B���h�E���쐬���Ȃ�
	case WM_CLOSE://�E�B���h�E������ꂽ�Ƃ��̏���
		return 0;//�E�B���h�E����Ȃ��悤�ɂ���
	case WM_RBUTTONDOWN://�E�N���b�N���ꂽ�Ƃ��̏��� �E�N���b�N�����Ƃ��ɃE�B���h�E��j������
		DestroyWindow(hwnd);//�E�B���h�E��j������
		PostQuitMessage(0);//���b�Z�[�W�L���[�ɏI�����b�Z�[�W�𑗂�
		return 0;
	/*case WM_DESTROY:
		MessageBox(hwnd, TEXT("����ŏI��肾�I�I"), TEXT("kitty"), MB_ICONINFORMATION);
		PostQuitMessage(0);//���b�Z�[�W�L���[�ɏI�����b�Z�[�W�𑗂�
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

	HWND hwnd;//win�n���h��
	WNDCLASS wc;//window�N���X
	//��������E�B���h�E�N���X�̕ϐ���錾���ď���������
	wc.style = CS_HREDRAW | CS_VREDRAW;//�E�B���h�E�N���X�̊�{�N���X�̎w��
	wc.lpfnWndProc = WndProc;//�E�B���h�E�v���\�W����o�^
	wc.cbClsExtra = NULL;
	wc.cbWndExtra = NULL;
	wc.hInstance = hinstance;//�C���X�^���X�n���h����o�^
	wc.hIcon = LoadIcon(NULL, IDI_APPLICATION);//�A�C�R���̖��O���w�肷��
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
			WS_OVERLAPPEDWINDOW| WS_VISIBLE,
			CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT,//�E�B���h�E�̈ʒu�ƃT�C�Y���f�t�H���g�ɂ���
			NULL, NULL,//�e�E�B���h�E�ƃ��j���[�n���h�����w�肵�Ȃ�
			hinstance, NULL
		);
		MSG msg;//���b�Z�[�W�\����
	//���b�Z�[�W���[�v
		if (hwnd == NULL)return 0;	
		while (	GetMessage(&msg, NULL, 0, 0))//���b�Z�[�W���擾����󂯎�郁�b�Z�[�W�͐������Ȃ�
			DispatchMessage(&msg);//���b�Z�[�W����������
		return msg.wParam;
}