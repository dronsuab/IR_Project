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
LIBS:TFDU4101-TR3
LIBS:prueba-cache
EELAYER 25 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 1 3
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
P 9300 2600
F 0 "U2" H 9300 3400 50  0000 C CNN
F 1 "NodeMCU_Amica_R2" H 9300 1750 50  0000 C CNN
F 2 "" H 9550 2600 50  0000 C CNN
F 3 "" H 9550 2600 50  0000 C CNN
	1    9300 2600
	1    0    0    -1  
$EndComp
$Comp
L LIS3DH U1
U 1 1 5B017F8F
P 3400 2950
F 0 "U1" H 2799 3471 50  0000 L BNN
F 1 "LIS3DH" H 2798 2348 50  0000 L BNN
F 2 "PQFN50P300X300X100-16N" H 3400 2950 50  0001 L BNN
F 3 "LIS3DH" H 3400 2950 50  0001 L BNN
F 4 "MEMS digital output motion sensor ultra low-power high performance 3-axes nano accelerometer" H 3400 2950 50  0001 L BNN "Campo4"
F 5 "Unavailable" H 3400 2950 50  0001 L BNN "Campo5"
F 6 "None" H 3400 2950 50  0001 L BNN "Campo6"
F 7 "LGA-16 STMicroelectronics" H 3400 2950 50  0001 L BNN "Campo7"
F 8 "STMicroelectronics" H 3400 2950 50  0001 L BNN "Campo8"
	1    3400 2950
	1    0    0    -1  
$EndComp
NoConn ~ 2700 3150
NoConn ~ 2700 3250
NoConn ~ 2700 3350
$Comp
L C C1
U 1 1 5B01CC43
P 4750 2850
F 0 "C1" H 4775 2950 50  0000 L CNN
F 1 "100n" H 4775 2750 50  0000 L CNN
F 2 "" H 4788 2700 50  0001 C CNN
F 3 "" H 4750 2850 50  0001 C CNN
	1    4750 2850
	0    1    1    0   
$EndComp
$Comp
L GND-RESCUE-prueba #PWR01
U 1 1 5B01CDAB
P 4950 3350
F 0 "#PWR01" H 4950 3400 40  0001 C CNN
F 1 "GND" H 4950 3200 40  0000 C CNN
F 2 "" H 4950 3350 35  0000 C CNN
F 3 "" H 4950 3350 35  0000 C CNN
	1    4950 3350
	1    0    0    -1  
$EndComp
Text Label 3350 1400 2    60   ~ 0
NRST
Text Label 3350 1550 2    60   ~ 0
VDD
Text Label 4350 2400 2    60   ~ 0
VDD
Text Label 5600 3900 2    60   ~ 0
VDD
Text Label 8650 3300 2    60   ~ 0
VDD
Text Label 10050 3000 0    60   ~ 0
USART2_TX
Text Label 10050 3100 0    60   ~ 0
USART2_RX
Text Label 2400 2750 2    60   ~ 0
VDD
Text Label 2400 2650 2    60   ~ 0
I2C1_SDA
Text Label 2400 2550 2    60   ~ 0
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
L GND-RESCUE-prueba #PWR02
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
NoConn ~ 2400 2850
NoConn ~ 2400 2950
Wire Wire Line
	3850 4050 4150 4050
Wire Wire Line
	3850 4150 4150 4150
Wire Wire Line
	3850 4250 4150 4250
Wire Wire Line
	4200 4350 4200 4550
Wire Wire Line
	3850 4350 4200 4350
Wire Wire Line
	2700 2550 2400 2550
Wire Wire Line
	2700 2650 2400 2650
Wire Wire Line
	2700 2750 2400 2750
Wire Wire Line
	4100 3250 4400 3250
Wire Wire Line
	4350 2400 4350 2650
Wire Wire Line
	4100 2650 4500 2650
Connection ~ 4350 2550
Wire Wire Line
	4950 3150 4100 3150
Connection ~ 4400 3250
Wire Wire Line
	2700 2850 2400 2850
