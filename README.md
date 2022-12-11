# Jit Attack

Jit attack is a short 2D top-down zombie survival game created using C++ and the SFML Library. This game is only one level with having a user player and a random spawning zombies that will be trying to stop you.
For more information about SFML you can visit [here](https://www.sfml-dev.org/)

---

## Prerequisits
Before install there are some dependencies that must be installed before so. This game is also made to be able to be able to use across Linux, MacOS and Windows so follwing the tutorials provided will very on the OS you are trying to run this on.

Please follow these links to the tutorial to be able to download the follwing dependencies:
> [here](https://www.youtube.com/watch?v=XEGLsHp2bw0&t=296s)

you can also follow the following documentation for more help.

### Windows

- [SFML 2.5.1 - GCC 7.3.0 MinGW (DW2) 32-bit (for Windows)](https://www.sfml-dev.org/files/SFML-2.5.1-windows-gcc-7.3.0-mingw-32-bit.zip)
- [GCC 7.3.0 MinGW (DW2) 32-bit (for Windows)](https://sourceforge.net/projects/mingw-w64/files/Toolchains%20targetting%20Win32/Personal%20Builds/mingw-builds/7.3.0/threads-posix/dwarf/i686-7.3.0-release-posix-dwarf-rt_v5-rev0.7z/download)
- [Git Bash (for Windows) ](https://git-scm.com/downloads)

### MacOS

- [SFML 2.5.1 - Clang 64-bit](https://www.sfml-dev.org/files/SFML-2.5.1-macOS-clang.tar.gz)
- Command Line Tools / XCode (type "xcode-select --install" in terminal to trigger the installer)

### Linux

- Get SFML 2.5.1 from your distro if it has it, or compile from source

### All

- [Visual Studio Code](https://code.visualstudio.com/download)
- Extensions (install from Extensions panel):
  - [Official C/C++ Extension (0.21.0+)](https://marketplace.visualstudio.com/items?itemName=ms-vscode.cpptools)
  - [Shader languages support for VS Code (Optional Syntax Highlighting)](https://marketplace.visualstudio.com/items?itemName=slevesque.shader)
  - [x86 and x86_64 Assembly (Optional Syntax Highlighting)](https://marketplace.visualstudio.com/items?itemName=13xforever.language-x86-64-assembly)
  - [Studio Icons (Optional Icon Theme)](https://marketplace.visualstudio.com/items?itemName=jtlowe.vscode-icon-theme)

**Note:** You can manage the "Path" environment variable from Windows if you'd like, but I've found sandboxing it in VS Code is better for tracking things like .dll dependencies.

---

## Configuration

At this point, everything you need is installed

1. Open the **sfml-vscode-boilerplate** folder in VS Code.
2. With Main.cpp (or any source file) open, check the lower-right to ensure "Win32/Mac/Linux" is the configuration set (this should be auto-selected by the C++ plugin). If it is not correct, hit **Ctrl+Shift+B** and select **C/Cpp: Select a configuration...** and choose the platform you're working on.
3. At this point you should be able to run a build task (**Ctrl+Shift+B** > **Build & Run**), but it'll be nicer to add keybindings for these tasks so you can build with 1 keypress.
4. Open the .vscode folder and click on the **\_keybindings.json** file. This is not an officially recognized file, but just contains the keybindings you can copy into the actual keybindings.json file.
5. Go into **File** > **Preferences** > **Keyboard Shortcuts** & click on the keybindings.json link at the top.
6. Copy the keybindings into this file. Feel free to change them if you don't like them later.
7. Hit the **F9** key to run the **Build & Run: Release** task. It should run the Makefile, find the compiler, build the Main.cpp into Main.o, and launch the sample SFML app. **Shift+F9** will launch the basic Debug build, and F8 will launch the actual Debugger alongside the Debug build.

---

At this point if you have followed all the steps correctly when trying to build and run the program it should work.

#### Other Sources
These sources were either used as documentation for creating the game or inspirtatoin. Big thank you to the following:

- [SFML](https://www.sfml-dev.org/)
- [SFML Learn](https://www.sfml-dev.org/learn.php)
- [SFML Tutorial](https://www.sfml-dev.org/tutorials/2.5/)
- [SFML API Instructions](https://www.sfml-dev.org/documentation/2.5.1/)
- [VSCode Template](https://github.com/chalet-org/chalet-example-sfml)
- [SFML GitHub](https://github.com/SFML/SFML)
- [C++ Documentation](https://cplusplus.com/doc/)