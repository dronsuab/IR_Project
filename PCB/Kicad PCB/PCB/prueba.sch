EESchema Schematic File Version 2
LIBS:prueba-rescue
LIBS:stm8
LIBS:stm32
LIBS:power
LIBS:device
LIBS:switches
LIBS:relays
LIBS:motors
LIBS:transistors
LIBS:conn
LIBS:linear
LIBS:regul
LIBS:74xx
LIBS:cmos4000
LIBS:adc-dac
LIBS:memory
LIBS:xilinx
LIBS:microcontrollers
LIBS:dsp
LIBS:microchip
LIBS:analog_switches
LIBS:motorola
LIBS:texas
LIBS:intel
LIBS:audio
LIBS:interface
LIBS:digital-audio
LIBS:philips
LIBS:display
LIBS:cypress
LIBS:siliconi
LIBS:opto
LIBS:atmel
LIBS:contrib
LIBS:valves
LIBS:rohm
LIBS:BU4210G-TR
LIBS:arduino
LIBS:nodemcu
LIBS:LIS3DH
LIBS:st_regul
LIBS:USB_MINI
LIBS:SC16
LIBS:TFDU4101-TR3
LIBS:prueba-cache
EELAYER 25 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 1 4
Title ""
Date ""
Rev ""
Comp ""
Comment1 ""
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
$Sheet
S 3550 1150 850  700 
U 5AF298D3
F0 "Power" 60
F1 "power.sch" 60
F2 "3V" O L 3550 1550 60 
F3 "NRST" O L 3550 1400 60 
$EndSheet
$Comp
L NodeMCU_Amica_R2 U2
U 1 1 5AFE8A27
P 9600 2600
F 0 "U2" H 9600 3400 50  0000 C CNN
F 1 "NodeMCU_Amica_R2" H 9600 1750 50  0000 C CNN
F 2 "" H 9850 2600 50  0000 C CNN
F 3 "" H 9850 2600 50  0000 C CNN
	1    9600 2600
	1    0    0    -1  
$EndComp
$Comp
L LIS3DH U1
U 1 1 5B017F8F
P 2600 2950
F 0 "U1" H 1999 3471 50  0000 L BNN
F 1 "LIS3DH" H 1998 2348 50  0000 L BNN
F 2 "PQFN50P300X300X100-16N" H 2600 2950 50  0001 L BNN
F 3 "LIS3DH" H 2600 2950 50  0001 L BNN
F 4 "MEMS digital output motion sensor ultra low-power high performance 3-axes nano accelerometer" H 2600 2950 50  0001 L BNN "Campo4"
F 5 "Unavailable" H 2600 2950 50  0001 L BNN "Campo5"
F 6 "None" H 2600 2950 50  0001 L BNN "Campo6"
F 7 "LGA-16 STMicroelectronics" H 2600 2950 50  0001 L BNN "Campo7"
F 8 "STMicroelectronics" H 2600 2950 50  0001 L BNN "Campo8"
	1    2600 2950
	1    0    0    -1  
$EndComp
$Comp
L C C1
U 1 1 5B01CC43
P 4300 2850
F 0 "C1" H 4325 2950 50  0000 L CNN
F 1 "100n" H 4325 2750 50  0000 L CNN
F 2 "" H 4338 2700 50  0001 C CNN
F 3 "" H 4300 2850 50  0001 C CNN
	1    4300 2850
	0    1    1    0   
$EndComp
$Comp
L GND-RESCUE-prueba-RESCUE-prueba #PWR01
U 1 1 5B01CDAB
P 4500 3350
F 0 "#PWR01" H 4500 3400 40  0001 C CNN
F 1 "GND" H 4500 3200 40  0000 C CNN
F 2 "" H 4500 3350 35  0000 C CNN
F 3 "" H 4500 3350 35  0000 C CNN
	1    4500 3350
	1    0    0    -1  
