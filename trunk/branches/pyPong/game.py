# -*- encoding: utf-8 -*-

import pygame
import functions
import globals

from pong import *
from ball import *
from scoreboard import *

class Game:
	'''
	@brief Encargada de actualizar lógicamente el juego y de mostrar 
	los componentes por pantalla.
	'''
	def __init__(self):
		'''
		@brief Inicializa los componentes basicos del juego
		(fondo, paletas y pelota).
		'''
		self.background = functions.load_image("media/background.png")
		
		#Cargamos los sprite que intervienen en el juego
		
		self.pong_human = Pong()
		self.ball = Ball()
		self.pong_ia = Pong(True)
		self.score_board = Score_Board()
		
	def check_collisions(self):
		'''
		@brief Gestiona las colisiones del juego y las consecuencias que estas
		provocan.
		'''
		if(self.ball.rect.bottom > globals.SCREEN_HEIGHT or self.ball.rect.top < 0):
			self.ball.speedy *= -1		
		if pygame.sprite.collide_mask(self.ball, self.pong_human):
			self.ball.speedx *= -1
			self.score_board.update_puntuation()
		if pygame.sprite.collide_mask(self.pong_ia, self.ball):
			self.ball.speedx *= -1
		if self.ball.rect.right > globals.SCREEN_WIDTH :
			self.ball.original_position()
		elif self.ball.rect.left < 0:
			self.ball.original_position()
			self.score_board.restart_puntuation()

	def update(self):
		'''
		@brief Actualiza logicamente los componentes del juego.
		'''
		self.pong_human.update()
		self.pong_ia.update_ia(self.ball)
		self.ball.update()
		
		self.check_collisions()
	
	def draw(self, screen):
		'''
		@brief Dibuja los componentes en pantalla.
		
		@param screen Superficie destino.
		'''
		screen.blit(self.background, (0, 0))
		self.score_board.draw(screen)
		self.ball.draw(screen)
		self.pong_human.draw(screen)
		self.pong_ia.draw(screen)

