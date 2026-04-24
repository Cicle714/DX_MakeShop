/// <summary>
/// CoGフレームワーク
/// Ver 3.1です
/// WinMain()から始まります
/// </summary>
/// <author>N.Hanai</author>
#include <DxLib.h>
#include "App.h"
#include "../Source/Screen.h"
#include "../ImGui/imgui_impl_dxlib.hpp"

#define CoGVersion (3.1)

// プログラムは WinMain から始まります
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	SetGraphMode(Screen::WIDTH, Screen::HEIGHT, 32);
	SetOutApplicationLogValidFlag(FALSE); // ログを出さない

	SetMainWindowText(Screen::WINDOW_NAME);
	SetWindowSizeExtendRate(Screen::WINDOW_EXTEND);
	ChangeWindowMode(Screen::WINDOW_MODE); // Windowモードの場合

	if (DxLib_Init() == -1)		// ＤＸライブラリ初期化処理
	{
		return -1;			// エラーが起きたら直ちに終了
	}
	SetDrawScreen(DX_SCREEN_BACK);
	SetAlwaysRunFlag(TRUE);
	SetUseZBuffer3D(TRUE);
	SetWriteZBuffer3D(TRUE);

	SetHookWinProc([](HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam) -> LRESULT /*CALLBACK*/
		{
			// DxLibとImGuiのウィンドウプロシージャを両立させる
			SetUseHookWinProcReturnValue(FALSE);
			return ImGui_ImplWin32_WndProcHandler(hWnd, msg, wParam, lParam);
		});
	// ImGUI初期化
	IMGUI_CHECKVERSION();
	ImGui::CreateContext();
	ImGuiIO& io = ImGui::GetIO();
	io.ConfigFlags |= ImGuiConfigFlags_DockingEnable;
	io.ConfigFlags |= ImGuiConfigFlags_ViewportsEnable;
	io.Fonts->AddFontFromFileTTF(u8"c:\\Windows\\Fonts\\meiryo.ttc", 18.0f, nullptr, io.Fonts->GetGlyphRangesJapanese());	ImGui_ImplDXlib_Init();

	AppInit();

	int mStartTime = GetNowCount();

	while (true) {
		int cur = GetNowCount();
		if (cur < mStartTime + 16) //120fps対策
			continue;
		mStartTime = cur;

		ImGui_ImplDXlib_NewFrame();
		ImGui::NewFrame();

		AppUpdate();


		if (ProcessMessage() == -1 || AppIsExit())
			break;

		ClearDrawScreen();
		AppDraw();
		ImGui::EndFrame();
		ImGui::Render();

		ImGui_ImplDXlib_RenderDrawData();

		if (ImGui::GetIO().ConfigFlags & ImGuiConfigFlags_ViewportsEnable)
		{
			ImGui::UpdatePlatformWindows();
			ImGui::RenderPlatformWindowsDefault();
		}
		RefreshDxLibDirect3DSetting();

		ScreenFlip();


	}
	AppRelease();
	DxLib_End();				// ＤＸライブラリ使用の終了処理

	return 0;				// ソフトの終了 
}