@echo off
call "C:\Program Files (x86)\Microsoft Visual Studio\2022\BuildTools\VC\Auxiliary\Build\vcvars64.bat"
cl /EHsc /std:c++17 src\main.cpp /I"lib\SFML-3.0.0\include" /link /LIBPATH:"lib\SFML-3.0.0\lib" sfml-graphics.lib sfml-window.lib sfml-system.lib