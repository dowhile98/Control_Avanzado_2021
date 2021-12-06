# CONTROL AVANZADO - UNAC 2021-B
archivos utilizados para la identificación y control de un motor DC
### Tarjeta de desarrollo usado
- NUCLEO-L412KB
<img src="https://www.st.com/bin/ecommerce/api/image.PF266995.en.feature-description-include-personalized-no-cpn-large.jpg">

## 1 LABORATORIO 1
ESQUEMA DE CONEXIONES Y SOFTWARE USADOS PARA LA IDENTIFICACION DE SISTEMA
<img src="https://user-images.githubusercontent.com/47931397/144940020-c1b5106c-b018-419f-b04d-77aedc483aeb.png">
### 1.1 Adquisición de datos
Este fragmento de código se ejecuta cada 20ms y es el encargado realizar la captura de datos.
<img src="https://user-images.githubusercontent.com/47931397/144940124-e7c11aa9-f0b9-4190-8ee2-20eef8a8c308.png">

Esta función es un comando para el depurador del IDE y es el encargado de exportar los datos. Para nuestro caso solo almacenamos la salida (velocidad rad/s) debido a que nuestra entrada es constante (15.5v).
<img src="https://user-images.githubusercontent.com/47931397/144940199-92d4d0ef-f781-4c18-877a-235ca882acf8.png">
#### archivo generado y1.dat

## 2 LABORATORIO 2
### 2.1 DISEÑO PID ANTI WIND-UP
<img src="https://user-images.githubusercontent.com/47931397/144940487-020af590-8212-434d-8238-a3c25639bf79.png">
#### Resultados
<img src="https://user-images.githubusercontent.com/47931397/144941089-ef4cbd89-67ce-449c-99c4-52c3104033fe.png">
### 2.2 DISEÑO MRAC
Para poder realizar la simulacion en el simulink primero ejecutar el archivo: 
#### modeloDeReferenica.mlx
<img src="https://user-images.githubusercontent.com/47931397/144940606-c394e620-ca5b-4d72-b7bd-aaf159e6a885.png">
#### Resultados
<img src="https://user-images.githubusercontent.com/47931397/144941151-e57aa994-1454-4c3c-8814-6478857b02f3.png">
### 2.3 IMPLEMENTACION 
En el diagrama siguiente se puede observar las conexiones necesarias para poder implementar el algoritmo de control. Para la lectura de pulsos del encoder se configura un pin como interrupción externa y para la salida del controlador se configura la salida PWM por un pin.

<img src="https://user-images.githubusercontent.com/47931397/144939754-5e4b5664-a05b-4277-9107-2e44b4a90674.png">

El siguiente modelo Simulink es el usado para Embedded coder para la generación de código y aplicar el algoritmo de control implementado. Se puede observar que dentro del bloque “ALGORITMO DE CONTROL” el subsistema MRAC que en este caso sería el algoritmo de control elegido y el cual será programado en el microcontrolador STM32L412KBU. En este caso todo el programa será ejecutado por el MCU, otra opción sería realizar una implementación conjunta con simulink donde la referencia y la salida sea establecido y visualizado respectivamente por el simulink.

<img src="https://user-images.githubusercontent.com/47931397/144938440-4a7c0afc-1527-4dab-a31d-a6493553fc05.png">
En este caso Embedded coder generará un código optimizado que podrá ser compilado y cargado al microcontrolador con un entorno de desarrollo, para este propósito usaremos Arm Keil uVision. Adicionalmente se hace uso del entorno gráfico STM32CubeMx el cual nos permitirá configurar el MCU de manera gráfica. Este entorno es proporcionado por el fabricante y nos ahorra el tiempo para poder centrarnos mas en la aplicación y no mucho en la inicialización de los periféricos del MCU, ahorrándonos tiempo.

### 2.4 IMPLEMENTACION PID 
El subsistema mostrado a continuación es el controlador PID implementado en MCU, para este caso se diseñó un PID Anti Wind-UP. Embedded coder generará el código optimizado la para poder ser compilado y cargado al MCU.
<img src="https://user-images.githubusercontent.com/47931397/144938727-2f7a1a9d-e63f-4bab-b591-1277291ed1c2.png">
<img src="https://user-images.githubusercontent.com/47931397/144938841-07790a11-af89-424d-b966-d6f19d4cc8e5.png">
#### Resultado
<img src="https://user-images.githubusercontent.com/47931397/144939379-78c8121e-d710-44cf-84cc-6cb67e7fefd3.png">
A continuación, se muestra la salida PWM del microcontrolador. El PWM generado es de 40KHz y el ancho de pulso variará de acuerdo con la entrada de referencia

<img src="https://user-images.githubusercontent.com/47931397/144939444-66532b47-efb0-4835-b4d2-eb618e93f271.png">

### 2.5 IMPLEMENTACION MRAC
<img src="https://user-images.githubusercontent.com/47931397/144938913-ffaf1517-dcac-4bb4-a36d-cc854386177b.png">
A continuación, se muestra el código generado por Embedded Coder para MRAC.
<img src="https://user-images.githubusercontent.com/47931397/144938919-d566f536-3395-47bb-b206-ea40885e85ca.png">
#### Resultado

<img src="https://user-images.githubusercontent.com/47931397/144939502-95ff4784-bab7-4adf-b0fe-6c1d854803b4.png">

## AUTORES
- QUINO BRICEÑO JEFFRY	
- ALCANTARA ALVARADO JEAN PIERRE 	
- APAZA ZARATE HEDRICH FERNANDO     	
- COTAQUISPE TOMAYQUISPE ALDO OLIVER 	
- NUÑEZ HUAMANI ANTHONY					
