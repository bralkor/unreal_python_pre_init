<br>

# Unreal Python Pre Init

A UE5 Plugin that adds support for a new Python Startup Script: `pre_init_unreal.py`<br>
Pre Init scripts run **before** the Default Map has been loaded in the Unreal Editor

---
<br>

## The challenge

This is the general order of operations during Unreal Editor Startup:
1) Plugins are mounted
2) Unreal opens the project's default Map file
3) Unreal reopens any cached Editor Utility Widgets from the previous session
4) Python Init Startup runs (any files named `init_unreal.py` are run)

Because Python initializes **last** (after the default Map has loaded and after any
cached Editor Utility Widgets have reopened), <br>
it can result in Blueprint Compiler Errors if any Editor Actors or Widgets rely on Python-generated Blueprint Functions.

---
<br>


## What this Plugin Adds

This plugin adds support for a new Python startup script: `pre_init_unreal.py`

During Editor Startup this Plugin will look for and run any files with this name in the Python Path. <br>
Anywhere you can place `init_unreal.py` you can add a `pre_init_unreal.py` file and it will run during Editor Startup.

Editor Startup now looks something like this:
1) Plugins are mounted
2) Python Pre Init Startup runs (any files named `pre_init_unreal.py` are run)
3) Unreal opens the project's Default Map file
4) Unreal reopens any cached Editor Utility Widgets from the previous session
5) Python Init Startup runs (any files named `init_unreal.py` are run)

<br>

Because this new startup scripts runs before Unreal has opened the Default Map, it is recommended <br>
to still use `init_unreal.py` files for most normal operations as the Editor is in a more stable state. <br>
The recommended use of `pre_init_unreal.py` scripts is to focus on:
- Validating and/or setting up the workspace environment
- Loading external config data that tools might rely on
- Initializing Blueprint Function Libraries

---
<br>

`pre_init_unreal.py` files can be added anywhere that `init_unreal.py` files are supported:

- The **Content/Python** sub-folder in your Project's folder
- The **Content/Python** sub-folder in the main Unreal Engine installation
- The **Content/Python** sub-folder in each enabled Plugin's folder
- The **Documents/UnrealEngine/Python** folder inside your user directory. <br>
  For example, on Windows 10, this is equivalent to `C:/Users/Username/Documents/UnrealEngine/Python`
