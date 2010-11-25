# -*- encoding: utf-8 -*-

import pygame
import globals

class Score_Board:
    '''
    @brief Gestiona el marcador de juego
    '''
    def __init__(self):
        '''
        @brief Inicializa los componentes del marcador
        '''
        self.font = pygame.font.Font("media/scoreboard.ttf", 30);
        self.human_score = 0
        self.best_score = 0
        self.color = (255, 255, 255)
        self.points_surface = self.font.render("Actual: " + str(self.human_score) \
                                + "      Mejor: " + str(self.best_score), True, self.color)
        self.rect_points = self.points_surface.get_rect()
    
    def draw(self, screen):
        '''
        @brief Dibuja el marcador en pantalla
        
        @param screen Superficie destino
        '''
        self.rect_points.centerx = (globals.SCREEN_WIDTH / 2) - 30
        self.rect_points.centery = 50
        screen.blit(self.points_surface, self.rect_points)
    
    def update_puntuation(self):
        '''
        @brief Actualiza la puntuación del marcador
        '''
        self.human_score += 1
        if self.human_score > self.best_score:
            self.best_score = self.human_score
        
        self.__update_points_surface()
        
    
    def restart_puntuation(self):
        '''
        @brief Reinicia la puntuacion del jugador en el tablero
        '''
        self.human_score = 0 
        self.__update_points_surface()
    
    def __update_points_surface(self):
        self.points_surface = self.font.render("Actual: " + str(self.human_score) \
                                + "      Mejor: " + str(self.best_score), True, self.color)
        self.rect_points = self.points_surface.get_rect()
        
