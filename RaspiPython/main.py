# /usr/bin/env python

# -*- coding: UTF-8 _*_
'''
 *
 *                        ,%%%%%%%%,
 *                      ,%%/\%%%%/\%%
 *                     ,%%%\c "" J/%%%
 *            %.       %%%%/ o  o \%%%
 *            `%%.     %%%%    _  |%%%
 *             `%%     `%%%%(__Y__)%%'
 *             //       ;%%%%`\-/%%%'
 *            ((       /  `%%%%%%%'
 *             \\    .'          |
 *              \\  /       \  | |
 *               \\/         ) | |
 *                \         /_ | |__
 *                (___________))))))) Carlos Lopez. 2017
 *'''
# python script document for B07 project.
#**************************************************************************#
#                                                                          #
#  @File       : *_main.py         	           			   #
#  @Copyright  : Powered by MULTIBEANS ORG rights reserved.                #
#  @Revision   : Ver 1.0.                                                  #
#  @Data       : 2017.08.31 Realse.                                        #
#  @Belong     : PROJECT.                                                  #
#  @Git	       : https://github.com/lifimlt/SFGA.git                       #
#  **code : (UTF-8) in Raspbian(x64). 			                   #
#**************************************************************************#
#  @Attention:                                                             #
#  ---------------------------------------------------------------------   #
#  |    Data    |  Behavior |     Offer      |          Content         |  #
#  | 2017.08.31 |   create  |Carlos Lopez(M) | ceate the document.      |  #
#  ---------------------------------------------------------------------   #
#  Email: carlos@mltbns.top                                  MULTIBEANS.   #
#**************************************************************************#

## Notice:
## *** This script run in the raspbian system on raspberry pi 3 B+.
## **  Don't run the program on other platform.
## *   Please use the root permission to run the script.

## ->  # sudo python main.py

## GNU ORIGIN

# one line to give the program's name and an idea of what it does.
# Copyright (C) MULTIBEANS TECHOLOGY ORG. This program is modify it under
# as published by of the License,free software; you can redistribute
# it and/or the terms of the GNU General Public License the Free
# Software Foundation; either version 2 or (at your option) any
# later version. This program is distributed in the hope that it will
# be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
# GNU General Public License for more details.

# You should have received a copy of the GNU General Public License
# along with this program; if not, write to the Free Software
# Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301, USA.



## Hello

import pygame
from picamera.array import PiRGBArray
import RPi.GPIO as GPIO
import serial
import time
import string
import struct
import binascii
import picamera
import cv2
import os
import threading
import sys, subprocess, urllib


#please modify your phone number.

# SIM800 Module
at_cmd_string_dialnumber = "ATD+8613130286058\r\n"
at_cmd_string_hangoutdial = "ATH\r\n"

# Define a data array.
# com: 0xAA 0xBB cmd dat1 dat2 dat3 dat4 plo
# 9-bits.
CMD_CMD_ERROR = 0x04
CMD_ALARM	= 0x00
CMD_GET_IMAGE	=	0x01
CMD_THEFT_CHECKED	=	0x02
CMD_ID_CONFIRM		= 	0x03
CMD_ID_CONFIRM_NO		=	0x04
CMD_ID_CONFIRM_YES		=	0x05
CMD_ID_STOP_WARN		=   0x06
CMD_RECOVERY_CHECK		= 	0x07

# Define global value in project
cmdBuffer = []
rxBuffer = []
rxCounter = 0

# start up serialPort function.
serialPort = serial.Serial( '/dev/serial0', 115200 )
gprsPort = serial.Serial( '/dev/ttyUSB0',115200 )

#def ProcessComEvent( rxBuffer ):
# Init the camera.
bool_newPhoto = False
camera = picamera.PiCamera()
rawCapture = PiRGBArray( camera )
camera.resolution = (450,450)				# set pix for photo
camera.led = False
camera.vflip = True

#def Technology open lock flag
global_id_confirm_flag = False
#request the id confirm.
#UartSendCmd(CMD_ID_CONFIRM)
# Init Sensors
vibSensorA0Channel = 5
vibSensorA1Channel = 6
vibSensorA2Channel = 13
vibSensorA3Channel = 19
vibSensorAlarmLight = 26
vibSensorDoorCheck = 20