Wire Wire Line
	2700 2950 2400 2950
Connection ~ 4400 3150
Wire Wire Line
	4950 2550 4950 3350
Connection ~ 4950 3150
Wire Wire Line
	3350 1550 3550 1550
Wire Wire Line
	3550 1400 3350 1400
Wire Wire Line
	5850 3900 5600 3900
Wire Wire Line
	5850 3750 5600 3750
Wire Wire Line
	5850 3600 5600 3600
Wire Wire Line
	8850 3300 8650 3300
Wire Wire Line
	9750 3000 10050 3000
Wire Wire Line
	9750 3100 10050 3100
Wire Wire Line
	7800 2900 8050 2900
Wire Wire Line
	7800 3050 8050 3050
Wire Wire Line
	7800 2050 8050 2050
Wire Wire Line
	7800 2200 8050 2200
Wire Wire Line
	5850 2050 5600 2050
Wire Wire Line
	5850 2200 5600 2200
Wire Wire Line
	5850 4050 5600 4050
NoConn ~ 8850 3100
NoConn ~ 8850 3000
NoConn ~ 8850 2900
NoConn ~ 8850 2800
NoConn ~ 8850 2700
NoConn ~ 8850 2600
NoConn ~ 8850 2500
NoConn ~ 8850 2400
NoConn ~ 8850 2300
NoConn ~ 8850 2200
NoConn ~ 8850 2100
NoConn ~ 8850 2000
NoConn ~ 8850 1900
NoConn ~ 9750 1900
NoConn ~ 9750 2000
NoConn ~ 9750 2100
NoConn ~ 9750 2200
NoConn ~ 9750 2300
NoConn ~ 9750 2400
NoConn ~ 9750 2500
NoConn ~ 9750 2600
NoConn ~ 9750 2700
NoConn ~ 9750 2800
NoConn ~ 9750 2900
NoConn ~ 9750 3200
NoConn ~ 9750 3300
Wire Wire Line
	4400 3350 4100 3350
Wire Wire Line
	4400 3150 4400 3350
Connection ~ 4350 2650
Wire Wire Line
	4100 2550 4600 2550
Wire Wire Line
	8850 3200 8400 3200
Wire Wire Line
	8400 3200 8400 3550
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
$EndSheet
Wire Wire Line
	5850 2900 5600 2900
Wire Wire Line
	5850 3050 5600 3050
Wire Wire Line
	7800 4100 8050 4100
$Comp
L GND-RESCUE-prueba #PWR03
U 1 1 5B01ECC0
P 8400 3550
F 0 "#PWR03" H 8400 3600 40  0001 C CNN
F 1 "GND" H 8400 3400 40  0000 C CNN
F 2 "" H 8400 3550 35  0000 C CNN
F 3 "" H 8400 3550 35  0000 C CNN
	1    8400 3550
	1    0    0    -1  
$EndComp
$Comp
L GND-RESCUE-prueba #PWR04
U 1 1 5B08E41E
P 8050 4100
F 0 "#PWR04" H 8050 4150 40  0001 C CNN
F 1 "GND" H 8050 3950 40  0000 C CNN
F 2 "" H 8050 4100 35  0000 C CNN
F 3 "" H 8050 4100 35  0000 C CNN
	1    8050 4100
	1    0    0    -1  
$EndComp
$Comp
L TFDU4101-TR3 U6
U 1 1 5B08E4A1
P 4950 5150
F 0 "U6" H 5600 5450 50  0000 L CNN
F 1 "TFDU4101-TR3" H 5600 5350 50  0000 L CNN
F 2 "TFDU4101-TR3" H 5600 5250 50  0001 L CNN
F 3 "http://uk.rs-online.com/web/p/products/0404691P" H 5600 5150 50  0001 L CNN
F 4 "VISHAY Infrared Transceiver Module - TFDU4101-TR3 - TX,INFRARED, 115.2KBPS, MSL-4" H 5600 5050 50  0001 L CNN "Description"
F 5 "0404691P" H 5600 4850 50  0001 L CNN "RS Part Number"
F 6 "Vishay" H 5600 4750 50  0001 L CNN "Manufacturer_Name"
F 7 "TFDU4101-TR3" H 5600 4650 50  0001 L CNN "Manufacturer_Part_Number"
	1    4950 5150
	1    0    0    -1  
