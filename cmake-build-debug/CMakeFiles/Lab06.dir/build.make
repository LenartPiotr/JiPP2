# CMAKE generated file: DO NOT EDIT!
# Generated by "NMake Makefiles" Generator, CMake Version 3.20

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:

.SUFFIXES: .hpux_make_needs_suffix_list

# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

#Suppress display of executed commands.
$(VERBOSE).SILENT:

# A target that is always out of date.
cmake_force:
.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

!IF "$(OS)" == "Windows_NT"
NULL=
!ELSE
NULL=nul
!ENDIF
SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "C:\Program Files\JetBrains\CLion 2021.2.2\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\JetBrains\CLion 2021.2.2\bin\cmake\win\bin\cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:\Users\Piotr\CLionProjects\Lab06

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Users\Piotr\CLionProjects\Lab06\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles\Lab06.dir\depend.make
# Include the progress variables for this target.
include CMakeFiles\Lab06.dir\progress.make

# Include the compile flags for this target's objects.
include CMakeFiles\Lab06.dir\flags.make

CMakeFiles\Lab06.dir\src\main.cpp.obj: CMakeFiles\Lab06.dir\flags.make
CMakeFiles\Lab06.dir\src\main.cpp.obj: ..\src\main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\Piotr\CLionProjects\Lab06\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Lab06.dir/src/main.cpp.obj"
	C:\PROGRA~2\MICROS~1\2019\COMMUN~1\VC\Tools\MSVC\1429~1.300\bin\Hostx86\x86\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoCMakeFiles\Lab06.dir\src\main.cpp.obj /FdCMakeFiles\Lab06.dir\ /FS -c C:\Users\Piotr\CLionProjects\Lab06\src\main.cpp
<<

CMakeFiles\Lab06.dir\src\main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Lab06.dir/src/main.cpp.i"
	C:\PROGRA~2\MICROS~1\2019\COMMUN~1\VC\Tools\MSVC\1429~1.300\bin\Hostx86\x86\cl.exe > CMakeFiles\Lab06.dir\src\main.cpp.i @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\Piotr\CLionProjects\Lab06\src\main.cpp
<<

CMakeFiles\Lab06.dir\src\main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Lab06.dir/src/main.cpp.s"
	C:\PROGRA~2\MICROS~1\2019\COMMUN~1\VC\Tools\MSVC\1429~1.300\bin\Hostx86\x86\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoNUL /FAs /FaCMakeFiles\Lab06.dir\src\main.cpp.s /c C:\Users\Piotr\CLionProjects\Lab06\src\main.cpp
<<

CMakeFiles\Lab06.dir\src\node.cpp.obj: CMakeFiles\Lab06.dir\flags.make
CMakeFiles\Lab06.dir\src\node.cpp.obj: ..\src\node.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\Piotr\CLionProjects\Lab06\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/Lab06.dir/src/node.cpp.obj"
	C:\PROGRA~2\MICROS~1\2019\COMMUN~1\VC\Tools\MSVC\1429~1.300\bin\Hostx86\x86\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoCMakeFiles\Lab06.dir\src\node.cpp.obj /FdCMakeFiles\Lab06.dir\ /FS -c C:\Users\Piotr\CLionProjects\Lab06\src\node.cpp
<<

CMakeFiles\Lab06.dir\src\node.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Lab06.dir/src/node.cpp.i"
	C:\PROGRA~2\MICROS~1\2019\COMMUN~1\VC\Tools\MSVC\1429~1.300\bin\Hostx86\x86\cl.exe > CMakeFiles\Lab06.dir\src\node.cpp.i @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\Piotr\CLionProjects\Lab06\src\node.cpp
<<

CMakeFiles\Lab06.dir\src\node.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Lab06.dir/src/node.cpp.s"
	C:\PROGRA~2\MICROS~1\2019\COMMUN~1\VC\Tools\MSVC\1429~1.300\bin\Hostx86\x86\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoNUL /FAs /FaCMakeFiles\Lab06.dir\src\node.cpp.s /c C:\Users\Piotr\CLionProjects\Lab06\src\node.cpp
<<

