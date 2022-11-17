import pyautogui as pag
import random
import time

try:
    while True:
        iters = random.randint(3, 7)
        cont = 0
        while cont < iters:
            cont+= 1
            x = random.randint(200,1000)
            y = random.randint(200,700)
            speed = random.uniform(0.5, 0.8)
            wait = random.uniform(1, 2)
            pag.moveTo(x,y,speed)
            time.sleep(wait)
        
        long_sleep = random.uniform(20, 50)
        time.sleep(long_sleep)
except KeyboardInterrupt:
    print("Have a nice day :)")
    pass