import pygame

pygame.init()
window = pygame.display.set_mode((640, 480))

robot = pygame.image.load("robot.png")
width = robot.get_width()
height = robot.get_height()

x = 0
y = 0
velocity = 1

clock = pygame.time.Clock()

while True:
    for event in pygame.event.get():
        if event.type == pygame.QUIT:
            exit()

    if x < 640 - width and y == 0:
        window.fill((0, 0, 0))
        window.blit(robot, (x, y))
        pygame.display.flip()
        x += velocity

    if x == 640 - width and y < 480 - height:
        window.fill((0, 0, 0))
        window.blit(robot, (x, y))
        pygame.display.flip()
        y += velocity

    velocity = -velocity
    
    if x > 0 and y == 480 - height:
        window.fill((0, 0, 0))
        window.blit(robot, (x, y))
        pygame.display.flip()
        x += velocity

    if x == 0 and y > 0:
        window.fill((0, 0, 0))
        window.blit(robot, (x, y))
        pygame.display.flip()
        y += velocity

    velocity = -velocity

    clock.tick(240)