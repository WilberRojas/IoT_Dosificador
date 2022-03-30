# Dosificador de medicamentos inteligente
Puede revisar el articulo en [Articulo.pdf](https://github.com/WilberRojas/IoT_Dosificador/blob/main/Articulo.pdf)

## 1. Comunicación IoT

![alt text](https://github.com/WilberRojas/IoT_Dosificador/blob/main/DiagramaIoT.png)

## 2. Prototipo en SolidWorks:

![alt text](https://github.com/WilberRojas/IoT_Dosificador/blob/main/SolidCompleto.png)

Cada pastilla necesita un diseño personalizado en los tubos del mecanismo del dispensador

### 2.1. Mecanismo de las Pastillas

![alt text](https://github.com/WilberRojas/IoT_Dosificador/blob/main/mecanismo_pastillas.gif)

### 2.2. Mecanismo del Azucar

![alt text](https://github.com/WilberRojas/IoT_Dosificador/blob/main/EnsamblajePowderDispenser.gif)

## 3. Diagrama del circuito:

Para diagramar el circuito del proyecto se uso la herramienta de https://fritzing.org/ 

Puede descargar el archivo .fzz aqui: [Diagrama_electronico.fzz](https://github.com/WilberRojas/IoT_Dosificador/blob/main/Diagrama_electronico.fzz?raw=true)

![alt text](https://github.com/WilberRojas/IoT_Dosificador/blob/main/Circuito.png)

NOTA: Es necesario el uso de dos fuentes de alimentacion DC, no es posible alimentar el circuito solo con el VCC de salida la placa Argon debido al uso de multiples motores que requieren gran amperaje.

## 4. Codigo

#### Carpeta ```/src```:
Esta es la carpeta de origen que contiene los archivos de firmware para el proyecto. Todo lo que esté en esta carpeta se compilará en un binario de firmware para el dispositivo Particle.

#### Archivo ```.ino```:
Este archivo es el firmware que se ejecutará como la aplicación principal en el dispositivo Particle. Contiene una función `setup ()` y `loop ()`, y se puede escribir en Wiring o C / C ++. En caso de replica solo de deberá copiar el contenido de este archivo e importar las librerias dentro. Puede revisar el codigo en [stepperL298N.ino](https://github.com/WilberRojas/IoT_Dosificador/blob/main/src/stepperL298N.ino).

#### Archivo ```project.properties```:
Este es el archivo que especifica el nombre y el número de versión de las bibliotecas de las que depende el proyecto. Las dependencias se agregan automáticamente al archivo `project.properties` cuando agrega una biblioteca a un proyecto usando el comando `Particle: Install Library` en el IDE de escritorio.