$EndComp
Text Label 3350 1400 2    60   ~ 0
NRST
Text Label 3350 1550 2    60   ~ 0
VDD
Text Label 3550 2400 2    60   ~ 0
VDD
Text Label 5600 3900 2    60   ~ 0
VDD
Text Label 8950 3300 2    60   ~ 0
VDD
Text Label 10350 3000 0    60   ~ 0
USART2_TX
Text Label 10350 3100 0    60   ~ 0
USART2_RX
Text Label 1600 2750 2    60   ~ 0
VDD
Text Label 1600 2650 2    60   ~ 0
I2C1_SDA
Text Label 1600 2550 2    60   ~ 0
I2C1_SCL
Text Label 8050 2900 0    60   ~ 0
I2C1_SCL
Text Label 8050 3050 0    60   ~ 0
I2C1_SDA
Text Label 8050 2050 0    60   ~ 0
USART2_RX
Text Label 8050 2200 0    60   ~ 0
USART2_TX
Text Label 5600 3600 2    60   ~ 0
SYS_SWDIO
Text Label 5600 3750 2    60   ~ 0
SYS_SWCLK
Text Label 5600 4050 2    60   ~ 0
NRST
$Comp
L Header Header1
U 1 1 5B024AA4
P 3500 4200
F 0 "Header1" H 3350 4500 60  0000 C CNN
F 1 "Header" H 3350 3900 60  0000 C CNN
F 2 "" H 3500 4200 60  0001 C CNN
F 3 "" H 3500 4200 60  0001 C CNN
	1    3500 4200
	-1   0    0    1   
$EndComp
$Comp
L GND-RESCUE-prueba-RESCUE-prueba #PWR02
U 1 1 5B02609A
P 4200 4550
F 0 "#PWR02" H 4200 4600 40  0001 C CNN
F 1 "GND" H 4200 4400 40  0000 C CNN
F 2 "" H 4200 4550 35  0000 C CNN
F 3 "" H 4200 4550 35  0000 C CNN
	1    4200 4550
	1    0    0    -1  
$EndComp
Text Label 4150 4050 0    60   ~ 0
VDD
Text Label 4150 4150 0    60   ~ 0
SYS_SWDIO
Text Label 4150 4250 0    60   ~ 0
SYS_SWCLK
NoConn ~ 1600 2950
NoConn ~ 9150 3100
NoConn ~ 9150 3000
NoConn ~ 9150 2900
NoConn ~ 9150 2800
NoConn ~ 9150 2700
NoConn ~ 9150 2600
NoConn ~ 9150 2500
NoConn ~ 9150 2400
NoConn ~ 9150 2300
NoConn ~ 9150 2200
NoConn ~ 9150 2100
NoConn ~ 9150 2000
NoConn ~ 9150 1900
NoConn ~ 10050 2100
NoConn ~ 10050 2200
NoConn ~ 10050 2300
NoConn ~ 10050 2400
NoConn ~ 10050 2600
NoConn ~ 10050 2700
NoConn ~ 10050 2800
NoConn ~ 10050 2900
NoConn ~ 10050 3300
$Sheet
S 5850 1800 1950 2550
U 5AF17978
F0 "Microcontroller" 60
F1 "microcontroller.sch" 60
F2 "3V" I L 5850 3900 60 
F3 "NRST" I L 5850 4050 60 
F4 "I2C1_SDA" B R 7800 3050 60 
F5 "SYS_SWDIO" I L 5850 3600 60 
F6 "SYS_SWCLK" I L 5850 3750 60 
F7 "USART2_RX" I R 7800 2050 60 
F8 "USART2_TX" O R 7800 2200 60 
F9 "I2C1_SCL" O R 7800 2900 60 
F10 "USART1_RX" I L 5850 2050 60 
F11 "USART1_TX" O L 5850 2200 60 
F12 "I2C2_SCL" O L 5850 2900 60 
F13 "I2C2_SDA" B L 5850 3050 60 
F14 "GND" I R 7800 4100 60 
F15 "INT1" I R 7800 3600 60 
F16 "INT2" I R 7800 3750 60 
F17 "PA5_GPIO" B R 7800 3200 60 
F18 "PA6_GPIO" B R 7800 3350 60 
$EndSheet
$Comp
L GND-RESCUE-prueba-RESCUE-prueba #PWR03
U 1 1 5B01ECC0
P 8700 3550
F 0 "#PWR03" H 8700 3600 40  0001 C CNN
F 1 "GND" H 8700 3400 40  0000 C CNN
F 2 "" H 8700 3550 35  0000 C CNN
F 3 "" H 8700 3550 35  0000 C CNN
	1    8700 3550
	1    0    0    -1  
