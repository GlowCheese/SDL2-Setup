# SDL2 Setup for Visual Studio 2022

## Prerequisites

1. Install `Visual Studio 2022` in your computer. If you don't have it installed, click [here](https://visualstudio.microsoft.com/vs).
2. Start the `Visual Studio Installer` through your Windows Search. After that, the Installer window appears.
3. Install two packages `Visual Studio Community 2022` (VS IDE) and `Desktop development with C++` (Build Tool).

## Setting up SDL2

1. Download 2 files `SDL2-2.26.2.zip` and `SDL2.Template.zip` from the [release page](https://github.com/GlowCheese/SDL2-Setup/releases).
2. Extract the zipped file `SDL2-src.zip` to your `C:\` folder.

   ##### NOTE: After you extract the file, the location of the folder MUST be `C:\SDL2-2.26.2`. Otherwise it will NOT work.
   
3. Copy the `SDL2.Template.zip` file to `%USERPROFILE%\Documents\Visual Studio 2022\Templates\ProjectTemplates` directory.

## Creating Project

1. Start `Visual Studio 2022`.
2. Click on `Create a new project`.
3. In the right sidebar, select `SDL2 Template` and click `Next`.
4. Change your project's name or location as you wish and click `Create`.
   ###### _After that, the main window of Visual Studio IDE will appears._
5. From the top sidebar, click on `Local Windows Debugger` to execute the project.
   ###### _After a few seconds, a small Pong Game window with will appear._
   ###### _Congratulation! You have successfully created the first working SDL2 project!_