bool_vibSensor0State = False
bool_vibSensor1State = False
bool_vibSensor2State = False
bool_vibSensor3State = False
bool_vibSensorDoorCheck = False
bool_alarm_signal_remove = True


GPIO.setmode( GPIO.BCM )
GPIO.setup( vibSensorA0Channel, GPIO.IN, pull_up_down=GPIO.PUD_DOWN )
GPIO.setup( vibSensorA1Channel, GPIO.IN, pull_up_down=GPIO.PUD_DOWN )
GPIO.setup( vibSensorA2Channel, GPIO.IN, pull_up_down=GPIO.PUD_DOWN )
GPIO.setup( vibSensorA3Channel, GPIO.IN, pull_up_down=GPIO.PUD_DOWN )
GPIO.setup( vibSensorDoorCheck, GPIO.IN, pull_up_down=GPIO.PUD_DOWN )

GPIO.setup( vibSensorAlarmLight, GPIO.OUT )
GPIO.output( vibSensorAlarmLight, GPIO.LOW )

print("SYSTEM : Check the door.... ")
if GPIO.input( vibSensorDoorCheck ):
	print("SYSTEM : The door is not close, Please Close the door...\n")

else :
	print("SYSTE : The door is closed...\n")

def CallTheHost( ):

	global gprsPort
	global hangoutThread

	gprsPort.write( at_cmd_string_dialnumber )
        print( "################SYSTEM : -> The system start call the host.  \n" )
	# hangoutThread.start()

def PlayTheToneAudio( ) :

	fileName = "/home/pi/script/a.mp3"
	pygame.mixer.music.load( fileName )
	pygame.mixer.music.play( loops = 0, start = 0.0 )
    	print( "################SYSTEM : -> The system play the tone audio...  \n" )

def PlayTheAlaAudio() :

	fileName = "/home/pi/script/b.mp3"
	pygame.mixer.music.load( fileName )
	pygame.mixer.music.play( loops = 5, start = 0.0 )
    	print( "################SYSTEM : -> The system play the alarm audio....  \n" )


#* Edit by Carlos
#* The function is U
def UartSendCmd( cmd ):

	global cmdBuffer
	global serialPort

	cmdBuffer = []

	cmdBuffer.append( 0xAA )
	cmdBuffer.append( 0xBB )
	cmdBuffer.append( cmd )
	cmdBuffer.append( '@' )
	cmdBuffer.append( '@' )
	cmdBuffer.append( '@' )
	serialPort.write(cmdBuffer)

    	print( "The system send cmd to APP :" + cmdBuffer + " -> ok \n" )
# _/\_________________________________________________ The Function end.


# _____________/\__________________________________________ Initial end.

# Add GPIO event processor
def SensorA0CallBackEvent( channel ):
	global bool_vibSensor0State
	bool_vibSensor0State = True
	print("SYSTEM: Detected the A0 VIB sensor is triggered by user...")
GPIO.add_event_detect( vibSensorA0Channel, GPIO.FALLING, callback = SensorA0CallBackEvent )
# _/\_________________________________________________ The Function end.
#
def SensorA1CallBackEvent( channel ):

	global bool_vibSensor1State
	bool_vibSensor1State = True
	print("SYSTEM: Detected the A1 VIB sensor is triggered by user...")
GPIO.add_event_detect( vibSensorA1Channel, GPIO.FALLING, callback = SensorA1CallBackEvent )
# _/\_________________________________________________ The Function end.
#
def SensorA2CallBackEvent( channel ):

	global bool_vibSensor2State
	bool_vibSensor2State = True
	print("SYSTEM: Detected the A2 VIB sensor is triggered by user...")
GPIO.add_event_detect( vibSensorA2Channel, GPIO.FALLING, callback = SensorA2CallBackEvent )
# _/\_________________________________________________ The Function end.
#
def SensorA3CallBackEvent( channel ):

	global bool_vibSensor3State
	bool_vibSensor3State = True
	print("SYSTEM: Detected the A3 VIB sensor is triggered by user...")
