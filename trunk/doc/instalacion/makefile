# Nombre del "proyecto"
NOM=instalacion

# Fuentes 
TEX=${NOM}.tex
# TEX temporal
TEXTTEMP=${TEX}.temp
PDF=${NOM}.pdf 	# Pdf resultado
CTEX=pdflatex 	# Compilador latex

.PHONY: clean clear

# Compilar el tex en pdf
#    La dependencia es el .tex
#    Compilamos dos veces para que haga el índice
$(PDF): $(TEX) 
	$(CTEX) $(TEX)
	$(CTEX) $(TEX)


# Cambiamos el TEX por otro con temporal con la letra GARAMOND
garamond: $(TEX)
	# Añadir letra Garamond
	mv $(TEX) $(TEXTTEMP)
	cat $(TEXTTEMP) | head -n 5 > $(TEX)
	echo '\\usepackage{garamond} \\fontsize{12pt}{15pt} \\selectfont' >> $(TEX)
	cat $(TEXTTEMP) | tail -n +5 >> $(TEX)

# Añadimos letra garamond, compilamos el pdf y devolvemos el TEX original
papel: garamond $(PDF)
	mv $(TEXTTEMP) $(TEX)

# Primero compila y después arranca evince
# para visualizar el pdf del tirón.
view: $(PDF)
	evince $(PDF) &

# Limpia los archivos temporales
clear: 
	rm -rf *.aux *.dvi *.log *.idx *.toc *.out *.temp 

# Limpia todo
clean: clear
	rm -rf *.pdf