$EndComp
Wire Wire Line
	4950 5150 4850 5150
Text Label 5600 2050 2    60   ~ 0
USART1_RX
Text Label 5600 2200 2    60   ~ 0
USART1_TX
Wire Wire Line
	4950 5250 4850 5250
Wire Wire Line
	4750 5350 4950 5350
Wire Wire Line
	5750 5350 5850 5350
Wire Wire Line
	5850 5350 5850 5450
Wire Wire Line
	5850 5450 5750 5450
$Comp
L GND #PWR05
U 1 1 5B08EA83
P 6050 5500
F 0 "#PWR05" H 6050 5250 50  0001 C CNN
F 1 "GND" H 6050 5350 50  0000 C CNN
F 2 "" H 6050 5500 50  0001 C CNN
F 3 "" H 6050 5500 50  0001 C CNN
	1    6050 5500
	1    0    0    -1  
$EndComp
Wire Wire Line
	5850 5400 6050 5400
Wire Wire Line
	6050 5400 6050 5500
Connection ~ 5850 5400
Wire Wire Line
	5750 5250 5950 5250
$Comp
L R R7
U 1 1 5B08EC4D
P 6100 5250
F 0 "R7" V 6180 5250 50  0000 C CNN
F 1 "56" V 6100 5250 50  0000 C CNN
F 2 "" V 6030 5250 50  0001 C CNN
F 3 "" H 6100 5250 50  0001 C CNN
	1    6100 5250
	0    1    1    0   
$EndComp
$Comp
L R R6
U 1 1 5B08ED71
P 4600 5350
F 0 "R6" V 4680 5350 50  0000 C CNN
F 1 "47" V 4600 5350 50  0000 C CNN
F 2 "" V 4530 5350 50  0001 C CNN
F 3 "" H 4600 5350 50  0001 C CNN
	1    4600 5350
	0    1    1    0   
$EndComp
Wire Wire Line
	4450 5350 4350 5350
Wire Wire Line
	6250 5250 6400 5250
NoConn ~ 5750 5150
NoConn ~ 4950 5450
Text Label 4850 5250 2    60   ~ 0
USART1_RX
Text Label 4850 5150 2    60   ~ 0
USART1_TX
Text Label 6400 5250 0    60   ~ 0
VDD
Text Label 4350 5350 2    60   ~ 0
VDD
$Comp
L C C9
U 1 1 5B091C82
P 4800 5600
F 0 "C9" H 4825 5700 50  0000 L CNN
F 1 "0.1u" H 4825 5500 50  0000 L CNN
F 2 "" H 4838 5450 50  0001 C CNN
F 3 "" H 4800 5600 50  0001 C CNN
	1    4800 5600
	1    0    0    -1  
$EndComp
$Comp
L C C10
U 1 1 5B091D47
P 6300 5550
F 0 "C10" H 6325 5650 50  0000 L CNN
F 1 "4.7u" H 6325 5450 50  0000 L CNN
F 2 "" H 6338 5400 50  0001 C CNN
F 3 "" H 6300 5550 50  0001 C CNN
	1    6300 5550
	1    0    0    -1  
$EndComp
Wire Wire Line
	4800 5450 4800 5350
Connection ~ 4800 5350
$Comp
L GND #PWR06
U 1 1 5B091FDC
P 4800 5750
F 0 "#PWR06" H 4800 5500 50  0001 C CNN
F 1 "GND" H 4800 5600 50  0000 C CNN
F 2 "" H 4800 5750 50  0001 C CNN
F 3 "" H 4800 5750 50  0001 C CNN
	1    4800 5750
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR07
U 1 1 5B09205C
P 6300 5700
F 0 "#PWR07" H 6300 5450 50  0001 C CNN
F 1 "GND" H 6300 5550 50  0000 C CNN
F 2 "" H 6300 5700 50  0001 C CNN
F 3 "" H 6300 5700 50  0001 C CNN
	1    6300 5700
	1    0    0    -1  
