# -*- encoding: utf-8 -*-
'''
@brief Contiene funciones individuales que pueden ser de utilidad.
'''
import pygame
from pygame.locals import *

def load_image(path_file, transparent = False):
	'''
	@brief Carga una imagen y la devuelve
	
	@param path_file ruta de la imagen a cargar.
	@param transparent valor booleano indica si el fondo de la imagen ya es 
	transparente por defecto o no
	'''
	try:
		image = pygame.image.load(path_file)
	except pygame.error, message:
		raise SystemExit, message
	
	image = image.convert_alpha()
	
	if transparent:
		color = image.get_at((0, 0))
		#image.set_colorkey(color,RLEACCEL)
	
	return image
		
