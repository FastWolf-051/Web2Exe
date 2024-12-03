# Web2Exe
An tiny HTML to exe converter (221kb so far)
Created in 06.10.2024
# About project
This tool is created to convert your web app (html/css/js) to exe
Avaliable only for windows platform
This tool created with WINAPI and WebView2 library (from nuget)
If you want to rewrite my idea to another programming language,
Write that orignal idea created by me(fastwolf) and updated/rewrited by you 
(example in copyright.txt)
# What is "stuff/compdat.cmp" ?
this file is an result of special-compiling an html/css/js together, without this file your app can't run
(compiling method created by me)
# What is "../output.exe.WebView2" ?
This folder with app cache, you can delete it after using the app
# How to use
1) Download archive
2) if you want, extract it (it maybe can works in archive)
3) Open folder "/bin"
4) put your the index.html and/or style.csss and/or script.js in this folder
5) start the executable (if nothing displays, restart the exe or rename source files)
   (index.html, style.css, script.js)
6) to hide cmd at startup, look in "/bin/stuff/config.txt" file and change 0 to 1 in showCMDonStartup
7) that's all