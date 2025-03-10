import pygame

pygame.init()
window = pygame.display.set_mode((640, 480))

robot = pygame.image.load("robot.png")
robot1_x = 0 + robot.get_width()
robot1_y = 0 + robot.get_height()
robot2_x = 640 - robot.get_width() * 2
robot2_y = 480 - robot.get_height() * 2

to_left = False
to_right = False
to_up = False
to_down = False

to_a = False
to_d = False
to_w = False
to_s = False

clock = pygame.time.Clock()

while True:
    for event in pygame.event.get():
        if event.type == pygame.KEYDOWN:
            if event.key == pygame.K_LEFT:
                to_left = True
            if event.key == pygame.K_RIGHT:
                to_right = True
            if event.key == pygame.K_UP:
                to_up = True
            if event.key == pygame.K_DOWN:
                to_down = True
            if event.key == pygame.K_a:
                to_a = True
            if event.key == pygame.K_d:
                to_d = True
            if event.key == pygame.K_w:
                to_w = True
            if event.key == pygame.K_s:
                to_s = True
            
        if event.type == pygame.KEYUP:
            if event.key == pygame.K_LEFT:
                to_left = False
            if event.key == pygame.K_RIGHT:
                to_right = False
            if event.key == pygame.K_UP:
                to_up = False
            if event.key == pygame.K_DOWN:
                to_down = False
            if event.key == pygame.K_a:
                to_a = False
            if event.key == pygame.K_d:
                to_d = False
            if event.key == pygame.K_w:
                to_w = False
            if event.key == pygame.K_s:
                to_s = False

        if event.type == pygame.QUIT:
            exit()

    if to_left:
        if robot1_x > 0:  
            robot1_x -= 2
    if to_right:
        if robot1_x < 640 - robot.get_width():
            robot1_x += 2
    if to_up:
        if robot1_y > 0:
            robot1_y -= 2
    if to_down:
        if robot1_y < 480 - robot.get_height():
            robot1_y += 2
    if to_a:
        if robot2_x > 0:  
            robot2_x -= 2
    if to_d:
        if robot2_x < 640 - robot.get_width():
            robot2_x += 2
    if to_w:
        if robot2_y > 0:
            robot2_y -= 2
    if to_s:
        if robot2_y < 480 - robot.get_height():
            robot2_y += 2

    window.fill((0, 0, 0))
    window.blit(robot, (robot1_x, robot1_y))
    window.blit(robot, (robot2_x, robot2_y))
    pygame.display.flip()

    clock.tick(60)