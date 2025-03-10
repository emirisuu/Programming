import pygame
import datetime
import math

pygame.init()
window = pygame.display.set_mode((640, 480))

frames = pygame.time.Clock()
seconds_for_angle = datetime.datetime.now()
seconds_for_angle = int(seconds_for_angle.strftime("%S"))
seconds_for_angle = f"{(seconds_for_angle / 9.554):.2f}"
minutes_for_angle = datetime.datetime.now()
minutes_for_angle = int(minutes_for_angle.strftime("%M"))
minutes_for_angle = f"{(minutes_for_angle / 9.554):.2f}"
hours_for_angle = datetime.datetime.now()
hours_for_angle = int(hours_for_angle.strftime("%I"))
hours_for_angle = 1.57 / 3 * hours_for_angle + float(minutes_for_angle) / 60
angle_s = 4.71 + float(seconds_for_angle)
angle_m = 4.71 + float(minutes_for_angle)
angle_h = 4.71 + hours_for_angle

while True:
    for event in pygame.event.get():
        if event.type == pygame.QUIT:
            exit()

    time_now = datetime.datetime.now()
    time_now = time_now.strftime("%X")
    pygame.display.set_caption(time_now)

    window.fill((0, 0, 0))
    pygame.draw.circle(window, (255, 0, 0), (320, 240), 10)
    pygame.draw.circle(window, (255, 0, 0), (320, 240), 200, 5)

    
    
    seconds_x = 320 + math.cos(angle_s) * 180
    seconds_y = 240 + math.sin(angle_s) * 180
    minutes_x = 320 + math.cos(angle_m) * 180
    minutes_y = 240 + math.sin(angle_m) * 180
    hours_x = 320 + math.cos(angle_h) * 150
    hours_y = 240 + math.sin(angle_h) * 150
    
    angle_s += 0.10467
    angle_m += 0.0017445
    angle_h += 0.000145375
    pygame.draw.line(window, (0, 0, 255), (320, 240), (seconds_x, seconds_y), 1)
    pygame.draw.line(window, (0, 0, 255), (320, 240), (minutes_x, minutes_y), 2)
    pygame.draw.line(window, (0, 0, 255), (320, 240), (hours_x, hours_y), 5)
    pygame.display.flip()

    frames.tick(1)
    