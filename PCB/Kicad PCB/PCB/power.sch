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
Sheet 2 4
Title ""
Date ""
Rev ""
Comp ""
Comment1 ""
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
$Comp
L LD3985M33R U4
U 1 1 5AF298DF
P 2650 1800
F 0 "U4" H 2400 2000 40  0000 C CNN
F 1 "LD3985M33R" H 2850 2000 40  0000 C CNN
F 2 "SOT-23-5" H 2650 1900 35  0000 C CIN
F 3 "" H 2650 1800 60  0000 C CNN
	1    2650 1800
	1    0    0    -1  
$EndComp
$Comp
L D_Schottky D2
U 1 1 5AF29996
P 4400 1750
F 0 "D2" H 4400 1850 50  0000 C CNN
F 1 "D_Schottky" H 4400 1650 50  0000 C CNN
F 2 "" H 4400 1750 50  0001 C CNN
F 3 "" H 4400 1750 50  0001 C CNN
	1    4400 1750
	-1   0    0    1   
$EndComp
$Comp
L C C9
U 1 1 5AF299D1
P 3650 1950
F 0 "C9" H 3675 2050 50  0000 L CNN
F 1 "1u" H 3675 1850 50  0000 L CNN
F 2 "" H 3688 1800 50  0001 C CNN
F 3 "" H 3650 1950 50  0001 C CNN
	1    3650 1950
	1    0    0    -1  
$EndComp
$Comp
L C C8
U 1 1 5AF29A25
P 3350 2100
F 0 "C8" H 3375 2200 50  0000 L CNN
F 1 "10n" H 3375 2000 50  0000 L CNN
F 2 "" H 3388 1950 50  0001 C CNN
F 3 "" H 3350 2100 50  0001 C CNN
	1    3350 2100
	1    0    0    -1  
$EndComp
$Comp
L C C10
U 1 1 5AF29B64
P 3950 2100
F 0 "C10" H 3975 2200 50  0000 L CNN
F 1 "100n" H 3975 2000 50  0000 L CNN
F 2 "" H 3988 1950 50  0001 C CNN
F 3 "" H 3950 2100 50  0001 C CNN
	1    3950 2100
	1    0    0    -1  
$EndComp
$Comp
L C C7
U 1 1 5AF29C40
P 2000 2100
F 0 "C7" H 2025 2200 50  0000 L CNN
F 1 "1u" H 2025 2000 50  0000 L CNN
F 2 "" H 2038 1950 50  0001 C CNN
F 3 "" H 2000 2100 50  0001 C CNN
	1    2000 2100
	1    0    0    -1  
$EndComp
$Comp
L C C6
U 1 1 5AF29CC4
P 1550 2100
F 0 "C6" H 1575 2200 50  0000 L CNN
F 1 "1u" H 1575 2000 50  0000 L CNN
F 2 "" H 1588 1950 50  0001 C CNN
F 3 "" H 1550 2100 50  0001 C CNN
	1    1550 2100
	1    0    0    -1  
$EndComp
$Comp
L GND-RESCUE-prueba-RESCUE-prueba #PWR016
U 1 1 5AF29D39
P 1550 2450
F 0 "#PWR016" H 1550 2200 50  0001 C CNN
F 1 "GND" H 1550 2300 50  0000 C CNN
F 2 "" H 1550 2450 50  0001 C CNN
F 3 "" H 1550 2450 50  0001 C CNN
	1    1550 2450
	1    0    0    -1  
$EndComp
$Comp
L BU4210G-TR U5
U 1 1 5AF2D23F
P 7250 4600
F 0 "U5" H 7037 5070 50  0000 L BNN
F 1 "BU4210G-TR" H 7082 3891 50  0000 L BNN
F 2 "SOT95P280X125-5N" H 7250 4600 50  0001 L BNN
F 3 "BU4210G-TR" H 7250 4600 50  0001 L BNN
F 4 "SSOP-5 Rohm" H 7250 4600 50  0001 L BNN "Field4"
F 5 "BU42 Series 1 V 70 mA Surface Mount CMOS Voltage Detector - SSOP-5" H 7250 4600 50  0001 L BNN "Field5"
F 6 "Rohm" H 7250 4600 50  0001 L BNN "Field6"
F 7 "0.33 USD" H 7250 4600 50  0001 L BNN "Field7"
F 8 "Good" H 7250 4600 50  0001 L BNN "Field8"
	1    7250 4600
	1    0    0    -1  
