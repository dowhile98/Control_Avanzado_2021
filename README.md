# CONTROL AVANZADO - UNAC 2021-B
archivos utilizados para la identificación y control de un motor DC
### Tarjeta de desarrolo usado
- NUCLEO-L412KB
<img src="https://www.st.com/bin/ecommerce/api/image.PF266995.en.feature-description-include-personalized-no-cpn-large.jpg">

## 1 LABORATORIO 1

## 2 LABORATORIO 2
### 2.1 DISEÑO PID ANTI WIND-UP

### 2.2 DISEÑO MRAC
### 2.3 IMPLEMENTACION 
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

