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
Sheet 4 4
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
L SC16IS750 SC16IS1
U 1 1 5B153456
P 3150 2100
F 0 "SC16IS1" H 2937 2570 50  0000 L BNN
F 1 "SC16IS750" H 3100 700 50  0000 L BNN
F 2 "SOP65P640X110-28N:SOP65P640X110-28N" H 4300 2350 50  0001 L BNN
F 3 "SC16IS750" H 4500 2250 50  0001 L BNN
	1    3150 2100
	1    0    0    -1  
$EndComp
$Comp
L TFDU4101-TR3 U7
U 1 1 5B15A5CD
P 8400 1700
F 0 "U7" H 9050 2000 50  0000 L CNN
F 1 "TFDU4101-TR3" H 9050 1900 50  0000 L CNN
F 2 "TFDU4101-TR3:TFDU4101-TR3" H 9050 1800 50  0001 L CNN
F 3 "http://uk.rs-online.com/web/p/products/0404691P" H 9050 1700 50  0001 L CNN
F 4 "VISHAY Infrared Transceiver Module - TFDU4101-TR3 - TX,INFRARED, 115.2KBPS, MSL-4" H 9050 1600 50  0001 L CNN "Description"
F 5 "0404691P" H 9050 1400 50  0001 L CNN "RS Part Number"
F 6 "Vishay" H 9050 1300 50  0001 L CNN "Manufacturer_Name"
F 7 "TFDU4101-TR3" H 9050 1200 50  0001 L CNN "Manufacturer_Part_Number"
	1    8400 1700
	1    0    0    -1  
$EndComp
$Comp
L TFDU4101-TR3 U8
U 1 1 5B15A662
P 8400 4000
F 0 "U8" H 9050 4300 50  0000 L CNN
F 1 "TFDU4101-TR3" H 9050 4200 50  0000 L CNN
F 2 "TFDU4101-TR3:TFDU4101-TR3" H 9050 4100 50  0001 L CNN
F 3 "http://uk.rs-online.com/web/p/products/0404691P" H 9050 4000 50  0001 L CNN
F 4 "VISHAY Infrared Transceiver Module - TFDU4101-TR3 - TX,INFRARED, 115.2KBPS, MSL-4" H 9050 3900 50  0001 L CNN "Description"
F 5 "0404691P" H 9050 3700 50  0001 L CNN "RS Part Number"
F 6 "Vishay" H 9050 3600 50  0001 L CNN "Manufacturer_Name"
F 7 "TFDU4101-TR3" H 9050 3500 50  0001 L CNN "Manufacturer_Part_Number"
	1    8400 4000
	1    0    0    -1  
$EndComp
$Comp
L R R20
U 1 1 5B15A8A2
P 7100 1650
F 0 "R20" V 7180 1650 50  0000 C CNN
F 1 "47" V 7100 1650 50  0000 C CNN
F 2 "Resistors_SMD:R_0201" V 7030 1650 50  0001 C CNN
F 3 "" H 7100 1650 50  0001 C CNN
	1    7100 1650
	0    1    1    0   
$EndComp
$Comp
L C C19
U 1 1 5B15A9DC
P 8000 2350
F 0 "C19" H 8025 2450 50  0000 L CNN
F 1 "4.7u" H 8025 2250 50  0000 L CNN
F 2 "Capacitors_SMD:C_0201" H 8038 2200 50  0001 C CNN
F 3 "" H 8000 2350 50  0001 C CNN
	1    8000 2350
	1    0    0    -1  
$EndComp
$Comp
L C C18
U 1 1 5B15AB08
P 7650 1800
F 0 "C18" H 7675 1900 50  0000 L CNN
F 1 "0.1u" H 7400 1800 50  0000 L CNN
F 2 "Capacitors_SMD:C_0201" H 7688 1650 50  0001 C CNN
F 3 "" H 7650 1800 50  0001 C CNN
	1    7650 1800
	1    0    0    -1  
