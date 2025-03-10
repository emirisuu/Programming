import pygame

pygame.init()
window = pygame.display.set_mode((640, 480))

robot = pygame.image.load("robot.png")
x = 640
y = 480

clock = pygame.time.Clock()

while True:
    for event in pygame.event.get():
        if event.type == pygame.MOUSEMOTION:
            x = 0 + event.pos[0] - robot.get_width() / 2
            y = 0 + event.pos[1] - robot.get_height() / 2
        if event.type == pygame.QUIT:
            exit()

    window.fill((0, 0, 0))
    window.blit(robot, (x, y))
    pygame.display.flip()

    clock.tick(60)