GPIO.add_event_detect( vibSensorA3Channel, GPIO.FALLING, callback = SensorA3CallBackEvent )
# _/\_________________________________________________ The Function end.
alarmCounter = 0
def SensorDoorOpenCheckEvent( channel ):

	global bool_vibSensorDoorCheck
	global global_id_confirm_flag
	global bool_alarm_signal_remove
	global alarmCounter

	bool_vibSensorDoorCheck = True
	print("SYSTEM: Door has been opened! \n")
	print("SYSTEM: Check the APP cmd state permission.... \n")
	if bool_alarm_signal_remove == True:

		print("SYSTEM: checked!!")
		if global_id_confirm_flag == True:
			print("SYSTEM: The id information has been detected, and system don't do nothing...\n")
		elif global_id_confirm_flag == False:

			if alarmCounter == 0:
				print("SYSTEM:The id information no detected, the system will alarm.....WARNING,WARNING,WARNING... \n")
				CallTheHost()
				UartSendCmd( CMD_THEFT_CHECKED )
				PlayTheAlaAudio()
				GPIO.output( vibSensorAlarmLight, GPIO.HIGH )
                		print("############################################################################################################ ")
                		print("ALARM .. ALARM .. ARARM .. ALARM .. ALARM .. ARARM .. ALARM .. ALARM .. ARARM .. ALARM .. ALARM .. ARARM .. ")
                		print("ALARM .. ALARM .. ARARM .. ALARM .. ALARM .. ARARM .. ALARM .. ALARM .. ARARM .. ALARM .. ALARM .. ARARM .. ")
                		print("ALARM .. ALARM .. ARARM .. ALARM .. ALARM .. ARARM .. ALARM .. ALARM .. ARARM .. ALARM .. ALARM .. ARARM .. ")
                		print("ALARM .. ALARM .. ARARM .. ALARM .. ALARM .. ARARM .. ALARM .. ALARM .. ARARM .. ALARM .. ALARM .. ARARM .. ")
                		print("ALARM .. ALARM .. ARARM .. ALARM .. ALARM .. ARARM .. ALARM .. ALARM .. ARARM .. ALARM .. ALARM .. ARARM .. ")
                		print("ALARM .. ALARM .. ARARM .. ALARM .. ALARM .. ARARM .. ALARM .. ALARM .. ARARM .. ALARM .. ALARM .. ARARM .. ")
                		print("ALARM .. ALARM .. ARARM .. ALARM .. ALARM .. ARARM .. ALARM .. ALARM .. ARARM .. ALARM .. ALARM .. ARARM .. ")
                		print("ALARM .. ALARM .. ARARM .. ALARM .. ALARM .. ARARM .. ALARM .. ALARM .. ARARM .. ALARM .. ALARM .. ARARM .. ")
                		print("ALARM .. ALARM .. ARARM .. ALARM .. ALARM .. ARARM .. ALARM .. ALARM .. ARARM .. ALARM .. ALARM .. ARARM .. ")
                		print("ALARM .. ALARM .. ARARM .. ALARM .. ALARM .. ARARM .. ALARM .. ALARM .. ARARM .. ALARM .. ALARM .. ARARM .. ")
                		print("############################################################################################################ \n")
				alarmCounter = alarmCounter + 1
			else :
				print("SYSTEM: The door triggered again by the user, but system current not allowed alarm.. !! \n ")
		# check the id.
		print( "SYSTEM: Door is opened." )
	else:
		print("SYSTEM: The APP refused the alarmed, if you want to alarm please click the botton of recovery.. \n")

GPIO.add_event_detect( vibSensorDoorCheck, GPIO.RISING, callback = SensorDoorOpenCheckEvent )


def SensorDoorCloseCheckEvent( channel ):
    print( "SYSTEM: The system capture the door closed by user... \n" )
GPIO.add_event_detect( vibSensorDoorCheck, GPIO.FALLING, callback = SensorDoorCloseCheckEvent )
# _/\_________________________________________________ The Function end.

