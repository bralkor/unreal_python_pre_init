print(
    "."
    "\n\t This is a Pre Init Unreal startup script,"
    "\n\t add it to a Project's /Content/Python folder"
    "\n\t and this Plugin will run it before the Default Map opens"
    "\n\t during Editor Startup"
    "\n."
    "\n\t Other supported locations:"
    "\n\t  - The Content/Python sub-folder in the main Unreal Engine installation"
    "\n\t  - The Content/Python sub-folder in each enabled Plugin's folder"
    "\n\t  - The Documents/UnrealEngine/Python folder inside your user directory."
    "\n\t    For example, on Windows 10, this is equivalent to `C:/Users/Username/Documents/UnrealEngine/Python`"
)

# Any variables or functions declared in this file are accessible
# automatically in the Unreal Editor Python Console (such as in the Output Log)
#

pre_init_value = 125


def pre_init_demo():
    print("This function was added to the Python Globals during Python Pre Init")
    print(f"Global Python Variable `pre_init_value` = `{pre_init_value}`")
    print(f"Try changing its value in the Python Console and rerunning this function")
