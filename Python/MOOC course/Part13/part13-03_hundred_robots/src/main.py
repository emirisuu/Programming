import pygame

pygame.init()

window = pygame.display.set_mode((640, 480))
robot = pygame.image.load("robot.png")
width = robot.get_width() - 10
height = robot.get_height()

window.fill((0, 0, 0))
window_height = 0
window_width = 0
for i in range(1, 11):
    for j in range(1, 11):
        window.blit(robot, (window_width + width * j, window_height + height))
    window_height += 20
    window_width += 10
pygame.display.flip()

while True:
    for event in pygame.event.get():
        if event.type == pygame.QUIT:
            exit()