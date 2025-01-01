#include "PythonAddPreInit.h"
#include "IPythonScriptPlugin.h"

#define LOCTEXT_NAMESPACE "FPythonAddPreInitModule"

void FPythonAddPreInitModule::StartupModule()
{
	RunPreInitScripts();
}

void FPythonAddPreInitModule::ShutdownModule()
{
}

void FPythonAddPreInitModule::RunPreInitScripts() const
{
    // Python code to look for and run any pre_init_unreal.py files it finds
    FString PreInitScript = TEXT(
        "from pathlib import Path\n"
        "import sys\n"
        "import unreal\n"
        "for folder_path in sys.path:\n"
        "    sys_folder = Path(folder_path)\n"
        "    for pre_init_file in sys_folder.glob('pre_init_unreal.py'):\n"
        "        print(f'Running Python Pre Init script: {pre_init_file}')\n"
        "        unreal.PythonScriptLibrary.execute_python_command(str(pre_init_file))"
    );

    UE_LOG(LogInit, Log, TEXT("Running Python Pre Init scripts (any files named /pre_init_unreal.py)"));

    auto& PythonModule = FModuleManager::LoadModuleChecked<IPythonScriptPlugin>("PythonScriptPlugin");
    PythonModule.ExecPythonCommand(*PreInitScript);
}

#undef LOCTEXT_NAMESPACE

IMPLEMENT_MODULE(FPythonAddPreInitModule, PythonAddPreInit)
