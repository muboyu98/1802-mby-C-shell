#!/bin/bash
flag=0
if [ ! -f "temp/information.txt" ];then    #判断临时信息文件是否已经创建，已经创建则不用重新创建
    flag=1
else
    touch temp/information.txt         #没有创建的情况下创建新的临时信息文件
    flag=1
fi
if (( flag )); then
    read -p "姓名：" var
    echo $var > temp/information.txt
    
    read -p "学号：" var
    echo $var >> temp/information.txt
    
    read -p "性别：" var
    echo $var >> temp/information.txt
    
    read -p "籍贯：" var
    echo $var >> temp/information.txt
    
    read -p "政治面貌：" var
    echo $var >> temp/information.txt
    
    read -p "电话：" var
    echo $var >> temp/information.txt
    
    read -p "QQ:" var
    echo $var >> temp/information.txt
    
    read -p "宿舍:" var
    echo $var >> temp/information.txt
fi