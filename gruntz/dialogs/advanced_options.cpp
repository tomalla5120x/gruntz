#include "advanced_options.h"

#include "../globals.h"
#include "../../resources/resource.h"
#include "../../utils/registry_helper.h"

namespace GruntzDialogs
{
	namespace
	{
		//@address: 0062a530
		//@address: 0040af60 (dynamic initializer)
		//@address: 0040afa0 (dynamic destructor)
		Utils::RegistryHelper advanced_options_registry_helper;

		void LoadOptions(HWND hWnd, Utils::RegistryHelper* pRegistryHelper)
		{
			//@address: 0040b1c0
			if(pRegistryHelper == nullptr)
				return;

			CheckDlgButton(hWnd, IDC_CONFIG_ADVANCED_DISABLE_VIDEO, pRegistryHelper->GetValueDword("Disable Direct Video Access", 0));
			CheckDlgButton(hWnd, IDC_CONFIG_ADVANCED_DISABLE_AUDIO, pRegistryHelper->GetValueDword("Disable Audio", 0));
			CheckDlgButton(hWnd, IDC_CONFIG_ADVANCED_DISABLE_SOUND, pRegistryHelper->GetValueDword("Disable Sound", 0));
			CheckDlgButton(hWnd, IDC_CONFIG_ADVANCED_DISABLE_MUSIC, pRegistryHelper->GetValueDword("Disable Music", 0));
			CheckDlgButton(hWnd, IDC_CONFIG_ADVANCED_DISABLE_MOVIE, pRegistryHelper->GetValueDword("Disable High Quality Movie", 0));
		}

		void SetDefaults(HWND hWnd)
		{
			//@address: 0040b170
			CheckDlgButton(hWnd, IDC_CONFIG_ADVANCED_DISABLE_VIDEO, BST_UNCHECKED);
			CheckDlgButton(hWnd, IDC_CONFIG_ADVANCED_DISABLE_AUDIO, BST_UNCHECKED);
			CheckDlgButton(hWnd, IDC_CONFIG_ADVANCED_DISABLE_SOUND, BST_UNCHECKED);
			CheckDlgButton(hWnd, IDC_CONFIG_ADVANCED_DISABLE_MUSIC, BST_UNCHECKED);

			//@note: the checkbox for disabling the high quality movies is unaffected
		}

		void SaveOption(HWND hWnd, Utils::RegistryHelper* pRegistryHelper, char* szValueName, DWORD controlId)
		{
			//@address: 0040b120
			if(hWnd == NULL || szValueName == nullptr || pRegistryHelper == nullptr)
				return;

			pRegistryHelper->SetValueDword(szValueName, IsDlgButtonChecked(hWnd, controlId));
		}

		void SaveOptions(HWND hWnd, Utils::RegistryHelper* pRegistryHelper)
		{
			//@address: 0040b280
			if(pRegistryHelper == nullptr)
				return;

			SaveOption(hWnd, pRegistryHelper, "Disable Direct Video Access", IDC_CONFIG_ADVANCED_DISABLE_VIDEO);
			SaveOption(hWnd, pRegistryHelper, "Disable Audio", IDC_CONFIG_ADVANCED_DISABLE_AUDIO);
			SaveOption(hWnd, pRegistryHelper, "Disable Sound", IDC_CONFIG_ADVANCED_DISABLE_SOUND);
			SaveOption(hWnd, pRegistryHelper, "Disable Music", IDC_CONFIG_ADVANCED_DISABLE_MUSIC);
			SaveOption(hWnd, pRegistryHelper, "Disable High Quality Movie", IDC_CONFIG_ADVANCED_DISABLE_MOVIE);
		}

		INT_PTR CALLBACK AdvancedOptionsDialogProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
		{
			//@address: 0040afc0
			if(message == WM_INITDIALOG)
			{
				advanced_options_registry_helper.Close();
				advanced_options_registry_helper.Open("Monolith Productions", "Gruntz", "1.0", nullptr, HKEY_LOCAL_MACHINE, nullptr);

				LoadOptions(hWnd, &advanced_options_registry_helper);

				HICON hIcon = LoadIconA(Globals::game_instance, "GRUNTZ");
				if(hIcon != NULL)
					SendMessageA(hWnd, WM_SETICON, ICON_BIG, (LPARAM)hIcon);

				if(IsIconic(hWnd))
					ShowWindow(hWnd, SW_RESTORE);

				SetForegroundWindow(hWnd);
				BringWindowToTop(hWnd);
				return true;
			}

			if(message == WM_COMMAND)
			{
				if(wParam == IDC_CONFIG_ADVANCED_CANCEL)
				{
					EndDialog(hWnd, 0);
					return true;
				}

				if(wParam == IDC_CONFIG_ADVANCED_OK)
				{
					SaveOptions(hWnd, &advanced_options_registry_helper);
					EndDialog(hWnd, 1);
					return true;
				}

				if(wParam == IDC_CONFIG_ADVANCED_DEFAULTS)
				{
					SetDefaults(hWnd);
					return true;
				}
			}

			return false;
		}
	}

	bool ShowAdvancedOptions()
	{
		//@address: none
		return(DialogBoxParamA(Globals::game_instance, "CONFIG_ADVANCED", NULL, &AdvancedOptionsDialogProc, 0) != 0);
	}
}