all: slides

slides: slides.tex
	xelatex slides.tex
	biber slides
	xelatex $< -o slides.pdf
	rm -f *.aux *.snm *.toc *.log *.nax *.out
	#evince slides.pdf
clean:
	rm -f *.aux *.snm *.toc *.log *.nax *.out *.nav
