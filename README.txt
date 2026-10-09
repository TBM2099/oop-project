====================================================================
FCAI-CU: CS213 Object-Oriented Programming (2026-2027)
Assignment 1 (Part 2) - Image Processing Application (Beast Level)
====================================================================

1. PROJECT OVERVIEW
-------------------
An interactive C++ Image Processing application built with the Qt6
framework and CMake. The application allows users to load images in
various formats (PNG, JPG, BMP), apply 18 different visual filters,
and save the modified results with custom filenames.

2. ACADEMIC & TEAM DETAILS
--------------------------
Faculty: Faculty of Computing and Artificial Intelligence,
         Cairo University (FCAI-CU)
Course: CS213 - Object-Oriented Programming (Semester 1, 2026-2027)
Supervision: Dr. Mohammad El-Ramly

Team Members & Work Breakdown:

- Student 1: Hatem Ahmed [ID: 20253050]
    * Individual Filters: Filter 1 (Grayscale), Filter 5 (Flip),
      Filter 9 (Merge), Filter 13 (Sunlight)
    * Task 4 Contributions:
        - Filter 17 (Skew)

- Student 2: Alaa Al-Deen Nabil [ID: 20253072]
    * Individual Filters: Filter 2 (Black & White), Filter 6 (Rotate),
      Filter 10 (Detect Edges), Filter 14 (Old TV)
    * Task 4 Contributions:
        - GUI-Backend Parameter Matching
        - Function Signature Compatibility Refactoring

- Student 3: Mohammed Mazen [ID: 20253073]
    * Individual Filters: Filter 3 (Invert), Filter 7 (Brightness),
      Filter 11 (Crop), Filter 15 (Purple)
    * Task 4 Contributions:
        - GUI Refactoring & Debugging: Reviewed, modified, and debugged
          C++/Qt code for backend filter constraints and parameter
          matching.
        - System Architecture & UML Design: Authored the full system
          breakdown diagrams and UML Class Diagram.

- Student 4: Mohammed Abdulmalik [ID: 20253081]
    * Individual Filters: Filter 4 (Frame), Filter 8 (Resize),
      Filter 12 (Blur), Filter 16 (Infrared)
    * Task 4 Contributions:
        - Filter 18 (Oil Painting)

- System Integrator: Mohammed Mazen [ID: 20253073]
    * Qt MainWindow Design, CMake Build Setup, System Integration &
      Function Refactoring for GUI.
    * GUI Environment & Build Configuration: Set up Qt6 and CMake
      build environment for cross-platform GUI execution.
    * GUI Architecture: Generated the initial UI framework for the
      application.

3. TOOLS & VERSIONS USED
------------------------
- Language & Standard: C++17
- Compiler: GCC (g++) 16.2.0 (MinGW-w64 UCRT64, via MSYS2)
- Build System: CMake 4.4.4 (minimum required: 3.16) with
  GNU Make 4.4.1 (mingw32-make), "MinGW Makefiles" generator
- GUI Framework: Qt 6.11.2 (Qt6Widgets)
- Image I/O Library: stb_image v2.29 and stb_image_write v1.16
  (stb_image.h & stb_image_write.h) via Image_Class.h
- Editor / IDE: Visual Studio Code with the CMake Tools extension
- Operating System: Windows 11 Pro (10.0.26200)

4. HOW TO SET UP AND RUN THE CODE
----------------------------------
Prerequisites (exact tested versions are listed in Section 3):
- Windows 11 with MSYS2 (UCRT64 environment) installed in C:\msys64.
- GCC (g++) with C++17 support.
- CMake 3.16 or higher.
- GNU Make (mingw32-make).
- Qt 6 with the Qt Widgets module.

Installing the tools (run in an MSYS2 UCRT64 terminal, as one command):
    pacman -S mingw-w64-ucrt-x86_64-toolchain mingw-w64-ucrt-x86_64-cmake mingw-w64-ucrt-x86_64-qt6-base

Add C:\msys64\ucrt64\bin to the Windows PATH, so that the compiler,
CMake and the Qt DLLs are found when building and running.

Important: CMakeLists.txt points to C:/msys64/ucrt64 for the compiler
and for Qt. If MSYS2 is installed in another folder, edit the lines
CMAKE_C_COMPILER, CMAKE_CXX_COMPILER, CMAKE_MAKE_PROGRAM and
CMAKE_PREFIX_PATH at the top of CMakeLists.txt.

Option A: Building via Visual Studio Code (used by the team)
1. Install Visual Studio Code with the 'CMake Tools' extension.
2. Open the project folder (the one that contains CMakeLists.txt).
3. Press Ctrl+Shift+P, choose 'CMake: Select a Kit', and pick the
   GCC kit located in C:\msys64\ucrt64\bin.
4. Press Ctrl+Shift+P and choose 'CMake: Configure'.
5. Click 'Build' in the status bar (or press F7).
6. Run the app with 'CMake: Run Without Debugging' (Ctrl+F5),
   or launch build\QtTest.exe.

Option B: Building via CMake Command Line
1. Open PowerShell or Command Prompt in the project root directory
   (the folder that contains CMakeLists.txt).
2. Configure the project:
       cmake -S . -B build -G "MinGW Makefiles"
3. Build the project:
       cmake --build build
4. Run the application:
       .\build\QtTest.exe

Using the application:
1. Click 'Load Image' and choose a PNG, JPG or BMP file.
2. Select a filter (Filter 1 to Filter 18) from the list and click
   'Apply Selected Filter'. Filters that need input (Frame, Flip,
   Rotate, Brightness, Resize, Merge, Crop, Blur, Skew) ask for it
   in a dialog window.
3. Click 'Save Image' and choose a file name (PNG, JPG or BMP).

Notes:
- The GUI is built entirely in C++ code (MainWindow). No Qt Designer
  or .ui file is used in this project.
- If QtTest.exe fails to start with a missing DLL error, make sure
  C:\msys64\ucrt64\bin is in the PATH, then reopen the terminal.