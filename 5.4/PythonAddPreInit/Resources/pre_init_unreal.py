from pathlib import Path
import sys

import unreal

for folder_path in sys.path:
    sys_folder = Path(folder_path)
    for pre_init_file in sys_folder.glob("pre_init_unreal.py"):
        print(f"Running Python Pre-Init script: {pre_init_file}")
        unreal.PythonScriptLibrary.execute_python_command(str(pre_init_file))
