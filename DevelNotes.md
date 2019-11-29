# Devlopers Notes #

## Git ##

	git@vuduo2x:/media/stick01/gitroot/Elektronik/Arduino/TestBed/Project.git
	git@vuduo2:/media/stick01/gitroot/Elektronik/Arduino/TestBed/Project.git$ git --bare init
	
see https://git-scm.com/book/en/v2/Git-on-the-Server-The-Protocols
git@vuduo2x:/media/stick01/gitroot/Elektronik/Arduino/TestBed/Project.git
ssh://git@vuduo2x/media/stick01/gitroot/Elektronik/Arduino/TestBed/Project.git



git@vuduo2:/media/stick01/gitroot/Elektronik/Arduino/TestBed/Project.git$ git --bare init


** git:// ** 
git@vuduo2:/media/stick01/gitroot/Elektronik/Arduino/TestBed/Project.git$ echo > git-daemon-export-ok

Jedzia@pubsiX MINGW64 /e/Projects/Elektronik/Arduino/ATtiny/UVTimer/Software/TestBed/bla (master)
$ git clone git://vuduo2x/Elektronik/Arduino/TestBed/Project.git

isn rotz, da es keine ordentliche safety gibt

--> https://stackoverflow.com/questions/7632454/how-do-you-use-git-bare-init-repository
write access: 
git config receive.denyCurrentBranch ignore

Community edit

git init --bare --shared=group
	
****
better:
login via key
https://devops.ionos.com/tutorials/use-ssh-keys-with-putty-on-windows/
-> D:\Users\Jedzia.pubsiX\.ssh
	
	

## Links involved in the development: ##

Joystick, Arduino, E:\Projects\Elektronik\Arduino\ATtiny\UVTimer\Software\TestBed

https://code.msdn.microsoft.com/DirectInput-Samples-8ac6f5e3/sourcecode?fileId=121930&pathId=1414531679
https://github.com/drewnoakes/joystick
https://stackoverflow.com/questions/9742611/usb-joystick-with-c-and-directinput
https://docs.microsoft.com/en-us/windows/win32/xinput/xinput-and-directinput
https://docs.microsoft.com/en-us/windows/win32/multimedia/joysticks
https://stackoverflow.com/questions/5803953/what-is-a-static-constructor
https://www.arduino.cc/reference/en/language/functions/external-interrupts/attachinterrupt/
https://github.com/vancegroup-mirrors/avr-libc/blob/master/avr-libc/include/avr/sfr_defs.h
https://www.codeproject.com/Articles/543055/Joystick-Driver-Project
https://www.codeproject.com/Articles/26949/Xbox-360-Controller-Input-in-C-with-XInput?msg=2622723#xx2622723xx
https://www.google.de/search?sxsrf=ACYBGNTEG-A5uRJNLQOHFrOM4SWglFtcWg%3A1573571511065&source=hp&ei=t8vKXeSPAZLsrgTfhLrgBg&q=AD9288&oq=AD9288&gs_l=psy-ab.3..0l3j0i30l7.176.1824..4617...0.0..0.97.542.6......0....1..gws-wiz.......35i39.Q4uOP356sJ4&ved=0ahUKEwikx8XX-uTlAhUStosKHV-CDmwQ4dUDCAc&uact=5
https://de.farnell.com/search?st=ad9288
https://de.farnell.com/clare/cpc1008n/relais-solid-state-kontakte/dp/1653755?st=cpc1008
https://www.mouser.de/Analog-Devices-Inc/Semiconductors/Integrated-Circuits-ICs/Data-Converter-ICs/Analog-to-Digital-Converters-ADC/AD9288-Series/_/N-6j74v?P=1yyhn2sZ1yyh4l4
https://www.reichelt.de/dds-waveform-generator-msop-10-ad-9833-brm-p112110.html?&trstct=pos_0
https://www.reichelt.de/ICs-AD-5260-AD-22100/2/index.html?ACTION=2&LA=3&GROUPID=5457
https://www.reichelt.de/index.html?ACTION=446&LA=3&q=optomos;SID=95XXjCkKwQAT4AAB67s8Adacc86ab4a767c0fde0b03232e983e46
https://www.reichelt.de/DC-DC-Wandler-diverse/2/index.html?ACTION=2&LA=2&GROUP=PA34&GROUPID=7247&START=0&OFFSET=100&SHOW=1;SID=95XXjCkKwQAT4AAB67s8Adacc86ab4a767c0fde0b03232e983e46
https://www.reichelt.de/index.html?ACTION=446&LA=446&q=pc817;SID=95XXjCkKwQAT4AAB67s8Adacc86ab4a767c0fde0b03232e983e46
https://de.farnell.com/search/prl/ergebnisse?packaging=cuttape&st=opa356&sort=P_PRICE
http://www.ti.com/product/OPA356
