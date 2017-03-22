#!/bin/bash
#echo $1
obj1=APK_SET_STR_AUTO_LOC_TITLE
obj2=APK_SET_STR_AUTO_LOC_READ_ME
obj3=APK_SET_STR_CAR_LINE_TITLE
obj4=APK_SET_STR_SET_SCREEN_LIGHT
obj5=APK_SET_STR_SET_SCREEN_SAVER
obj6=APK_SET_STR_SET_LAN_TITLE
obj7=APK_SET_STR_SET_SOUND
obj8=APK_SET_STR_SET_KEY_SOUND_TITLE
obj9=APK_SET_STR_ABOUT_SYS_VER_TITLE
obj10=APK_SET_STR_ABOUT_CARD_INFO
obj11=APK_SET_STR_ABOUT_MACHINE_NUM
obj12=APK_SET_STR_ABOUT_FORMAT
obj13=APK_SET_STR_ABOUT_RECOVER
obj="apk_updata_string_size(GOBJ_APK_SETTING_STR6,STR_APK_SET_STR_ABOUT,\r\n
				APK_SETTING_FONT,APK_SET_STR_ABOUT_L,APK_SET_STR_ABOUT_T);\r\n
	ApkShowFont(GOBJ_APK_SETTING_STR6,STR_APK_SET_STR_ABOUT,\r\n
				APK_SETTING_FONT,APK_SET_STR_ABOUT_L,APK_SET_STR_ABOUT_T,\r\n
				APK_SET_STR_ABOUT_W,APK_SET_STR_ABOUT_H,GFLAGS_LEFT);\r\n"
#echo $obj
lien="***********************"
echo $obj|sed -e "s/APK_SET_STR_ABOUT/$obj1/g" >>code_back_result.txt
echo $line>>code_back_result.txt
echo $obj|sed -e "s/APK_SET_STR_ABOUT/$obj2/g" >>code_back_result.txt
echo $line>>code_back_result.txt
echo $obj|sed -e "s/APK_SET_STR_ABOUT/$obj3/g" >>code_back_result.txt
echo $line>>code_back_result.txt
echo $obj|sed -e "s/APK_SET_STR_ABOUT/$obj4/g" >>code_back_result.txt
echo $line>>code_back_result.txt
echo $obj|sed -e "s/APK_SET_STR_ABOUT/$obj5/g" >>code_back_result.txt
echo $line>>code_back_result.txt
echo $obj|sed -e "s/APK_SET_STR_ABOUT/$obj6/g" >>code_back_result.txt
echo $line>>code_back_result.txt
echo $obj|sed -e "s/APK_SET_STR_ABOUT/$obj6/g" >>code_back_result.txt
echo $line>>code_back_result.txt
echo $obj|sed -e "s/APK_SET_STR_ABOUT/$obj7/g" >>code_back_result.txt
echo $line>>code_back_result.txt
echo $obj|sed -e "s/APK_SET_STR_ABOUT/$obj8/g" >>code_back_result.txt
echo $line>>code_back_result.txt
echo $obj|sed -e "s/APK_SET_STR_ABOUT/$obj9/g" >>code_back_result.txt
echo $line>>code_back_result.txt
echo $obj|sed -e "s/APK_SET_STR_ABOUT/$obj10/g" >>code_back_result.txt
echo $line>>code_back_result.txt
echo $obj|sed -e "s/APK_SET_STR_ABOUT/$obj11/g" >>code_back_result.txt
echo $line>>code_back_result.txt
echo $obj|sed -e "s/APK_SET_STR_ABOUT/$obj12/g" >>code_back_result.txt
echo $line>>code_back_result.txt
echo $obj|sed -e "s/APK_SET_STR_ABOUT/$obj13/g" >>code_back_result.txt
echo $line>>code_back_result.txt
