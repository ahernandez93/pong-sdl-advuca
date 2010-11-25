# -*- encoding: utf-8 -*-

import pygame
import functions
import globals
from pygame.locals import *

class Pong(pygame.sprite.Sprite):
	'''
	@brief Representa las paletas del juego, tanto la controlada por el jugados,
	como la controlada por la ia.
	'''
	def __init__(self, ia = False):
		'''
		@brief Inicializa los básicos de la bola, como la imagen, velocidad...
		
		@param ia boleano que indica si la paleta sera controlada por el jugador
		o por la ia.
		'''
		pygame.sprite.Sprite.__init__(self)
		self.speed = 12

		if ia:
			self.image = functions.load_image("media/pong2.png",True)
			self.rect = self.image.get_rect()
			self.rect.centerx =  globals.SCREEN_WIDTH - 25

		else:
			self.image = functions.load_image("media/pong.png",True)
			self.rect = self.image.get_rect()
			self.rect.centerx = 25
					
		self.rect.centery = globals.SCREEN_HEIGHT / 2
	
	def update(self):
		'''
		@brief Actualiza la paleta del jugador según la entrada.
		'''
		controls = pygame.key.get_pressed()
		
		if controls[K_UP]:
			self.rect.centery -= self.speed
			self.screen_control()
			
		elif controls[K_DOWN]:
			self.rect.centery += self.speed
			self.screen_control()
	
	def update_ia(self, ball):
		'''
		@brief Actualiza la paleta controlada por la ia, segun la posición de la bola.
		
		@param ball referencia de la bola
		'''
		if ball.speedx > 0 and ball.rect.top + 10 < self.rect.centery: #Si la bola va hacia nuesto lado
			self.rect.centery -= self.speed
			self.screen_control()
		elif ball.speedx > 0 and ball.rect.top - 10 > self.rect.centery:
			self.rect.centery += self.speed
			self.screen_control()
	
		elif ball.rect.y - 10 > self.rect.y + self.rect.h/2:
			if (ball.rect.x > self.rect.x and ball.speedx < 0) or (ball.rect.x < self.rect.x and ball.speedx > 0):
				self.rect.centery += self.speed

	def screen_control(self):
		'''
		@brief Controla que las paletas no se salgan de los limites de la pantalla
		'''
		if self.rect.top < 0:
			self.rect.top = 0
		elif self.rect.bottom > globals.SCREEN_HEIGHT:
			self.rect.bottom = globals.SCREEN_HEIGHT
					
	def draw(self, screen):
		'''
		@brief Dibuja la paleta en la pantalla.
		
		@param screen Supercifie destino.
		'''
		screen.blit(self.image,self.rect)
		
'''def update_ia(self, ball):
		if ball.speedx > 0 and ball.rect.top + 10 < self.rect.centery: #Si la bola va hacia nuesto lado
			self.rect.centery -= self.speed
			self.screen_control()
		elif ball.speedx > 0 and ball.rect.top - 10 > self.rect.centery:
			self.rect.centery += self.speed
			self.screen_control() 
			
	def update_ia(self, ball):
		if ball.rect.y + 10 < self.rect.y + self.rect.h/2:
			if (ball.rect.x > self.rect.x and ball.speedx < 0) or (ball.rect.x < self.rect.x and ball.speedx > 0):
				self.rect.centery -= self.speed
				#pong->y -= pong->vy;
				'''
