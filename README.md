## 3hr Electric Skate Code/Build with SimpleFOC using b-g431b-esc1 stm32 discovery kit for drones

I'm using this [b-g431b-esc1](https://www.st.com/en/evaluation-tools/b-g431b-esc1.html) discovery kit to drive and control an electric BLDC motor with hallsensors.  It uses SimpleFOC in closed loop voltage mode.

This is the code that accompanies my 3hr code/build video.  It's not identical, it has more debug code and some motor calibration to help with different motors:

[![3hr Electric Skate Code/Build with SimpleFOC](http://img.youtube.com/vi/BfrIjmR5qrM/0.jpg)]
(https://youtu.be/BfrIjmR5qrM)

Please note that this board at time of writing needs a couple of Pull Requests to be approved to be 'easy' to use from platformio and Arduino IDE:

https://github.com/stm32duino/Arduino_Core_STM32/pull/1236 - this will add the board to the stm32duino board manager list.  If you have added stm32duino as a board manager and this PR has been approved you should see it in the list of boards within Arduino

https://github.com/platformio/platform-ststm32/pull/447 - this adds extra info required by platformio to find use the board.

Of lesser importance - I managed to get breakpoint debugging to work for stm32g4 boards like this one, again this needs another PR to be approved before it becomes easy from platformio:
https://sourceforge.net/p/openocd/code/merge-requests/16/

## STM32 datasheet
The stm32 user manual for this board is excellent:
https://www.st.com/resource/en/user_manual/dm00564746-electronic-speed-controller-discovery-kit-for-drones-with-stm32g431cb-stmicroelectronics.pdf

Some pics from the manual
[b-g431b-esc1 discovery-kit](b-g431b-esc1-discovery-kit.png) [b-g431b-esc1 drone x4](b-g431b-esc1-drone_x4.png) [b-g431b-esc1 hall sensors](b-g431b-esc1-hall-sensor.png) [b-g431b-esc1 pwm](b-g431b-esc1-pwm.png) [b-g431b-esc1 shunt and opamp](b-g431b-esc1-shunt.png)

## Board with Duct tape
[skate](skate-static.jpg)