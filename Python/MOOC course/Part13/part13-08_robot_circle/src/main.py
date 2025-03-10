import pygame
import math

pygame.init()
window = pygame.display.set_mode((640, 480))

robot = pygame.image.load("robot.png")
height = robot.get_height()
width = robot.get_width()

class Robot:
    def __init__(self, angle: float):
        self.x = 0
        self.y = 0
        self.angle = angle

clock = pygame.time.Clock()

robots = []

for i in range(10):
    robots.append(Robot(i / 1.6))

while True:
    for event in pygame.event.get():
        if event.type == pygame.QUIT:
            exit()


    window.fill((0, 0, 0))
    for rob in robots:
        rob.x = 320+math.cos(rob.angle)*130-width/2
        rob.y = 240+math.sin(rob.angle)*130-height/2
        window.blit(robot, (rob.x, rob.y))
        pygame.display.flip()
        rob.angle += 0.01
    
    clock.tick(60)