# New Thread 1Hz checked
checkFreq = 0.01
def CheckTheVibSensorsState() :

	global bool_vibSensor0State
	global bool_vibSensor1State
	global bool_vibSensor2State
	global bool_vibSensor3State
	global checkSensorThread
    	global bool_alarm_signal_remove

	int_subState = 0

	if bool_vibSensor0State == True:
		int_subState = int_subState + 1
		bool_vibSensor0State = False

	if bool_vibSensor1State == True:
		int_subState = int_subState + 1
		bool_vibSensor1State = False

	if bool_vibSensor2State == True:
		int_subState = int_subState + 1
		bool_vibSensor2State = False

	if bool_vibSensor3State == True:
		int_subState = int_subState + 1
		bool_vibSensor3State = False
	# Any two sensors are actived.
	if int_subState > 5:
        print( "SYSTEM: The vib sensors are enabled, and system checking the APP wether permission..." )
        if bool_alarm_signal_remove == False:
            	print("SYSTEM : -> APP said YES.... ")
    		print("SYSTEM : The vib sensors are triggered and APP passed it, the alarm behavior start....\n")
    		UartSendCmd( CMD_THEFT_CHECKED )
    		PlayTheAlaAudio()
    		CallTheHost()
    	    	GPIO.output( vibSensorAlarmLight, GPIO.HIGH )
           	print("############################################################################################################ ")
            	print("ALARM .. ALARM .. ARARM .. ALARM .. ALARM .. ARARM .. ALARM .. ALARM .. ARARM .. ALARM .. ALARM .. ARARM .. ")
            	print("ALARM .. ALARM .. ARARM .. ALARM .. ALARM .. ARARM .. ALARM .. ALARM .. ARARM .. ALARM .. ALARM .. ARARM .. ")
            	print("ALARM .. ALARM .. ARARM .. ALARM .. ALARM .. ARARM .. ALARM .. ALARM .. ARARM .. ALARM .. ALARM .. ARARM .. ")
            	print("ALARM .. ALARM .. ARARM .. ALARM .. ALARM .. ARARM .. ALARM .. ALARM .. ARARM .. ALARM .. ALARM .. ARARM .. ")
            	print("ALARM .. ALARM .. ARARM .. ALARM .. ALARM .. ARARM .. ALARM .. ALARM .. ARARM .. ALARM .. ALARM .. ARARM .. ")
            	print("ALARM .. ALARM .. ARARM .. ALARM .. ALARM .. ARARM .. ALARM .. ALARM .. ARARM .. ALARM .. ALARM .. ARARM .. ")
            	print("ALARM .. ALARM .. ARARM .. ALARM .. ALARM .. ARARM .. ALARM .. ALARM .. ARARM .. ALARM .. ALARM .. ARARM .. ")
            	print("ALARM .. ALARM .. ARARM .. ALARM .. ALARM .. ARARM .. ALARM .. ALARM .. ARARM .. ALARM .. ALARM .. ARARM .. ")
            	print("ALARM .. ALARM .. ARARM .. ALARM .. ALARM .. ARARM .. ALARM .. ALARM .. ARARM .. ALARM .. ALARM .. ARARM .. ")
            	print("ALARM .. ALARM .. ARARM .. ALARM .. ALARM .. ARARM .. ALARM .. ALARM .. ARARM .. ALARM .. ALARM .. ARARM .. ")
            	print("############################################################################################################ \n")
        elif:
            	print(" SYSTEM : -> APP said No, if you want to enable vib alarm function, you should click recovery check on your phone. \n")
	
	# Initial the all sensor flag states.
	bool_vibSensor0State = False
	bool_vibSensor1State = False
	bool_vibSensor2State = False
	bool_vibSensor3State = False

	checkSensorThread  = threading.Timer( checkFreq, CheckTheVibSensorsState )
	checkSensorThread.start()
# _/\_________________________________________________ The Function end.

checkSensorThread = threading.Timer( checkFreq, CheckTheVibSensorsState )
# start check sensors state. checkFreq->Hz

data = 1

bool_id_pass = False

def ComProtocalProcess( cmd ):
	global bool_id_pass

	# if the cmd id getImage command, The system need take a photo and transmit it.
	if cmd == CMD_GET_IMAGE:
		# Take a photo.
		GetPhotoFromCamera()
		# Inform host pc to prepare recv image datas.
		TransmitThePhotoData()
	# if the cmd is idConfirm, wait the information.
	if cmd == CMD_ID_CONFIRM:
		bool_id_pass = True

# _/\_________________________________________________ The Function end.


def AlarmLightEnable( enable ) :

	global vibSensorAlarmLight

	if enable == False:
		GPIO.OUT( vibSensorAlarmLight, GPIO.LOW )
	elif enable == True :
		GPIO.OUT( vibSensorAlarmLight, GPIO.HIGH )

