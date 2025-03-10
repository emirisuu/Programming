import pygame

pygame.init()
window = pygame.display.set_mode((640, 480))

ball = pygame.image.load("ball.png")
width = ball.get_width()
height = ball.get_height()

x = 0
y = 0
velocity_x = 2
velocity_y = 2

clock = pygame.time.Clock()

while True:
    for event in pygame.event.get():
        if event.type == pygame.QUIT:
            exit()

    window.fill((0, 0, 0))
    window.blit(ball, (x, y))
    pygame.display.flip()

    x += velocity_x
    y += velocity_y

    if x + width >= 640:
        velocity_x = -velocity_x
    if y + height >= 480:
        velocity_y = -velocity_y
    if x <= 0:
        velocity_x = -velocity_x
    if y <= 0:
        velocity_y = -velocity_y

    clock.tick(60)
    