$EndComp
Wire Wire Line
	6300 5400 6300 5250
Connection ~ 6300 5250
NoConn ~ 5600 2900
NoConn ~ 5600 3050
$Comp
L R R8
U 1 1 5B093E09
P 4350 2850
F 0 "R8" V 4430 2850 50  0000 C CNN
F 1 "1K" V 4350 2850 50  0000 C CNN
F 2 "" V 4280 2850 50  0001 C CNN
F 3 "" H 4350 2850 50  0001 C CNN
	1    4350 2850
	0    1    1    0   
$EndComp
Wire Wire Line
	4500 2650 4500 2850
Wire Wire Line
	4100 2850 4200 2850
$Comp
L PWR_FLAG #FLG08
U 1 1 5B098C77
P 8950 4950
F 0 "#FLG08" H 8950 5025 50  0001 C CNN
F 1 "PWR_FLAG" H 8950 5100 50  0000 C CNN
F 2 "" H 8950 4950 50  0001 C CNN
F 3 "" H 8950 4950 50  0001 C CNN
	1    8950 4950
	1    0    0    -1  
$EndComp
$Comp
L PWR_FLAG #FLG09
U 1 1 5B098D6F
P 9550 4950
F 0 "#FLG09" H 9550 5025 50  0001 C CNN
F 1 "PWR_FLAG" H 9550 5100 50  0000 C CNN
F 2 "" H 9550 4950 50  0001 C CNN
F 3 "" H 9550 4950 50  0001 C CNN
	1    9550 4950
	1    0    0    -1  
$EndComp
$Comp
L GND-RESCUE-prueba #PWR010
U 1 1 5B098DF2
P 8950 5300
F 0 "#PWR010" H 8950 5350 40  0001 C CNN
F 1 "GND" H 8950 5150 40  0000 C CNN
F 2 "" H 8950 5300 35  0000 C CNN
F 3 "" H 8950 5300 35  0000 C CNN
	1    8950 5300
	1    0    0    -1  
$EndComp
$Comp
L VCC #PWR011
U 1 1 5B098E6D
P 9550 5300
F 0 "#PWR011" H 9550 5150 50  0001 C CNN
F 1 "VCC" H 9550 5450 50  0000 C CNN
F 2 "" H 9550 5300 50  0001 C CNN
F 3 "" H 9550 5300 50  0001 C CNN
	1    9550 5300
	-1   0    0    1   
$EndComp
Wire Wire Line
	8950 5300 8950 4950
Wire Wire Line
	9550 4950 9550 5300
$Comp
L VCC #PWR012
U 1 1 5B09902D
P 3400 1900
F 0 "#PWR012" H 3400 1750 50  0001 C CNN
F 1 "VCC" H 3400 2050 50  0000 C CNN
F 2 "" H 3400 1900 50  0001 C CNN
F 3 "" H 3400 1900 50  0001 C CNN
	1    3400 1900
	-1   0    0    1   
$EndComp
Wire Wire Line
	3400 1900 3400 1550
Connection ~ 3400 1550
Wire Wire Line
	4900 2850 4950 2850
Connection ~ 4950 2850
Wire Wire Line
	4600 2550 4600 2850
$Comp
L C C13
U 1 1 5B0A27B6
P 4750 2550
F 0 "C13" H 4775 2650 50  0000 L CNN
F 1 "10u" H 4775 2450 50  0000 L CNN
F 2 "" H 4788 2400 50  0001 C CNN
F 3 "" H 4750 2550 50  0001 C CNN
	1    4750 2550
	0    1    1    0   
$EndComp
Wire Wire Line
	4900 2550 4950 2550
$EndSCHEMATC
