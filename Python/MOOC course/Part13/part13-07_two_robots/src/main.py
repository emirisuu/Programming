import pygame

pygame.init()
window = pygame.display.set_mode((640, 480))

robot = pygame.image.load("robot.png")
height = robot.get_height()
width = robot.get_width()

class Robot:
    def __init__(self, velocity: int):
        self.x = 0
        self.y = 0
        self.velocity = velocity

clock = pygame.time.Clock()

robot1 = Robot(1)
robot2 = Robot(2)

while True:
    for event in pygame.event.get():
        if event.type == pygame.QUIT:
            exit()

    window.fill((0, 0, 0))
    window.blit(robot, (robot1.x, robot1.y + height))
    window.blit(robot, (robot2.x, robot2.y + height * 2))
    robot1.x += robot1.velocity
    robot2.x += robot2.velocity
    
    pygame.display.flip()

    if robot1.x + width >= 640:
        robot1.velocity = -robot1.velocity
    if robot1.x <= 0:
        robot1.velocity = -robot1.velocity

    if robot2.x + width >= 640:
        robot2.velocity = -robot2.velocity
    if robot2.x <= 0:
        robot2.velocity = -robot2.velocity

    clock.tick(60)
