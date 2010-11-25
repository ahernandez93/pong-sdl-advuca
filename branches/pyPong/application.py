# -*- encoding: utf-8 -*-

import pygame
import globals
import functions
import game
from pygame.locals import *

class Application:
	'''
	@brief Clase encargada de inicializar pygame y contiene el bucle principal del juego
	'''
	def __init__(self):
		'''
		@brief Inicializa pygame y fija las características básicas de la pantalla
		'''
		pygame.init()
		self.screen = pygame.display.set_mode((globals.SCREEN_WIDTH, globals.SCREEN_HEIGHT))
		pygame.display.set_caption("Pong in pygame");
		self.closing = functions.load_image("media/closing.png")
		self.game = game.Game()
		self.salir = False
		self.n = 0
		self.clock = pygame.time.Clock()
		
	def control_exit(self):
		'''
		@brief Gestiona la salida del juego
		'''
		for event in pygame.event.get():
			if event.type == QUIT:
				print "%s" % ("Closing game...")
				self.salir = True
			if event.type == KEYDOWN and event.key == K_o:
				print "%s" % ("Pulsando el 0")
				pygame.image.save(self.screen, "dump%04d.png" % self.n)
				self.n += 1
		
	def run(self):
		'''
		@brief Ejecuta el bucle principal del juego
		'''
		while not self.salir:
			self.clock.tick(globals.FPS)
			print "%f" % (self.clock.get_fps())
			self.control_exit()
			
			self.game.update()
			self.game.draw(self.screen)
			
			pygame.display.flip()
			
			