$EndComp
$Comp
L GND-RESCUE-prueba-RESCUE-prueba #PWR04
U 1 1 5B08E41E
P 8050 4100
F 0 "#PWR04" H 8050 4150 40  0001 C CNN
F 1 "GND" H 8050 3950 40  0000 C CNN
F 2 "" H 8050 4100 35  0000 C CNN
F 3 "" H 8050 4100 35  0000 C CNN
	1    8050 4100
	1    0    0    -1  
$EndComp
Text Label 5600 2050 2    60   ~ 0
USART1_RX
Text Label 5600 2200 2    60   ~ 0
USART1_TX
$Comp
L R R7
U 1 1 5B08EC4D
P 6250 5600
F 0 "R7" V 6330 5600 50  0000 C CNN
F 1 "56" V 6250 5600 50  0000 C CNN
F 2 "" V 6180 5600 50  0001 C CNN
F 3 "" H 6250 5600 50  0001 C CNN
	1    6250 5600
	0    -1   -1   0   
$EndComp
$Comp
L R R6
U 1 1 5B08ED71
P 5550 5100
F 0 "R6" V 5630 5100 50  0000 C CNN
F 1 "47" V 5550 5100 50  0000 C CNN
F 2 "" V 5480 5100 50  0001 C CNN
F 3 "" H 5550 5100 50  0001 C CNN
	1    5550 5100
	0    1    1    0   
$EndComp
NoConn ~ 6850 5200
Text Label 6750 5400 2    60   ~ 0
USART1_RX
Text Label 6750 5300 2    60   ~ 0
USART1_TX
Text Label 5300 5100 2    60   ~ 0
VDD
$Comp
L C C9
U 1 1 5B091C82
P 5750 5350
F 0 "C9" H 5775 5450 50  0000 L CNN
F 1 "0.1u" H 5775 5250 50  0000 L CNN
F 2 "" H 5788 5200 50  0001 C CNN
F 3 "" H 5750 5350 50  0001 C CNN
	1    5750 5350
	1    0    0    -1  
$EndComp
$Comp
L C C10
U 1 1 5B091D47
P 6500 5850
F 0 "C10" H 6525 5950 50  0000 L CNN
F 1 "4.7u" H 6525 5750 50  0000 L CNN
F 2 "" H 6538 5700 50  0001 C CNN
F 3 "" H 6500 5850 50  0001 C CNN
	1    6500 5850
	1    0    0    -1  
$EndComp
$Comp
L GND-RESCUE-prueba-RESCUE-prueba #PWR05
U 1 1 5B091FDC
P 5750 5500
F 0 "#PWR05" H 5750 5250 50  0001 C CNN
F 1 "GND" H 5750 5350 50  0000 C CNN
F 2 "" H 5750 5500 50  0001 C CNN
F 3 "" H 5750 5500 50  0001 C CNN
	1    5750 5500
	1    0    0    -1  
$EndComp
NoConn ~ 5600 2900
NoConn ~ 5600 3050
$Comp
L R R8
U 1 1 5B093E09
P 3550 2850
F 0 "R8" V 3630 2850 50  0000 C CNN
F 1 "1K" V 3550 2850 50  0000 C CNN
F 2 "" V 3480 2850 50  0001 C CNN
F 3 "" H 3550 2850 50  0001 C CNN
	1    3550 2850
	0    1    1    0   
$EndComp
$Comp
L PWR_FLAG #FLG06
U 1 1 5B098C77
P 8950 4950
F 0 "#FLG06" H 8950 5025 50  0001 C CNN
F 1 "PWR_FLAG" H 8950 5100 50  0000 C CNN
F 2 "" H 8950 4950 50  0001 C CNN
F 3 "" H 8950 4950 50  0001 C CNN
	1    8950 4950
	1    0    0    -1  
