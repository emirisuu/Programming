import pygame
from random import randint

pygame.init()
window = pygame.display.set_mode((640, 480))

robot = pygame.image.load("robot.png")
x = randint(0, 640 - robot.get_width())
y = randint(0, 480 - robot.get_height())

clock = pygame.time.Clock()

while True:
    for event in pygame.event.get():
        if event.type == pygame.MOUSEBUTTONDOWN:
            if event.pos[0] >= x and event.pos[0] <= x + robot.get_width() and event.pos[1] >= y and event.pos[1] <= y + robot.get_height():
                x = randint(0, 640 - robot.get_width())
                y = randint(0, 480 - robot.get_height())
        if event.type == pygame.QUIT:
            exit()

    window.fill((0, 0, 0))
    window.blit(robot, (x, y))
    pygame.display.flip()

    clock.tick(60)