## ¡Bienvenido al Dosificador de medicamentos inteligente!

Cada proyecto de Particle se compone de 3 elementos importantes que se han creado en el directorio para el proyecto final.

#### Carpeta ```/ src```:
Esta es la carpeta de origen que contiene los archivos de firmware para su proyecto. No debe cambiarse el nombre.
Todo lo que esté en esta carpeta se compilará en un binario de firmware para el dispositivo Particle.

#### Archivo ```.ino```:
Este archivo es el firmware que se ejecutará como la aplicación principal en su dispositivo Particle. Contiene una función `setup ()` y `loop ()`, y se puede escribir en Wiring o C / C ++.
#### Archivo ```project.properties```:
Este es el archivo que especifica el nombre y el número de versión de las bibliotecas de las que depende su proyecto. Las dependencias se agregan automáticamente a su archivo `project.properties` cuando agrega una biblioteca a un proyecto usando el comando `Particle: Install Library` en la CLI o agrega una biblioteca en el IDE de escritorio.
