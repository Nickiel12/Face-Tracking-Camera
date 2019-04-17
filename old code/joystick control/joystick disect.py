import pygame
import logging

logging.basicConfig(level=logging.DEBUG, format= '%(asctime)s - %(levelname)s - %(message)s')    

pygame.init()
 
# Used to manage how fast the screen updates
clock = pygame.time.Clock()

done = False

# Initialize the joysticks
pygame.joystick.init()
    
# -------- Main Program Loop -----------
while done==False:

    pygame.event.get() # User did something

    # Get count of joysticks
    joystick_count = pygame.joystick.get_count()


    logging.debug(joystick_count)    
    # For each joystick:
    for i in range(joystick_count):
        joystick = pygame.joystick.Joystick(i)
        joystick.init()
    
        # Get the name from the OS for the controller/joystick
        name = joystick.get_name()
        logging.debug(name)
        
        # Usually axis run in pairs, up/down for one, and left/right for
        # the other.
        axes = joystick.get_numaxes()

        logging.debug(axes)
        for i in range( axes ):
            axis = joystick.get_axis( i )
            logging.debug(axis)
            
        buttons = joystick.get_numbuttons()
        logging.debug(buttons)

        for i in range( buttons ):
            button = joystick.get_button( i )
            logging.debug(button)
            
        # Hat switch. All or nothing for direction, not like joysticks.
        # Value comes back in an array.
        hats = joystick.get_numhats()

        for i in range( hats ):
            hat = joystick.get_hat( i )


        if joystick.get_button(0) == 1:
            done = True       
    # Limit to 20 frames per second
    clock.tick(20)
pygame.quit ()