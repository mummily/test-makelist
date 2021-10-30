@echo off

color 0a

REM 切换为当前路径
cd %~dp0

set /p platform=请输入编译平台(win32 or x64)：

REM 删除%platform%路径
if exist %platform% (
@echo 正在删除平台文件 ==================================================
rmdir /s /q %platform% || GOTO:FAILED
)

REM 创建%platform%路径
mkdir %platform% || GOTO:FAILED

@echo. 
@echo 正在进行CMake编译 =================================================
cmake ./ -B %platform% -A %platform% || GOTO:FAILED

@echo.
@echo 正在生成Debug编译 =================================================
cmake --build %platform% || GOTO:FAILED

@echo.
@echo 正在生成Release编译 ===============================================
REM cmake --build %platform% --config Release || GOTO:FAILED

GOTO:END

:FAILED 失败
color 04
GOTO:END

:END 结束
@echo.
@echo 完成~
@echo on
@pause
