#include "HPDP.h"

#include "Window.h"

using namespace hpdp;

HINSTANCE ghInst;
const LPCTSTR lpClassName = "HPDP";
HWND hDlgCurrent = NULL;

int winWidth = 600;
int winHeight = 300;





int x = 0;
int y = 0;


void onResize(HINSTANCE hInstance) {
	//resizeView(winWidth, winHeight);



}

LRESULT CALLBACK mainWndProc(HWND hwnd, UINT msg, WPARAM wparam, LPARAM lparam) {

	switch (msg) {
	case WM_CREATE:

		break;
	case WM_COMMAND:
		break;
	case WM_ACTIVATE:
		if (0 == wparam) {             // becoming inactive
			hDlgCurrent = NULL;
		}
		else {                         // becoming active
			hDlgCurrent = hwnd;
		}
		return FALSE;
	case WM_SIZE:
		onResize(ghInst);
		break;

	case WM_CLOSE:
		PostQuitMessage(0);
		DestroyWindow(hwnd);
		break;
	case WM_DESTROY:
		PostQuitMessage(0);
		DestroyWindow(hwnd);
		break;
	case WM_QUIT:
		PostQuitMessage(0);
		DestroyWindow(hwnd);
		break;
	default:
		return DefWindowProc(hwnd, msg, wparam, lparam);
	}
	return 0;
}


// Main entry point
int APIENTRY WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nShowCmd) {


	ghInst = hInstance;

	WNDCLASSEX ex;

	ex.cbSize = sizeof(WNDCLASSEX);
	ex.cbClsExtra = 0;
	ex.cbWndExtra = 0;
	ex.hInstance = ghInst;
	ex.style = 0;
	ex.lpszMenuName = NULL;
	ex.hbrBackground = CreateSolidBrush(RGB(255, 255, 255));
	ex.hCursor = LoadCursor(NULL, IDC_ARROW);
	ex.hIcon = LoadIcon(NULL, IDI_APPLICATION);
	ex.hIconSm = LoadIcon(NULL, IDI_APPLICATION);
	ex.lpszClassName = lpClassName;
	ex.style = NULL;
	ex.lpfnWndProc = mainWndProc;

	RegisterClassEx(&ex);

	//ifstream file("C:\\Users\\Lewis\\Desktop\\Tablet.txt", std::ifstream::in|std::ifstream::app);

	//file >> tablet;
	//file.close();
	//parse();
	ofstream file("Debug.txt", std::ofstream::out | std::ofstream::app);
	file << "Uno:";
	file.flush();
	List* listA = newList();
	List* listB = newList();
	newLastItem(listA, listB);
	file << "IndexItem";
	file << (LONGLONG)((ListItem*)listA->indexItem);
	file.flush();
	//listA->index = 3;
	file << "List ind:";
	file.flush();
	file << listA->index;
	file.flush();
	file << "\n";
	file << "Index item:";
	file.flush();
	file << (LONGLONG)((ListItem*)listA->indexItem)->item;
	file << "\n";
	file << "First item:";
	file << (LONGLONG)((ListItem*)listA->firstItem)->item;
	file << "\n";
	resetIndex(listA);
	file << "List ind2:";
	file << listA->index;
	file << "\n";
	file << "List items count:";
	file << listA->itemsCount;
	file << "\n";

	List* listC = (List*)getNextItem(listA);
	file << "Item addressC:";
	file << (LONGLONG)listC;
	file << "\n";
	file << "Item addressb:";
	file << (LONGLONG)listB;
	file << "\n";
	file << "Item addressa:";
	file << (LONGLONG)listA;
	file << "\n";
	file << "Index item:";
	file << (LONGLONG)listA->indexItem;
	file << "\n";

	

	HPDP* hpdp = new HPDP();
	//hpdp->writeHTML(NULL);
	CTrans* cTrans = hpdp->newCTrans();

	Topology* topology = newTopology();
	newShape(topology, TOPOLOGYSHAPE_LETTERS);

	Layout* layout = newLayout();
	newSpaceTopology(layout->space, topology, NULL);
	CHTML* cHTML = new CHTML();
	newLastItem(cHTML->html->layouts, layout);
	
	cTrans->cHTMLList->push_back(cHTML);

	cTrans->expose();

	

	HWND hwnd = CreateWindowEx(NULL, lpClassName, "HPDP",
		WS_CAPTION | WS_SYSMENU | WS_MINIMIZEBOX | WS_MAXIMIZEBOX | WS_SIZEBOX,
		50, 50, winWidth, winHeight, NULL, NULL, ghInst, NULL);

	ShowWindow(hwnd, 5);//nShowCmd);
	ShowCursor(FALSE);
	MSG msg = { 0 };


	while (msg.message != WM_QUIT) {
		if (PeekMessage(&msg, 0, 0, 0, PM_REMOVE)) {
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}
		else {

		}
		//

	}

	return msg.wParam;
}