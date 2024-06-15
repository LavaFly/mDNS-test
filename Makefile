all: upload

compile:
	pio run -e d1_mini

upload:
	pio run -e d1_mini -t upload

clean:
	pio run -t clean
