# SDL2 Setup for Visual Studio 2022

## Prerequisites

1. Install `Visual Studio 2022` in your computer. If you don't have it installed, click [here](https://visualstudio.microsoft.com/vs).
2. Start the `Visual Studio Installer` through your Windows Search. After that, the Installer window popup appears.
3. Select `Visual Studio Community 2022` (the core IDE of VS) and `Desktop development with C++` (Build Tool for C++ project) for them to be installed.

## Setting up SDL2

1. Go to the [release page](https://github.com/GlowCheese/SDL2-VS-Setup/releases) of SDL2-Setup and download 2 files: `SDL2-2.26.2.zip` and `SDL2.Template.zip`.
2. Extract the zipped file `SDL2-src.zip` to your `C:\` folder.

   **After you extract the file, check the location of the folder should be `C:\SDL2-2.26.2`. Otherwise it won't work**.
   
3. Copy the compressed file `SDL2.Template.zip` to the folder `%USERPROFILE%\Documents\Visual Studio 2022\Templates\ProjectTemplates`.

## Creating Project

1. Start `Visual Studio 2022`.
2. Select `Create a new project`.
3. From the right sidebar, select `SDL2 Template` and click `Next`.
4. Modify the project's name or location as you want and click `Create`. After that, the main window of `VS IDE` will appears.
5. From the top sidebar, click on `Local Windows Debugger` to check if the project is working properly.
6. After a few seconds, if a window popups with an orange background then congratulation! You have successfully created the first working SDL2 project!