$EndComp
$Comp
L C C11
U 1 1 5AF2D37F
P 5550 5200
F 0 "C11" H 5575 5300 50  0000 L CNN
F 1 "1u" H 5575 5100 50  0000 L CNN
F 2 "" H 5588 5050 50  0001 C CNN
F 3 "" H 5550 5200 50  0001 C CNN
	1    5550 5200
	1    0    0    -1  
$EndComp
$Comp
L C C12
U 1 1 5AF2D49B
P 6200 4750
F 0 "C12" H 6225 4850 50  0000 L CNN
F 1 "1u" H 6225 4650 50  0000 L CNN
F 2 "" H 6238 4600 50  0001 C CNN
F 3 "" H 6200 4750 50  0001 C CNN
	1    6200 4750
	1    0    0    -1  
$EndComp
$Comp
L GND-RESCUE-prueba-RESCUE-prueba #PWR017
U 1 1 5AF2D6D4
P 6550 5500
F 0 "#PWR017" H 6550 5250 50  0001 C CNN
F 1 "GND" H 6550 5350 50  0000 C CNN
F 2 "" H 6550 5500 50  0001 C CNN
F 3 "" H 6550 5500 50  0001 C CNN
	1    6550 5500
	1    0    0    -1  
$EndComp
$Comp
L R R7
U 1 1 5AF53303
P 6950 3900
F 0 "R7" V 7030 3900 50  0000 C CNN
F 1 "R" V 6950 3900 50  0000 C CNN
F 2 "" V 6880 3900 50  0001 C CNN
F 3 "" H 6950 3900 50  0001 C CNN
	1    6950 3900
	0    1    1    0   
$EndComp
$Comp
L R R8
U 1 1 5AF53392
P 8500 3900
F 0 "R8" V 8580 3900 50  0000 C CNN
F 1 "R" V 8500 3900 50  0000 C CNN
F 2 "" V 8430 3900 50  0001 C CNN
F 3 "" H 8500 3900 50  0001 C CNN
	1    8500 3900
	0    1    1    0   
$EndComp
NoConn ~ 6550 4800
$Comp
L GND-RESCUE-prueba-RESCUE-prueba #PWR018
U 1 1 5AF5415A
P 3600 4750
F 0 "#PWR018" H 3600 4500 50  0001 C CNN
F 1 "GND" H 3600 4600 50  0000 C CNN
F 2 "" H 3600 4750 50  0001 C CNN
F 3 "" H 3600 4750 50  0001 C CNN
	1    3600 4750
	1    0    0    -1  
$EndComp
Text Notes 2650 1500 2    60   Italic 12
PWR\n
Text Notes 2050 3500 2    60   Italic 12
USB\n
Text Notes 7300 3600 2    60   Italic 12
RST\n
Text Label 1550 1550 2    60   Italic 12
5V
Text HLabel 5100 1750 2    60   Output ~ 0
3V
Text HLabel 9000 3900 2    60   Output ~ 0
NRST
Text Label 6200 3700 1    60   Italic 12
3V
Text Label 4800 1750 0    60   ~ 0
3V
$Comp
L USB_MINI USB1
U 1 1 5B0456AE
P 2300 4200
F 0 "USB1" H 2300 4100 50  0000 C CNN
F 1 "USB_MINI" H 2300 4300 50  0000 C CNN
F 2 "MODULE" H 2300 4200 50  0001 C CNN
F 3 "DOCUMENTATION" H 2300 4200 50  0001 C CNN
	1    2300 4200
	1    0    0    1   
$EndComp
Wire Wire Line
	3100 1900 3350 1900
Wire Wire Line
	3350 1900 3350 1950
Wire Wire Line
	3100 1750 4250 1750
Wire Wire Line
	3650 1750 3650 1800
Connection ~ 3650 1750
Wire Wire Line
	3950 1750 3950 1950
Connection ~ 3950 1750
Wire Wire Line
	3650 2350 3650 2100
