@echo off
setlocal 
cd %~dp0
md ..\build\shaders\dx11 2> nul

..\bin\shaderc.exe -f vs_surface_default.sc -o ../build/shaders/dx11/vs_surface_default.bin --platform windows --type vertex --profile vs_4_0
..\bin\shaderc.exe -f fs_surface_default.sc -o ../build/shaders/dx11/fs_surface_default.bin --platform windows --type fragment --profile ps_4_0