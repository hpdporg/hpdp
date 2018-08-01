REM CALL "C:\Program Files (x86)\Microsoft Visual Studio\2017\Community\Common7\Tools\VsDevCmd.bat"
CALL "C:\Program Files (x86)\Microsoft Visual Studio\2017\Community\Common7\Tools\VsDevCmd.bat"
CALL "C:\Program Files (x86)\Microsoft Visual Studio\2017\Community\VC\Auxiliary\Build\vcvarsall.bat" x64
cd src\test
cl /c /I"C:\Users\Qualitest\hpdp\external\googletest\googletest\include" /EHsc /nologo /diagnostics:classic  GTestsEntry.cpp /Fo:"C:\Users\Qualitest\hpdp\build\GTestsEntry.obj"
cd "C:\Users\Qualitest\hpdp\build"
link /LARGEADDRESSAWARE /MACHINE:X64 /DYNAMICBASE /INCREMENTAL GTestsEntry.obj "gmock.lib" "gmock_main.lib" /LIBPATH:"C:\Users\Qualitest\hpdp\external\googletestBuild\googlemock\Release" /LIBPATH:"C:\Users\Qualitest\hpdp\build" 
GTestsEntry