import pygame
from random import randint

pygame.init()
window = pygame.display.set_mode((640, 480))

robot = pygame.image.load("robot.png")
width = robot.get_width()
height = robot.get_height()
frames = 600
spawn_frames = 600

class Robot:
    def __init__(self):
        self.x = randint(0, 640 - width)
        self.y = 0 - height - randint(0, height * 2)
        self.velocity_x = 0
        self.velocity_y = 1

robots = []




clock = pygame.time.Clock()

while True:
    for event in pygame.event.get():
        if event.type == pygame.QUIT:
            exit()

    if frames == spawn_frames:
        for i in range(randint(3, 5)):
            robots.append(Robot())
        frames = 0
        spawn_frames = randint(180, 600)

    window.fill((0, 0, 0))
    for item in robots:
        window.blit(robot, (item.x, item.y))
        pygame.display.flip()
        item.x += item.velocity_x
        item.y += item.velocity_y
        if item.y + height >= 480:
            item.velocity_y = 0
            if item.x + width / 2 > 320:
                item.velocity_x = 1
            else:
                item.velocity_x = -1
        if item.x <= 0 - width or item.x >= 640:
            robots.remove(item) 
    
    frames += 1
    clock.tick(60)
    
    