$EndComp
$Comp
L PWR_FLAG #FLG07
U 1 1 5B098D6F
P 9550 4950
F 0 "#FLG07" H 9550 5025 50  0001 C CNN
F 1 "PWR_FLAG" H 9550 5100 50  0000 C CNN
F 2 "" H 9550 4950 50  0001 C CNN
F 3 "" H 9550 4950 50  0001 C CNN
	1    9550 4950
	1    0    0    -1  
$EndComp
$Comp
L GND-RESCUE-prueba-RESCUE-prueba #PWR08
U 1 1 5B098DF2
P 8950 5300
F 0 "#PWR08" H 8950 5350 40  0001 C CNN
F 1 "GND" H 8950 5150 40  0000 C CNN
F 2 "" H 8950 5300 35  0000 C CNN
F 3 "" H 8950 5300 35  0000 C CNN
	1    8950 5300
	1    0    0    -1  
$EndComp
$Comp
L VCC #PWR09
U 1 1 5B098E6D
P 9550 5300
F 0 "#PWR09" H 9550 5150 50  0001 C CNN
F 1 "VCC" H 9550 5450 50  0000 C CNN
F 2 "" H 9550 5300 50  0001 C CNN
F 3 "" H 9550 5300 50  0001 C CNN
	1    9550 5300
	-1   0    0    1   
$EndComp
$Comp
L VCC #PWR010
U 1 1 5B09902D
P 3400 1900
F 0 "#PWR010" H 3400 1750 50  0001 C CNN
F 1 "VCC" H 3400 2050 50  0000 C CNN
F 2 "" H 3400 1900 50  0001 C CNN
F 3 "" H 3400 1900 50  0001 C CNN
	1    3400 1900
	-1   0    0    1   
$EndComp
$Comp
L C C13
U 1 1 5B0A27B6
P 4300 2550
F 0 "C13" H 4325 2650 50  0000 L CNN
F 1 "10u" H 4325 2450 50  0000 L CNN
F 2 "" H 4338 2400 50  0001 C CNN
F 3 "" H 4300 2550 50  0001 C CNN
	1    4300 2550
	0    1    1    0   
$EndComp
$Comp
L TFDU4101-TR3 U6
U 1 1 5B12E0BF
P 6900 5150
F 0 "U6" H 7550 5450 50  0000 L CNN
F 1 "TFDU4101-TR3" H 7550 5350 50  0000 L CNN
F 2 "TFDU4101-TR3" H 7550 5250 50  0001 L CNN
F 3 "http://uk.rs-online.com/web/p/products/0404691P" H 7550 5150 50  0001 L CNN
F 4 "VISHAY Infrared Transceiver Module - TFDU4101-TR3 - TX,INFRARED, 115.2KBPS, MSL-4" H 7550 5050 50  0001 L CNN "Description"
F 5 "0404691P" H 7550 4850 50  0001 L CNN "RS Part Number"
F 6 "Vishay" H 7550 4750 50  0001 L CNN "Manufacturer_Name"
F 7 "TFDU4101-TR3" H 7550 4650 50  0001 L CNN "Manufacturer_Part_Number"
	1    6900 5150
	1    0    0    -1  
$EndComp
$Comp
L GND-RESCUE-prueba-RESCUE-prueba #PWR011
U 1 1 5B12E98B
P 6750 6150
F 0 "#PWR011" H 6750 5900 50  0001 C CNN
F 1 "GND" H 6750 6000 50  0000 C CNN
F 2 "" H 6750 6150 50  0001 C CNN
F 3 "" H 6750 6150 50  0001 C CNN
	1    6750 6150
	1    0    0    -1  
