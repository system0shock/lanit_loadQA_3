@echo off

                del *.log /S /Q

                del *.bak /S /Q

                del *.idx /S /Q

                del *.ci  /S /Q

                del *.tmp  /S /Q

                del *.db /S /Q

                del *.pickle /S /Q

                del *.sdf /S /Q

                del *.xml /S /Q

                del *.txt /S /Q

                del *.zip /S /Q

                del combined*.c /S /Q

                del output* /S /Q

                del mdrv* /S /Q

                del options.txt /S /Q

                del pre_cci.c /S /Q

                del replay.har /S /Q

                del shunra.shunra /S /Q

rmdir /s /q result1

rmdir /s /q result2

rmdir /s /q result3

rmdir /s /q data

rd /S /Q DfeConfig

rd /S /Q data

