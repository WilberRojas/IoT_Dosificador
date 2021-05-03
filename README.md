## ¡Bienvenido al Dosificador de medicamentos inteligente!

Cada proyecto de Particle se compone de 3 elementos importantes que verá que se han creado en el directorio de su proyecto para el proyecto final.

#### Carpeta ```/ src```:
Esta es la carpeta de origen que contiene los archivos de firmware para su proyecto. * No * debe cambiarse el nombre.
Todo lo que esté en esta carpeta cuando compile su proyecto se enviará a nuestro servicio de compilación y se compilará en un binario de firmware para el dispositivo Particle al que se ha dirigido.

Si su aplicación contiene varios archivos, todos deben incluirse en la carpeta `src`. Si su firmware depende de las bibliotecas de partículas, esas dependencias se especifican en el archivo `project.properties` al que se hace referencia a continuación.

#### Archivo ```.ino```:
Este archivo es el firmware que se ejecutará como la aplicación principal en su dispositivo Particle. Contiene una función `setup ()` y `loop ()`, y se puede escribir en Wiring o C / C ++. Para obtener más información sobre el uso de la API de firmware de Particle para crear firmware para su dispositivo Particle, consulte la sección [Referencia de firmware] (https://docs.particle.io/reference/firmware/) de la documentación de Particle.

#### Archivo ```project.properties```:
Este es el archivo que especifica el nombre y el número de versión de las bibliotecas de las que depende su proyecto. Las dependencias se agregan automáticamente a su archivo `project.properties` cuando agrega una biblioteca a un proyecto usando el comando` partículas biblioteca agregar` en la CLI o agrega una biblioteca en el IDE de escritorio.

## Agregar archivos adicionales a su proyecto

#### Proyectos con múltiples fuentes
Si desea agregar archivos adicionales a su aplicación, debe agregarlos a la carpeta `/ src`. Todos los archivos de la carpeta `/ src` se enviarán a la nube de partículas para producir un binario compilado.

#### Proyectos con bibliotecas externas
Si su proyecto incluye una biblioteca que no se ha registrado en el sistema de bibliotecas de partículas, debe crear una nueva carpeta llamada `/ lib / <nombredebiblioteca> / src` en` / <directorio del proyecto> `y agregar el` .h`, Archivos `.cpp` &` library.properties` para su biblioteca allí. Lea la [Guía de bibliotecas de firmware] (https://docs.particle.io/guide/tools-and-features/libraries/) para obtener más detalles sobre cómo desarrollar bibliotecas. Tenga en cuenta que todo el contenido de la carpeta y subcarpetas `/ lib` también se enviará a la nube para su compilación.

## Compilando tu proyecto

Cuando esté listo para compilar su proyecto, asegúrese de tener seleccionado el objetivo de dispositivo de partículas correcto y ejecute `compilación de partículas <plataforma>` en la CLI o haga clic en el botón Compilar en el IDE de escritorio. Los siguientes archivos de la carpeta de su proyecto se enviarán al servicio de compilación:

- Todo en la carpeta `/ src`, incluido el archivo de aplicación `.ino`
- El archivo `project.properties` para su proyecto
- Cualquier biblioteca almacenada en `lib / <libraryname> / src`
