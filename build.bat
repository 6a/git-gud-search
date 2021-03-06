:: set the path to your visual studio vcvars script, it is different for every version of Visual Studio.
set VS2019TOOLS="C:\Program Files (x86)\Visual Studio Community 2019\VC\Auxiliary\Build\vcvars64.bat"

:: set the name of the output executable
set EXECUTABLE="%~dp0/main.exe"

:: make sure we found them
if not exist %VS2019TOOLS% (
    echo VS 2019 Build Tools are missing!
    exit
)

:: call that script, which essentially sets up the VS Developer Command Prompt
call %VS2019TOOLS%

:: run the compiler with your arguments - exit on error
cl.exe /EHsc /Zi /Fe: main.exe main.cpp || echo. && echo ! Build failed ! && exit /b

:: if the exe exists, run it
if exist %EXECUTABLE% (
    echo.
    echo.
    %EXECUTABLE%
)

exit