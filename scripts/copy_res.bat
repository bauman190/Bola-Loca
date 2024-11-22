
set SolutionDir=%~1
set OutDir=%~2

xcopy "%SolutionDir%res" "%OutDir%res" /i /y

copy "%SolutionDir%lib\SFML-2.6.2\dll\*.dll" "%OutDir%" /y