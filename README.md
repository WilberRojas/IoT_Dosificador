# Dosificador de medicamentos inteligente

## Prototipo en SolidWorks:

![alt text](https://github.com/WilberRojas/IoT_Dosificador/blob/main/SolidCompleto.png)

Cada pastilla necesita un diseño personalizado en los tubos del mecanismo del dispensador

### Mecanismo de las Pastillas

![alt text](https://github.com/WilberRojas/IoT_Dosificador/blob/main/EnsamblajePowderDispenser.gif)

### Mecanismo del Azucar

![alt text](https://github.com/WilberRojas/IoT_Dosificador/blob/main/EnsamblajePowderDispenser.gif)

## Diagrama del circuito:

![alt text](https://github.com/WilberRojas/IoT_Dosificador/blob/main/mecanismoServo.png)

NOTA: Es necesario el uso de dos fuentes de alimentacion DC, tratar de alimentar el circuito con el VCC de la placa Argon no sera sufuciente debido al uso de multiples motores.

##Codigo

#### Carpeta ```/src```:
Esta es la carpeta de origen que contiene los archivos de firmware para el proyecto. Todo lo que esté en esta carpeta se compilará en un binario de firmware para el dispositivo Particle.

#### Archivo ```.ino```:
Este archivo es el firmware que se ejecutará como la aplicación principal en su dispositivo Particle. Contiene una función `setup ()` y `loop ()`, y se puede escribir en Wiring o C / C ++. En caso de replica solo de deberá copiar el contenido de este archivo e importar las librerias dentro.

#### Archivo ```project.properties```:
Este es el archivo que especifica el nombre y el número de versión de las bibliotecas de las que depende el proyecto. Las dependencias se agregan automáticamente al archivo `project.properties` cuando agrega una biblioteca a un proyecto usando el comando `Particle: Install Library` en el IDE de escritorio.