$EndComp
NoConn ~ 6850 5700
Text Label 6050 5600 2    60   ~ 0
VDD
NoConn ~ 8050 3600
Text Label 8050 3750 0    60   ~ 0
INT2
Text Label 1600 2850 2    60   ~ 0
INT2
$Comp
L GND-RESCUE-prueba-RESCUE-prueba #PWR012
U 1 1 5B133E88
P 10300 3250
F 0 "#PWR012" H 10300 3300 40  0001 C CNN
F 1 "GND" H 10300 3100 40  0000 C CNN
F 2 "" H 10300 3250 35  0000 C CNN
F 3 "" H 10300 3250 35  0000 C CNN
	1    10300 3250
	1    0    0    -1  
$EndComp
$Comp
L GND-RESCUE-prueba-RESCUE-prueba #PWR013
U 1 1 5B133F1A
P 10300 2500
F 0 "#PWR013" H 10300 2550 40  0001 C CNN
F 1 "GND" H 10300 2350 40  0000 C CNN
F 2 "" H 10300 2500 35  0000 C CNN
F 3 "" H 10300 2500 35  0000 C CNN
	1    10300 2500
	1    0    0    -1  
$EndComp
Text Label 8050 3200 0    60   ~ 0
PA5_GPIO
Text Label 8050 3350 0    60   ~ 0
PA6_GPIO
Text Label 10300 1900 0    60   ~ 0
PA5_GPIO
Text Label 10300 2000 0    60   ~ 0
PA6_GPIO
$Comp
L GND-RESCUE-prueba-RESCUE-prueba #PWR014
U 1 1 5B13BB66
P 1400 3600
F 0 "#PWR014" H 1400 3650 40  0001 C CNN
F 1 "GND" H 1400 3450 40  0000 C CNN
F 2 "" H 1400 3600 35  0000 C CNN
F 3 "" H 1400 3600 35  0000 C CNN
	1    1400 3600
	1    0    0    -1  
$EndComp
$Comp
L R R15
U 1 1 5B13BC04
P 1600 3350
F 0 "R15" V 1680 3350 50  0000 C CNN
F 1 "1K" V 1600 3350 50  0000 C CNN
F 2 "" V 1530 3350 50  0001 C CNN
F 3 "" H 1600 3350 50  0001 C CNN
	1    1600 3350
	0    1    1    0   
$EndComp
$Comp
L R R14
U 1 1 5B13BCC9
P 1600 3250
F 0 "R14" V 1680 3250 50  0000 C CNN
F 1 "1K" V 1600 3250 50  0000 C CNN
F 2 "" V 1530 3250 50  0001 C CNN
F 3 "" H 1600 3250 50  0001 C CNN
	1    1600 3250
	0    1    1    0   
$EndComp
$Comp
L R R13
U 1 1 5B13BD73
P 1600 3150
F 0 "R13" V 1680 3150 50  0000 C CNN
F 1 "1K" V 1600 3150 50  0000 C CNN
F 2 "" V 1530 3150 50  0001 C CNN
F 3 "" H 1600 3150 50  0001 C CNN
	1    1600 3150
	0    1    1    0   
$EndComp
$Comp
L C C15
U 1 1 5B13CF71
P 3950 2950
F 0 "C15" H 3975 3050 50  0000 L CNN
F 1 "100n" H 3975 2850 50  0000 L CNN
F 2 "" H 3988 2800 50  0001 C CNN
F 3 "" H 3950 2950 50  0001 C CNN
	1    3950 2950
	-1   0    0    1   
$EndComp
Connection ~ 4500 3150
Connection ~ 1400 3250
Wire Wire Line
	1450 3150 1400 3150
Connection ~ 1400 3350
Wire Wire Line
	1450 3250 1400 3250
Wire Wire Line
	1400 3150 1400 3600
Wire Wire Line
	1400 3350 1450 3350
Wire Wire Line
	1750 3350 1900 3350
Wire Wire Line
	1750 3250 1900 3250
Wire Wire Line
	1750 3150 1900 3150
Wire Wire Line
	7800 3350 8050 3350
Wire Wire Line
	7800 3200 8050 3200
Wire Wire Line
	10300 3200 10050 3200
Wire Wire Line
	10300 3250 10300 3200
Wire Wire Line
	10050 2500 10300 2500
Wire Wire Line
	10050 2000 10300 2000
Wire Wire Line
	10050 1900 10300 1900