# _/\_________________________________________________ The Function end.


def UartSendIOStream( ioStream ):

	global serialPort

	serialPort.write( ioStream )
	serialPort.write( "###" )

# _/\_________________________________________________ The Function end.




def GetPhotoFromCamera():
	
	global camera
	global bool_newPhoto
	global rawCapture

	bool_newPhoto = True
	camera.capture('image.jpg')				# take a photo and save it
    	# camera.capture( rawCapture, format="bgr" )
	print('SYSTEM : The system take a photo and save it as "image.jpg" in current path ! \n')
# _/\_________________________________________________ The Function end.



def TransmitThePhotoData():

	global bool_newPhoto
	global rawCapture

	print("SYSTEM : The system is transimitting the image data, Notice : Don't do anything in your APP....  \n")
	imageTarget = open('image.jpg')
	try:
		imageIOStream = imageTarget.read()
	finally:
		imageTarget.close()

	UartSendIOStream( imageIOStream )
	bool_newPhoto = False

	print("SYSTEM : The image datas has been transmited.....  \n")

# _/\_________________________________________________ The Function end.

###
###
###
def ScanUartDatas( serial ):
# /\_/\_/\_/\_/\_/\_/\_/\_/\_/\_/\_/\_THIS IS IMPORTANT!!!

	global rxCounter
	global rxBuffer
	global cmdBuffer
	global bool_id_pass
	global global_id_confirm_flag
    	global gprsPort
    	global bool_alarm_signal_remove
    	global pygame
    	global alarmCounter

	plo = 0
	rec_a_data = serial.read(1)
	rxBuffer.append( rec_a_data )
	rxCounter += 1
	print( rxBuffer )
	# if the @@@ chars are contained in rxBuffer
	if "@" in rxBuffer:
		# Deal with the cmd
		cmd_s = rxBuffer[rxBuffer.index('\xaa'):rxBuffer.index('@')];
		print("cmd_s is :")
		print( cmd_s )
		cmd = cmd_s[2]
		# char format trans.
		cmd_v = int( str( binascii.b2a_hex( cmd ) ) )

		if cmd_v == CMD_GET_IMAGE:
            		print( "SYSTEM : NOW ,the system recieved get picture command, preparing .... \n" )
			GetPhotoFromCamera()
			TransmitThePhotoData()
			rxBuffer = []

		# add 2017.11.04 , by carlos, content: add interval for id confirm.
		elif cmd_v == CMD_ID_CONFIRM_YES:

			bool_id_pass = True
			global_id_confirm_flag = True
			print( "SYSTEM: The system recived the a4d5sjsdf6556x checked code. " )
			print( "SYSTEM: The system pass the APP checked. \n" )
			rxBuffer = []

		elif cmd_v == CMD_ID_CONFIRM_NO:

			bool_id_pass = False
			global_id_confirm_flag = False
			print( "SYSTEM: The system will close the id. \n " )
			rxBuffer = []

		elif cmd_v == CMD_ID_STOP_WARN:

			bool_alarm_signal_remove = False
			alarmCounter = 0
            		print( "The user cancel the alarm.... \n" )
            		GPIO.output( vibSensorAlarmLight, GPIO.LOW )
            		print( "The AlarmLight closed..... \n" )
            		gprsPort.write( at_cmd_string_hangoutdial )
            		print( "HangoutHost AT CMD has been send.....\n" )
            		pygame.mixer.music.stop()
            		print( "The system has been close the audio..... \n" )
			rxBuffer = []

		elif cmd_v == CMD_ALARM:
            		print("SYSTEM: The APP CMD is tone play. \n")
			PlayTheToneAudio()
			rxBuffer = []

		elif cmd_v == CMD_RECOVERY_CHECK:
            		print("SYSTEM: The APP CMD is recovery the check..\n");
			bool_alarm_signal_remove = True
        		#end of if

		rxBuffer = []
		cmd_s = []
# ____/\______________________________________________ The Function end.
# Init audio
pygame.mixer.init()
# Start thread.
checkSensorThread.start()


while True:

	ScanUartDatas(serialPort)

# Copyright (C) 1989, 1991 Free Software Foundation, Inc.
# 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301, USA
# Everyone is permitted to copy and distribute verbatim copies
# of this license document, but changing it is not allowed.
