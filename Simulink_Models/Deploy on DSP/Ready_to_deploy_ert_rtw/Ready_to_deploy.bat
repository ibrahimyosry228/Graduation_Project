cd .

if "%1"=="" ("C:\PROGRA~1\POLYSP~1\R2020a\bin\win64\gmake"  -B -f Ready_to_deploy.mk all) else ("C:\PROGRA~1\POLYSP~1\R2020a\bin\win64\gmake"  -B -f Ready_to_deploy.mk %1)
@if errorlevel 1 goto error_exit

exit 0

:error_exit
echo The make command returned an error of %errorlevel%
exit 1
