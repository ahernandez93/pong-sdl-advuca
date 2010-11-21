# Rutas
MOTOR_DIR := motor

# Ejecutable
EXE := pong
EXEWIN := pong.exe

# Ficheros fuente del juego
SRC := main.cpp

# Ficheros fuente del motor.
SRC_MOTOR := bola.o imagen.o juego.o marcador.o pong.o
		
# motor_dir + fuentes
SRC_DIR_MOTOR := $(foreach src, $(SRC_MOTOR),$(MOTOR_DIR)/$(src) )

# Objetos
OBJS := $(SRC:%.cpp=%.o)
OBJS_MOTOR := $(SRC_DIR_MOTOR:%.cpp=%.o)

OPTIMIZACION := 3

# Compilador y las opciones 
CXX = gcc
CFLAGS = -pedantic -Wall -pipe -ggdb -I$(MOTOR_DIR) -O$(OPTIMIZACION)
LDFLAGS =  -lSDL -ggdb -lSDL_ttf -lSDL_image
LDWINFLAGS = -lmingw32 -lSDLmain -lSDL -lSDL_ttf -lSDL_image

# Config para make
all: $(EXE)
win32: $(EXEWIN)

# Obtención del ejecutable 
$(EXE): $(OBJS) $(OBJS_MOTOR)
	$(CXX) -o $@ $^ $(LDFLAGS)

$(EXEWIN): $(OBJS) $(OBJS_MOTOR)
	$(CXX) -o $@ $^ $(LDWINFLAGS)

# Limpieza
clean: 
	 $(RM) $(EXE) $(OBJS) $(OBJS_MOTOR) *~ -rf

clean-win32:
	del $(EXEWIN) *.o .\motor\*.o *~

