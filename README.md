<br>

# Unreal Python Pre Init

A UE5 Plugin that adds support for a new Python Startup Script: `pre_init_unreal.py`<br>
Pre Init scripts run **before** the Default Map has been loaded in the Unreal Editor<br>
Functions and Variables declared in a `pre_init_unreal.py` file will be added to the Python Globals

---
<br>

# Quick Setup Guide

With this Plugin enabled, here is a quick setup guide to use the plugin:

1) In an Unreal Project, add the following folder if it does not already exist:
   1) `/Content/Python`
2) In our Unreal Project's `/Content/Python` folder we can now create the following file:
   2) `pre_init_unreal.py`
3) Any Python code placed in this file will run before the Default Map has been loaded during Editor Startup

---
<br>


# How This Plugin Works

This plugin adds support for a new Python startup script: `pre_init_unreal.py`

During Editor Startup this Plugin will look for and run any files with this name in the Python Path. <br>
Anywhere you can place `init_unreal.py` you can add a `pre_init_unreal.py` file and it will run during Editor Startup.

<br>

With this Plugin, Editor startup now looks something like this:
1) Plugins are mounted
2) Python Pre Init Startup runs (any files named `pre_init_unreal.py` are run)
3) Unreal opens the project's Default Map file
4) Unreal reopens any cached EUWs (Editor Utility Widgets) from the previous session
5) Python Init Startup runs (any files named `init_unreal.py` are run)
6) Any Functions or Variables declared in a `init_unreal.py` file will be added to the Python Globals

This grants us the ability to run Python scripts before the Default Map opens or any cached EUWs reopen.
A common example is for Python-generated Blueprint Function Libraries, this allows us to safely import them
before any cached EUWs reopen during Editor Startup.

---
<br>


# Where a pre_init_unreal.py file can be added

`pre_init_unreal.py` files can be added anywhere that `init_unreal.py` files are supported:

- The **Content/Python** sub-folder in your Project's folder
- The **Content/Python** sub-folder in the main Unreal Engine installation
- The **Content/Python** sub-folder in each enabled Plugin's folder
- The **Documents/UnrealEngine/Python** folder inside your user directory. <br>
  For example, on Windows 10, this is equivalent to `C:/Users/Username/Documents/UnrealEngine/Python`

---
<br>


# Recommended Use

The init_unreal.py file is still recommended for most standard startup scripts 
as the Editor is in a more complete state. 

The pre_init_unreal.py file is recommended for tasks such as:
- Validating and/or setting up the workspace environment
- Loading external config data that tools might rely on
- Initializing Blueprint Function Libraries

There really isn't a limitation on what it can run, I just find that it works best when 
focused on ensuring your Python-sourced environment is set up correctly before the 
Default Map / any Editor Utility Widgets have loaded.