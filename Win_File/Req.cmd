@ECHO OFF

START /B pip3 install -r requirements.txt  2>NUL >NUL
echo INSTALLING REQUIREMENTS DO NOT CLOSE THIS WINDOW MANUALLY...
cd ../
echo path= %CD% >>CEO_OSINT/Configuration/Configuration.ini
echo Desktop>CEO_OSINT/Display/Display.txt