$EndComp
$Comp
L R R22
U 1 1 5B15AB84
P 7800 2150
F 0 "R22" V 7880 2150 50  0000 C CNN
F 1 "47" V 7800 2150 50  0000 C CNN
F 2 "Resistors_SMD:R_0201" V 7730 2150 50  0001 C CNN
F 3 "" H 7800 2150 50  0001 C CNN
	1    7800 2150
	0    1    1    0   
$EndComp
Text Label 6850 1650 2    60   ~ 0
VDD
Text Label 7550 2150 2    60   ~ 0
VDD
Text Label 7650 2000 0    60   ~ 0
GND
Text Label 8200 2800 3    60   ~ 0
GND
NoConn ~ 8350 2250
NoConn ~ 8350 1750
$Comp
L R R19
U 1 1 5B15B047
P 7050 3950
F 0 "R19" V 7130 3950 50  0000 C CNN
F 1 "47" V 7050 3950 50  0000 C CNN
F 2 "Resistors_SMD:R_0201" V 6980 3950 50  0001 C CNN
F 3 "" H 7050 3950 50  0001 C CNN
	1    7050 3950
	0    1    1    0   
$EndComp
$Comp
L C C17
U 1 1 5B15B0E3
P 7550 4100
F 0 "C17" H 7575 4200 50  0000 L CNN
F 1 "0.1u" H 7300 4100 50  0000 L CNN
F 2 "Capacitors_SMD:C_0201" H 7588 3950 50  0001 C CNN
F 3 "" H 7550 4100 50  0001 C CNN
	1    7550 4100
	1    0    0    -1  
$EndComp
$Comp
L R R21
U 1 1 5B15B1D0
P 7750 4450
F 0 "R21" V 7830 4450 50  0000 C CNN
F 1 "47" V 7750 4450 50  0000 C CNN
F 2 "Resistors_SMD:R_0201" V 7680 4450 50  0001 C CNN
F 3 "" H 7750 4450 50  0001 C CNN
	1    7750 4450
	0    1    1    0   
$EndComp
$Comp
L C C20
U 1 1 5B15B264
P 8000 4600
F 0 "C20" H 8025 4700 50  0000 L CNN
F 1 "4.7u" H 8025 4500 50  0000 L CNN
F 2 "Capacitors_SMD:C_0201" H 8038 4450 50  0001 C CNN
F 3 "" H 8000 4600 50  0001 C CNN
	1    8000 4600
	1    0    0    -1  
$EndComp
NoConn ~ 8350 4050
NoConn ~ 8350 4550
Text Label 6850 3950 2    60   ~ 0
VDD
Text Label 7500 4450 2    60   ~ 0
VDD
Text Label 8000 4950 3    60   ~ 0
GND
Text Label 7550 4300 0    60   ~ 0
GND
Text Label 4600 2400 0    60   ~ 0
GND
NoConn ~ 2450 2900
NoConn ~ 2450 1800
NoConn ~ 2450 1900
NoConn ~ 4150 2900
NoConn ~ 4150 3000
NoConn ~ 4150 2800
NoConn ~ 4150 2700
NoConn ~ 4150 2600
NoConn ~ 4150 2500
NoConn ~ 4150 2100
NoConn ~ 4150 2000
NoConn ~ 4150 1900
NoConn ~ 4150 1800
NoConn ~ 2450 2300
NoConn ~ 2450 2400
$Comp
L R R18
U 1 1 5B1F8BCA
P 4500 2950
F 0 "R18" V 4580 2950 50  0000 C CNN
F 1 "1K" V 4500 2950 50  0000 C CNN
F 2 "Resistors_SMD:R_0201" V 4430 2950 50  0001 C CNN
F 3 "" H 4500 2950 50  0001 C CNN
	1    4500 2950
	1    0    0    -1  