CMakeFiles\Lab06.dir\src\vector.cpp.obj: CMakeFiles\Lab06.dir\flags.make
CMakeFiles\Lab06.dir\src\vector.cpp.obj: ..\src\vector.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\Piotr\CLionProjects\Lab06\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/Lab06.dir/src/vector.cpp.obj"
	C:\PROGRA~2\MICROS~1\2019\COMMUN~1\VC\Tools\MSVC\1429~1.300\bin\Hostx86\x86\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoCMakeFiles\Lab06.dir\src\vector.cpp.obj /FdCMakeFiles\Lab06.dir\ /FS -c C:\Users\Piotr\CLionProjects\Lab06\src\vector.cpp
<<

CMakeFiles\Lab06.dir\src\vector.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Lab06.dir/src/vector.cpp.i"
	C:\PROGRA~2\MICROS~1\2019\COMMUN~1\VC\Tools\MSVC\1429~1.300\bin\Hostx86\x86\cl.exe > CMakeFiles\Lab06.dir\src\vector.cpp.i @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\Piotr\CLionProjects\Lab06\src\vector.cpp
<<

CMakeFiles\Lab06.dir\src\vector.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Lab06.dir/src/vector.cpp.s"
	C:\PROGRA~2\MICROS~1\2019\COMMUN~1\VC\Tools\MSVC\1429~1.300\bin\Hostx86\x86\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoNUL /FAs /FaCMakeFiles\Lab06.dir\src\vector.cpp.s /c C:\Users\Piotr\CLionProjects\Lab06\src\vector.cpp
<<

CMakeFiles\Lab06.dir\src\ImaginaryNumber.cpp.obj: CMakeFiles\Lab06.dir\flags.make
CMakeFiles\Lab06.dir\src\ImaginaryNumber.cpp.obj: ..\src\ImaginaryNumber.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\Piotr\CLionProjects\Lab06\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/Lab06.dir/src/ImaginaryNumber.cpp.obj"
	C:\PROGRA~2\MICROS~1\2019\COMMUN~1\VC\Tools\MSVC\1429~1.300\bin\Hostx86\x86\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoCMakeFiles\Lab06.dir\src\ImaginaryNumber.cpp.obj /FdCMakeFiles\Lab06.dir\ /FS -c C:\Users\Piotr\CLionProjects\Lab06\src\ImaginaryNumber.cpp
<<

CMakeFiles\Lab06.dir\src\ImaginaryNumber.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Lab06.dir/src/ImaginaryNumber.cpp.i"
	C:\PROGRA~2\MICROS~1\2019\COMMUN~1\VC\Tools\MSVC\1429~1.300\bin\Hostx86\x86\cl.exe > CMakeFiles\Lab06.dir\src\ImaginaryNumber.cpp.i @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\Piotr\CLionProjects\Lab06\src\ImaginaryNumber.cpp
<<

CMakeFiles\Lab06.dir\src\ImaginaryNumber.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Lab06.dir/src/ImaginaryNumber.cpp.s"
	C:\PROGRA~2\MICROS~1\2019\COMMUN~1\VC\Tools\MSVC\1429~1.300\bin\Hostx86\x86\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoNUL /FAs /FaCMakeFiles\Lab06.dir\src\ImaginaryNumber.cpp.s /c C:\Users\Piotr\CLionProjects\Lab06\src\ImaginaryNumber.cpp
<<

CMakeFiles\Lab06.dir\src\triangle.cpp.obj: CMakeFiles\Lab06.dir\flags.make
CMakeFiles\Lab06.dir\src\triangle.cpp.obj: ..\src\triangle.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\Piotr\CLionProjects\Lab06\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/Lab06.dir/src/triangle.cpp.obj"
	C:\PROGRA~2\MICROS~1\2019\COMMUN~1\VC\Tools\MSVC\1429~1.300\bin\Hostx86\x86\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoCMakeFiles\Lab06.dir\src\triangle.cpp.obj /FdCMakeFiles\Lab06.dir\ /FS -c C:\Users\Piotr\CLionProjects\Lab06\src\triangle.cpp
<<

