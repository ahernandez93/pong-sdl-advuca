# -*- encoding: utf-8 -*-

import pygame
import functions
import globals

class Ball(pygame.sprite.Sprite):
	'''
	@brief Representa la bola del juego y su comportamiento.
	'''
	def __init__(self):
		'''
		@brief inicializa los aspectos básicos de la bola.
		'''
		pygame.sprite.Sprite.__init__(self)
		
		self.image = functions.load_image("media/ball.png",True)
		self.rect = self.image.get_rect()
		self.original_position()

	def update(self):
		'''
		@brief Actualiza lógicamente a la bola
		'''
		self.rect.centerx += self.speedx
		self.rect.centery += self.speedy
	
	def draw(self, screen):
		'''
		@brief Dibuja la bola en pantalla
		
		@param screen Superficie destino
		'''
		screen.blit(self.image, self.rect)
		
	def original_position(self):
		'''
		@brief Devuelve la bola al medio del campo
		'''
		self.rect.centerx = globals.SCREEN_WIDTH /2
		self.rect.centery = globals.SCREEN_HEIGHT /2
		self.speedx = -11
		self.speedy = -11