$EndComp
Text Label 4500 2750 0    60   ~ 0
VDD
Text Label 2300 2000 2    60   ~ 0
TXA
Text Label 2300 2100 2    60   ~ 0
RXA
Text Label 2300 2600 2    60   ~ 0
VDD
Text Label 2300 2500 2    60   ~ 0
VDD
Text HLabel 2300 3000 0    60   Input ~ 0
I2C_SCL
Text HLabel 2300 3100 0    60   BiDi ~ 0
I2C_SDA
Text Label 2300 2700 2    60   ~ 0
VDD
Text Label 2300 2800 2    60   ~ 0
VDD
Text Label 4600 3100 0    60   ~ 0
IRQ
Text Label 4300 2200 0    60   ~ 0
RXB
Text Label 4300 2300 0    60   ~ 0
TXB
Text Label 2300 2200 2    60   ~ 0
VDD
Text Label 8250 1850 2    60   ~ 0
TXA
Text Label 8250 1950 2    60   ~ 0
RXA
Text Label 8250 4150 2    60   ~ 0
TXB
Text Label 8250 4250 2    60   ~ 0
RXB
Text Label 3350 800  2    60   ~ 0
VDD
Text HLabel 3850 800  2    60   Input ~ 0
VDD
Wire Wire Line
	8350 2600 8350 2350
Wire Wire Line
	8000 2500 8000 2600
Wire Wire Line
	8000 2600 8350 2600
Connection ~ 8350 2600
Wire Wire Line
	8350 2050 8200 2050
Wire Wire Line
	8200 2050 8200 2800
Connection ~ 8200 2600
Wire Wire Line
	7250 1650 8350 1650
Wire Wire Line
	7950 2150 8350 2150
Wire Wire Line
	8000 2150 8000 2200
Connection ~ 8000 2150
Connection ~ 7650 1650
Wire Wire Line
	7650 1950 7650 2000
Wire Wire Line
	7650 2150 7550 2150
Wire Wire Line
	6950 1650 6850 1650
Wire Wire Line
	7200 3950 8350 3950
Connection ~ 7550 3950
Wire Wire Line
	8350 4350 8250 4350
Wire Wire Line
	8250 4350 8250 4850
Wire Wire Line
	8250 4650 8350 4650
Wire Wire Line
	8250 4850 8000 4850
Wire Wire Line
	8000 4750 8000 4950
Connection ~ 8250 4650
Wire Wire Line
	7600 4450 7500 4450
Wire Wire Line
	7550 4250 7550 4300
Wire Wire Line
	6900 3950 6850 3950
Connection ~ 8000 4850
Wire Wire Line
	4150 2400 4600 2400
Wire Wire Line
	4150 2200 4300 2200
Wire Wire Line
	4150 2300 4300 2300
Wire Wire Line
	4150 3100 4600 3100
Wire Wire Line
	2450 3100 2300 3100
Wire Wire Line
	2450 3000 2300 3000
Wire Wire Line
	2450 2700 2300 2700
Wire Wire Line
	2450 2800 2300 2800
Wire Wire Line
	2450 2500 2300 2500
Wire Wire Line
	2450 2000 2300 2000
Wire Wire Line
	2450 2100 2300 2100
Wire Wire Line
	2450 2200 2300 2200
Wire Wire Line
	8350 4150 8250 4150
Wire Wire Line
	8350 4250 8250 4250
Wire Wire Line
	8350 1950 8250 1950
Wire Wire Line
	8350 1850 8250 1850
Wire Wire Line
	2450 2600 2300 2600
Wire Wire Line
	4500 2800 4500 2750
Connection ~ 4500 3100
Wire Wire Line
	3350 800  3850 800 
Wire Wire Line
	3350 950  3850 950 
Text Label 3350 950  2    60   ~ 0
GND
Text HLabel 3850 950  2    60   Input ~ 0
GND
Wire Wire Line
	7900 4450 8350 4450
Connection ~ 8000 4450
$EndSCHEMATC
