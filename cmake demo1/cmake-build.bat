@echo off

color 0a

REM �л�Ϊ��ǰ·��
cd %~dp0

set /p platform=���������ƽ̨(win32 or x64)��

REM ɾ��%platform%·��
if exist %platform% (
@echo ����ɾ��ƽ̨�ļ� ==================================================
rmdir /s /q %platform% || GOTO:FAILED
)

REM ����%platform%·��
mkdir %platform% || GOTO:FAILED

@echo. 
@echo ���ڽ���CMake���� =================================================
cmake ./ -B %platform% -A %platform% || GOTO:FAILED

@echo.
@echo ��������Debug���� =================================================
cmake --build %platform% || GOTO:FAILED

@echo.
@echo ��������Release���� ===============================================
REM cmake --build %platform% --config Release || GOTO:FAILED

GOTO:END

:FAILED ʧ��
color 04
GOTO:END

:END ����
@echo.
@echo ���~
@echo on
@pause