CMakeFiles\Lab06.dir\src\triangle.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Lab06.dir/src/triangle.cpp.i"
	C:\PROGRA~2\MICROS~1\2019\COMMUN~1\VC\Tools\MSVC\1429~1.300\bin\Hostx86\x86\cl.exe > CMakeFiles\Lab06.dir\src\triangle.cpp.i @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\Piotr\CLionProjects\Lab06\src\triangle.cpp
<<

CMakeFiles\Lab06.dir\src\triangle.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Lab06.dir/src/triangle.cpp.s"
	C:\PROGRA~2\MICROS~1\2019\COMMUN~1\VC\Tools\MSVC\1429~1.300\bin\Hostx86\x86\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoNUL /FAs /FaCMakeFiles\Lab06.dir\src\triangle.cpp.s /c C:\Users\Piotr\CLionProjects\Lab06\src\triangle.cpp
<<

# Object files for target Lab06
Lab06_OBJECTS = \
"CMakeFiles\Lab06.dir\src\main.cpp.obj" \
"CMakeFiles\Lab06.dir\src\node.cpp.obj" \
"CMakeFiles\Lab06.dir\src\vector.cpp.obj" \
"CMakeFiles\Lab06.dir\src\ImaginaryNumber.cpp.obj" \
"CMakeFiles\Lab06.dir\src\triangle.cpp.obj"

# External object files for target Lab06
Lab06_EXTERNAL_OBJECTS =

Lab06.exe: CMakeFiles\Lab06.dir\src\main.cpp.obj
Lab06.exe: CMakeFiles\Lab06.dir\src\node.cpp.obj
Lab06.exe: CMakeFiles\Lab06.dir\src\vector.cpp.obj
Lab06.exe: CMakeFiles\Lab06.dir\src\ImaginaryNumber.cpp.obj
Lab06.exe: CMakeFiles\Lab06.dir\src\triangle.cpp.obj
Lab06.exe: CMakeFiles\Lab06.dir\build.make
Lab06.exe: CMakeFiles\Lab06.dir\objects1.rsp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\Users\Piotr\CLionProjects\Lab06\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Linking CXX executable Lab06.exe"
	"C:\Program Files\JetBrains\CLion 2021.2.2\bin\cmake\win\bin\cmake.exe" -E vs_link_exe --intdir=CMakeFiles\Lab06.dir --rc=C:\PROGRA~2\WI3CF2~1\10\bin\100190~1.0\x86\rc.exe --mt=C:\PROGRA~2\WI3CF2~1\10\bin\100190~1.0\x86\mt.exe --manifests -- C:\PROGRA~2\MICROS~1\2019\COMMUN~1\VC\Tools\MSVC\1429~1.300\bin\Hostx86\x86\link.exe /nologo @CMakeFiles\Lab06.dir\objects1.rsp @<<
 /out:Lab06.exe /implib:Lab06.lib /pdb:C:\Users\Piotr\CLionProjects\Lab06\cmake-build-debug\Lab06.pdb /version:0.0 /machine:X86 /debug /INCREMENTAL /subsystem:console  kernel32.lib user32.lib gdi32.lib winspool.lib shell32.lib ole32.lib oleaut32.lib uuid.lib comdlg32.lib advapi32.lib 
<<

# Rule to build all files generated by this target.
CMakeFiles\Lab06.dir\build: Lab06.exe
.PHONY : CMakeFiles\Lab06.dir\build

CMakeFiles\Lab06.dir\clean:
	$(CMAKE_COMMAND) -P CMakeFiles\Lab06.dir\cmake_clean.cmake
.PHONY : CMakeFiles\Lab06.dir\clean

CMakeFiles\Lab06.dir\depend:
	$(CMAKE_COMMAND) -E cmake_depends "NMake Makefiles" C:\Users\Piotr\CLionProjects\Lab06 C:\Users\Piotr\CLionProjects\Lab06 C:\Users\Piotr\CLionProjects\Lab06\cmake-build-debug C:\Users\Piotr\CLionProjects\Lab06\cmake-build-debug C:\Users\Piotr\CLionProjects\Lab06\cmake-build-debug\CMakeFiles\Lab06.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles\Lab06.dir\depend