Wire Wire Line
	1550 2350 3950 2350
Wire Wire Line
	3950 2350 3950 2250
Wire Wire Line
	3350 2350 3350 2250
Connection ~ 3650 2350
Wire Wire Line
	4550 1750 5100 1750
Wire Wire Line
	2650 2100 2650 2350
Connection ~ 3350 2350
Wire Wire Line
	1550 1750 2200 1750
Wire Wire Line
	2000 1750 2000 1950
Wire Wire Line
	2000 1900 2200 1900
Connection ~ 2000 1900
Wire Wire Line
	2000 2250 2000 2350
Connection ~ 2650 2350
Connection ~ 2000 1750
Wire Wire Line
	1550 2250 1550 2450
Connection ~ 2000 2350
Connection ~ 1550 2350
Connection ~ 1550 1750
Wire Wire Line
	6200 3700 6200 4600
Wire Wire Line
	6200 4400 6550 4400
Wire Wire Line
	6550 4600 6400 4600
Wire Wire Line
	6400 4600 6400 5050
Wire Wire Line
	6400 5050 5550 5050
Wire Wire Line
	6550 5000 6550 5500
Wire Wire Line
	5550 5350 6550 5350
Connection ~ 6550 5350
Wire Wire Line
	6200 4900 6200 5250
Wire Wire Line
	6200 5250 6550 5250
Connection ~ 6550 5250
Connection ~ 6200 4400
Wire Wire Line
	7950 3900 7950 4550
Connection ~ 6200 3900
Connection ~ 7950 3900
Wire Wire Line
	6200 3900 6800 3900
Wire Wire Line
	7100 3900 8350 3900
Wire Wire Line
	8650 3900 9000 3900
Wire Wire Line
	1550 1550 1550 1950
Wire Wire Line
	3050 4400 3600 4400
Wire Wire Line
	3050 4300 3600 4300
Wire Wire Line
	3050 4200 3300 4200
Wire Wire Line
	3050 4100 3300 4100
Wire Wire Line
	3050 4000 3650 4000
Wire Wire Line
	3600 4300 3600 4750
Connection ~ 3600 4400
Text Label 4650 4000 0    60   ~ 0
5V
NoConn ~ 3300 4100
NoConn ~ 3300 4200
$Comp
L Ferrite_Bead L1
U 1 1 5B13F962
P 4300 4000
F 0 "L1" V 4150 4025 50  0000 C CNN
F 1 "Ferrite_Bead" V 4450 4000 50  0000 C CNN
F 2 "" V 4230 4000 50  0001 C CNN
F 3 "" H 4300 4000 50  0001 C CNN
	1    4300 4000
	0    1    1    0   
$EndComp
$Comp
L D_TVS D1
U 1 1 5B13FBE2
P 3800 4000
F 0 "D1" H 3800 4100 50  0000 C CNN
F 1 "D_TVS" H 3800 3900 50  0000 C CNN
F 2 "" H 3800 4000 50  0001 C CNN
F 3 "" H 3800 4000 50  0001 C CNN
	1    3800 4000
	1    0    0    -1  
$EndComp
Wire Wire Line
	3950 4000 4150 4000
Wire Wire Line
	4450 4000 4650 4000
$Comp
L C C13
U 1 1 5B1409CA
P 7950 4700
F 0 "C13" H 7975 4800 50  0000 L CNN
F 1 "1n" H 7975 4600 50  0000 L CNN
F 2 "" H 7988 4550 50  0001 C CNN
F 3 "" H 7950 4700 50  0001 C CNN
	1    7950 4700
	1    0    0    -1  
$EndComp
$Comp
L GND-RESCUE-prueba-RESCUE-prueba #PWR019
U 1 1 5B140A20
P 7950 5250
F 0 "#PWR019" H 7950 5000 50  0001 C CNN
F 1 "GND" H 7950 5100 50  0000 C CNN
F 2 "" H 7950 5250 50  0001 C CNN
F 3 "" H 7950 5250 50  0001 C CNN
	1    7950 5250
	1    0    0    -1  
$EndComp
Wire Wire Line
	7950 4850 7950 5250
Connection ~ 7950 4400
$EndSCHEMATC
