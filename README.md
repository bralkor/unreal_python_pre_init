<br></br>

<h2 align="center">Unreal Python Pre Init</h2>

<p align="center">
A UE5 Plugin that adds support for pre_init_unreal.py files,<br>
startup scripts that run much earlier in the Unreal Startup process
</p>



## The problem

This is the general order of events during Editor Startup:
1) Plugins are mounted
2) Unreal opens the project's default Map file
3) Unreal reopens any cached Editor Utility Widgets from the previous session
4) Python Init Startup runs (any files named `init_unreal.py` are run)

The problem is that Python initializes **last**: after the default Map has loaded and after any 
cached Editor Utility Widgets have reopened. If an Editor Actor or Widget relying on Python-generated
BP Nodes loads before Python has been initialized it will result in Blueprint Compiler errors.

<br>

---

## What this Plugin Adds

This plugin adds support for a new Python startup script: `pre_init_unreal.py`

During Editor Startup this Plugin will look for and run any files with this name in the Python Path. Anywhere you
can place `init_unreal.py` you can add a `pre_init_unreal.py` file, and it will run during Editor Startup.

Editor Startup now looks something like this:
1) Plugins are mounted
2) Python Pre Init Startup runs (any files named `pre_init_unreal.py` are run)
3) Unreal opens the project's Default Map file
4) Unreal reopens any cached Editor Utility Widgets from the previous session
5) Python Init Startup runs (any files named `init_unreal.py` are run)

<br>

I would still recommend using `init_unreal.py` for most normal startup operations as they run near the end of the
startup process (Editor is more stable / almost ready for the user). For the `pre_init_unreal.py` scripts I would
recommend focusing on prerequisite tasks such as:
- Initializing Blueprint Function Libraries
- Validating the workspace environment
- Loading external config data tools might rely on