Wire Wire Line
	7800 3750 8050 3750
Wire Wire Line
	7800 3600 8050 3600
Wire Wire Line
	6100 5600 6050 5600
Connection ~ 6500 5600
Wire Wire Line
	6500 5700 6500 5600
Connection ~ 6750 6000
Wire Wire Line
	6750 6000 6500 6000
Wire Wire Line
	6400 5600 6850 5600
Connection ~ 6750 5800
Wire Wire Line
	6750 5800 6850 5800
Wire Wire Line
	6750 5500 6750 6150
Wire Wire Line
	6850 5500 6750 5500
Wire Wire Line
	4450 2550 4500 2550
Wire Wire Line
	4150 2550 4150 2850
Connection ~ 4500 2850
Wire Wire Line
	4450 2850 4500 2850
Connection ~ 3400 1550
Wire Wire Line
	3400 1900 3400 1550
Wire Wire Line
	9550 4950 9550 5300
Wire Wire Line
	8950 5300 8950 4950
Wire Wire Line
	3300 2850 3400 2850
Wire Wire Line
	3700 2650 3700 2850
Connection ~ 5750 5100
Wire Wire Line
	5750 5200 5750 5100
Wire Wire Line
	5400 5100 5300 5100
Wire Wire Line
	5700 5100 6850 5100
Wire Wire Line
	6850 5400 6750 5400
Wire Wire Line
	6850 5300 6750 5300
Wire Wire Line
	7800 4100 8050 4100
Wire Wire Line
	5850 3050 5600 3050
Wire Wire Line
	5850 2900 5600 2900
Wire Wire Line
	8700 3200 8700 3550
Wire Wire Line
	9150 3200 8700 3200
Wire Wire Line
	3300 2550 4150 2550
Connection ~ 3550 2650
Wire Wire Line
	3600 3150 3600 3350
Wire Wire Line
	3600 3350 3300 3350
Wire Wire Line
	5850 4050 5600 4050
Wire Wire Line
	5850 2200 5600 2200
Wire Wire Line
	5850 2050 5600 2050
Wire Wire Line
	7800 2200 8050 2200
Wire Wire Line
	7800 2050 8050 2050
Wire Wire Line
	7800 3050 8050 3050
Wire Wire Line
	7800 2900 8050 2900
Wire Wire Line
	10050 3100 10350 3100
Wire Wire Line
	10050 3000 10350 3000
Wire Wire Line
	9150 3300 8950 3300
Wire Wire Line
	5850 3600 5600 3600
Wire Wire Line
	5850 3750 5600 3750
Wire Wire Line
	5850 3900 5600 3900
Wire Wire Line
	3550 1400 3350 1400
Wire Wire Line
	3350 1550 3550 1550
Wire Wire Line
	4500 2550 4500 3350
Connection ~ 3600 3150
Wire Wire Line
	1900 2950 1600 2950
Wire Wire Line
	1900 2850 1600 2850
Connection ~ 3600 3250
Wire Wire Line
	3300 3150 4500 3150
Connection ~ 3550 2550
Wire Wire Line
	3300 2650 3700 2650
Wire Wire Line
	3550 2400 3550 2650
Wire Wire Line
	3300 3250 3600 3250
Wire Wire Line
	1900 2750 1600 2750
Wire Wire Line
	1900 2650 1600 2650
Wire Wire Line
	1900 2550 1600 2550
Wire Wire Line
	3850 4350 4200 4350
Wire Wire Line
	4200 4350 4200 4550
Wire Wire Line
	3850 4250 4150 4250
Wire Wire Line
	3850 4150 4150 4150
Wire Wire Line
	3850 4050 4150 4050
Wire Wire Line
	3950 2800 3950 2750
Wire Wire Line
	3950 2750 3700 2750
Connection ~ 3700 2750
Wire Wire Line
	3950 3150 3950 3100
Connection ~ 3950 3150
$Sheet
S 2250 5300 1050 1300
U 5B15327D
F0 "IrDA_Driver" 60
F1 "IrDA_Driver.sch" 60
$EndSheet
$EndSCHEMATC
