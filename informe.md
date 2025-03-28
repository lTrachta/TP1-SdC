| Benchmark           | Descripcion           | Integrantes                                                                 |
|---------------------|----------------|-----------------------------------------------------------------------------|
| Linpack             | Mide el rendimiento en cálculos matemáticos, especialmente en operaciones de álgebra lineal como la resolución de sistemas de ecuaciones      | Luciano Trachta y Juan Ferrero (IC): No usarian este Benchmark ya que hasta el momento no fue necesario verificar que tan rapido el procesador realiza calculos matematicos, Mateo Pieckenstainer (IE): Tampoco usaria este Benchmark, pero podria utilizarlo en un futuro para la aplicación de sistemas embebidos |
| Livermore Loops     | Evalúa la eficiencia en cálculos numéricos utilizando una serie de bucles representativos de cargas de trabajo científicas.| Luciano Trachta y Juan Ferrero (IC): Seria de utilidad por el hecho que mide la eficiencia del codigo cuando se hacen calculos repetitivos y a la hora de programar seria de gran utilidad. Mateo Pieckenstainer (IE): Seria de gran utilidad, para la simulación de circuitos especificos dentro del area de la eletronica aplicada. |
| Fhourstones         | Se enfoca en operaciones con enteros, evaluando el rendimiento del procesador en tareas de lógica y aritmética básica.         | Luciano Trachta y Juan Ferrero (IC): En el caso que sigan la rama de la programación en videojuegos, seria de gran utilidad. Mateo Pieckenstainer (IE): Podria utilizarse para el diseno de chips destinados a tareas que necesitan eficiencia y velocidad en los calculos. |
| Compilación con GCC | Analiza el rendimiento del CPU al compilar código fuente, reflejando la eficiencia en entornos de desarrollo de software.  | Luciano Trachta y Juan Ferrero (IC): Sirve a los programadores para poder medir el tiempo que tarda la CPU en realizar las conversiones cuando pasan de un codigo fuente a un programa ejecutable. Mateo Pieckenstainer (IE): No usaria este benchmark |
| 3DMark              | Evalúa la capacidad gráfica en 3D de una GPU a través de pruebas de renderizado intensivo y efectos visuales avanzados.      | Luciano Trachta y Juan Ferrero (IC): Actuamente no seria de utilidad. Mateo Pieckenstainer (IE): Podria ayudar a verificar si una GPU funciona bien y si su diseno es efiiente para graficos y simulaciones |
| Renderizado en Blender              | Mide el rendimiento de la GPU al procesar escenas complejas de animación y diseño 3D.      | Luciano Trachta y Juan Ferrero (IC): No se ha utilizado hasta el momento ya que no se han desarrollado en el area de videojuegos. Mateo Pieckenstainer (IE): No usaria este benchmark. |
| MemTest86              |  Verifica la estabilidad y velocidad de la memoria RAM mediante pruebas de lectura/escritura en diferentes patrones de acceso.      | Luciano Trachta y Juan Ferrero (IC): Podria ser de gran utilidad para poder verificar inconvenientes en la memoria Ram a la hora de realizar codigos.  Mateo Pieckenstainer (IE): Lo utilizariamos para la prueba de modulos de memoria antes de integrarlos en otros dispositivos. |
| STREAM               | Mide el ancho de banda de la memoria en sistemas de alto rendimiento al evaluar la transferencia de datos en memoria.      | Luciano Trachta y Juan Ferrero (IC): Podria utilizarse este benchmark cuando en otra materia de la facultad se realiza transferencia de datos o paquetes en la memoria de la computadora. Mateo Pieckenstainer (IE): Podria utilizarse e sistemas embebidos que necesiten una movilidad de datos de memoria a gran velocidad |



Comparacion de los procesadores pedidos:
![image](https://github.com/user-attachments/assets/8c7c2f97-aeb8-4795-aafa-7748a3d99ae5)

En esta imagen y en un texto de conclusion dice que el procesador Intel Core i5-13600K obtuvo la mayor cantidad de victorias, ocupando el primer lugar en el 80 % de las pruebas. Según la media geométrica de todos los resultados, el procesador más rápido (Intel Core i5-13600K) fue 1,14 veces más rápido que el más lento (AMD Ryzen 9 5900X de 12 núcleos).

+ Para calcular una aceleracion cuando usamos un AMD Ryzen 9 7950X 16-Core usamos la siguiente formula:

*Speedup=Tiempo del procesador de referencia/Tiempo del ADM Ryzen 9 7950X 16-Core*

Si usamos como procesador de referencia el AMD Ryzen 9 5900X 12-Core tenemos Speedup= 97s/53s=1.83

Si usamos como procesador de referencia el Intel Core i5-13600K tenemos Speedup= 83s/53s=1.83=1.56

Git Luciano:

![image](https://github.com/user-attachments/assets/26a69502-76dd-4150-8daa-bf96d5d84acf)
![image](https://github.com/user-attachments/assets/8fd530b1-bc73-487a-8016-ae542a7bc70d)
![image](https://github.com/user-attachments/assets/aa2eb064-727a-435b-97de-a31677615b74)
![image](https://github.com/user-attachments/assets/22686e71-5c70-4c0b-a3e7-095e4cb8e452)


